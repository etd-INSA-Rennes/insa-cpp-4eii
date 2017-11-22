#pragma once

#include "MyGameElement.hpp"

#include <cstdlib>

class MyMobile : public MyGameElement {

public:

	explicit MyMobile(const Position &p, const MySize &s, const Speed &sp, Color c = Color::Black);
	explicit MyMobile(const Position &p, int s, const Speed &sp, Color c = Color::Black);

	~MyMobile();

	bool isHit(const BoundingBox &bb) const;
	void step();

	void changeDirection();

protected:

	Speed speed_;

	int xDirection_;
	int yDirection_;
};

