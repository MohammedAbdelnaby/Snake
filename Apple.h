#pragma once
#include "Position.h"

class Apple
{
public:
	Apple(int x, int y);
	~Apple();

public:
	Position pos;
};

Apple::Apple(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

Apple::~Apple() = default;
