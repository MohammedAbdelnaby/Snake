#pragma once
#include "Apple.h"
#include "Position.h"
#include "Snake.h"

#define GRID_X_MAX 32
#define GRID_Y_MAX 16

class Game
{
public:
	Game();
	~Game();

public:
	Apple* m_Apple = new Apple(5, 5);
	Snake* m_Player = new Snake((int)(GRID_X_MAX/2), (int)(GRID_Y_MAX / 2));

	
};

Game::Game()
{
}

Game::~Game() = default;