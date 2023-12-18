#include<iostream>
using namespace std;
struct edge{
	char dest;
	edge *link=NULL;
};

struct node{
	char name;
	edge *adj = NULL;
	node *next = NULL;
}*start = NULL;

// Insertion of node in Graph
void insert_node(char ch){
	node *temp = new node();
	temp->name = ch;
	node *ptr = start;
	
	if(ptr = NULL)
	{
		start = temp;	
	}
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
}

// find function
node *find(char ch)
{
	node *ptr = start;
	while(ptr != NULL)
	{
		if(ptr->name == ch)
		{
			break;
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return ptr;
}

//	insertion of edge in Graph 
void insert_edge(char source, char dest)
{
	edge *ptr;
	edge *temp = new edge();
	node *u = find(source);
	node *v = find(dest);
	if(u == NULL)
	{
		cout<<"source dosen't exist";
		return;	
	}
	else if(v == NULL)
	{
		cout<<"destination dosen't exist";
		return;	
	}
	temp->dest =dest;
	if(u->adj == NULL)
	{
		u->adj =temp;
		return;
	}
	ptr = u->adj;
	while(ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = temp;
}

// deletion of node in Graph
void delete_node(char ch)
{
	node *q = start;
	node *temp;
	if(q->name == ch)
	{
		temp = start;
		start = start->next;
		delete(temp);
		return;
	}
	while(q->next->next != NULL)
	{
		if(q->next->name == ch)
		{
			temp = q->next;
			q->next = q->next->next;
			delete(temp);
			return;
		}
		q = q->next;
	}
	if(q->next->name == ch)
	{
		temp = q->next;
		q->next = NULL;
		delete(temp);
		return;
	}
}

//	deletion of edge in Graph 
void delete_edge(char source, char dest)
{
	node *u, *v;
	edge *eptr, *temp, *q;
	u = find(source);
	if(u == NULL)
	{
		cout<<"source dosen't exist";
		return;	
	}
	if(u->adj->dest = dest)
	{
		temp = u->adj;
		u->adj = u->adj->link;	// first element deleted
		delete(temp);
		return;
	}
	q = u->adj;
	while(q->link->link != NULL)
	{
		if(q->link->dest == dest)	// element deleted in between
		{
			temp = q->link;
			q->link = temp->link;
			delete(temp);
			return;
		}
		q = q->link;
	}
	if(q->link->dest == dest)	//element deleted in last
	{
		temp = q->link;
		delete(temp);
		q->link = NULL;
		return;
	}
	cout<<"This edge doesn't present in Graph";
}

// function to display
void display()
{
	node *ptr;
	edge *q;
	
	ptr = start;
	while(ptr != NULL)
	{
		cout<<ptr->name;
		q = ptr->adj;
		while(q != NULL)
		{
			cout<<q->dest;
			q = q->link;
		}
		cout<<endl;
		ptr = ptr->next;
	}
}

int main()
{
	insert_node('a');
	insert_node('b');
	
	display();
	return 0;
}