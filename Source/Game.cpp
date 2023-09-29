#include "Game.h"
#include <iostream>


Game::Game()
{
	GameOn = true;
}

void Game::CheckCollisionApple()
{
	if (m_snake.GetX() == m_apple.GetX() && m_snake.GetX() < m_apple.GetX() + m_apple.GetScale() && m_snake.GetY() == m_apple.GetY() && m_snake.GetY() < m_apple.GetY() + m_apple.GetScale())
	{
		m_snake.AddTail();
		m_apple.Update();
		for (int i = 0; i < m_snake.Tail.size(); i++)
		{
			if (m_apple.GetX() == m_snake.Tail[i].GetPrevX() && m_apple.GetY() == m_snake.Tail[i].GetPrevY() && m_apple.GetX() == m_snake.GetSnakePrevX() && m_apple.GetY() == m_snake.GetSnakePrevY())
			{
				m_apple.Update();
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

void Game::CheckCollisionScreen()
{
	if (m_snake.GetX() < 0 || m_snake.GetX() > GetScreenWidth() || m_snake.GetY() < 0 || m_snake.GetY() > GetScreenHeight())
	{
		GameOn = false;
	}
}

void Game::ProcessInput()
{
	if (GameOn == true)
	{
		m_snake.Input();
	}
}

void Game::Update()
{
	if (GameOn == true)
	{
		m_snake.Update();
		CheckCollisionScreen();
		CheckCollisionApple();
		CheckCollisionBody();
	}
}

void Game::Draw()
{
	if (GameOn == true)
	{
		m_snake.Draw();
		m_apple.Draw();
		m_score.Draw();
	}
}