#include "Background.h"

//Block::Block(int xpos, int ypos) : Object(xpos, ypos)
Background::Background(int xpos, int ypos, char _letter) : Object(xpos, ypos)
{

	letter = _letter;
}

Background::~Background()
{

}

void Background::update()
{

}