#include "Block.h"

//Block::Block(int xpos, int ypos) : Object(xpos, ypos)
Block::Block(int xpos, int ypos, char _letter) : Object(xpos, ypos)
{
	
	letter = _letter;
	
}

Block::~Block()
{

}

void Block::update()
{

}

void Block::setCollisions(int c)
{
	collisions = c;
}

int Block::getCollisions() const
{
	return collisions;
}