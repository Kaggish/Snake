#pragma once
#include "screen.h"

class score
{
	int x, y, Score;
	Color color;

	void AddScore();
	void DrawText(Screen &p_screen);
public:
	score(Screen &p_screen);
	~score();
	void Update();
	void Draw(Screen& p_screen);
	int GetScore();
};