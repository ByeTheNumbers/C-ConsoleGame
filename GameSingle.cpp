#include "GameSingle.h"
#include <iostream>
#include <conio.h>
#include<Windows.h>

using namespace std;

GameSingle::GameSingle()


{
	//	char initial;
	running = true;



	field = new Field(44, 25);


	cout << "Show grid? [1||0]";
	cin >> want_grid;
	if (want_grid == 1) // MAKE THIS A BOOL OR SOMETHING
	{

		background1 = new Background(20, 10, '|');
		background2 = new Background(20, 12, '|');
		background3 = new Background(20, 14, '|');
		background4 = new Background(22, 10, '|');
		background5 = new Background(22, 12, '|');
		background6 = new Background(22, 14, '|');
		background7 = new Background(19, 11, '-');
		background8 = new Background(21, 11, '-');
		background9 = new Background(23, 11, '-');
		background10 = new Background(19, 13, '-');
		background11 = new Background(21, 13, '-');
		background12 = new Background(23, 13, '-');


	}

	player = new Player(2, 2);

	//player.
	//void Player.setLetter(char initial);
	//player = new Player(2, 2, letter);

	//block = new Block(5, 5);
	//player1 = new Player(2, 2);
	//block1 = new Block(5, 5);
	//block2 = new Block(6, 5);

	block1 = new Block(5, 5, 'A');
	block2 = new Block(5, 6, 'B');
	block3 = new Block(5, 7, 'C');
	//block4 = new Block(5, 10, '1');
	//block5 = new Block(5, 11, '2');
	//block6 = new Block(5, 12, '3');
	//block7 = new Block(11, 5, 'G');
	//block8 = new Block(12, 5, 'H');
	//block9 = new Block(13, 5, 'I');
	List firstLine;
	//collisionSystem = new CollisionSystem(player, block, field->getXSize(), field->getYSize());
	//USE THE ONE BELOW
	//collisionSystem = new CollisionSystem(player, block1, block2, field->getXSize(), field->getYSize());

	collisionSystem = new CollisionSystemSingle(player, block1, block2, block3, field->getXSize(), field->getYSize());
	//listCollisionSystem = new ListCollision(player1, player2, firstLine, field->getXSize(), field->getYSize());
}

GameSingle::~GameSingle()
{
	delete field;
	delete player;

	//delete player1;
	//delete player2;

	//delete block;
	delete block1;
	delete block2;
	delete block3;
	//delete block4;
	//delete block5;
	//delete block6;

	delete background1;
	delete background2;
	delete background3;
	delete background4;
	delete background5;
	delete background6;
	delete background7;
	delete background8;
	delete background9;
	delete background10;
	delete background11;
	delete background12;

	delete collisionSystem;
}

void GameSingle::run()
{
	while (running)
	{
		List Line = line();
		draw(Line);

		//draw();
		input();
		update();
		checkWin(Line);
		clear();

	}
}

List GameSingle::line()
{
	List Line;// Line;
	Line.addNode(block1->getLetter(), block1->getXPos(), block1->getYPos());
	Line.addNode(block2->getLetter(), block2->getXPos(), block2->getYPos());
	Line.addNode(block3->getLetter(), block3->getXPos(), block3->getYPos());
	//Line.addNode(block4->getLetter(), block4->getXPos(), block4->getYPos());
	//Line.addNode(block5->getLetter(), block5->getXPos(), block5->getYPos());
	//Line.addNode(block6->getLetter(), block6->getXPos(), block6->getYPos());
	//Line.print();
	return Line;
}

void GameSingle::draw(List Line)
//void GameSingle::draw()
{
	///*
	if (want_grid == 1)
	{
		background1->draw(*field);
		background2->draw(*field);
		background3->draw(*field);
		background4->draw(*field);
		background5->draw(*field);
		background6->draw(*field);
		background7->draw(*field);
		background8->draw(*field);
		background9->draw(*field);
		background10->draw(*field);
		background11->draw(*field);
		background12->draw(*field);
	}

	//block->draw(*field);
	block1->draw(*field);
	block2->draw(*field);
	block3->draw(*field);
	//block4->draw(*field);
	//block5->draw(*field);
	//block6->draw(*field);

	player->draw(*field);

	//player1->draw(*field);
	//player2->draw(*field);


	field->display();

	List mLine = Line;
	//mLine.print();
	//TEST
	//cout << "Time: " << srand(time(0));

	cout << player->getLetter() << " " << player->getXPos() << " " << player->getYPos() << " " << "Pushes: " << player->getCollisions() << endl;

	//cout << player1->getLetter() << " " << player1->getXPos() << " " << player1->getYPos() << " " << "Pushes: " << player1->getCollisions() << endl;
	//cout << player2->getLetter() << " " << player2->getXPos() << " " << player2->getYPos() << " " << "Pushes: " << player2->getCollisions() << endl;

	mLine.print();


}

