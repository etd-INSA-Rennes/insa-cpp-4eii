#pragma once

#include "MyGraphicObject.hpp"

class MyPoint : public MyGraphicObject {

public:
	explicit MyPoint(int x = 0, int y = 0, Color color = Color::Black);
	~MyPoint();

	void draw();
};

