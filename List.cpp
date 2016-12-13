#include "List.h"
using namespace std;
#include <iostream>


List::List() {
	headP = NULL;
	tailP = NULL;
	length = 0;
}
//Copy List
List::List(const List & input_Node)
{		
	length = 0;
	headP = NULL;
	tailP = NULL;
						
	Node *p = input_Node.headP;

	while (p != NULL) {
			addNode(p->getLetter(), p->getXPos(), p->getYPos());
			p = p->getNext();
	
	}
	
}


List::~List() {
	//Destructor -- free up all used nodes
	Node* curr = headP; //start at head of list
	Node* next;

	while (curr != NULL) { //iterate until end
		next = curr->getNext(); //remember what next one is
		delete curr; //delete the current one
		curr = next; //move to the next one
	}
}

void List::print() {
	Node* currNode;
	currNode = headP;
	while (currNode != NULL) {
		//cout << currNode->getData() << " ";
		cout << currNode->getLetter() << " " << currNode->getXPos() << " " << currNode->getYPos()<<endl;
		currNode = currNode->getNext();
	}
	cout << endl;
}

//void List::addNode(int newData) {
void List::addNode(char input_letter, int input_xpos, int input_ypos) {

	//create the new node
	//Node* newNode = new Node(newData);
	Node* newNode = new Node(input_letter, input_xpos, input_ypos);

	//add it to the tail of the list
	if (tailP == NULL)
		//list was empty
		headP = tailP = newNode;
	else {
		//list not empty
		tailP->setNext(newNode);
		tailP = newNode;
	}
	length++;
}

//bool List::removeNode(int _data) {
bool List::removeNode(char input_letter) {
	//Scan the list looking for 1st occurrence of data
	Node* curr = headP;
	Node* prev = headP;

	while (curr != 0) {
		//if (curr->getData() == _data) {//found it so remove it
		if (curr->getLetter() == input_letter) {
			if (curr == headP) {
				//this is the first element
				headP = curr->getNext();
			}//4
			else {
				//not the first element
				prev->setNext(curr->getNext());
				if (curr == tailP) {
					//this is the last element
					tailP = prev;
				}
			}
			delete curr;
			length--;
			return true;
		}
		//Move to the next one, using prev to remember previous node
		prev = curr;
		curr = curr->getNext();
	}
	//If we get to here then none found
	return false;
}


char List::lockSquare(List Line) {
	//Scan the list looking for 1st occurrence of data
	Node* curr = headP;
	Node* prev = headP;

	while (curr != 0) {
		//if (curr->getData() == _data) {//found it so remove it
	
		if    ((curr->getXPos() == 19 && curr->getYPos() == 10 || curr->getXPos() == 21 && curr->getYPos() == 10 || curr->getXPos() == 23 && curr->getYPos() == 10)
			|| (curr->getXPos() == 19 && curr->getYPos() == 12 || curr->getXPos() == 21 && curr->getYPos() == 12 || curr->getXPos() == 23 && curr->getYPos() == 12)
			|| (curr->getXPos() == 19 && curr->getYPos() == 14 || curr->getXPos() == 21 && curr->getYPos() == 14 || curr->getXPos() == 23 && curr->getYPos() == 14))
		{
			return curr->getLetter();
		}
		//Move to the next one, using prev to remember previous node
		prev = curr;
		curr = curr->getNext();
	}
	//If we get to here then none found
	return 'Q';
}

Node* List::getNode(List Line, int node_num)
{
	Node* curr = headP;

	for (int i = 1; i <= node_num; i++) {
		curr = curr->getNext();
	}
		return curr;
	
}



//**********************************************************

/*

//CollisionLinkedListSingle::CollisionLinkedListSingle(Player *player, Block *block1, Block *block2, Block *block3, int xsize, int ysize)
CollisionLinkedListSingle::CollisionLinkedListSingle( int poop)
{

	
	head = NULL;
	curr = NULL;
	temp = NULL;

	
	mPlayer = player;

	mBlock1 = block1;
	mBlock2 = block2;
	mBlock3 = block3;

	xSize = xsize;
	ySize = ysize;
	


}

CollisionLinkedListSingle::~CollisionLinkedListSingle()
{

}

void CollisionLinkedListSingle::update(Movement::direction d)
{
	Letters = CollisionLinkedListSingle ;

	List.AddNode(mBlock1->getXPos(), mBlock1->getYPos(), 'A');
	Letters.AddNode(mBlock2->getXPos(), mBlock2->getYPos(), 'B');
	Letters.AddNode(mBlock3->getXPos(), mBlock3->getYPos(), 'C');
}
void  CollisionLinkedListSingle::AddNode(int xpos, int ypos, char _letter)
//void  CollisionLinkedListSingle::AddNode(Player *player, Block *block1, Block *block2, Block *block3, int xsize, int ysize)
{

	nodePtr n = new node;
	n->next = NULL;
	//n->pointer = *block1;
	n->letter = _letter;
	n->xpos = xpos;
	n->ypos = ypos;

	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
	}
	else
	{
		head = n;
	}
}


void CollisionLinkedListSingle::PrintList()
{
	curr = head;
	while (curr != NULL)
	{
		cout << curr->letter <<" "<< curr->xpos<<" "<<curr->ypos<< endl;
		curr = curr->next;
	}
}

void CollisionLinkedListSingle::MakeList(Block *block1, Block *block2, Block *block3)
{


	cout << "ITS HAPPENING";
}

/*


CollisionLinkedListSingle::~CollisionLinkedListSingle()
{

}

void CollisionLinkedListSingle::update(Movement::direction d)
{
	switch (d)
	{
		//************UP******************
	case Movement::Up:

		for (int i = 1; i <= 3; i++) {
			if (mPlayer->getXPos() == mBlock(i)->getXPos() && mPlayer->getYPos() == mBlock(i)->getYPos())
			{
				mBlock(i)->setYPos(mBlock(i)->getYPos() - 1);// -1 = BLOCK TRAVEL DISTANCE
				mPlayer->setCollisions(mPlayer->getCollisions() + 1);
			}
		}
		*/