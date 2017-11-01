#include "MyCircle.hpp"

MyCircle::MyCircle(int x, int y, Color color, bool fill, int radius) : MyGraphicObject(x, y, color), fill_(fill), radius_(radius) {

}

MyCircle::~MyCircle() {

}

void MyCircle::draw() {
	Draw::circle(x_, y_, radius_, 2, color_, fill_);
}