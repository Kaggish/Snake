#pragma once
#include "screen.h"
#include <vector>

class tail
{
	int x, y, scale, tailprevX, tailprevY;
	Color color;

	void DrawTail(Screen& p_screen);
public:
	tail(Screen &p_screen, int prevX, int prevY);
	~tail();
	void SetX(int x);
	void SetY(int y);
	int GetPrevX();
	int GetPrevY();
	void Update();
	void Draw(Screen &p_screen);
};