void GameSingle::input()
{
	in = _getch();
}

void GameSingle::update()
{
	//ESC WILL EXIT THE GAME
	if (in == 27)
	{
		running = false;
	}


	//ONE PLAYER
	switch (in)
	{
	case 'w':
		direction = Movement::Up;
		break;
	case 's':
		direction = Movement::Down;
		break;
	case 'a':
		direction = Movement::Left;
		break;
	case 'd':
		direction = Movement::Right;
		break;
	default:
		direction = Movement::Stay_Still;
	}

	player->update(direction);

	//player1->update(direction1);
	//player2->update(direction2);
	//block->update();
	block1->update();
	block2->update();
	block3->update();
	//block4->update();
	//block5->update();
	//block6->update();
	collisionSystem->update(direction);
	//collisionSystem->update(direction1);
	//collisionSystem->update(direction2);
}


void GameSingle::checkWin(List Line)
{
	List mLine = Line;
	cout << "Here: " << mLine.lockSquare(Line) << endl;
	//cout << "LIST: " << mLine.
	//MAYBE INSTEAD OF DELETING THE BLOC AND LOCKING IT IN WE JUST BOOL IT

	//IF A BLOCK IS IN A SQUARE LOCK THE SQUARE IF IT IS NOT IN THE SQUARE ULOCK THE SQUARE
	//if ('A' == (mLine.lockSquare(Line))) //|| 'B' == (mLine.lockSquare(Line)) || 'C' == (mLine.lockSquare(Line)))
	//{
	//bool 
	//if(background1a) delete background1a;
	//background1a = new Background(block1->getXPos(), block1->getYPos(), 'A');
	//	background1->draw(*field);
	//delete block1;
	//mLine.removeNode('A');
	//}
	/*
	delete block2;
	delete block3;
	delete block4;
	delete block5;
	delete block6;
	background1a = new Background(19, 10, 'A');
	background1b = new Background(21, 10, 'A');
	background1c = new Background(23, 10, 'A');

	background2a = new Background(19, 12, 'A');
	background2b = new Background(21, 12, 'A');
	background2c = new Background(23, 12, 'A');

	background3a = new Background(19, 14, 'A');
	background3b = new Background(21, 14, 'A');
	background3c = new Background(23, 14, 'A');
	*/
}

void GameSingle::clear()
{
	field->clear();
	system("cls");
}




