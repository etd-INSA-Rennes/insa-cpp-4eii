#include "MySquare.hpp"

MySquare::MySquare(int x, int y, Color color, bool fill, int length_x, int length_y) : MyRectangle(x, y, color, length_x, length_y) {

}

MySquare::~MySquare() {

}

void MySquare::draw() {
	Draw::rectangle(x_, y_, length_x_, length_y_, 2, color_, fill_);
}