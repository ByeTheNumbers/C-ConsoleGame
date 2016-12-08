#include "Field.h"
#include <iostream>

Field::Field(int xsize, int ysize) : xSize(xsize), ySize(ysize)
{
	for (int x = 0; x < xSize; ++x)
	{
		std::vector<char> column;
		for (int y = 0; y < ySize; ++y)
		{
			column.push_back(' ');
		}

		matrix.push_back(column);
	}

}

Field::~Field()
{

}

void Field::draw(int xpos, int ypos, char l)
{
	matrix.at(xpos).at(ypos) = l;
}

void Field::display()
{
	for (int y = 0; y < ySize; ++y)
	{
		for (int x = 0; x < xSize; ++x)
		{
			std::cout << matrix.at(x).at(y);
		}
		std::cout << '\n';
	}
}

void Field::clear()
{
	for (int y = 0; y < ySize; ++y)
	{
		for (int x = 0; x < xSize; ++x)
		{
			matrix.at(x).at(y) = ' ';
		}
	}
}

int Field::getXSize()const
{
	return xSize - 1;
}

int Field::getYSize()const
{
	return ySize - 1;
}
