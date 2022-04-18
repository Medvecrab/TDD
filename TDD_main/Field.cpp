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
