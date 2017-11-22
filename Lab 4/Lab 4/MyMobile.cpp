#include "MyMobile.hpp"

MyMobile::MyMobile(const Position &p, const MySize &s, const Speed &sp, Color c) : MyGameElement(p, s, c), speed_(sp), xDirection_(1), yDirection_(1) {

}

MyMobile::MyMobile(const Position &p, int s, const Speed &sp, Color c) : MyGameElement(p, s, c), speed_(sp), xDirection_(1), yDirection_(1) {

}

MyMobile::~MyMobile() {

}

void MyMobile::step() {
	bb_.p.x += xDirection_ * speed_.x;
	bb_.p.y += yDirection_ * speed_.y;

	for (int i = 0; i < figures_.size(); ++i) {
		figures_[i].move(xDirection_ * speed_.x, yDirection_ * speed_.y);
	}
}

void MyMobile::changeDirection() {
	const int min = -1;
	const int max =  1;

	xDirection_ = rand() % (max - min + 1) + min;
	yDirection_ = rand() % (max - min + 1) + min;
}

bool MyMobile::isHit(const BoundingBox &bb) const {
	return !((bb.p.x > bb_.p.x + bb_.s.dx) || (bb.p.x + bb.s.dx < bb_.p.x) || (bb.p.y > bb_.p.y + bb_.s.dy) || (bb.p.y + bb.s.dy < bb_.p.y));
}