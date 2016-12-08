#ifndef GAME_H
#define GAME_H


#include "Field.h"
#include "Player.h"
#include "Block.h"
#include "CollisionSystemSingle.h"
#include "Background.h"


class GameSingle {
public:
	GameSingle();
	~GameSingle();

	void run();

private:
	void draw();
	void input();
	void update();
	void clear();

	bool running;

	char in;
	Movement::direction direction;

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
	Player *player;
	//Block *block;

	Block *block1;
	Block *block2;
	//Block *block3;
	//Block *block4;
	//Block *block5;
	//Block *block6;
	//Block *block7;
	//Block *block8;
	//Block *block9;
	CollisionSystemSingle *collisionSystem;

public:
	bool want_grid = false;
};

#endif