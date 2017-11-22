#include "MyImmobile.hpp"

MyImmobile::MyImmobile(const Position &p, const MySize &s, Color c) : MyGameElement(p, s, c) {

}

MyImmobile::~MyImmobile() {

}

bool MyImmobile::isHit(const BoundingBox &bb) const {
	return (bb.p.x < bb_.p.x) || (bb.p.x + bb.s.dx > bb_.p.x + bb_.s.dx) || (bb.p.y < bb_.p.y) || (bb.p.y + bb.s.dy > bb_.p.y + bb_.s.dy);
}