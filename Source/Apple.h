#pragma once
#include "raylib.h"

class apple
{
	Vector2 Position;
	int scale;
	Color color;

	void DrawApple();
	void SetPosition();
public:
	apple();
	~apple() = default;
	void Update();
	void Draw();
	float GetX();
	float GetY();
	int GetScale();
};