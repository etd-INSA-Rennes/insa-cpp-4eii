#pragma once

#include "MyGDIPlus.hpp"

class MyGraphicObject {

public:
	explicit MyGraphicObject(int x = 0, int y = 0, Color color = Color::Black);
	~MyGraphicObject();

	virtual void draw() = 0;

	void move(int dx, int dy);

	static inline MyGraphicObject * getFirst() { return MyGraphicObject::first_; }

	inline MyGraphicObject * getNext() const { return next_; }

protected:

	int x_, y_;
	Color color_;

private:

	static MyGraphicObject * first_;
	MyGraphicObject * next_ = nullptr;
};

