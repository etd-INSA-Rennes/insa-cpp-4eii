#include "MyRocket.hpp"

MyRocket::MyRocket(const Position &p, const MySize &s, const Speed &sp, Color c) : MyMobile(p, s, sp, c) {
	addGraphicObject();
}

MyRocket::~MyRocket() {

}

void MyRocket::addGraphicObject() {
	figures_.addObject(new MyRectangle(bb_.p.x, bb_.p.y		, color_, false, 30, 30));
	figures_.addObject(new MyRectangle(bb_.p.x, bb_.p.y + 30, color_,  true, 30, 30));
}