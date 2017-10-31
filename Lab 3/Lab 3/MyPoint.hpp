#pragma once

#include "MyGraphicObject.hpp"

class MyPoint : public MyGraphicObject {

public:
	MyPoint(int x = 0, int y = 0, int color = Color::Black);
	~MyPoint();
};

