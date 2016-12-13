#include "SuperBlock.h"


SuperBlock::SuperBlock(int xpos, int ypos, char _letter, Player *player, SuperBlock *block, int xsize, int ysize) : Object(xpos, ypos)
{
	
	letter = _letter;

	mPlayer = player;
	mBlock = block;

	xSize = xsize;
	ySize = ysize;
}

SuperBlock::~SuperBlock()
{

}

void SuperBlock::update()
{

}

void SuperBlock::setCollisions(int c)
{
	collisions = c;
}

int SuperBlock::getCollisions() const
{
	return collisions;
}

void SuperBlock::update(Movement::direction d)
{
	switch (d)
	{
	case Movement::Up:

		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos()) //PUSH BLOCK
		{
			mBlock->setYPos(mBlock->getYPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos())
			{
				mBlock->setYPos(mBlock->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos()) //PUSH BLOCK
		{
			mBlock->setYPos(mBlock->getYPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos()) //TRAIN
			{
				mBlock->setYPos(mBlock->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock->getYPos() < 0)
		{
			mBlock->setYPos(ySize);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos()) //TRAIN
			{
				mBlock->setYPos(mBlock->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock->getYPos() < 0)
		{
			mBlock->setYPos(ySize);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos()) //TRAIN
			{
				mBlock->setYPos(mBlock->getYPos() - 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		break;

	case Movement::Down:


		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos())
		{
			mBlock->setYPos(mBlock->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos()) //TRAIN
			{
				mBlock->setYPos(mBlock->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos())
		{
			mBlock->setYPos(mBlock->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos()) //TRAIN
			{
				mBlock->setYPos(mBlock->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock->getYPos() > ySize)
		{
			mBlock->setYPos(0);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos()) //TRAIN
			{
				mBlock->setYPos(mBlock->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock->getYPos() > ySize)
		{
			mBlock->setYPos(0);
			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos()) //TRAIN
			{
				mBlock->setYPos(mBlock->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		break;

	case Movement::Left:

		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos())
		{
			mBlock->setXPos(mBlock->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos())
			{
				mBlock->setXPos(mBlock->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos())
		{
			mBlock->setXPos(mBlock->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos())
			{
				mBlock->setXPos(mBlock->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos())
		{
			mBlock->setXPos(mBlock->getXPos() - 1);//BLOCK TRAVEL DISTANCE
		}

		if (mBlock->getXPos() < 0)
		{
			mBlock->setXPos(xSize);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos())
			{
				mBlock->setXPos(mBlock->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock->getXPos() < 0)
		{
			mBlock->setXPos(xSize);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos())
			{
				mBlock->setXPos(mBlock->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			}
		}

		break;

	case Movement::Right:

		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos())
		{
			mBlock->setXPos(mBlock->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos())
			{
				mBlock->setXPos(mBlock->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock->getXPos() == mPlayer->getXPos() && mBlock->getYPos() == mPlayer->getYPos())
		{
			mBlock->setXPos(mBlock->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos())
			{
				mBlock->setXPos(mBlock->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock->getXPos() > xSize)
		{
			mBlock->setXPos(0);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos())
			{
				mBlock->setXPos(mBlock->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock->getXPos() > xSize)
		{
			mBlock->setXPos(0);

			if (mBlock->getXPos() == mBlock->getXPos() && mBlock->getYPos() == mBlock->getYPos())
			{
				mBlock->setXPos(mBlock->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			}
		}

		break;

	}

}