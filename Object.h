#ifndef OBJECT_H
#define OBJECT_H

#include "Field.h"
//#include "Background.h"

namespace Movement
{
	enum direction 
	{
		Up, Down, Left, Right, Stay_Still
	};
}

class Object
{
public:
	Object(int xpos, int ypos);
	~Object();

	void draw(Field &field);

	void setXPos(int x);
	void setYPos(int y);

	int getXPos() const;
	int getYPos() const;

	char getLetter();
	void setLetter(char input_letter);

	//char letter;
	//char getLetter() { return letter; }
	//void setLetter(const Player& letter) { initial = letter; }


protected:
	int xPos;
	int yPos;
	char letter;

};

#endif