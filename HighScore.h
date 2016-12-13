#pragma once

#include <string>
using namespace std;
//To read in name and score
//Write to a text file in order of score value
//print text file when requested

class HighScore
{
public:
	//CollisionSystem(Player *player, Block *block, int xsize, int ysize);
	HighScore(int score, string name);
	~HighScore();

private:

	int score;
	string name;
	int rank;

	
};