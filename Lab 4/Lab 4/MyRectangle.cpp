#include "MyRectangle.hpp"

MyRectangle::MyRectangle(int x, int y, Color color, bool fill, int length_x, int length_y) : MyGraphicObject(x, y, color), fill_(fill), length_x_(length_x), length_y_(length_y) {

}

MyRectangle::~MyRectangle() {

}

void MyRectangle::draw() {
	Draw::rectangle(x_, y_, length_x_, length_y_, 2, color_, fill_);
}