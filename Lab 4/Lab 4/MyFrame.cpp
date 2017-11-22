#include "MyFrame.hpp"

MyFrame::MyFrame(const Position &p, const MySize &s, Color c) : MyImmobile(p, s, c) {
	addGraphicObject();
}

MyFrame::~MyFrame() {

}

void MyFrame::addGraphicObject() {
	// top
	figures_.addObject(new MyRectangle(0, 0, Color::Red, true, 750, 10));

	// right
	figures_.addObject(new MyRectangle(725, 0, Color::Red, true, 10, 500));

	// bot
	figures_.addObject(new MyRectangle(0, 450, Color::Red, true, 750, 10));

	// left
	figures_.addObject(new MyRectangle(0, 0, Color::Red, true, 10, 500));
}