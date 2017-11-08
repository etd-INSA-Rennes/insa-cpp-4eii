#pragma once

#include <windows.h>
#include <gdiplus.h>
using namespace Gdiplus;

// provide low level drawing functions
namespace Draw {
	void line(int x1, int y1, int x2, int y2, int pen_width, Color c);
	void point(int x1, int y1, int pen_width, Color c);
	void rectangle(int x1, int y1, int side_length, int side_width, int pen_width, Color c, bool fill);
	void circle(int x1, int y1, int radius, int pen_width, Color c, bool fill);
}


