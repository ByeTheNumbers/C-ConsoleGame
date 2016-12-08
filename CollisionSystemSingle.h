//#ifndef COLLISIONSYSTEMSINGLE_H
//#define COLLISIONSYSTEMSINGLE_H
#pragma once

#include "Player.h"
#include "Block.h"

class CollisionSystemSingle
{
public:
	//CollisionSystem(Player *player, Block *block, int xsize, int ysize);
	CollisionSystemSingle(Player *player, Block *block1, Block *block2, int xsize, int ysize);
	~CollisionSystemSingle();

	void update(Movement::direction d);
private:
	Player *mPlayer;
	//Block *mBlock;
	Block *mBlock1;
	Block *mBlock2;

	int xSize;
	int ySize;
};

//#endif