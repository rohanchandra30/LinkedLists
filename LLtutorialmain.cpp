#include <cstdlib>
#include <iostream>
#include "LLtutorial.h"
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	
	// int x=atoi(argv[1]);
	// int y=atoi(argv[2]);

	LinkedList ListObj;
	//LinkedList ListObj1;
	ListObj.AddNodetoTail(1);
	ListObj.AddNodetoTail(2);
	ListObj.AddNodetoTail(3);
	ListObj.AddNodetoTail(4);
	ListObj.AddNodetoTail(5);
	ListObj.AddNodetoTail(6);
	ListObj.AddNodetoTail(7);
	ListObj.AddNodetoTail(8);
	ListObj.AddNodetoTail(9);
	ListObj.AddNodetoTail(10);
	ListObj.AddNodetoTail(11);
	// for (int i = 1; i <10; i=i+2)
	// {
	// 	ListObj.swap(i,i+1);
	// }
	 // cout<<ListObj.numberofnodes();
	//ListObj.DeleteNode(10);
	//ListObj.swappairs();
	//ListObj.AddNodeinBetween(x,y);
	
	//cout<<ListObj.returnN(8)<<"\n";
	//ListObj.groupoddeven();
	//ListObj.fillup();
	// ListObj.setptrtolast();
	//cout<<ListObj.setptrtolast();
	//cout<<ListObj.PrintKthNode(1);
	//ListObj.rotate(1234);
	//ListObj.partition(50);
	ListObj.MoveNode(11,9);

	ListObj.PrintList();




	return 0;
}
