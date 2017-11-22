#include "MyRocket.hpp"

MyRocket::MyRocket(const Position &p, const MySize &s, const Speed &sp, Color c) : MyMobile(p, s, sp, c) {
	addGraphicObject();
}

MyRocket::~MyRocket() {

}

void MyRocket::addGraphicObject() {
	figures_.addObject(new MyRectangle(bb_.p.x, bb_.p.y		, Color::Green, false, 10, 10));
	figures_.addObject(new MyRectangle(bb_.p.x, bb_.p.y + 10, Color::Green,  true, 10, 10));
}

void MyRocket::step() {
	bb_.p.x++;
	bb_.p.y++;

	for (int i = 0; i < figures_.size(); ++i) {
		figures_[i].move(1, 1);
	}
}