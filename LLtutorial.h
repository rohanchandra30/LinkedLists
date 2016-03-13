#ifndef LLTUTORIAL_H
#define LLTUTORIAL_H

#include <iostream>
#include <cstdlib>

class LinkedList
{

private:

typedef struct node
{
	int data;
	node* next;
}* nodePtr;

nodePtr head;
nodePtr curr;
nodePtr temp;
nodePtr p;

public:
	
//constructor for declaring initial vaues of head, curr and temp.
	LinkedList();

//add a node at the end and place a value in it
	void AddNodetoTail(int addData);
//add a node in the beginning
	void AddNodetoHead(int addData);
//add a node in between..
	void AddNodeinBetween(int addData,int pos);
//delete node
 	int DeleteNode(int delData);
//swap 2 nodes..
 	void swap(int swapdata1, int swapdata2);
//Print List
	void PrintList();	
//reverse the list
	void reverse();
// group odd and even terms..
	void groupoddeven();
//detect cycles..
	void detectcycle();
//delete node by position..
	int DeletePos(int k);
//void fill up queue..
	void fillup();
//find the number of nodes..
	int numberofnodes();
//swap in pairs..
	void swappairs();
//set pointer to last node..
	node *setptrtolast();
//Print out the Kth node..
	int PrintKthNode(int k);
//rotate by k..
	void rotate(int k);
//partition list..
	void partition(int k);
///moves a node to a desired location..
	void MoveNode(int c, int d);
//get ptr for kth node..
	node *getPtrforKthNode(int k);
};

#endif 