//********************
/*
GameSingle::GameSingle() 
{


	//char initial;
	running = true;
	//TEST
	//srand(time(0));


	field = new Field(40, 20);

	
	cout << "Show grid? [1||0]";
	cin >> want_grid;
	want_grid = 0;
	if (want_grid == 1) // MAKE THIS A BOOL OR SOMETHING
	{

		background1 = new Background(10, 10, '|');
		background2 = new Background(10, 12, '|');
		background3 = new Background(10, 14, '|');
		background4 = new Background(12, 10, '|');
		background5 = new Background(12, 12, '|');
		background6 = new Background(12, 14, '|');
		background7 = new Background(9, 11, '-');
		background8 = new Background(11, 11, '-');
		background9 = new Background(13, 11, '-');
		background10 = new Background(9, 13, '-');
		background11 = new Background(11, 13, '-');
		background12 = new Background(13, 13, '-');
	}

	player = new Player(2, 2);

	//player.
	//void Player.setLetter(char initial);
	//player = new Player(2, 2, letter);
	
	//block = new Block(5, 5);
	//player1 = new Player(2, 2);
	//block1 = new Block(5, 5);
	//block2 = new Block(6, 5);

	block1 = new Block(5, 5, 'A');
	block2 = new Block(6, 5, 'B');
	block3 = new Block(7, 5, 'C');
	//block4 = new Block(8, 5, 'D');
	//block5 = new Block(9, 5, 'E');
	//block6 = new Block(10, 5, 'F');
	//block7 = new Block(11, 5, 'G');
	//block8 = new Block(12, 5, 'H');
	//block9 = new Block(13, 5, 'I');
	
	/* // MULTIPLE BLOCK INTERACTIONS HARD TO CODE
	

	
	
	
	
	//CollisionLinkedListSingle get_Letters()
	//{
	//	return Letters;
	//}

	//collisionSystem = new CollisionSystem(player, block, field->getXSize(), field->getYSize());

	//USE THE ONE BELOW
	collisionSystem = new CollisionSystemSingle(player, block1, block2, block3, block4, block5, block6, block7, block8, field->getXSize(), field->getYSize());


}

GameSingle::~GameSingle() 
{
	delete field;
	delete player;

	//delete block;
	delete block1;
	delete block2;
	delete block3;
	//delete block4;
	//delete block5;
	//delete block6;
	//delete block7;
	//delete block8;
	


	delete collisionSystem;
}

void GameSingle::run()
{
	while (running)
	{
		draw();
		input();
		update();
		clear();

	}
}

void GameSingle::draw()
{
	///*
	if (want_grid == 1)
	{
		background1->draw(*field);
		background2->draw(*field);
		background3->draw(*field);
		background4->draw(*field);
		background5->draw(*field);
		background6->draw(*field);
		background7->draw(*field);
		background8->draw(*field);
		background9->draw(*field);
		background10->draw(*field);
		background11->draw(*field);
		background12->draw(*field);
	}
	
	player->draw(*field);


	//block->draw(*field);
	block1->draw(*field);
	block2->draw(*field);
	block3->draw(*field);
	block4->draw(*field);
	block5->draw(*field);
	block6->draw(*field);
	block7->draw(*field);
	block8->draw(*field);
	
	
	//superBlock1->draw(*field);

	field->display();

	//TEST
	//cout << "Time: " << srand(time(0));

	cout << "Collisions: " << player->getCollisions() << endl;

	cout << "Player X: " << player->getXPos() << endl;
	cout << "Player Y: " << player->getYPos() << endl;

	//CollisionSystemSingle List::Line.print();
	//CollisionSystemSingle::getLine;
	//CollisionSystemSingle List -> getLine;
	
	//WE WANT TO PRINT LIST LINE HERE
	List Line;
	Line.addNode(block1->getLetter(), block1->getXPos(), block1->getYPos());
	Line.addNode(block2->getLetter(), block2->getXPos(), block2->getYPos());
	Line.addNode(block3->getLetter(), block3->getXPos(), block3->getYPos());
	Line.addNode(block4->getLetter(), block4->getXPos(), block4->getYPos());
	Line.addNode(block5->getLetter(), block5->getXPos(), block5->getYPos());
	Line.addNode(block6->getLetter(), block6->getXPos(), block6->getYPos());
	Line.addNode(block7->getLetter(), block7->getXPos(), block7->getYPos());
	Line.addNode(block8->getLetter(), block8->getXPos(), block8->getYPos());
	Line.print();


	

	//cout << "Block X: " << block->getXPos() << endl;
	//cout << "Block Y: " << block->getYPos() << endl;


	//Letters.AddNode(block1->getXPos(), block1->getYPos(), 'A');
	//Letters.AddNode(block2->getXPos(), block2->getYPos(), 'B');
//	Letters.AddNode(block3->getXPos(), block3->getYPos(), 'C');
	
	
	cout << "Block1 X: " << block1->getXPos() << endl;
	cout << "Block1 Y: " << block1->getYPos() << endl;
	cout << "Block2 X: " << block2->getXPos() << endl;
	cout << "Block2 Y: " << block2->getYPos() << endl;
	cout << "Block3 X: " << block3->getXPos() << endl;
	cout << "Block3 Y: " << block3->getYPos() << endl;

	
}

void GameSingle::input() 
{
	in = _getch();
}

void GameSingle::update()
{
	//ESC WILL EXIT THE GAME
	if (in == 27)
	{
		running = false;
	}
	 //ONE PLAYER
	switch (in)
	{
	case 'w':
		direction = Movement::Up;
		break;
	case 's':
		direction = Movement::Down;
		break;
	case 'a':
		direction = Movement::Left;
		break;
	case 'd':
		direction = Movement::Right;
		break;
	default:
		direction = Movement::Stay_Still;
	}


	player->update(direction);
	//block->update();
	block1->update();
	block2->update();
	block3->update();
	block4->update();
	block5->update();
	block6->update();
	block7->update();
	block8->update();
	//superBlock1->update();

	collisionSystem->update(direction);
}

void GameSingle::clear()
{
	field->clear();
	system("cls");
}
*/