#include<iostream>
using namespace std;

struct NODE{
	int data;
	NODE* next;
};

// CHECK IF STACK IS EMPTY
void isEmpty(struct Node* &top){
	if(top == NULL){
		cout<<"STACK UNDERFLOW"<<endl;
	}
}

// TO INSERT NODE AT BEGINING OF STACK
void push(struct NODE* &top, int x){
	NODE* new_node = new NODE();
	
	new_node->data = x;
	new_node->next = top;
	top = new_node;
}

// TO REMOVE NODE FROM STACK
int pop(struct NODE* &top){
	if(top == NULL){
		cout<<"STACK UNDERFLOW"<<endl;
		return 0;
	}
	
	NODE* temp = top;
	top = top->next;
	int x = temp->data;
	delete(temp);
	
	return x;
}

// TO DISPLAY NODES OF STACK
void display(struct NODE* &top){
	if(top == NULL){
		cout<<"STACK UNDERFLOW"<<endl;
		return;
	}
	
	NODE* temp = top;
	while(temp != NULL){
		cout<<temp->data<<", ";
		temp = temp->next;
	}
	cout<<"\n";
	
}
int main(){
	NODE* top = NULL;
	
	push(top, 5);
	push(top, 6);
	push(top, 7);
	
	display(top);
	
	cout<<pop(top);
	
	return 0;
}
