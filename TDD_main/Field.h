#pragma once
#include <vector>
#include <string>

class Field
{
public:
	int size;
	const int PADDING = 1; //����� ����������� ��� ���������� �������� ������� (� ������� ����� ��������� ��� �� �������� ������� � �����)
	std::vector<std::string> field;
	
	void fill_default();
	Field(int);
	Field();
};

