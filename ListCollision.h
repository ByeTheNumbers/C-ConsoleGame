#pragma once

#include "Player.h"
#include "Block.h"
#include "List.h"


//extern List Line;
class ListCollision
{
public:
	//CollisionSystem(Player *player, Block *block, int xsize, int ysize);
	ListCollision(Player *player1, Player *player2, List Line, int xsize, int ysize);
	~ListCollision();

	void update(Movement::direction d);

	//List getLine();


private:

	
	Player *mPlayer1;
	Player *mPlayer2;

	//Block *mBlock;
	Block *mBlock1;
	Block *mBlock2;
	Block *mBlock3;
	Block *mBlock4;
	Block *mBlock5;
	Block *mBlock6;
	Block *mBlock7;
	Block *mBlock8;

	int xSize;
	int ySize;
};
