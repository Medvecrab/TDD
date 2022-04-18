#include <iostream>
#include "Field.h"

int main()
{
	int size = 10;
	Field* player_field = new Field(size);
	player_field->place_ship(4, 3, 0, 0);
	player_field->place_ship(1, 1, 8, 8);
	player_field->place_ship(2, 4, 7, 8);
	player_field->place_ship(3, 3, 0, 1);
	player_field->place_ship(4, 2, 3, 5);
	int first = player_field->shoot(0, 0); //hit
	int second = player_field->shoot(5, 5); //miss
	player_field->print_field();
	player_field->print_enemy_field();
}
