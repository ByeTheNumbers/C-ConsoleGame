//#ifndef COLLISIONSYSTEMSINGLE_H
//#define COLLISIONSYSTEMSINGLE_H
#pragma once

#include "Player.h"
#include "Block.h"
#include "List.h"

 

class CollisionSystemSingle
{
public:
	//CollisionSystem(Player *player, Block *block, int xsize, int ysize);
	CollisionSystemSingle(Player *player, Block *block1, Block *block2, Block *block3, int xsize, int ysize);
	~CollisionSystemSingle();

	void update(Movement::direction d);

	//List getLine();
	

private:

	List Line;
	Player *mPlayer;
	//Block *mBlock;
	Block *mBlock1;
	Block *mBlock2;
	Block *mBlock3;
//	Block *mBlock4;
//	Block *mBlock5;
//	Block *mBlock6;
//	Block *mBlock7;
//	Block *mBlock8;

	int xSize;
	int ySize;
};


//#endif