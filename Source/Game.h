#pragma once
#include "Apple.h"
#include "screen.h"
#include "TheSnake.h"
#include "Score.h"

class Game
{
	apple m_apple;
	snake m_snake;
	score m_score;
	Screen &m_screen;

	bool GameOn;

	void CheckCollisionApple(Screen &p_screen);
	void CheckCollisionBody();
	void CheckCollisionScreen(Screen &p_screen);
public:
	Game(Screen &p_screen);
	~Game();
	void ProcessInput(Screen &p_screen);
	void Update(Screen &p_screen);
	void Draw(Screen &p_screen);
};