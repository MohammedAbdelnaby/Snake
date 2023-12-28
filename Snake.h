#pragma once
#include "Position.h"
#include <vector>
#include "SnakeBody.h"

class Snake
{
private:
	Position Direction;

public:
	Snake(int x, int y);
	~Snake();
	void SetDirection(Position dir);
	Position GetDirection();
	void Eat(int value);
	bool MoveBody();

public:
	Position pos;
	std::vector<SnakeBody> body;

};

Snake::Snake(int x, int y)
{
	pos.x = x;
	pos.y = y;
	Direction = Dir::Right();
	Eat(2);
}

Snake::~Snake() = default;

void Snake::SetDirection(Position dir)
{
	Direction = dir;
}

Position Snake::GetDirection()
{
	return Direction;
}

void Snake::Eat(int value)
{
	for (int i = 0; i < value; i++)
	{
		SnakeBody tempBody;
		body.push_back(tempBody);

	}
}

bool Snake::MoveBody()
{
	Position PrevPos = pos;
	for (int i = 0; i < body.size(); i++)
	{
		Position temp = body[i].pos;
		body[i].pos = PrevPos;
		PrevPos = temp;
	}

	return true;
}
