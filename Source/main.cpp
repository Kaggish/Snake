//Jakub Orlowski Date: 2021-12-12//
#include "Screen.h"
#include "Game.h"

int screenWidth = 1000;
int screenHeight = 1000;

int main(int argc, char** argv)
{
	int seconds = 0;

	Screen screen(screenWidth, screenHeight, "Galba");
	Game game(screen);
 	while (screen.IsOpen())
	{
		seconds++;

		screen.Clear();

		game.ProcessInput(screen);
		if (seconds == 15)
		{
			game.Update(screen);
			seconds = 0;
		}
		game.Draw(screen);

		screen.Display();
	}
	return 0;
}