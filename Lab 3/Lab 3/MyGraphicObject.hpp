#pragma once

#include "MyGDIPlus.hpp"

class MyGraphicObject {

public:
	MyGraphicObject(int x = 0, int y = 0, Color color = Color::Black);
	~MyGraphicObject();

	virtual void draw() = 0;

	void move(int dx, int dy);

	static inline MyGraphicObject * getFirst();
	inline MyGraphicObject * getNext();

protected:

	int x_, y_;
	Color color_;

private:

	static MyGraphicObject * first_;
	MyGraphicObject * next_ = nullptr;
};

