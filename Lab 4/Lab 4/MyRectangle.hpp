#pragma once

#include "MyGraphicObject.hpp"

class MyRectangle : public MyGraphicObject {

public:
	explicit MyRectangle(int x = 0, int y = 0, Color color = Color::Black, bool fill = true, int length_x = 0, int length_y = 0);
	~MyRectangle();

	void draw();

protected:

	bool fill_;
	int length_x_, length_y_;
};