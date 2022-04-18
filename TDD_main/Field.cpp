#include "Field.h"

void Field::fill_default()
{
	char current_symbol = '~'; //для пустого места
	for (int i = 0; i < size + PADDING; i++)
	{
		for (int j = 0; j < size + PADDING; j++)
		{
			if (i == 0)
				current_symbol = 'A';
			if (j == 0)
				current_symbol = '0';
			if (i == 0 && j == 0)
				current_symbol = ' ';
			//automatic symbol calculation
			field[i][j] = current_symbol + (j == 0 && i > 1 ? i - 1 : 0) + (i == 0 && j > 1 ? j - 1 : 0);
			current_symbol = '~';
		}
	}
	return;
}

int Field::place_ship(int length, int direction, int row, int column)
{
	if (row + PADDING > size || row < 0 || column + PADDING  > size || column < 0)
		return INPUT_ERROR;
	if (length > 4 || length < 1)
		return INPUT_ERROR;
	std::vector<std::string> field_copy = field;
	switch (direction)
	{
	case 1:
		if (row + PADDING - length < 1) //out of bounds
			return BOUNDARY_ERROR;
		for (int i = row + PADDING; i > row + PADDING - length; i--)
		{
			if (field[i][column + PADDING] == 'o')
			{
				field = field_copy;
				return COLLISION_ERROR;
			}
			field[i][column + PADDING] = 'o';
		}
		break;
	case 2:
		if (column + PADDING + length > size) //out of bounds
			return BOUNDARY_ERROR;
		for (int j = column + PADDING; j < column + PADDING + length; j++)
		{
			if (field[row + PADDING][j] == 'o')
			{
				field = field_copy;
				return COLLISION_ERROR;
			}
			field[row + PADDING][j] = 'o';
		}
		break;
	case 3:
		if (row + PADDING + length > size) //out of bounds
			return BOUNDARY_ERROR;
		for (int i = row + PADDING; i < row + PADDING + length; i++)
		{
			if (field[i][column + PADDING] == 'o')
			{
				field = field_copy;
				return COLLISION_ERROR;
			}
			field[i][column + PADDING] = 'o';
		}
		break;
	case 4:
		if (column + PADDING - length < 1) //out of bounds
			return BOUNDARY_ERROR;
		for (int j = column + PADDING; j > column + PADDING - length; j--)
		{
			if (field[row + PADDING][j] == 'o')
			{
				field = field_copy;
				return COLLISION_ERROR;
			}
			field[row + PADDING][j] = 'o';
		}
		break;
	default:
		return INPUT_ERROR;
	}
	return 0;
}

int Field::shoot(int row, int column)
{
	if (row + PADDING > size|| row < 0 || column + PADDING  > size || column < 0)
		return INPUT_ERROR;
	if (field[row + PADDING][column + PADDING] == 'o')
	{
		field[row + PADDING][column + PADDING] = 'x';
		return 1;
	}
	return 0;
}

Field::Field(int new_size)
{
	size = new_size;
	field = std::vector<std::string>(size + PADDING);
	for (int i = 0; i < size + PADDING; i++)
	{
		field[i] = std::string(size + PADDING, ' ');
	}
	fill_default();
}
