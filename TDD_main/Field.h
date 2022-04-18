#pragma once
#include <vector>
#include <string>

#define INPUT_ERROR -1
#define BOUNDARY_ERROR -2
#define COLLISION_ERROR -3
#define PADDING 1 //for row and column numbers & letters

class Field
{
public:
	int size;
	std::vector<std::string> field;

	Field(int new_size);
	void fill_default();
	int place_ship(int length, int direction, int row, int column);
	int shoot(int row, int column);
};

