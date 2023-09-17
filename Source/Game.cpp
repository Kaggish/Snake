#include "Game.h"
#include "screen.h"
#include <iostream>


Game::Game(Screen& p_screen) : m_screen(p_screen), m_snake(p_screen), m_apple(p_screen), m_score(p_screen)
{
	GameOn = true;
}

Game::~Game()
{

}

void Game::CheckCollisionApple(Screen &p_screen)
{
	if (m_snake.GetX() == m_apple.GetX() && m_snake.GetX() < m_apple.GetX() + m_apple.GetScale() && m_snake.GetY() == m_apple.GetY() && m_snake.GetY() < m_apple.GetY() + m_apple.GetScale())
	{
		m_snake.AddTail(p_screen);
		m_apple.Update(p_screen);
		for (int i = 0; i < m_snake.Tail.size(); i++)
		{
			if (m_apple.GetX() == m_snake.Tail[i].GetPrevX() && m_apple.GetY() == m_snake.Tail[i].GetPrevY() && m_apple.GetX() == m_snake.GetSnakePrevX() && m_apple.GetY() == m_snake.GetSnakePrevY())
			{
				m_apple.Update(p_screen);
			}
		}
		m_score.Update();
	}
}

void Game::CheckCollisionBody()
{
	for (int i = 0; i < m_snake.Tail.size(); i++)
	{
		if (m_snake.GetX() == m_snake.Tail[i].GetPrevX() && m_snake.GetY() == m_snake.Tail[i].GetPrevY())
		{
			GameOn = false;
		}
	}
}

void Game::CheckCollisionScreen(Screen& p_screen)
{
	if (m_snake.GetX() < 0 || m_snake.GetX() > p_screen.GetWindowWidth() || m_snake.GetY() < 0 || m_snake.GetY() > p_screen.GetWindowHeight())
	{
		GameOn = false;
	}
}

void Game::ProcessInput(Screen &p_screen)
{
	if (GameOn == true)
	{
		m_snake.Input(p_screen);
	}
}

void Game::Update(Screen &p_screen)
{
	if (GameOn == true)
	{
		m_snake.Update();
		CheckCollisionScreen(p_screen);
		CheckCollisionApple(p_screen);
		CheckCollisionBody();
	}
}

void Game::Draw(Screen &p_screen)
{
	if (GameOn == true)
	{
		m_snake.Draw(p_screen);
		m_apple.Draw(p_screen);
		m_score.Draw(p_screen);
	}
}