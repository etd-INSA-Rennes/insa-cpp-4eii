#include "MyGraphicObject.hpp"

MyGraphicObject::MyGraphicObject(int x, int y, Color color) : x_(x), y_(y), color_(color) {

}


MyGraphicObject::~MyGraphicObject() {

}

void MyGraphicObject::move(int dx, int dy) {
	x_ += dx;
	y_ += dy;
}