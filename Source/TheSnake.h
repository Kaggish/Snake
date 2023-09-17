#pragma once
#include "screen.h"
#include "Tail.h"
#include <vector>


class snake
{
	int x, y, scale, speed, Xdir, Ydir;
	Color color;
	int snakeprevX, snakeprevY;

	void Movement();
	void DrawSnake(Screen& p_screen);
public:
	std::vector<tail> Tail;
	snake(Screen &p_screen);
	~snake();
	void AddTail(Screen &p_screen);
	void Input(Screen& p_screen);
	void Draw(Screen& p_screen);
	void Update();
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
	int GetSnakePrevX();
	int GetSnakePrevY();
};