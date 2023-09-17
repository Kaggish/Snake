#include "Score.h"
#include "screen.h"
#include <iostream>
#include <string>

score::score(Screen &p_screen)
{
	x = p_screen.GetWindowWidth() / 2 - 90;
	y = 0;
	Score = 0;
	color = { 255, 255, 255, 255 };
}

score::~score()
{

}

int score::GetScore()
{
	return Score;
}

void score::DrawText(Screen &p_screen)
{
	p_screen.DrawText(x, y, color, "Score: " + std::to_string(GetScore()));
}

void score::AddScore()
{
	Score++;
}

void score::Update()
{
	AddScore();
}

void score::Draw(Screen &p_screen)
{
	DrawText(p_screen);
}