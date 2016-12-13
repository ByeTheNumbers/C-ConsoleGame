#include "ListCollision.h"


ListCollision::ListCollision(Player *player1, Player *player2, List Line, int xsize, int ysize)
{

	mPlayer1 = player1;
	mPlayer2 = player2;
	List mLine = Line;
	//mLine.print();
	xSize = xsize;
	ySize = ysize;
}

ListCollision::~ListCollision()
{

}

void ListCollision::update(Movement::direction d)
{
	switch (d)

		/*
		CONCEPT 1
		# We want 2 players and 6 blocks.
		# Each player can push his 3 blocks.
		# The players pass through the other players boxes.
		# The players and boxes are returned to their initial state if they try to push one of 
		  their boxes on top of one their opponents boxes. 
		  (So it looks like they cant push their blocks past an opponents block)
		  OR the movement commands arent executed until its verified no opponent boxes in the way.

		IDEA 1
		# Blocks in Linked List. [Letter, XPOS, YPOS]
		# Go through Linked List each time player moves to check if new position
		  is the same as his own boxes position
		# If there is one the same check 1 further down that row/coloum for another block
		# if all blocks to be pushed are players own blocks, move them.
		# if there is a block that is not the players, push the player and affected boxes back one.

		CONCEPT 2
		# We want 2 players and 6 blocks.
		# Each player can push all 6 blocks.
		# If there is one the same check 1 further down that row/coloum for another block
		# If a block moves into the other player, add one to its movement.

		IDEA 2
		# Blocks in Linked List. [Letter, XPOS, YPOS]
		# Go through Linked List each time player moves to check if new position
		is the same as any boxes position
		# If a block moves into the other player, add one to its movement.

		*/
		//THREE BLOCKS THAT PUSH EACH OTHER
	{

		//**********************UP************************UP********************************************
	case Movement::Up:

		//WRAP AROUND MAP FOR PLAYER 1
		if (mPlayer1->getYPos() < 0)
		{
			mPlayer1->setYPos(ySize);
		}

		//WRAP AROUND MAP FOR PLAYER 2
		if (mPlayer2->getYPos() < 0)
		{
			mPlayer2->setYPos(ySize);
		}

		//IF PLAYER1 L XPOS YPOS == BLOCK (1) XPOS YPOS

		//   IF PLAYER1 L XPOS YPOS-- == BLOCK (1) XPOS YPOS

		//**************************DOWN*************************************************************
	case Movement::Down:

		//WRAP AROUND PLAYER 1
		if (mPlayer1->getYPos() > ySize)
		{
			mPlayer1->setYPos(0);
		}

		//WRAP AROUND PLAYER 2
		if (mPlayer2->getYPos() > ySize)
		{
			mPlayer2->setYPos(0);
		}
		//****************************************LEFT**********************************************
	case Movement::Left:

		//WRAP AROUND PLAYER 1
		if (mPlayer1->getXPos() < 0)
		{
			mPlayer1->setXPos(xSize);
		}

		//WRAP AROUND PLAYER 2
		if (mPlayer2->getXPos() < 0)
		{
			mPlayer2->setXPos(xSize);
		}

		//*********************************RIGHT**********************************************************
	case Movement::Right:
		
		//WRAP AROUND PLAYER 1
		if (mPlayer1->getXPos() > xSize)
		{
			mPlayer1->setXPos(0);
		}

		//WRAP AROUND PLAYER 2
		if (mPlayer2->getXPos() > xSize)
		{
			mPlayer2->setXPos(0);
		}

	}
}
