#include "GameDouble.h"
#include <iostream>
#include <conio.h>
#include<Windows.h>
//TEST
#include <ctime>
using namespace std;

GameDouble::GameDouble()
{
//	char initial;
	running = true;
	//TEST
	//srand(time(0));


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

	//player = new Player(2, 2);

	player1 = new Player(2, 2);
	player2 = new Player(5, 12);

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
	block4 = new Block(5, 10, '1');
	block5 = new Block(5, 11, '2');
	block6 = new Block(5, 12, '3');
	//block7 = new Block(11, 5, 'G');
	//block8 = new Block(12, 5, 'H');
	//block9 = new Block(13, 5, 'I');
	List firstLine;
	//collisionSystem = new CollisionSystem(player, block, field->getXSize(), field->getYSize());
	//USE THE ONE BELOW
	//collisionSystem = new CollisionSystem(player, block1, block2, field->getXSize(), field->getYSize());

	collisionSystem = new CollisionSystemDouble(player1, player2, block1, block2, block3, block4, block5, block6, field->getXSize(), field->getYSize());
	//listCollisionSystem = new ListCollision(player1, player2, firstLine, field->getXSize(), field->getYSize());
}

GameDouble::~GameDouble()
{
	delete field;
	//delete player;

	delete player1;
	delete player2;

	//delete block;
	delete block1;
	delete block2;
	delete block3;
	delete block4;
	delete block5;
	delete block6;

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

void GameDouble::run()
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

List GameDouble::line()
{
	List Line;// Line;
	Line.addNode(block1->getLetter(), block1->getXPos(), block1->getYPos());
	Line.addNode(block2->getLetter(), block2->getXPos(), block2->getYPos());
	Line.addNode(block3->getLetter(), block3->getXPos(), block3->getYPos());
	Line.addNode(block4->getLetter(), block4->getXPos(), block4->getYPos());
	Line.addNode(block5->getLetter(), block5->getXPos(), block5->getYPos());
	Line.addNode(block6->getLetter(), block6->getXPos(), block6->getYPos());
	//Line.print();
	return Line;
}

void GameDouble::draw(List Line)
//void GameDouble::draw()
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
	block4->draw(*field);
	block5->draw(*field);
	block6->draw(*field);

	player1->draw(*field);
	player2->draw(*field);


	field->display();

	List mLine = Line;
	//mLine.print();
	//TEST
	//cout << "Time: " << srand(time(0));

	cout << player1->getLetter() <<" " << player1->getXPos() <<" "<< player1->getYPos() <<" "<< "Pushes: " << player1->getCollisions() << endl;
	cout << player2->getLetter()<<" " << player2->getXPos() <<" "<< player2->getYPos() <<" "<< "Pushes: " << player2->getCollisions() << endl;

	mLine.print();
	
	
}

void GameDouble::input()
{
	in = _getch();
}

void GameDouble::update()
{
	//ESC WILL EXIT THE GAME
	if (in == 27)
	{
		running = false;
	}


	 //2 PLAYERS

	switch (in)
	{
		//Player 1 Controls
	case 'w':
		direction1 = Movement::Up;
		direction2 = Movement::Stay_Still;
		break;
	case 's':
		direction1 = Movement::Down;
		direction2 = Movement::Stay_Still;
		break;
	case 'a':
		direction1 = Movement::Left;
		direction2 = Movement::Stay_Still;
		break;
	case 'd':
		direction1 = Movement::Right;
		direction2 = Movement::Stay_Still;
		break;
		
		//Player 2 Controls
	case 'i':
		direction1 = Movement::Stay_Still;
		direction2 = Movement::Up;
		break;
	case 'k':
		direction1 = Movement::Stay_Still;
		direction2 = Movement::Down;
		break;
	case 'j':
		direction1 = Movement::Stay_Still;
		direction2 = Movement::Left;
		break;
	case 'l':
		direction1 = Movement::Stay_Still;
		direction2 = Movement::Right;
		break;
	default:
		direction2 = Movement::Stay_Still;
		direction1 = Movement::Stay_Still;
	}


	player1->update(direction1);
	player2->update(direction2);
	//block->update();
	block1->update();
	block2->update();
	block3->update();
	block4->update();
	block5->update();
	block6->update();
	//collisionSystem->update(direction);
	collisionSystem->update(direction1);
	collisionSystem->update(direction2);
}


void GameDouble::checkWin(List Line)
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

void GameDouble::clear()
{
	field->clear();
	system("cls");
}