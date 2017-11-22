#pragma once

#include "MyGDIPlus.hpp"

class MyGraphicObject {

public:
	MyGraphicObject(int x = 0, int y = 0, Color color = Color::Black);
	~MyGraphicObject();

	virtual void draw() const = 0;

	void move(int dx, int dy);

protected:

	int x_, y_;
	Color color_;
};

