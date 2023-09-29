#pragma once
#include "raylib.h"
#include <string>
#include <cstring>

class score
{
	Vector2 Position;
	int Score;
	Color color;

	void AddScore();
	void WriteText();
public:
	score();
	~score() = default;
	void Update();
	void Draw();
	int GetScore();
};