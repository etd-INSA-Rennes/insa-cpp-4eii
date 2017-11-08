#pragma once

#include "MyImmobile.hpp"

class MyFrame : public MyImmobile {

public:

	explicit MyFrame(const Position &p, const MySize &s, Color c = Color::Black);
	~MyFrame();
};

