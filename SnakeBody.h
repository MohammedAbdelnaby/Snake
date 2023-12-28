#pragma once
#include "Position.h"
class SnakeBody
{
public:
	SnakeBody();
	SnakeBody(int x, int y);
	~SnakeBody();

public:
	Position pos;
};

SnakeBody::SnakeBody() {}
SnakeBody::SnakeBody(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

SnakeBody::~SnakeBody() = default;