#include "CollisionSystemDouble.h"

//CollisionSystem::CollisionSystem(Player *player, Block *block, int xsize, int ysize)
CollisionSystemDouble::CollisionSystemDouble(Player *player1, Player *player2, Block *block1, Block *block2, int xsize, int ysize)
{
	mPlayer1 = player1;
	mPlayer2 = player2;
	//mBlock = block;
	mBlock1 = block1;
	mBlock2 = block2;

	xSize = xsize;
	ySize = ysize;
}

CollisionSystemDouble::~CollisionSystemDouble()
{

}

void CollisionSystemDouble::update(Movement::direction d)
{
	switch (d)
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


		//TWO BLOCKS THAT PUSH EACH OTHER
	{
	case Movement::Up:

		if (mPlayer1->getYPos() < 0) //WRAP AROUND PLAYER
		{
			mPlayer1->setYPos(ySize);
		}

		if (mBlock1->getXPos() == mPlayer1->getXPos() && mBlock1->getYPos() == mPlayer1->getYPos()) //PUSH BLOCK
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

		if (mPlayer1->getYPos() > ySize) //WRAP AROUND PLAYER
		{
			mPlayer1->setYPos(0);
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

		if (mPlayer1->getXPos() < 0) //WRAP AROUND PLAYER
		{
			mPlayer1->setXPos(xSize);
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

		if (mPlayer1->getXPos() > xSize) //WRAP AROUND PLAYER
		{
			mPlayer1->setXPos(0);
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