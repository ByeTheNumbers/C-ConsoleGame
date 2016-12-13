#include "CollisionSystemSingle.h"

//CollisionSystem::CollisionSystem(Player *player, Block *block, int xsize, int ysize)
CollisionSystemSingle::CollisionSystemSingle(Player *player, Block *block1, Block *block2, Block *block3, int xsize, int ysize)
{
	mPlayer = player;
	//mBlock = block;
	mBlock1 = block1;
	mBlock2 = block2;
	mBlock3 = block3;
//	mBlock4 = block4;
//	mBlock5 = block5;
//	mBlock6 = block6;
//	mBlock7 = block7;
//	mBlock8 = block8;

	xSize = xsize;
	ySize = ysize;

	

	//******************************************

	//List l1; //Declare an empty list
	//List Line;
	//int num = 0; //Local variable
	//while (num != 99) { //Loop until user types 99
//		cout << "Enter number: ";
	//	cin >> num;
	//	if (num != 99)
	//		l1.addNode(num); //Add number to list
	//}

	
	
	//l1.print(); //Print out the list


	//num = 0;	//reset local variable
	//while (num != 99) { //Loop until user types 99
	//	cout << endl << "Enter a value to delete from list: ";
	//	cin >> num;
	//	if (num != 99)
	//		if (!l1.removeNode(num)) { //remove the node and check if it was successful
	//			cout << "No such node in list!" << endl;
	//		}
	//}

	//l1.print();
//}

//***************************************
}

CollisionSystemSingle::~CollisionSystemSingle()
{

}

//List CollisionSystemSingle::getLine()
//{
//	return Line;
//}


void CollisionSystemSingle::update(Movement::direction d)
{

	switch (d)

		// /*
       //THREE BLOCKS THAT PUSH EACH OTHER
	{
	//************UP******************
	case Movement::Up:
		
		//WRAP AROUND MAP FOR PLAYER
		if (mPlayer->getYPos() < 0) 
		{
			mPlayer->setYPos(ySize);
		}
		//PLAYER PUSHES BLOCK 1
		if (mBlock1->getXPos() == mPlayer->getXPos() && mBlock1->getYPos() == mPlayer->getYPos()) 
		{
			mBlock1->setYPos(mBlock1->getYPos() - 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1); //COLLISIONS INCREMENTED

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

		//PLAYER PUSHES BLOCK 2
		if (mBlock2->getXPos() == mPlayer->getXPos() && mBlock2->getYPos() == mPlayer->getYPos()) 
		{
			mBlock2->setYPos(mBlock2->getYPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

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

		//PLAYER PUSHES BLOCK 3
		if (mBlock3->getXPos() == mPlayer->getXPos() && mBlock3->getYPos() == mPlayer->getYPos())
		{
			mBlock3->setYPos(mBlock3->getYPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

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
		
		break;

		//*************DOWN*******************
	case Movement::Down:

		
		if (mPlayer->getYPos() > ySize) //WRAP AROUND PLAYER
		{
			mPlayer->setYPos(0);
		}
		//PLAYER PUSHES BLOCK 1
		if (mBlock1->getXPos() == mPlayer->getXPos() && mBlock1->getYPos() == mPlayer->getYPos())
		{
			mBlock1->setYPos(mBlock1->getYPos() + 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1); //COLLISIONS INCREMENTED

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

		//PLAYER PUSHES BLOCK 2
		if (mBlock2->getXPos() == mPlayer->getXPos() && mBlock2->getYPos() == mPlayer->getYPos())
		{
			mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

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

		//PLAYER PUSHES BLOCK 3
		if (mBlock3->getXPos() == mPlayer->getXPos() && mBlock3->getYPos() == mPlayer->getYPos())
		{
			mBlock3->setYPos(mBlock3->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

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

		break;

		/*
		if (mBlock1->getXPos() == mPlayer->getXPos() && mBlock1->getYPos() == mPlayer->getYPos())
		{
			mBlock1->setYPos(mBlock1->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos()) //TRAIN
			{
				mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE IF TRAIN
			}
		}

		if (mBlock2->getXPos() == mPlayer->getXPos() && mBlock2->getYPos() == mPlayer->getYPos())
		{
			mBlock2->setYPos(mBlock2->getYPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

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
		*/
		//***************LEFT******************
	case Movement::Left:

		if (mPlayer->getXPos() < 0) //WRAP AROUND PLAYER
		{
			mPlayer->setXPos(xSize);
		}

		//PLAYER PUSHES BLOCK 1
		if (mBlock1->getXPos() == mPlayer->getXPos() && mBlock1->getYPos() == mPlayer->getYPos())
		{
			mBlock1->setXPos(mBlock1->getXPos() - 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1); //COLLISIONS INCREMENTED

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

		//PLAYER PUSHES BLOCK 2
		if (mBlock2->getXPos() == mPlayer->getXPos() && mBlock2->getYPos() == mPlayer->getYPos())
		{
			mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

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

		//PLAYER PUSHES BLOCK 3
		if (mBlock3->getXPos() == mPlayer->getXPos() && mBlock3->getYPos() == mPlayer->getYPos())
		{
			mBlock3->setXPos(mBlock3->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

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

		break;
		/*
		if (mBlock1->getXPos() == mPlayer->getXPos() && mBlock1->getYPos() == mPlayer->getYPos())
		{
			mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock2->getXPos() == mPlayer->getXPos() && mBlock2->getYPos() == mPlayer->getYPos())
		{
			mBlock2->setXPos(mBlock2->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock1->setXPos(mBlock1->getXPos() - 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
		{
			mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE
		}

		if (mBlock1->getXPos() < 0)
		{
			mBlock1->setXPos(xSize);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock2->getXPos() < 0)
		{
			mBlock2->setXPos(xSize);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			}
		}

		*/
		break;
		//*****************RIGHT**********************
	case Movement::Right:

		if (mPlayer->getXPos() > xSize) //WRAP AROUND PLAYER
		{
			mPlayer->setXPos(0);
		}

		//PLAYER PUSHES BLOCK 1
		if (mBlock1->getXPos() == mPlayer->getXPos() && mBlock1->getYPos() == mPlayer->getYPos())
		{
			mBlock1->setXPos(mBlock1->getXPos() + 1);// -1 = BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1); //COLLISIONS INCREMENTED

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

		//PLAYER PUSHES BLOCK 2
		if (mBlock2->getXPos() == mPlayer->getXPos() && mBlock2->getYPos() == mPlayer->getYPos())
		{
			mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

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

		//PLAYER PUSHES BLOCK 3
		if (mBlock3->getXPos() == mPlayer->getXPos() && mBlock3->getYPos() == mPlayer->getYPos())
		{
			mBlock3->setXPos(mBlock3->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

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

		break;


		/*
		if (mBlock1->getXPos() == mPlayer->getXPos() && mBlock1->getYPos() == mPlayer->getYPos())
		{
			mBlock1->setXPos(mBlock1->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

			if (mBlock1->getXPos() == mBlock2->getXPos() && mBlock1->getYPos() == mBlock2->getYPos())
			{
				mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			}
		}

		if (mBlock2->getXPos() == mPlayer->getXPos() && mBlock2->getYPos() == mPlayer->getYPos())
		{
			mBlock2->setXPos(mBlock2->getXPos() + 1);//BLOCK TRAVEL DISTANCE
			mPlayer->setCollisions(mPlayer->getCollisions() + 1);

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
		*/
	}

}

//*/





		//USING LINKED LIST


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

