#pragma once

#include <string>
//To read in name and score
//Write to a text file in order of score value
//print text file when requested

class HighScore
{
public:
	//CollisionSystem(Player *player, Block *block, int xsize, int ysize);
	HighScore();
	~HighScore();

private:

	int score;
	string name;
	int rank;

	
};