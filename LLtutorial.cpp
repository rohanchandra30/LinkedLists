// forward_list::push_front
#include <iostream>
#include <cstdlib>
#include "LLtutorial.h"
#include <queue>
#include <stack>
using namespace std;



	LinkedList::LinkedList(){
		head=NULL;
		curr=NULL;
		temp=NULL;
	}
	int LinkedList::numberofnodes(){
		int count=0;
		for(p=head;p!=NULL;p=p->next){count++;}
			return count;
	}
LinkedList::node *LinkedList::setptrtolast(){
		p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		return p;
	}


LinkedList::node *LinkedList::getPtrforKthNode(int k){

	p=head;

while(p->data!=k){
			p=p->next;
		}
		return p;
	}


	void LinkedList::reverse(){
		curr=NULL;
		temp=NULL;
		while(head->next!=NULL){
			curr=head->next;
			head->next=temp;
			temp=head;
			head=curr;
		}
		head->next=temp;
	}
	void LinkedList::rotate(int k){
		int i;
		int m=numberofnodes()- k%numberofnodes();
		for (curr=head,temp=head->next,i = 0; i < m-1; ++i,curr=curr->next,temp=temp->next);
			setptrtolast()->next=head;
			curr->next=NULL;
			head=temp;
			}
	void LinkedList::detectcycle(){
		curr=head;
		temp=head->next;
		while(temp->next){
			curr=curr->next;
			temp=temp->next->next;
			if (curr==temp)
			{
				cout<<"cycle detected!"<<"\n";
				break;
			}
		}
			cout<<"no cycles present"<<"\n";		
	}

	void LinkedList::groupoddeven(){

		nodePtr n=head->next;
		nodePtr m=head;
		int k=1;
		while(m->next!=NULL){
			m=m->next;
			k++;
		}
		curr=head;
		temp=head->next;
		if (k%2==0)
		{
			while(temp->next!=NULL){
			curr->next=temp->next;
		curr=temp->next;
			temp->next=curr->next;
		temp=curr->next;
		}
// cout<<curr->data<<temp->data;
		temp->next=NULL;
		curr->next=n;
		}
		else{
			while(temp->next->next!=NULL){
				curr->next=temp->next;
		curr=temp->next;
			temp->next=curr->next;
		temp=curr->next;
			}
			curr->next=temp->next;
			curr=curr->next;
			temp->next=NULL;
			curr->next=n;
		}
	}

void LinkedList::AddNodetoTail(int addData){
		nodePtr n= new node;
		n->next=NULL;
		n->data=addData;

		if (head!=NULL)
		{	
			curr=head;
			while(curr->next!=NULL){
				curr=curr->next;
			}

			curr->next=n;

		}

		else{
			head=n;
		}
}

void LinkedList::AddNodetoHead(int addData){
nodePtr n=new node;
if (head==NULL)
{
	n->next=NULL;
	n->data=addData;
	head=n;
}
else{
n->next=head;
n->data=addData;
head=n;
}
}

void LinkedList::AddNodeinBetween(int addData, int pos){
if (pos==1)
{
	AddNodetoHead(addData);
}
if (pos==numberofnodes())
{
	AddNodetoTail(addData);
}
	nodePtr n=new node;
	n->data=addData;
	int i=1;
	curr=head;
	while(curr!=NULL && i<pos){
		i++;
		temp=curr;
		curr=curr->next;

	}
	temp->next=n;
	n->next=curr;

}


int LinkedList::DeleteNode(int delData){
		nodePtr delPtr=NULL;
		if (delData==head->data)
		{
			delPtr=head;
			head=head->next;

			delete delPtr;
		}

		else{

			for (temp=head,curr=head->next;curr!=NULL && !(curr->data==delData);temp=temp->next,curr=curr->next);
			
				if (curr!=NULL)
				{
					delPtr=curr;
					temp->next=curr->next;
					if (curr->next==NULL)
					{
						temp->next=NULL;
					}
					delete delPtr;
				}
			
		}
		return delData;
}

int LinkedList::DeletePos(int k){
		nodePtr delPtr=NULL;
		int i,dat;
		if (k==1)
		{
			delPtr=head;
			head=head->next;
			dat=delPtr->data;
			delete delPtr;
		}

		else{

			for (temp=head,curr=head->next,i=1;curr!=NULL && !(i==k-1);temp=temp->next,curr=curr->next,i++);
			
				if (curr!=NULL)
				{
					dat=curr->data;
					delPtr=curr;
					temp->next=curr->next;
					if (curr->next==NULL)
					{
						temp->next=NULL;
					}
					delete delPtr;
				}
			
		}
		return dat;
}
void LinkedList::fillup(){
	queue<int> Q;
	stack<int> S,S1;
	nodePtr n;
while(head!=NULL){
	Q.push(DeletePos(1));
}	
S.push(Q.front());
Q.pop();
	while(!Q.empty()){
		if (Q.front()!=S.top())
		{
			S.push(Q.front());
			Q.pop();
		}
		else{
			Q.pop();
		}
	}
	while(!S.empty()){
		S1.push(S.top());
		S.pop();
	}
while(!S1.empty()){
	AddNodetoTail(S1.top());
	S1.pop();
}
}

