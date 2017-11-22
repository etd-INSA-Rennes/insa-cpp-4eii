#pragma once

#include "MyGameElement.hpp"

class MyMobile : public MyGameElement {

public:

	explicit MyMobile(const Position &p, const MySize &s, const Speed &sp, Color c = Color::Black);
	explicit MyMobile(const Position &p, int s, const Speed &sp, Color c = Color::Black);

	~MyMobile();

	bool isHit(const BoundingBox &bb) const;
	virtual void step() = 0;

protected:

	Speed speed_;
};

