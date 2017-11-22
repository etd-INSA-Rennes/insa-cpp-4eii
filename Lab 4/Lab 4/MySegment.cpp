#include "MySegment.hpp"

MySegment::MySegment(int x, int y, Color color, int dx, int dy) : MyGraphicObject(x, y, color), dx_(dx), dy_(dy) {

}

MySegment::~MySegment() {

}

void MySegment::draw() const {
	Draw::line(x_, y_, x_ + dx_, y_ + dy_, 2, color_);
}