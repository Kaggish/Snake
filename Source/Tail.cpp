#include "Tail.h"

tail::tail(Vector2 p_position)
	:Position(p_position)
	,PreviousPosition({1.0f, 1.0f})
	,scale(50)
	,color({0, 255, 0, 255})
{
}

float tail::GetPrevX()
{
	return PreviousPosition.x;
}

float tail::GetPrevY()
{
	return PreviousPosition.y;
}

void tail::SetX(float p_positionX)
{
	Position.x = p_positionX;
}

void tail::SetY(float p_positionY)
{
	Position.y = p_positionY;
}

void tail::DrawTail()
{
	DrawRectangle((int)Position.x, (int)Position.y, scale, scale, color);
}

void tail::Update()
{
	PreviousPosition = Position;
}

void tail::Draw()
{
	DrawTail();
}