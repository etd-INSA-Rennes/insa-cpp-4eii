#pragma once

#include "MyGraphicObject.hpp"
#include "MyGDIPlus.hpp"

class MySegment : public MyGraphicObject {

public:
	explicit MySegment(int x = 0, int y = 0, Color color = Color::Black, int dx = 0, int dy = 0);
	~MySegment();

	void draw();

protected:

	int dx_, dy_;
};