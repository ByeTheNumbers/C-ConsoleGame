#include "CollisionSystemDouble.h"

//CollisionSystem::CollisionSystem(Player *player, Block *block, int xsize, int ysize)
CollisionSystemDouble::CollisionSystemDouble(Player *player1, Player *player2, Block *block1, Block *block2, Block *block3, Block *block4, Block *block5, Block *block6, int xsize, int ysize)
//CollisionSystemDouble::CollisionSystemDouble(Player *player1, Player *player2, List Line, int xsize, int ysize)
{
	mPlayer1 = player1;
	mPlayer2 = player2;

	//List mLine = Line;

	
	//mBlock = block;

	mBlock1 = block1;
	mBlock2 = block2;
	mBlock3 = block3;

	mBlock4 = block4;
	mBlock5 = block5;
	mBlock6 = block6;

	/*
	mBlock1 = mLine.getNode(Line, 1);
	mBlock2 = mLine.getNode(Line, 2);
	mBlock3 = mLine.getNode(Line, 3);

	mBlock4 = mLine.getNode(Line, 4);
	mBlock5 = mLine.getNode(Line, 5);
	mBlock6 = mLine.getNode(Line, 6);
	*/
	xSize = xsize;
	ySize = ysize;
}

CollisionSystemDouble::~CollisionSystemDouble()
{

}

