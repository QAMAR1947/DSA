#include<iostream>
using namespace std;

struct node{
	int value;
	struct node* link;
}*front = NULL, *rear = NULL;

// inserting new element in queue at the end
void enqueue(int x)
{
	node* temp = new node();
	temp->value = x;
	temp->link = NULL;
	
	// if queue is empty
	if(front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}
	else
	{
		rear->link = temp;
		rear = temp;	
		return;
	}
}

// deleting element from queue from beginning and printing it
int dequeue()
{
	if(front == NULL && rear == NULL)
	{
		cout<<"queue is empty";
		return false;
	}
	else if(front == NULL)
	{
		cout<<"Queue underflow";
		return false;
	}
	else
	{
		node* temp = front;
		front = front->link;
		int value = temp->value;	// storing deleted node value to be printed
		delete(temp);
		temp = front;
		
		return value;
	}
}

// funtion to display peek value
void peek()
{
	if(front == NULL && rear == NULL)
	{
		cout<<"Queue is empty";
		return;
	}
	else
	{
		node* temp = front;
		cout<<temp->value;
	}
}

// function to display the elements of queue
void display(){
	if(front == NULL && rear == NULL)
	{
		cout<<"Queue is empty";
		return;
	}
	else
	{
		node* temp = front;
		while(temp != NULL)
		{
			cout<<temp->value<<", ";
			temp = temp->link;
		}
	}
}

// MAIN Function
int main()
{
	enqueue(5);
	enqueue(10);
	enqueue(15);
	enqueue(20);
	
	cout<<"\nelements of queue are: ";
	display();
	
	cout<<"\nPeek value is: ";
	peek();
	
	cout<<"\nDequeuing elements: ";
	cout<<dequeue();
	cout<<dequeue();
	cout<<dequeue();
	cout<<dequeue();
	cout<<dequeue();
	
	return 0;
}
