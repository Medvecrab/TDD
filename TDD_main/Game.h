#pragma once
#include "Field.h"
#include <iostream>

class Game
{
public:
	Field* player_field;
	Field* bot_field;
	int main_menu();
	int play_game();
	Game();
};

