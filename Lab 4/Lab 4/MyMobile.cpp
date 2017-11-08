#include "MyMobile.hpp"

MyMobile::MyMobile(const Position &p, const MySize &s, const Speed &sp, Color c) : MyGameElement(p, s, c), speed_(sp) {

}

MyMobile::MyMobile(const Position &p, int s, const Speed &sp, Color c) : MyGameElement(p, s, c), speed_(sp) {

}

MyMobile::~MyMobile() {

}

bool MyMobile::isHit(const BoundingBox &bb) const {
	return false;
}