#include "includes.h"
/// James Bartulis - my code : /
using namespace std;

int main()
{
	Tetris *game = new Tetris();

	while(game->isRunning())
	{
		game->Display();
		game->Input();
		if(game->getFrame() % 5 == 0)
			game->Logic();
		Sleep(50);
	}
}