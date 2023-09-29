#pragma once
#include "Apple.h"
#include "raylib.h"
#include "TheSnake.h"
#include "Score.h"

class Game
{
	apple m_apple;
	snake m_snake;
	score m_score;

	bool GameOn;

	void CheckCollisionApple();
	void CheckCollisionBody();
	void CheckCollisionScreen();
public:
	Game();
	~Game() = default;
	void ProcessInput();
	void Update();
	void Draw();
};