void CollisionSystemDouble::update(Movement::direction d)
{
	switch (d)


		//THREE BLOCKS THAT PUSH EACH OTHER
	{
		//************UP******************
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


		//PLAYER 1 PUSHES BLOCK 1
		if (mBlock1->getXPos() == mPlayer1->getXPos() && mBlock1->getYPos() == mPlayer1->getYPos())
		{
			mBlock1->setYPos(mBlock1->getYPos() - 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1); //COLLISIONS INCREMENTED

																  //IF THE PUSHED BLOCK 1 PUSHES BLOCK 2
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>2>3
				if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos())
				{
					mBlock3->setYPos(mBlock3->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//PUSHED 1>3
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos())
			{
				mBlock3->setYPos(mBlock3->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>3>2
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos())
				{
					mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 1 PUSHES BLOCK 2
		if (mBlock2->getXPos() == mPlayer1->getXPos() && mBlock2->getYPos() == mPlayer1->getYPos())
		{
			mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			//BLOCK 2 PUSHES BLOCK 1
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock3->setYPos(mBlock3->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 2 PUSHES BLOCK 3
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock3->setYPos(mBlock3->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 1 PUSHES BLOCK 3
		if (mBlock3->getXPos() == mPlayer1->getXPos() && mBlock3->getYPos() == mPlayer1->getYPos())
		{
			mBlock3->setYPos(mBlock3->getYPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			//BLOCK 3 PUSHES BLOCK 1
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 3 PUSHES BLOCK 2
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 4
		if (mBlock4->getXPos() == mPlayer2->getXPos() && mBlock4->getYPos() == mPlayer2->getYPos())
		{
			mBlock4->setYPos(mBlock4->getYPos() - 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1); //COLLISIONS INCREMENTED

																	//IF THE PUSHED BLOCK 4 PUSHES BLOCK 5
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos())
			{
				mBlock5->setYPos(mBlock5->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>2>3
				if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos())
				{
					mBlock6->setYPos(mBlock6->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//PUSHED 1>3
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos())
			{
				mBlock6->setYPos(mBlock6->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>3>2
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos())
				{
					mBlock5->setYPos(mBlock5->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 5
		if (mBlock5->getXPos() == mPlayer2->getXPos() && mBlock5->getYPos() == mPlayer2->getYPos())
		{
			mBlock5->setYPos(mBlock5->getYPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1);

			//BLOCK 5 PUSHES BLOCK 4
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock4->setYPos(mBlock4->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock6->setYPos(mBlock6->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 5 PUSHES BLOCK 6
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock6->setYPos(mBlock6->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock4->setYPos(mBlock4->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 6
		if (mBlock6->getXPos() == mPlayer2->getXPos() && mBlock6->getYPos() == mPlayer2->getYPos())
		{
			mBlock6->setYPos(mBlock6->getYPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1);

			//BLOCK 6 PUSHES BLOCK 4
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock4->setYPos(mBlock4->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setYPos(mBlock5->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 6 PUSHES BLOCK 5
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock5->setYPos(mBlock5->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock4->setYPos(mBlock4->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//WRAP AROUND MAP BLOCK 2
		if (mBlock2->getYPos() < 0)
		{
			mBlock2->setYPos(ySize);
			//2>1
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock3->setYPos(mBlock3->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//2>3
			if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock3->setYPos(mBlock3->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}
		//WRAP AROUND MAP BLOCK 1
		if (mBlock1->getYPos() < 0)
		{
			mBlock1->setYPos(ySize);
			//1>2
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>2>3
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock3->setYPos(mBlock3->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//1>3
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock3->setYPos(mBlock3->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>3>2
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 3
		if (mBlock3->getYPos() < 0)
		{
			mBlock3->setYPos(ySize);
			//3>1
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//3>2
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 5
		if (mBlock5->getYPos() < 0)
		{
			mBlock5->setYPos(ySize);
			//2>1
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock4->setYPos(mBlock4->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock6->setYPos(mBlock6->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//2>3
			if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock6->setYPos(mBlock6->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock4->setYPos(mBlock4->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}
		//WRAP AROUND MAP BLOCK 4
		if (mBlock4->getYPos() < 0)
		{
			mBlock4->setYPos(ySize);
			//1>2
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock5->setYPos(mBlock5->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>2>3
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock6->setYPos(mBlock6->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//1>3
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock6->setYPos(mBlock6->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>3>2
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setYPos(mBlock5->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 6
		if (mBlock6->getYPos() < 0)
		{
			mBlock6->setYPos(ySize);
			//3>1
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock4->setYPos(mBlock4->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setYPos(mBlock5->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//3>2
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock5->setYPos(mBlock5->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock4->setYPos(mBlock4->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		break;

		//*************DOWN*******************
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

		//PLAYER 1 PUSHES BLOCK 1
		if (mBlock1->getXPos() == mPlayer1->getXPos() && mBlock1->getYPos() == mPlayer1->getYPos())
		{
			mBlock1->setYPos(mBlock1->getYPos() + 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1); //COLLISIONS INCREMENTED

																  //IF THE PUSHED BLOCK 1 PUSHES BLOCK 2
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>2>3
				if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos())
				{
					mBlock3->setYPos(mBlock3->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//PUSHED 1>3
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos())
			{
				mBlock3->setYPos(mBlock3->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>3>2
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos())
				{
					mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 1 PUSHES BLOCK 2
		if (mBlock2->getXPos() == mPlayer1->getXPos() && mBlock2->getYPos() == mPlayer1->getYPos())
		{
			mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			//BLOCK 2 PUSHES BLOCK 1
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock3->setYPos(mBlock3->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 2 PUSHES BLOCK 3
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock3->setYPos(mBlock3->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 1 PUSHES BLOCK 3
		if (mBlock3->getXPos() == mPlayer1->getXPos() && mBlock3->getYPos() == mPlayer1->getYPos())
		{
			mBlock3->setYPos(mBlock3->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			//BLOCK 3 PUSHES BLOCK 1
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 3 PUSHES BLOCK 2
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 4
		if (mBlock4->getXPos() == mPlayer2->getXPos() && mBlock4->getYPos() == mPlayer2->getYPos())
		{
			mBlock4->setYPos(mBlock4->getYPos() + 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1); //COLLISIONS INCREMENTED

																	//IF THE PUSHED BLOCK 4 PUSHES BLOCK 5
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos())
			{
				mBlock5->setYPos(mBlock5->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>2>3
				if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos())
				{
					mBlock6->setYPos(mBlock6->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//PUSHED 1>3
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos())
			{
				mBlock6->setYPos(mBlock6->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>3>2
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos())
				{
					mBlock5->setYPos(mBlock5->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 5
		if (mBlock5->getXPos() == mPlayer2->getXPos() && mBlock5->getYPos() == mPlayer2->getYPos())
		{
			mBlock5->setYPos(mBlock5->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1);

			//BLOCK 5 PUSHES BLOCK 4
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock4->setYPos(mBlock4->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock6->setYPos(mBlock6->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 5 PUSHES BLOCK 6
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock6->setYPos(mBlock6->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock4->setYPos(mBlock4->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 6
		if (mBlock6->getXPos() == mPlayer2->getXPos() && mBlock6->getYPos() == mPlayer2->getYPos())
		{
			mBlock6->setYPos(mBlock6->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1);

			//BLOCK 6 PUSHES BLOCK 4
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock4->setYPos(mBlock4->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setYPos(mBlock5->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 6 PUSHES BLOCK 5
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock5->setYPos(mBlock5->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock4->setYPos(mBlock4->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//WRAP AROUND MAP BLOCK 2
		if (mBlock2->getYPos() > ySize)
		{
			mBlock2->setYPos(0);
			//2>1
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock3->setYPos(mBlock3->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//2>3
			if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock3->setYPos(mBlock3->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}
		//WRAP AROUND MAP BLOCK 1
		if (mBlock1->getYPos() > ySize)
		{
			mBlock1->setYPos(0);
			//1>2
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>2>3
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock3->setYPos(mBlock3->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//1>3
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock3->setYPos(mBlock3->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>3>2
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 3
		if (mBlock3->getYPos() > ySize)
		{
			mBlock3->setYPos(0);
			//3>1
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//3>2
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 5
		if (mBlock5->getYPos() > ySize)
		{
			mBlock5->setYPos(0);
			//2>1
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock4->setYPos(mBlock4->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock6->setYPos(mBlock6->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//2>3
			if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock6->setYPos(mBlock6->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock4->setYPos(mBlock4->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}
		//WRAP AROUND MAP BLOCK 4
		if (mBlock4->getYPos() > ySize)
		{
			mBlock4->setYPos(0);
			//1>2
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock5->setYPos(mBlock5->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>2>3
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock6->setYPos(mBlock6->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//1>3
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock6->setYPos(mBlock6->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>3>2
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setYPos(mBlock5->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 6
		if (mBlock6->getYPos() > ySize)
		{
			mBlock6->setYPos(0);
			//3>1
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock4->setYPos(mBlock4->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setYPos(mBlock5->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//3>2
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock5->setYPos(mBlock5->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock4->setYPos(mBlock4->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		break;

		
		//***************LEFT******************
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

		//PLAYER 1 PUSHES BLOCK 1
		if (mBlock1->getXPos() == mPlayer1->getXPos() && mBlock1->getYPos() == mPlayer1->getYPos())
		{
			mBlock1->setXPos(mBlock1->getXPos() - 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1); //COLLISIONS INCREMENTED

																  //IF THE PUSHED BLOCK 1 PUSHES BLOCK 2
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>2>3
				if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos())
				{
					mBlock3->setXPos(mBlock3->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//PUSHED 1>3
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos())
			{
				mBlock3->setXPos(mBlock3->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>3>2
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos())
				{
					mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 1 PUSHES BLOCK 2
		if (mBlock2->getXPos() == mPlayer1->getXPos() && mBlock2->getYPos() == mPlayer1->getYPos())
		{
			mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			//BLOCK 2 PUSHES BLOCK 1
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock3->setXPos(mBlock3->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 2 PUSHES BLOCK 3
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock3->setXPos(mBlock3->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 1 PUSHES BLOCK 3
		if (mBlock3->getXPos() == mPlayer1->getXPos() && mBlock3->getYPos() == mPlayer1->getYPos())
		{
			mBlock3->setXPos(mBlock3->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			//BLOCK 3 PUSHES BLOCK 1
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 3 PUSHES BLOCK 2
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 4
		if (mBlock4->getXPos() == mPlayer2->getXPos() && mBlock4->getYPos() == mPlayer2->getYPos())
		{
			mBlock4->setXPos(mBlock4->getXPos() - 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1); //COLLISIONS INCREMENTED

																	//IF THE PUSHED BLOCK 4 PUSHES BLOCK 5
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos())
			{
				mBlock5->setXPos(mBlock5->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>2>3
				if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos())
				{
					mBlock6->setXPos(mBlock6->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//PUSHED 1>3
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos())
			{
				mBlock6->setXPos(mBlock6->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>3>2
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos())
				{
					mBlock5->setXPos(mBlock5->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 5
		if (mBlock5->getXPos() == mPlayer2->getXPos() && mBlock5->getYPos() == mPlayer2->getYPos())
		{
			mBlock5->setXPos(mBlock5->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1);

			//BLOCK 5 PUSHES BLOCK 4
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock4->setXPos(mBlock4->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock6->setXPos(mBlock6->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 5 PUSHES BLOCK 6
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock6->setXPos(mBlock6->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock4->setXPos(mBlock4->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 6
		if (mBlock6->getXPos() == mPlayer2->getXPos() && mBlock6->getYPos() == mPlayer2->getYPos())
		{
			mBlock6->setXPos(mBlock6->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1);

			//BLOCK 6 PUSHES BLOCK 4
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock4->setXPos(mBlock4->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setXPos(mBlock5->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 6 PUSHES BLOCK 5
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock5->setXPos(mBlock5->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock4->setXPos(mBlock4->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//WRAP AROUND MAP BLOCK 2
		if (mBlock2->getXPos() < 0)
		{
			mBlock2->setXPos(xSize);
			//2>1
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock3->setXPos(mBlock3->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//2>3
			if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock3->setXPos(mBlock3->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}
		//WRAP AROUND MAP BLOCK 1
		if (mBlock1->getXPos() < 0)
		{
			mBlock1->setXPos(xSize);
			//1>2
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>2>3
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock3->setXPos(mBlock3->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//1>3
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock3->setXPos(mBlock3->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>3>2
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 3
		if (mBlock3->getXPos() < 0)
		{
			mBlock3->setXPos(xSize);
			//3>1
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//3>2
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 5
		if (mBlock5->getXPos() < 0)
		{
			mBlock5->setXPos(xSize);
			//2>1
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock4->setXPos(mBlock4->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock6->setXPos(mBlock6->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//2>3
			if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock6->setXPos(mBlock6->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock4->setXPos(mBlock4->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}
		//WRAP AROUND MAP BLOCK 4
		if (mBlock4->getXPos() < 0)
		{
			mBlock4->setXPos(xSize);
			//1>2
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock5->setXPos(mBlock5->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>2>3
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock6->setXPos(mBlock6->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//1>3
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock6->setXPos(mBlock6->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>3>2
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setXPos(mBlock5->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 6
		if (mBlock6->getXPos() < 0)
		{
			mBlock6->setXPos(xSize);
			//3>1
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock4->setXPos(mBlock4->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setXPos(mBlock5->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//3>2
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock5->setXPos(mBlock5->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock4->setXPos(mBlock4->getXPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		break;
		
		break;
		//*****************RIGHT**********************
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

		//PLAYER 1 PUSHES BLOCK 1
		if (mBlock1->getXPos() == mPlayer1->getXPos() && mBlock1->getYPos() == mPlayer1->getYPos())
		{
			mBlock1->setXPos(mBlock1->getXPos() + 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1); //COLLISIONS INCREMENTED

																  //IF THE PUSHED BLOCK 1 PUSHES BLOCK 2
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>2>3
				if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos())
				{
					mBlock3->setXPos(mBlock3->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//PUSHED 1>3
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos())
			{
				mBlock3->setXPos(mBlock3->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>3>2
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos())
				{
					mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 1 PUSHES BLOCK 2
		if (mBlock2->getXPos() == mPlayer1->getXPos() && mBlock2->getYPos() == mPlayer1->getYPos())
		{
			mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			//BLOCK 2 PUSHES BLOCK 1
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock3->setXPos(mBlock3->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 2 PUSHES BLOCK 3
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock3->setXPos(mBlock3->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 1 PUSHES BLOCK 3
		if (mBlock3->getXPos() == mPlayer1->getXPos() && mBlock3->getYPos() == mPlayer1->getYPos())
		{
			mBlock3->setXPos(mBlock3->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			//BLOCK 3 PUSHES BLOCK 1
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 3 PUSHES BLOCK 2
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 4
		if (mBlock4->getXPos() == mPlayer2->getXPos() && mBlock4->getYPos() == mPlayer2->getYPos())
		{
			mBlock4->setXPos(mBlock4->getXPos() + 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1); //COLLISIONS INCREMENTED

																	//IF THE PUSHED BLOCK 4 PUSHES BLOCK 5
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos())
			{
				mBlock5->setXPos(mBlock5->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>2>3
				if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos())
				{
					mBlock6->setXPos(mBlock6->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//PUSHED 1>3
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos())
			{
				mBlock6->setXPos(mBlock6->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //IF PUSHED 1>3>2
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos())
				{
					mBlock5->setXPos(mBlock5->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 5
		if (mBlock5->getXPos() == mPlayer2->getXPos() && mBlock5->getYPos() == mPlayer2->getYPos())
		{
			mBlock5->setXPos(mBlock5->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1);

			//BLOCK 5 PUSHES BLOCK 4
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock4->setXPos(mBlock4->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock6->setXPos(mBlock6->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 5 PUSHES BLOCK 6
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock6->setXPos(mBlock6->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock4->setXPos(mBlock4->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//PLAYER 2 PUSHES BLOCK 6
		if (mBlock6->getXPos() == mPlayer2->getXPos() && mBlock6->getYPos() == mPlayer2->getYPos())
		{
			mBlock6->setXPos(mBlock6->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer2->setCollisions(mPlayer2->getCollisions() + 1);

			//BLOCK 6 PUSHES BLOCK 4
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock4->setXPos(mBlock4->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setXPos(mBlock5->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//BLOCK 6 PUSHES BLOCK 5
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock5->setXPos(mBlock5->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock4->setXPos(mBlock4->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}

		//WRAP AROUND MAP BLOCK 2
		if (mBlock2->getXPos() > xSize)
		{
			mBlock2->setXPos(0);
			//2>1
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock3->setXPos(mBlock3->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//2>3
			if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock3->setXPos(mBlock3->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
				{
					mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}
		//WRAP AROUND MAP BLOCK 1
		if (mBlock1->getXPos() > xSize)
		{
			mBlock1->setXPos(0);
			//1>2
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>2>3
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock3->setXPos(mBlock3->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//1>3
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock3->setXPos(mBlock3->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>3>2
				if (mBlock3->getXPos() == mBlock2->getXPos() && mBlock3->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 3
		if (mBlock3->getXPos() > xSize)
		{
			mBlock3->setXPos(0);
			//3>1
			if (mBlock1->getXPos() == mBlock3->getXPos() && mBlock1->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//3>2
			if (mBlock2->getXPos() == mBlock3->getXPos() && mBlock2->getYPos() == mBlock3->getYPos()) //TRAIN
			{
				mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
				{
					mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 5
		if (mBlock5->getXPos() > xSize)
		{
			mBlock5->setXPos(0);
			//2>1
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock4->setXPos(mBlock4->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>1>3
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock6->setXPos(mBlock6->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
			//2>3
			if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock6->setXPos(mBlock6->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //2>3>1
				if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
				{
					mBlock4->setXPos(mBlock4->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}
		}
		//WRAP AROUND MAP BLOCK 4
		if (mBlock4->getXPos() > xSize)
		{
			mBlock4->setXPos(0);
			//1>2
			if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
			{
				mBlock5->setXPos(mBlock5->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>2>3
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock6->setXPos(mBlock6->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//1>3
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock6->setXPos(mBlock6->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //1>3>2
				if (mBlock6->getXPos() == mBlock5->getXPos() && mBlock6->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setXPos(mBlock5->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		//WRAP AROUND MAP BLOCK 6
		if (mBlock6->getXPos() > xSize)
		{
			mBlock6->setXPos(0);
			//3>1
			if (mBlock4->getXPos() == mBlock6->getXPos() && mBlock4->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock4->setXPos(mBlock4->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>1>2
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock5->setXPos(mBlock5->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

			//3>2
			if (mBlock5->getXPos() == mBlock6->getXPos() && mBlock5->getYPos() == mBlock6->getYPos()) //TRAIN
			{
				mBlock5->setXPos(mBlock5->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN

														 //3>2>1
				if (mBlock4->getXPos() == mBlock5->getXPos() && mBlock4->getYPos() == mBlock5->getYPos()) //TRAIN
				{
					mBlock4->setXPos(mBlock4->getXPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
				}
			}

		}

		break;
	}

	}
		/* //SINGLE BLOCK
		{
		case Movement::Up:

		if (mPlayer->getYPos() < 0) //WRAP AROUND
		{
		mPlayer->setYPos(ySize);
		}

		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos())
		{
		mBlock->setYPos(mBlock->getYPos() - 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock->getYPos() < 0)
		{
		mBlock->setYPos(ySize);
		}

		break;
		case Movement::Down:

		if (mPlayer->getYPos() > ySize) //WRAP AROUND
		{
		mPlayer->setYPos(0);
		}

		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos())
		{
		mBlock->setYPos(mBlock->getYPos() + 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock->getYPos() > ySize)
		{
		mBlock->setYPos(0);
		}

		break;

		case Movement::Left:

		if (mPlayer->getXPos() < 0) //WRAP AROUND
		{
		mPlayer->setXPos(xSize);
		}

		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos())
		{
		mBlock->setXPos(mBlock->getXPos() - 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock->getXPos() < 0)
		{
		mBlock->setXPos(xSize);
		}

		break;

		case Movement::Right:

		if (mPlayer->getXPos() > xSize) //WRAP AROUND
		{
		mPlayer->setXPos(0);
		}

		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos())
		{
		mBlock->setXPos(mBlock->getXPos() + 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock->getXPos() > xSize)
		{
		mBlock->setYPos(0);
		}

		break;

		}
		*/


		/* //TWO BLOCKS THAT PASS THROUGH EACH OTHER
		{
		case Movement::Up:

		if (mPlayer->getYPos() < 0) //WRAP AROUND
		{
		mPlayer->setYPos(ySize);
		}

		if (mBlock1->getXPos() == mPlayer->getXPos() && mBlock1->getYPos() == mPlayer->getYPos())
		{
		mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock1->getYPos() < 0)
		{
		mBlock1->setYPos(ySize);
		}

		if (mBlock2->getXPos() == mPlayer->getXPos() && mBlock2->getYPos() == mPlayer->getYPos())
		{
		mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock2->getYPos() < 0)
		{
		mBlock2->setYPos(ySize);
		}

		break;
		case Movement::Down:

		if (mPlayer->getYPos() > ySize) //WRAP AROUND
		{
		mPlayer->setYPos(0);
		}

		if (mBlock1->getXPos() == mPlayer->getXPos() && mBlock1->getYPos() == mPlayer->getYPos())
		{
		mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock1->getYPos() > ySize)
		{
		mBlock1->setYPos(0);
		}

		if (mBlock2->getXPos() == mPlayer->getXPos() && mBlock2->getYPos() == mPlayer->getYPos())
		{
		mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock2->getYPos() > ySize)
		{
		mBlock2->setYPos(0);
		}

		break;

		case Movement::Left:

		if (mPlayer->getXPos() < 0) //WRAP AROUND
		{
		mPlayer->setXPos(xSize);
		}

		if (mBlock1->getXPos() == mPlayer->getXPos() && mBlock1->getYPos() == mPlayer->getYPos())
		{
		mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock1->getXPos() < 0)
		{
		mBlock1->setXPos(xSize);
		}

		if (mBlock2->getXPos() == mPlayer->getXPos() && mBlock2->getYPos() == mPlayer->getYPos())
		{
		mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock2->getXPos() < 0)
		{
		mBlock2->setXPos(xSize);
		}

		break;

		case Movement::Right:

		if (mPlayer->getXPos() > xSize) //WRAP AROUND
		{
		mPlayer->setXPos(0);
		}

		if (mBlock1->getXPos() == mPlayer->getXPos() && mBlock1->getYPos() == mPlayer->getYPos())
		{
		mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock1->getXPos() > xSize)
		{
		mBlock1->setYPos(0);
		}

		if (mBlock2->getXPos() == mPlayer->getXPos() && mBlock2->getYPos() == mPlayer->getYPos())
		{
		mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE
		mPlayer->setCollisions(mPlayer->getCollisions() + 1);
		}

		if (mBlock2->getXPos() > xSize)
		{
		mBlock2->setYPos(0);
		}

		break;

		}

		*/
/*

		//TWO BLOCKS THAT PUSH EACH OTHER
	{
	case Movement::Up:
		//WRAP AROUND PLAYER 1
		if (mPlayer1->getYPos() < 0) 
		{
			mPlayer1->setYPos(ySize);
		}

		//WRAP AROUND PLAYER 2
		if (mPlayer2->getYPos() < 0) 
		{
			mPlayer2->setYPos(ySize);
		}



		//PLAYER 1 PUSH BLOCK
		if (mBlock1->getXPos() == mPlayer1->getXPos() && mBlock1->getYPos() == mPlayer1->getYPos()) 
		{
			mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock2->getXPos() == mPlayer1->getXPos() && mBlock2->getYPos() == mPlayer1->getYPos()) //PUSH BLOCK
		{
			mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock2->getYPos() < 0)
		{
			mBlock2->setYPos(ySize);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock1->getYPos() < 0)
		{
			mBlock1->setYPos(ySize);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		break;

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

		if (mBlock1->getXPos() == mPlayer1->getXPos() && mBlock1->getYPos() == mPlayer1->getYPos())
		{
			mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock2->getXPos() == mPlayer1->getXPos() && mBlock2->getYPos() == mPlayer1->getYPos())
		{
			mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock1->getYPos() > ySize)
		{
			mBlock1->setYPos(0);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock2->getYPos() > ySize)
		{
			mBlock2->setYPos(0);
			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		break;

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

		if (mBlock1->getXPos() == mPlayer1->getXPos() && mBlock1->getYPos() == mPlayer1->getYPos())
		{
			mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock2->getXPos() == mPlayer1->getXPos() && mBlock2->getYPos() == mPlayer1->getYPos())
		{
			mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
		{
			mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE
		}

		if (mBlock1->getXPos() < 0)
		{
			mBlock1->setXPos(xSize);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock2->getXPos() < 0)
		{
			mBlock2->setXPos(xSize);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			}
		}

		break;

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

		if (mBlock1->getXPos() == mPlayer1->getXPos() && mBlock1->getYPos() == mPlayer1->getYPos())
		{
			mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock2->getXPos() == mPlayer1->getXPos() && mBlock2->getYPos() == mPlayer1->getYPos())
		{
			mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer1->setCollisions(mPlayer1->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock1->getXPos() > xSize)
		{
			mBlock1->setXPos(0);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock2->getXPos() > xSize)
		{
			mBlock2->setXPos(0);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			}
		}

		break;

	}

}
*/