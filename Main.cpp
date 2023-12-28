#include <iostream>
#include <vector>
#include "Game.h"
#include<windows.h>
#include <conio.h>
#include <cstdlib>
using namespace std;
char Grid[GRID_Y_MAX][GRID_X_MAX];

void Draw(Game& game);

void Render(char (&Grid)[GRID_Y_MAX][GRID_X_MAX]);

void Input(Game& game);

void Update(Game& game);

void CollisionChecks(Game& game);

void main()
{
	Game game;
	while (true)
	{
		Sleep(250);
		CollisionChecks(game);
		Update(game);
		Draw(game);
	}
}

void Draw(Game& game)
{
	for (int y = 0; y < GRID_Y_MAX; y++)
	{
		for (int x = 0; x < GRID_X_MAX; x++)
		{
			if ((y == GRID_Y_MAX - 1) || (y == 0) ||
				(x == GRID_X_MAX - 1) || (x == 0))
				Grid[y][x] = '#';
			else if (game.m_Apple->pos.x == x && game.m_Apple->pos.y == y)
				Grid[y][x] = 'a';
			else if (game.m_Player->pos.x == x && game.m_Player->pos.y == y)
				Grid[y][x] = 'o';
			else
			{
				Grid[y][x] = ' ';
			}
		}
	}

	for (int i = 0; i < game.m_Player->body.size(); i++)
	{
		Grid[game.m_Player->body[i].pos.y][game.m_Player->body[i].pos.x] = '+';
	}
	Render(Grid);
	cout << "PLayer Pos: (" << game.m_Player->pos.x << " ," << game.m_Player->pos.y << ")" << endl;
	cout << "Apple Pos: (" << game.m_Apple->pos.x << " ," << game.m_Apple->pos.y << ")" << endl;
}

void Render(char (&Grid)[GRID_Y_MAX][GRID_X_MAX])
{
	system("CLS");
	for (auto& row : Grid)
	{
		for (auto& col : row)
		{
			cout << col;
		}
		cout << endl;
	}
}

void Input(Game& game)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			if(!(game.m_Player->GetDirection() == Dir::Down()))
				game.m_Player->SetDirection(Dir::Up());
			break;
		case 's':
			if (!(game.m_Player->GetDirection() == Dir::Up()))
				game.m_Player->SetDirection(Dir::Down());
			break;
		case 'a':
			if (!(game.m_Player->GetDirection() == Dir::Right()))
				game.m_Player->SetDirection(Dir::Left());
			break;
		case 'd':
			if (!(game.m_Player->GetDirection() == Dir::Left()))
				game.m_Player->SetDirection(Dir::Right());
			break;

		default:
			break;
		}
	}
}

void Update(Game& game)
{
	Input(game);
	if (game.m_Player->MoveBody())
	{
		game.m_Player->pos.x += game.m_Player->GetDirection().x;
		game.m_Player->pos.y += game.m_Player->GetDirection().y;
	}
}

void CollisionChecks(Game& game)
{
	if (game.m_Player->pos.x >= GRID_X_MAX)
	{
		game.m_Player->pos.x = 1;
	}
	if (game.m_Player->pos.x <= 0)
	{
		game.m_Player->pos.x = GRID_X_MAX - 1;
	}
	if (game.m_Player->pos.y >= GRID_Y_MAX)
	{
		game.m_Player->pos.y = 1;
	}
	if (game.m_Player->pos.y <= 0)
	{
		game.m_Player->pos.y = GRID_Y_MAX - 1;
	}
	if (game.m_Player->pos.x == game.m_Apple->pos.x && game.m_Player->pos.y == game.m_Apple->pos.y)
	{
		game.m_Player->Eat(1);
		game.m_Apple->pos.x = rand() % (GRID_X_MAX - 2) + 1;
		game.m_Apple->pos.y = rand() % (GRID_Y_MAX - 2) + 1;
	}
}
