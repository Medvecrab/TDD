#include "Game.h"
#define DEBUG 1


int Game::main_menu()
{
	bool t = true;
	int ship_count = -1;
	int ships_set = 0;
	int size = 10;
	player_field = new Field(size);
	bot_field = new Field(size);
	while (t)
	{
		system("cls");
		std::cout << "Press 1 to enter amount of your ships (the bot gets the same amount as you)\n";
		std::cout << "Press 2 to set your ships (the bot will do it automatically)\n";
		std::cout << "Press 3 to start the game\n";
		int input;
		std::cin >> input;
		switch (input)
		{
		case 1:
			std::cout << "Enter amount of ships (from 1 to 10)\n";
			std::cin >> ship_count;
			if (ship_count < 1)	ship_count = 1;
			if (ship_count > 10) ship_count = 10;
			break;
		case 2:
			ships_set = 1;
			if (ship_count == -1)
			{
				std::cout << "No ships! Exiting...";
				return -1;
			}
			for (int i = ship_count; i > 0; i--)
			{
				std::cout << i << " ships left\n";
				std::cout << "Enter size of your ship (from 1 to 4), then the direction (1 = up, 2 = right, 3 = down, 4 = left)" 
					<< ",\nthen row and column of first square of your ship (1 to 10)\n";
				int ship_length, direction, row, column;
				std::cin >> ship_length;
				std::cin >> direction;
				std::cin >> row;
				std::cin >> column;
				int error = player_field->place_ship(ship_length, direction, row - 1, column - 1);
				if (error)
				{
					std::cout << "Error when placing ship! Exiting...";
					return -1;
				}
				//ship placement for bot
				error = 0;
				do
				{
					ship_length = rand() % 4 + 1;
					direction = rand() % 4 + 1;
					row = rand() % 10;
					column = rand() % 10;
					error = bot_field->place_ship(ship_length, direction, row - 1, column - 1);
				} while (error);
			}
			break;
		case 3:
			if (!ships_set)
			{
				std::cout << "No ships! Exiting...";
				return -1;
			}
			t = play_game();
			break;
		default:
			break;
		}
	}
}

int Game::play_game()
{
	bool player_win = false;
	bool bot_win = false;
	do 
	{
		int player_hit = 0;
		int bot_hit = 0;
		int row, column;
		do
		{
			system("cls");
			player_field->print_field();
			#ifdef DEBUG
			bot_field->print_field();
			#endif
			#ifndef DEBUG
			bot_field->print_enemy_field();
			#endif
			std::cout << "Enter row and column to hit\n";
			std::cin >> row;
			std::cin >> column;
			player_hit = bot_field->shoot(row, column);
			if (player_hit == -1)
				return 0;
			player_win = bot_field->check_win();
		} while (player_hit && !player_win);
		do
		{
			row = rand() % 10;
			column = rand() % 10;
			bot_hit = player_field->shoot(row, column);
			bot_win = player_field->check_win();
		} while (bot_hit && !bot_win);
	} while (!player_win && !bot_win);
	if (player_win)
	{
		std::cout << "You win! Congratulations!\n";
		int input = 0;
		std::cout << "If you want to go to main menu and play again, input 1, else if you want to exit press 0\n";
		std::cin >> input;
		return input;
	}
	if (bot_win)
	{
		std::cout << "You lose. Better luck next time.";
		return 0;
	}
}

Game::Game()
{
}
