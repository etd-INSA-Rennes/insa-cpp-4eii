#pragma once

#include "MyRectangle.hpp"

class MySquare : public MyRectangle {

public:
	MySquare(int x = 0, int y = 0, Color color = Color::Black, bool fill, int length_x, int length_y);
	~MySquare();
};

