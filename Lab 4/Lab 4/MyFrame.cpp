#include "MyFrame.hpp"

MyFrame::MyFrame(const Position &p, const MySize &s, Color c) : MyImmobile(p, s, c) {
	addGraphicObject();
}

MyFrame::~MyFrame() {

}

void MyFrame::addGraphicObject() {
	// top
	figures_.addObject(new MyRectangle(bb_.p.x, bb_.p.y, color_, true, bb_.s.dx, 1));

	// right
	figures_.addObject(new MyRectangle(bb_.p.x + bb_.s.dx, bb_.p.y, color_, true, 1, bb_.s.dy));

	// bot
	figures_.addObject(new MyRectangle(bb_.p.x, bb_.p.y + bb_.s.dy, color_, true, bb_.s.dx, 1));

	// left
	figures_.addObject(new MyRectangle(bb_.p.x, bb_.p.y, color_, true, 1, bb_.s.dy));
}