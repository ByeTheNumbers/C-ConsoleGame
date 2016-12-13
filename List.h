#pragma once

#include "LetterNode.h"
#include "Player.h"
#include "Block.h"


// WE WANT TO CREATE A LINKED LIST WITH THE FOLLOWING DATA: CHAR LETTER, INT XPOS, INT YPOS
class List {
private:
	Node* headP;	//a pointer to the first node in list
	Node* tailP;	//a point to the last node in list
	int length;		//the length of the list
public:
	List();			//Constructor to create an empty list
	List(const List & input_Node);
	~List();		//Destructor that deletes all nodes in the list
	//void addNode(int newData);	//Add a node to the end of the list
	void addNode(char input_letter, int input_xpos, int input_ypos);
	//bool removeNode(int _data);	//Remove a node that contains the integer passed in
	char lockSquare(List Line);
	bool removeNode(char input_letter);
	void print();	//Print out all the data values in the list
	Node* getNode(List Line, int node_num);
};




/*

class CollisionLinkedListSingle
{
public:
	//CollisionLinkedListSingle(Player *player, Block *block1, Block *block2, Block *block3, int xsize, int ysize);
	CollisionLinkedListSingle(int poop);
	~CollisionLinkedListSingle();

	void update(Movement::direction d);
	//CollisionLinkedListSingle(Player *player, Block *block1, Block *block2, Block *block3, int xsize, int ysize);
	void AddNode(int xpos, int ypos, char _letter);
	//void AddNode(Player *player, Block *block1, Block *block2, Block *block3, int xsize, int ysize);
	void PrintList();
	void CollisionLinkedListSingle::MakeList(Block *block1, Block *block2, Block *block3);
	//~CollisionLinkedListSingle();


private:

	typedef struct node 
	{
		char letter;
		int xpos;
		int ypos;

		//Block pointer;
		node* next;
	}* nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
	

//	CollisionLinkedListSingle  Letters;

	Player *mPlayer;
	//Block *mBlock;
	Block *mBlock1;
	Block *mBlock2;
	Block *mBlock3;

	int xSize;
	int ySize;
};

*/