#pragma once

#include "MyMobile.hpp"
#include "MyCircle.hpp"

class MyMissile : public MyMobile {

public:

	explicit MyMissile(const Position &p, const MySize &s, const Speed &sp, Color c = Color::Black);
	explicit MyMissile(const Position &p, int s, const Speed &sp, Color c = Color::Black);

	~MyMissile();

private:

	void addGraphicObject();
};

