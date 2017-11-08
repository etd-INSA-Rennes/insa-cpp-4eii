#pragma once

#include "MyMobile.hpp"

class MyRocket : public MyMobile {

public:

	explicit MyRocket(const Position &p, const MySize &s, const Speed &sp, Color c);
	~MyRocket();
};

