#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Player : public Object //INHERITANCE
{
public:
	Player(int xpos, int ypos);
	//Player(int xpos, int ypos, char letter);
	~Player();

	void update(Movement::direction d);

	void setCollisions(int c);
	int getCollisions() const;
	
private:
	int collisions;
};

#endif
