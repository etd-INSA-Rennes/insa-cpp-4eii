#include "MyGraphicObject.hpp"

MyGraphicObject * MyGraphicObject::first_ = nullptr;

MyGraphicObject::MyGraphicObject(int x, int y, Color color) : x_(x), y_(y), color_(color) {
	if (MyGraphicObject::first_ != nullptr) {
		next_ = MyGraphicObject::first_;
	}

	MyGraphicObject::first_ = this;
}


MyGraphicObject::~MyGraphicObject() {

}

void MyGraphicObject::move(int dx, int dy) {
	x_ += dx;
	y_ += dy;
}

MyGraphicObject * MyGraphicObject::getFirst() {
	return MyGraphicObject::first_;
}

MyGraphicObject * MyGraphicObject::getNext() const {
	return next_;
}