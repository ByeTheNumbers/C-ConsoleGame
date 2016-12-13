//Node.cpp
//Implements constructor, getter and setter methods

#include "LetterNode.h"

//Node::Node(int newData) {
Node::Node(char input_letter, int input_xpos, int input_ypos){
	//data = newData; //initialise the data of the new node
	letter = input_letter;
	xpos = input_xpos;
	ypos = input_ypos;

	nextP = NULL;	//doesn't point to anything yet
}

//int Node::getData() { //getter method for the data
//	return data;
//}
char Node::getLetter() {
	return letter;
}

int Node::getXPos() {
	return xpos;
}

int Node::getYPos() {
	return ypos;
}

Node* Node::getNext() { //getter method for pointer to next node
	return nextP;
}

void Node::setNext(Node* _next) { //setter method for pointer to next node
	nextP = _next;
}



void Node::setXPos(int x)
{
	xpos = x;
}

void Node::setYPos(int y)
{
	ypos = y;
}