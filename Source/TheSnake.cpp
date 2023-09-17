#include <iostream>
#include "TheSnake.h"
#include "screen.h"

snake::snake(Screen &p_screen)
{
	x = p_screen.GetWindowWidth() / 2;
	y = p_screen.GetWindowHeight() / 2;
	scale = 50;
	color = { 0, 255, 0, 255 };
	speed = 5;
	Xdir = 1;
	Ydir = 0;
	snakeprevX = 1;
	snakeprevY = 1;
}

snake::~snake()
{

}

int snake::GetX()
{
	return x;
}

int snake::GetSnakePrevX()
{
	return snakeprevX;
}

int snake::GetSnakePrevY()
{
	return snakeprevY;
}

int snake::GetY()
{
	return y;
}

void snake::SetX(int p_x)
{
	x = p_x;
}

void snake::SetY(int p_y)
{
	y = p_y;
}

void snake::DrawSnake(Screen& p_screen)
{
	p_screen.DrawRectangle(x, y, scale, scale, color);
	for (int i = 0; i < Tail.size(); i++)
	{
		Tail[i].Draw(p_screen);
	}
}

void snake::AddTail(Screen& p_screen)
{
	Tail.push_back(tail(p_screen, snakeprevX, snakeprevY));
}


void snake::Input(Screen &p_screen)
{
	if (p_screen.IsKeyDown(Key::Left) && Xdir != 1)
	{
		Xdir = -1;
		Ydir = 0;
	}
	else if (p_screen.IsKeyDown(Key::Right) && Xdir != -1)
	{
		Xdir = 1;
		Ydir = 0;
	}
	else if (p_screen.IsKeyDown(Key::Up) && Ydir != 1)
	{
		Ydir = -1;
		Xdir = 0;
	}
	else if (p_screen.IsKeyDown(Key::Down) && Ydir != -1)
	{
		Ydir = 1;
		Xdir = 0;
	}
}

void snake::Movement()
{
	snakeprevX = x;
	snakeprevY = y;
	if (Tail.size() > 0)
	{
		Tail[0].SetX(snakeprevX);
		Tail[0].SetY(snakeprevY);
		if (Tail.size() > 1)
		{
			for (int i = 1; i < Tail.size(); i++)
			{
				Tail[i].SetX(Tail[(long long)i - 1].GetPrevX());
				Tail[i].SetY(Tail[(long long)i - 1].GetPrevY());
			}
		}
	}
	for (int i = 0; i < Tail.size(); i++)
	{
		Tail[i].Update();
	}
	SetX(x + (scale * Xdir));
	SetY(y + (scale * Ydir));
}

void snake::Update()
{
	Movement();
}

void snake::Draw(Screen& p_screen)
{
	DrawSnake(p_screen);
}