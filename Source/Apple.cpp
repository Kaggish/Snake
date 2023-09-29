#include "Apple.h"
#include <iostream>


apple::apple()
	:Position({ 100.0f, 100.0f })
	,scale(50)
	,color{255, 0, 0, 255}
{
}

float apple::GetX()
{
	return Position.x;
}

float apple::GetY()
{
	return Position.y;
}

int apple::GetScale()
{
	return scale;
}


void apple::SetPosition()
{
	Position.x = static_cast <float> ((rand() % 10) * 50);
	Position.y = static_cast <float> ((rand() % 10) * 50);
}

void apple::DrawApple()
{
	DrawRectangle((int)Position.x, (int)Position.y, scale, scale, color);
}

void apple::Update()
{
	SetPosition();
}

void apple::Draw()
{
	DrawApple();
}