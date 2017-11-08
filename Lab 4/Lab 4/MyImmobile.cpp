#include "MyImmobile.hpp"

MyImmobile::MyImmobile(const Position &p, const MySize &s, Color c) : MyGameElement(p, s, c) {

}

MyImmobile::~MyImmobile() {

}

bool MyImmobile::isHit(const BoundingBox &bb) const {
	return false;
}