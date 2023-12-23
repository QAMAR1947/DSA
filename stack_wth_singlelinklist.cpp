#include<iostream>
using namespace std;

struct node
{
	int value;
	struct node* link;
}*top = NULL;

// Function to check underflow
int is_Empty()
{
	if(top == NULL)
	{
		return 1;	
	}
	else
	{
		return 0;
	}	
}

// Inserting value at the beginnig
void push(int x)
{
	node *temp = new node();
	temp->value = x;
	temp->link = NULL;
	
	temp->link = top;
	top = temp;
}

// Deleting value from the beginning and return it
int pop()
{
	if(is_Empty())
	{
		cout<<"Stack underflow";
		return(0);
	}
	else
	{
		node* temp = top;
		top = temp->link;
		int value = temp->value;
		delete(temp);
		return value;	
	}
}

// display the top most element of stack
int peek()
{
	if(is_Empty())
	{
		cout<<"Stack Underflow";
		return false;
	}
	else
	{
		node* temp = top;
		return temp->value;
	}
}

// display the elements of stack
void display(){
	if(is_Empty())
	{
		cout<<"Stack Underflow";
		return;
	}
	else
	{
		node* temp = top;
		while(temp!= NULL)
		{
			cout<<temp->value<<", ";
			temp= temp->link;
		}
	}
}

// MAIN Function
int main()
{
	push(3);
	push(4);
	push(5);
	push(6);
	
	display();
	cout<<"Top element: "<<peek();
	
	pop();
	pop();
	pop();
	pop();
	pop();
	
	return 0;
}
