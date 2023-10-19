#include<iostream>
using namespace std;

struct queue{
	int data;
	queue* next;
};

// INSERT NODE AT END
void push(struct queue* &front,struct queue* &end,int x){
	queue* node = new queue();
	node->data = x;
	node->next = NULL;
	
	if(front == NULL){
		front = node;
		end = node;
		return;
	}
	
	end->next = node;
	end = node;
		
}

// DELETE NODE AT BEGINING
int pop(struct queue* &front,struct queue* &end){
	if(front == NULL){
		cout<<"Queue Underflow"<<endl;
		return 0;
	}
	
	queue* temp = front;
	front = front->next;
	int x = temp->data;
	delete(temp);
	
	return x;
	
}

int main(){
	queue* front = NULL;
	queue* end = NULL;
	
	push(front,end,10);
	push(front,end,11);
	push(front,end,12);
	
	cout<<pop(front,end)<<endl;
	cout<<pop(front,end)<<endl;
	cout<<pop(front,end)<<endl;
	cout<<pop(front,end)<<endl;
	
	
	
	
	return 0;
}
