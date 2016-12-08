#ifndef BACKGROUND_H
#define BACKGROUND_H

#include"Object.h"
#include"Field.h"


class Background : public Object
{
public:
	//Block(int xpos, int ypos);
	Background(int xpos, int ypos, char _line);
	~Background();

	void update();


private:


};

#endif
