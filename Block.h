#ifndef BLOCK_H
#define BLOCK_H

#include"Object.h"
class Block : public Object
{
public:
	//Block(int xpos, int ypos);
	Block(int xpos, int ypos, char _letter);
	~Block();

	void update();

	void setCollisions(int c);
	int getCollisions() const;

	//void AddNode(int xpos, int ypos, char _letter);
	//void PrintList();

private:
	int collisions;
	//Block* next;

//	Block* head;
//	Block* curr;
//	Block* temp;

};



#endif