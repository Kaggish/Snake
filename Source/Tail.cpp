#include "Tail.h"

tail::tail(Screen& p_screen, int prevX, int prevY)
{
	x = prevX;
	y = prevY;
	scale = 50;
	color = { 0, 255, 0, 255 };
	tailprevX = 1;
	tailprevY = 1;
}

tail::~tail()
{

}

int tail::GetPrevX()
{
	return tailprevX;
}

int tail::GetPrevY()
{
	return tailprevY;
}

void tail::SetX(int p_x)
{
	x = p_x;
}

void tail::SetY(int p_y)
{
	y = p_y;
}

void tail::DrawTail(Screen &p_screen)
{
	p_screen.DrawRectangle(x, y, scale, scale, color);
}

void tail::Update()
{
	tailprevX = x;
	tailprevY = y;
}

void tail::Draw(Screen &p_screen)
{
	DrawTail(p_screen);
}