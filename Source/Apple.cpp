#include "Apple.h"
#include "screen.h"
#include <iostream>


apple::apple(Screen &p_screen)
{
	x = 100;
	y = 100;
	scale = 50;
	color = { 255, 0, 0, 255 };
}

apple::~apple()
{

}

int apple::GetX()
{
	return x;
}

int apple::GetY()
{
	return y;
}

int apple::GetScale()
{
	return scale;
}


void apple::SetPosition(Screen& p_screen)
{
	x = (rand() % 20) * 50;
	y = (rand() % 20) * 50;
}

void apple::DrawApple(Screen& p_screen)
{
	p_screen.DrawRectangle(x, y, scale, scale, color);
}

void apple::Update(Screen &p_screen)
{
	SetPosition(p_screen);
}

void apple::Draw(Screen& p_screen)
{
	DrawApple(p_screen);
}