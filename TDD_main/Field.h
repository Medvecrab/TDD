#pragma once
#include <vector>
#include <string>

class Field
{
public:
	int size;
	const int PADDING = 1; //будет применяться для адрессации элемнтов массива (в массиве будут храниться так же названия колонок и строк)
	std::vector<std::string> field;
	
	void fill_default();
	Field(int);
	Field();
};

