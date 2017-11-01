#pragma once

#include "MyRectangle.hpp"

class MySquare : public MyRectangle {

public:
	explicit MySquare(int x = 0, int y = 0, Color color = Color::Black, bool fill = true, int length_x = 0, int length_y = 0);
	~MySquare();

	void draw();
};

