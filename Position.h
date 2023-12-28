#pragma once
struct Position
{
	Position() {}
	Position(int X, int Y)
	{
		x = X;
		y = Y;
	}
	int x = 0;
	int y = 0;

	inline bool operator==(Position pos) {
		if (x == pos.x && y == pos.y)
		{
			return true;
		}
		else
			return false;
	}
};

class Dir
{
public:
	static Position Up();
	static Position Down();
	static Position Right();
	static Position Left();

	Dir() = delete;
};

Position Dir::Up()
{
	return Position(0, -1);
}

Position Dir::Down()
{
	return Position(0 , 1);
}

Position Dir::Right()
{
	return Position(1, 0);
}

Position Dir::Left()
{
	return Position(-1, 0);
}