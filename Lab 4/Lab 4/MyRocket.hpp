#pragma once

#include "MyMobile.hpp"
#include "MyRectangle.hpp"
#include "MyCircle.hpp"

class MyRocket : public MyMobile {

public:

	explicit MyRocket(const Position &p, const MySize &s, const Speed &sp, Color c);

	~MyRocket();

	void explode();

private:

	void addGraphicObject();
};

