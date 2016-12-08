//#ifndef FIELD_H
//#define FIELD_H
#pragma once
#include <vector>

class Field
{
public:
	Field(int xsize, int ysize);
	~Field();

	void draw(int xpos, int ypos, char l);
	void display();
	void clear();

	int getXSize() const;
	int getYSize() const;

private:
	std::vector < std::vector<char> >matrix;

	int xSize;
	int ySize;

};

//#endif
