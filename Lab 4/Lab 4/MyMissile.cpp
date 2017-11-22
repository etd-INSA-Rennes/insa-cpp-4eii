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
	figures_.addObject(new MyCircle(bb_.p.x, bb_.p.y, color_, true, bb_.s.dx));
}