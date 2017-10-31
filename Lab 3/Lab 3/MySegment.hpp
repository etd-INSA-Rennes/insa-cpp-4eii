#pragma once

#include "MyGraphicObject.hpp"

class MySegment : public MyGraphicObject {

public:
	MySegment(int x = 0, int y = 0, Color color = Color::Black, int dx = 0, int dy = 0);
	~MySegment();

protected:

	int dx_, dy_;

private:


};

