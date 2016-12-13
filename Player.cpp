#include "Player.h"
#include<iostream>

Player::Player(int xpos, int ypos) : Object(xpos, ypos)
//Player::Player(int xpos, int ypos, char letter) : Object(xpos, ypos)
{
	char initial;
	std::cout << "Enter Initial: ";
	std::cin >> initial;
	letter = initial;
	collisions = 0;
}

Player::~Player()
{

}

void Player::update(Movement::direction d)
{
	switch (d)
	{
	case Movement::Up:
		yPos -= 1;
		break;
	case Movement::Down:
		yPos += 1;
		break;
	case Movement::Left:
		xPos -= 1;
		break;
		case Movement::Right:
		xPos += 1;
		break;
		case Movement::Stay_Still:

 		break;
	}
}

void Player::setCollisions(int c)
{
	collisions = c;
}

int Player::getCollisions() const
{
	return collisions;
}