#pragma once
#include "raylib.h"
#include "Tail.h"
#include <vector>


class snake
{
	Vector2 Position;
	Vector2 PreviousPosition;
	float SPEED;
	int scale = 50;
	int Xdir, Ydir;
	Color color;

	void Movement();
	void DrawSnake();
public:
	std::vector<tail> Tail;
	snake();
	~snake() = default;
	void AddTail();
	void Input();
	void Draw();
	void Update();
	void SetX(float p_positionX);
	void SetY(float p_positionY);
	float GetX();
	float GetY();
	float GetSnakePrevX();
	float GetSnakePrevY();
};