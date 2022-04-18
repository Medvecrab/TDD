#pragma once
#include <vector>
#include <string>

#define INPUT_ERROR -1
#define BOUNDARY_ERROR -2
#define COLLISION_ERROR -3

class Field
{
public:
	int size;
	const int PADDING = 1; //����� ����������� ��� ���������� �������� ������� (� ������� ����� ��������� ��� �� �������� ������� � �����)
	std::vector<std::string> field;

	Field(int new_size);
	void fill_default();
	int place_ship(int length, int direction, int row, int column);
	int shoot(int row, int column);
};

