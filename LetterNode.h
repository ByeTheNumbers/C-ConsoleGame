#pragma once
#include <iostream>
using namespace std;

class Node {
private:
	//int data;		//a number
	char letter; //STORES THE OBJECT LETTER
	int xpos;
	int ypos;

	Node* nextP;	//a pointer to the next node
public:
	//Node(int newData);	//set the data to the integer passed in
	Node(char input_letter, int input_xpos, int input_ypos);
	//int getData();		//return the value of data
	char getLetter();
	int getXPos();
	int getYPos();
	Node* getNext();	//return the value of the next pointer
	void setNext(Node* _next);	//set the value of the next pointer

	void setXPos(int x);
	void setYPos(int y);
};
