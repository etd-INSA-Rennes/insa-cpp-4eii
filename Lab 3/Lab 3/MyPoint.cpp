#include "MyPoint.hpp"

MyPoint::MyPoint(int x, int y, Color color) : MyGraphicObject(x, y, color) {

}

MyPoint::~MyPoint() {

}

void MyPoint::draw() {
	Draw::point(x_, y_, 2, color_);
}