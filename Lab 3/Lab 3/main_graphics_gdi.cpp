/*!
* \file  graphics_gdi.cpp
* \brief  Manages the graphic application (main program)
*/


#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#include "MyGDIPlus.hpp"

// static objects
namespace {
	HDC     hdc = NULL;
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	const int kWidth = 750;
	const int kHeight = 500;

	class OffScreen {
	public:
		OffScreen() {
			hdc_ = NULL;
			hdc_screen_ = NULL;
			hbm_ = NULL;
			handle_ = NULL;
			w_ = h_ = 0;
		}
		~OffScreen() { clear(); }

		void resize(int w, int h) {
			clear();
			hdc_ = CreateCompatibleDC(hdc);
			hbm_ = CreateCompatibleBitmap(hdc, w, h);
			w_ = w;
			h_ = h;
		}
		void start() {
			if (!hdc_) return;
			if (hdc == hdc_) return; // already selected
			hdc_screen_ = hdc; // save handle
			hdc = hdc_; // replace
			handle_ = SelectObject(hdc_, hbm_);
			Graphics graphics(hdc_);
			graphics.Clear(Color::White); // clear bitmap
		}
		void end() {
			if (hdc != hdc_) return;
			hdc = hdc_screen_; // replace back
			SelectObject(hdc_screen_, handle_); // give back handle to screen
			BitBlt(hdc_screen_, 0, 0, w_, h_, hdc_, 0, 0, SRCCOPY); // copy bitmap to screen
			handle_ = NULL;
		}
	private:
		void clear() {
			if (!hdc_) return;
			SelectObject(hdc_, handle_);
			handle_ = NULL;
			DeleteObject(hbm_);
			DeleteDC(hdc_);
			hbm_ = NULL;
			hdc_ = NULL;
		}

		HDC          hdc_;
		HDC          hdc_screen_;
		HBITMAP      hbm_;
		HANDLE       handle_;
		int w_, h_;
	};
	OffScreen offscreen;
}


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
	HWND                hWnd;
	MSG                 msg;
	WNDCLASS            wndClass;
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = TEXT("TP3Class");

	RegisterClass(&wndClass);

	hWnd = CreateWindow(
		TEXT("TP3Class"),   // window class name
		TEXT("Not by Picasso"),  // window caption
		WS_OVERLAPPEDWINDOW,      // window style
		CW_USEDEFAULT,            // initial x position
		CW_USEDEFAULT,            // initial y position
		kWidth,            // initial x size : CW_USEDEFAULT
		kHeight,            // initial y size
		NULL,                     // parent window handle
		NULL,                     // window menu handle
		hInstance,                // program instance handle
		NULL);                    // creation parameters

	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);

	Game::init(); // create all objects
	SetTimer(hWnd, 1 /* id*/, 20 /* update period in ms */, NULL);  // create a timer which call redraw every X ms
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	GdiplusShutdown(gdiplusToken);
	return msg.wParam;
}  // WinMain

namespace {
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
		WPARAM wParam, LPARAM lParam)
	{
		PAINTSTRUCT  ps;

		switch (message)
		{
		case WM_SIZE:
		{
			hdc = GetWindowDC(hWnd);
			int w = LOWORD(lParam);
			int h = HIWORD(lParam);
			offscreen.resize(w, h);
		}
			return 0;
		case WM_TIMER:
			Game::step();
			InvalidateRect(hWnd, NULL, FALSE);  // force redraw of the whole area
			return 0;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			offscreen.start();
			Game::draw();
			offscreen.end();
			EndPaint(hWnd, &ps);
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	} // WndProc

}


namespace Draw {
	/*!
	* \fn void line(int x1, int y1, int x2, int y2, int pen_width, Color c)
	* \brief Draw a segment
	* \param[in] x1,y1 : the coordinates of the first point
	* \param[in] x2,y2 : the coordinates of the second point
	* \param[in] pen_width : pencil width
	* \param[in] c : pencil color
	*/
	void line(int x1, int y1, int x2, int y2, int pen_width, Color c) {
		Graphics graphics(hdc);
		Pen      pen(c, (Gdiplus::REAL) pen_width);
		graphics.DrawLine(&pen, x1, y1, x2, y2);
	}



	/*!
	* \fn void point( int x1, int y1, int pen_width, Color c )
	* \brief Draw a point
	* \param[in] x1,y1 : coordinates of the point
	* \param[in] pen_width : pencil width
	* \param[in] c : pencil color
	*/
	void point(int x1, int y1, int pen_width, Color c) {
		line(x1, y1, x1 + 1, y1 + 1, pen_width, c);
		line(x1 + 1, y1, x1, y1 + 1, pen_width, c);
	}


	/*!
	* \fn void rectangle( int x1, int y1, int side_length, int side_width, int pen_width, Color c, bool fill)
	* \brief Draw a rectangle
	* \param[in] x1,y1 : the coordinates of the top left point of the rectangle
	* \param[in] side_length,side_width : width and height of the rectangle
	* \param[in] pen_width : pencil width
	* \param[in] c : pencil color
	* \param[in] fill : true if the rectangle is filled, false otherwise
	*/
	void rectangle(int x1, int y1, int side_length, int side_width, int pen_width, Color c, bool fill) {

		Graphics graphics(hdc);
		Pen pen(c, (Gdiplus::REAL)pen_width);
		graphics.DrawRectangle(&pen, x1, y1, side_length, side_width);
		if (fill) {
			SolidBrush brush(c);
			graphics.FillRectangle(&brush, x1, y1, side_length, side_width);
		}
	}


	/*!
	* \fn void  circle( int x1, int y1, int radius,  int pen_width, Color c, bool fill)
	* \brief Draw a circle
	* \param[in] x1,y1 : the coordinates of the top left point of the square that describes the bounds of the circle
	* \param[in] radius : the circle radius
	* \param[in] pen_width : pencil width
	* \param[in] c : pencil color
	* \param[in] fill : true if the circle is filled, false otherwise
	*/
	void circle(int x1, int y1, int radius, int pen_width, Color c, bool fill) {

		Graphics graphics(hdc);
		Pen      pen(c, (Gdiplus::REAL)pen_width);
		Rect circleRect(x1, y1, radius, radius);
		graphics.DrawEllipse(&pen, circleRect);
		if (fill) {
			SolidBrush brush(c);
			graphics.FillEllipse(&brush, circleRect);
		}

	}
}

