#include "GameSingle.h"//CHECK
#include "GameDouble.h"
#include "List.h"
#include <iostream>
using namespace std;

int main() 
{


	int number_of_players;
	cout << "1 Player or 2 Player? ";
	cin >> number_of_players;

	if (number_of_players == 1)
	{
		GameSingle game;
		game.run();

		return 0;
	}
	else
	{
		//List mLine = Line;
		GameDouble game;
		game.run();

		return 0;
	}
	
	
}