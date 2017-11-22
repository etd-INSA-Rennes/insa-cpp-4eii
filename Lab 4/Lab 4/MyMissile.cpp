#include "MyMissile.hpp"

MyMissile::MyMissile(const Position &p, const MySize &s, const Speed &sp, Color c) : MyMobile(p, s, sp, c) {
	addGraphicObject();
}

MyMissile::MyMissile(const Position &p, int s, const Speed &sp, Color c) : MyMobile(p, s, sp, c) {
	addGraphicObject();
}

MyMissile::~MyMissile() {

}

void MyMissile::addGraphicObject() {
	figures_.addObject(new MyCircle(bb_.p.x, bb_.p.y, Color::Gray, true, 10));
}

void MyMissile::step() {
	bb_.p.x++;
	bb_.p.y++;

	for (int i = 0; i < figures_.size(); ++i) {
		figures_[i].move(1, 1);
	}
}