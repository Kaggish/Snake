#include <iostream>
#include "TheSnake.h"

snake::snake()
	:Position{(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2}
	,scale(50)
	,SPEED(5)
	,Xdir(0)
	,Ydir(1)
	,PreviousPosition{ 1.0f, 1.0f }
	,color{0, 255, 0, 255}
{
}

float snake::GetX()
{
	return Position.x;
}

float snake::GetY()
{
	return Position.y;
}

float snake::GetSnakePrevX()
{
	return PreviousPosition.x;
}

float snake::GetSnakePrevY()
{
	return PreviousPosition.y;
}

void snake::SetX(float p_positionX)
{
	Position.x = p_positionX;
}

void snake::SetY(float p_positionY)
{
	Position.y = p_positionY;
}

void snake::DrawSnake()
{
	DrawRectangle((int)Position.x, (int)Position.y, scale, scale, color);
	for (int i = 0; i < Tail.size(); i++)
	{
		Tail[i].Draw();
	}
}

void snake::AddTail()
{
	Tail.push_back(tail(PreviousPosition));
}


void snake::Input()
{
	if (IsKeyDown(KeyboardKey::KEY_A) && Xdir != 1)
	{
		Xdir = -1;
		Ydir = 0;
	}
	else if (IsKeyDown(KeyboardKey::KEY_D) && Xdir != -1)
	{
		Xdir = 1;
		Ydir = 0;
	}
	else if (IsKeyDown(KeyboardKey::KEY_W) && Ydir != 1)
	{
		Ydir = -1;
		Xdir = 0;
	}
	else if (IsKeyDown(KeyboardKey::KEY_S) && Ydir != -1)
	{
		Ydir = 1;
		Xdir = 0;
	}
}

void snake::Movement()
{
	PreviousPosition = Position;
	if (Tail.size() > 0)
	{
		Tail[0].SetX(PreviousPosition.x);
		Tail[0].SetY(PreviousPosition.y);
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
	SetX(Position.x + (scale * Xdir));
	SetY(Position.y + (scale * Ydir));
}

void snake::Update()
{
	Movement();
}

void snake::Draw()
{
	DrawSnake();
}