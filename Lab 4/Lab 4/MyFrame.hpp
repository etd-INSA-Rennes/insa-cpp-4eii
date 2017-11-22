#pragma once

#include "MyImmobile.hpp"
#include "MyRectangle.hpp"

class MyFrame : public MyImmobile {

public:

	explicit MyFrame(const Position &p, const MySize &s, Color c = Color::Black);

	~MyFrame();

private:

	void addGraphicObject();
};

