#pragma once
//#ifndef COLLISIONSYSTEM_H
//#define COLLISIONSYSTEM_H

#include "Player.h"
#include "Block.h"
#include "List.h"

class CollisionSystemDouble
{
public:
	//CollisionSystem(Player *player, Block *block, int xsize, int ysize);
	CollisionSystemDouble(Player *player1, Player *player2, Block *block1, Block *block2, Block *block3, Block *block4, Block *block5, Block *block6, int xsize, int ysize);
	//CollisionSystemDouble(Player *player1, Player *player2, List Line, int xsize, int ysize);
	~CollisionSystemDouble();

	void update(Movement::direction d);
private:
	Player *mPlayer1;
	Player *mPlayer2;
	//Block *mBlock;
	
	/*
	Node *mBlock1;
	Node *mBlock2;
	Node *mBlock3;

	Node *mBlock4;
	Node *mBlock5;
	Node *mBlock6;
	*/


	Block *mBlock1;
	Block *mBlock2;
	Block *mBlock3;

	Block *mBlock4;
	Block *mBlock5;
	Block *mBlock6;
	
	int xSize;
	int ySize;
};

//#endif