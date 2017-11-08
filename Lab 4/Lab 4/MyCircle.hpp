#pragma once

#include "MyGraphicObject.hpp"

class MyCircle : public MyGraphicObject {

public:
	explicit MyCircle(int x = 0, int y = 0, Color color = Color::Black, bool fill = true, int radius = 0);
	~MyCircle();

	void draw();

protected:

	bool fill_;
	int radius_;
};