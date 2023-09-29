#include "Score.h"
#include <iostream>

score::score()
	:Position{(float)GetScreenWidth() / 2 - 70.0f, 0.0f}
	,Score(0)
	,color{255, 255, 255, 255}
{
}

int score::GetScore()
{
	return Score;
}

void score::WriteText()
{
	DrawText(TextFormat("Score: %d", Score), (int)Position.x, (int)Position.y, 20, color);
}

void score::AddScore()
{
	Score++;
}

void score::Update()
{
	AddScore();
}

void score::Draw()
{
	WriteText();
}