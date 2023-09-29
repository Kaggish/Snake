#pragma once
#include "raylib.h"
#include <vector>

class tail
{
	Vector2 Position;
	Vector2 PreviousPosition;
	int scale;
	Color color;

	void DrawTail();
public:
	tail(Vector2 p_position);
	~tail() = default;
	void SetX(float x);
	void SetY(float y);
	float GetPrevX();
	float GetPrevY();
	void Update();
	void Draw();
};