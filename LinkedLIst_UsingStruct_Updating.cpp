//Linked list using structure 

//#include "stdafx.h"
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *nxt;
};
node *head = NULL;

void InsertAtEnd(int val)
{
	node *n = new node; 
	n->data = val;
	if (head == NULL)
	{
		head = n;
	}
	else
	{
		node *temp;
		temp = head;

		while (1)
		{
			if (temp->nxt == NULL)
			{
				break;
			}
			else
				temp = temp->nxt;
		}
		temp->nxt = n;
	}
	n->nxt = NULL;
}

void InsertAtStart(int val)
{
	node *n = new node;
	n->data = val;
	if (head == NULL)
	{
		head = n; 
		n->nxt = NULL;
	}
	else
	{
		n->nxt = head;
		head = n;
	}
}
void DelAtEnd()
{
	node *temp = head;
	if (temp==NULL || temp->nxt==NULL)
	{
		head = NULL;
		cout << "Linked list is empty" << endl;
	}
	else
	{

		while (temp->nxt->nxt != NULL)
		{
			temp = temp->nxt;
		}
		temp->nxt = NULL;
	}
}
void DelAtStart()
{
	if (head != NULL)
	{
		head = head->nxt;
	}
}
void InsertAtPos(int pos , int val)
{
    node *n = new node;
    node *temp = head;
    for(int i = 0 ; i<pos-1 ; i++)
    {
        temp = temp->nxt;
    }
    if(pos == 0 )
    {
        n->nxt = temp;
        head  = n;
    }
    else
    {
        n->nxt = temp->nxt;
        temp->nxt = n;
    }
    n->data = val;
}
void show()
{
	node *temp = head;
	if (head == NULL)
		cout << "NULL";
	else
	{
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->nxt;
		}

	}
}

void DelFrPos()
{
	node *temp = head;
	
	cout<<"enter the position from where you want to delete : ";
	int pos; cin>>pos;

	for(int i=0 ; i<pos-1 ; i++)
		temp = temp->nxt;

	if(pos==0)
	{
		head = temp->nxt;
	}
	else
	{
		temp->nxt= temp->nxt->nxt;
	}
}
void Insert(int input)
{
	cout << "Enter the no. of value you want to input : ";
	int n,val;
	cin >> n;
	int pos;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		switch (input)
		{
		case 1: InsertAtEnd(val); break;
		case 2: InsertAtStart(val); break;
		case 5: cout<<"Enter the position : "; cin>>pos; InsertAtPos(pos, val); break;
		}
	}
}

void Rev(node *temp)
{
	if(temp->nxt==NULL)
	{
		cout<<temp->data<<" ";
		return ; 
	}
	else
		Rev(temp->nxt);
	cout<<temp->data<<" ";
}

int main()
{
Again:
	system("cls");
	cout << "Linked List is : "; show();
	cout <<endl<<endl<< "1) Enter element at end "<<endl<<
	"2) Enter Element at start " <<endl<<
	"3) Delete Element from end "<<endl<<
	"4) Delete Element from start"<<endl<<
	"5) Enter an element at particular position "<<endl<<
	"6) Delete Node from particular position"<<endl<<
	"7) Print the current list in reverse"
	<<endl<<"0) Exit"<< endl << endl;
	
	int input;
	cout << "Enter your choise : ";
	cin >> input;

	switch (input)
	{
	case 1: Insert(input); break;
	case 2: Insert(input); break;
	case 3: DelAtEnd();	break;
	case 4: DelAtStart(); break;
	case 5: Insert(input); break;
	case 6: DelFrPos(); break;
	case 7: Rev(head); break;
	case 0: exit(0); break;
	}

	
	goto Again;
	return 0;
}
