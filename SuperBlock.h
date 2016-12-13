#pragma once

#include "Player.h"
#include"Object.h"
#include "Block.h"

class SuperBlock : public Object
{
public:
	//Block(int xpos, int ypos);
	SuperBlock(int xpos, int ypos, char _letter, Player *player, SuperBlock *block, int xsize, int ysize);
	~SuperBlock();

	void update();
	void update(Movement::direction d);

	void setCollisions(int c);
	int getCollisions() const;

private:
	int collisions;

	Player *mPlayer;
	SuperBlock *mBlock;

	int xSize;
	int ySize;
};

