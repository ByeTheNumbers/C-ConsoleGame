//#ifndef GAME_H
//#define GAME_H
#pragma once


#include "Field.h"
#include "Player.h"
#include "Block.h"
#include "CollisionSystemDouble.h"
#include "Background.h"
#include "List.h"
#include "LetterNode.h"
#include "ListCollision.h"


class GameDouble {
public:
	GameDouble();
	~GameDouble();

	void run();

private:
	List line();
	void draw(List Line);
	void input();
	void update();
	void checkWin(List Line);
	void clear();

	bool running;

	char in;
	//Movement::direction direction;
	Movement::direction direction1;
	Movement::direction direction2;

	Field *field;
	Background *background1;
	Background *background2;
	Background *background3;
	Background *background4;
	Background *background5;
	Background *background6;
	Background *background7;
	Background *background8;
	Background *background9;
	Background *background10;
	Background *background11;
	Background *background12;

	Background *background1a;
	Background *background1b;
	Background *background1c;

	Background *background2a;
	Background *background2b;
	Background *background2c;

	Background *background3a;
	Background *background3b;
	Background *background3c;
	//Player *player;
	//Block *block;

	Player *player1;
	Player *player2;
	Block *block1;
	Block *block2;
	Block *block3;
	Block *block4;
	Block *block5;
	Block *block6;
	//Block *block7;
	//Block *block8;
	//Block *block9;
	CollisionSystemDouble *collisionSystem;

public:
	bool want_grid = false;
};

//#endif
