#include <iostream>
#include "Field.h"
#include "Game.h";

int main()
{
	srand(time(0));
	Game* game = new Game();
	game->main_menu();
}
