#pragma once

#include "MyGameElement.hpp"

class MyImmobile : public MyGameElement {

public:

	explicit MyImmobile(const Position &p, const MySize &s, Color c = Color::Black);

	~MyImmobile();

	bool isHit(const BoundingBox &bb) const;
};

