#pragma once
//#ifndef COLLISIONSYSTEM_H
//#define COLLISIONSYSTEM_H

#include "Player.h"
#include "Block.h"

class CollisionSystemDouble
{
public:
	//CollisionSystem(Player *player, Block *block, int xsize, int ysize);
	CollisionSystemDouble(Player *player1, Player *player2, Block *block1, Block *block2, int xsize, int ysize);
	~CollisionSystemDouble();

	void update(Movement::direction d);
private:
	Player *mPlayer1;
	Player *mPlayer2;
	//Block *mBlock;
	Block *mBlock1;
	Block *mBlock2;

	int xSize;
	int ySize;
};

//#endif