#include "Object.h"

Object::Object(int xpos, int ypos) : xPos(xpos), yPos(ypos)
{

}

Object::~Object()
{

}

void Object::draw(Field &field)
{
	field.draw(xPos, yPos, letter);
}

void Object::setXPos(int x)
{
	xPos = x;
}

void Object::setYPos(int y)
{
	yPos = y;
}

int Object::getXPos() const
{
	return xPos;
}

int Object::getYPos() const
//int Object::getYPos(Pointer in here?) const
{
	return yPos;
}

char Object::getLetter()
{
	return letter;
}

void Object::setLetter(char input_letter)
{
	letter= input_letter;
}