void LinkedList::MoveNode(int c,int d){
DeleteNode(d);
if (c==1)
{
	AddNodetoHead(d);
}
else if (c==numberofnodes())
{
	AddNodetoTail(d);
}
else{
	AddNodeinBetween(d,c);
}
}

void LinkedList::swap(int swapdata1, int swapdata2){

nodePtr n=new node;
nodePtr m=new node;
curr=head;
temp=head;
int count1=0;
int count2=0;

if(head->data!=swapdata1 && head->data!=swapdata2){
for(curr=head;curr->next->data!=swapdata1;curr=curr->next){count1++;}
for(temp=head;temp->next->data!=swapdata2;temp=temp->next){count2++;}
	
if (temp->next->next!=NULL &&curr->next->next!=NULL)
{
if(count1<count2){
n=curr->next;
m=temp->next->next;
curr->next=temp->next;
temp->next=n;
curr->next->next=n->next;
n->next=m;
}
else if(count2<count1){
n=temp->next;
m=curr->next->next;
temp->next=curr->next;
curr->next=n;
temp->next->next=n->next;
n->next=m;
}

}

//this else takes effect when one of the nodes is in terminal node..
else{
	if (count1<count2)
		if (curr->next!=temp)
		{
			n=curr->next;
	curr->next=temp->next;
	curr->next->next=n->next;
	temp->next=n;
	n->next=NULL;
	temp->next=n;
		}
	else{
			curr->next=temp->next;
			curr->next->next=temp;
			temp->next=NULL;
		}
	if (count2<count1)
	if(temp->next!=curr){
	n=temp->next;
	temp->next=curr->next;
	temp->next->next=n->next;
	curr->next=n;
	n->next=NULL;
	curr->next=n;
	}
	else{

		temp->next=curr->next;
			temp->next->next=curr;
			curr->next=NULL;
		}
	}

}
//this else takes effect when one of the nodes is the head..
else{
	if (head->data==swapdata1)
	{
		for(temp=head;temp->next->data!=swapdata2;temp=temp->next){count2++;}
			if (temp!=curr)
			{
					m=temp->next->next;
			n=curr->next;
			head=temp->next;
			head->next=n;
			temp->next=curr;
			curr->next=m;
			}
			else{
				m=temp->next->next;
				head=temp->next;
				head->next=temp;
				temp->next=m;

			}
		
	}
	else if (head->data==swapdata2)
	{
		for(curr=head;curr->next->data!=swapdata1;curr=curr->next){count1++;}
			if(curr!=temp){m=curr->next->next;
			n=temp->next;
			head=curr->next;
			head->next=n;
			curr->next=temp;
			temp->next=m;}
			else{
				m=curr->next->next;
				head=curr->next;
				head->next=curr;
				curr->next=m;

			}
	}
}
}

void LinkedList::partition(int k){
	queue<int> Q;
	nodePtr m=head;
	nodePtr p=head->next;

	while(p->next!=NULL){
		if (p->data<k)
		{
			m=m->next;
			p=p->next;
		}
		else if (p->data>=k)
		{
			m->next=p->next;
			Q.push(p->data);
			p=p->next;
		}

	}
	if (p->data>=k)
	{
		Q.push(p->data);
		p=m;
		m->next=NULL;
	}

	while(!Q.empty()){

		AddNodetoTail(Q.front());
		Q.pop();
		p=p->next;
	}

	p->next=NULL;
	
	if (head->data>=k)
	{
		nodePtr n=new node;
		n->data=head->data;
		if(m->next->data<k)
		{n->next=m->next->next;
		m->next->next=n;}
		else{
			n->next=m->next;
		m->next=n;
		}
		DeletePos(1);
	}
	
}

void LinkedList::swappairs(){

	for (int i = 1; i <numberofnodes()-1; i=i+2)
	{
		swap(i,i+1);
	}


	
}
int LinkedList::PrintKthNode(int k){
int i;
	for (curr=head, i = 0; i < k-1; ++i,curr=curr->next);
	return curr->data;

}
void LinkedList::PrintList(){

curr=head;
while(curr!=NULL){
cout<<curr->data<<"\n";
curr=curr->next;
} 
}
