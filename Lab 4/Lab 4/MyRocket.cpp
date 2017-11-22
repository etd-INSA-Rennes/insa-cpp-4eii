#include "MyRocket.hpp"

MyRocket::MyRocket(const Position &p, const MySize &s, const Speed &sp, Color c) : MyMobile(p, s, sp, c) {
	addGraphicObject();
}

MyRocket::~MyRocket() {

}

void MyRocket::explode() {
	figures_.clear();

	figures_.addObject(new MyCircle(bb_.p.x + 20, bb_.p.y, Color::Yellow, true, 20));
	figures_.addObject(new MyCircle(bb_.p.x, bb_.p.y + 10, Color::Orange, true, 30));
	figures_.addObject(new MyCircle(bb_.p.x + 40, bb_.p.y + 10, Color::Red, true, 40));
}

void MyRocket::addGraphicObject() {
	figures_.addObject(new MyRectangle(bb_.p.x, bb_.p.y				  , color_, false, bb_.s.dx, bb_.s.dy / 2));
	figures_.addObject(new MyRectangle(bb_.p.x, bb_.p.y + bb_.s.dy / 2, color_,  true, bb_.s.dx, bb_.s.dy / 2));
}