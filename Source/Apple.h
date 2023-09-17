#pragma once
#include "screen.h"

class apple
{
	int x, y, scale;
	Color color;

	void DrawApple(Screen& p_screen);
	void SetPosition(Screen& p_screen);
public:
	apple(Screen& p_screen);
	~apple();
	void Update(Screen &p_screen);
	void Draw(Screen& p_screen);
	int GetX();
	int GetY();
	int GetScale();
};