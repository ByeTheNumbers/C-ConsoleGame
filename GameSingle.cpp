#include "GameSingle.h"
#include <iostream>
#include <conio.h>
#include<Windows.h>
//TEST
#include <ctime>
using namespace std;

GameSingle::GameSingle() 
{
	char initial;
	running = true;
	//TEST
	//srand(time(0));


	field = new Field(40, 20);

	
	cout << "Show grid? [1||0]";
	cin >> want_grid;
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

	block1 = new Block(5, 5, '1');
	block2 = new Block(6, 5, '2');
	//block3 = new Block(7, 5);
	//block4 = new Block(8, 5);
	//block5 = new Block(9, 5);
	//block6 = new Block(10, 5);
	//block7 = new Block(11, 5);
	//block8 = new Block(12, 5);
	//block9 = new Block(13, 5);
	//collisionSystem = new CollisionSystem(player, block, field->getXSize(), field->getYSize());
	//USE THE ONE BELOW
	collisionSystem = new CollisionSystemSingle(player, block1, block2, field->getXSize(), field->getYSize());


}

GameSingle::~GameSingle() 
{
	delete field;
	delete player;

	//delete block;
	delete block1;
	delete block2;
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
	//*/
	player->draw(*field);


	//block->draw(*field);
	block1->draw(*field);
	block2->draw(*field);
	

	field->display();

	//TEST
	//cout << "Time: " << srand(time(0));

	cout << "Collisions: " << player->getCollisions() << endl;

	cout << "Player X: " << player->getXPos() << endl;
	cout << "Player Y: " << player->getYPos() << endl;


	//cout << "Block X: " << block->getXPos() << endl;
	//cout << "Block Y: " << block->getYPos() << endl;

	cout << "Block X: " << block1->getXPos() << endl;
	cout << "Block Y: " << block1->getYPos() << endl;
	cout << "Block X: " << block2->getXPos() << endl;
	cout << "Block Y: " << block2->getYPos() << endl;
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
	}


	player->update(direction);
	//block->update();
	block1->update();
	block2->update();
	collisionSystem->update(direction);
}

void GameSingle::clear()
{
	field->clear();
	system("cls");
}