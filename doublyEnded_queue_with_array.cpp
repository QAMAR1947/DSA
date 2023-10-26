#include<iostream>
#define MAX 5
using namespace std;

// declaring variables to control queue
int front = -1;
int rear = -1;
int *array;	// pointer array that will store address of 0 index
int isFull(); // definition of function
int isEmpty(); // definition of function


// creating enqueue/push_rear function
void enqueue(int arr[], int val){
	
	// case 1 -> queue is full
	if(isFull()){
		cout<<"queue is full";
		return;
	}
	
	else if(front == -1){
		front = rear = 0;
	}
	
	// to maintain cyclic nature
	else if(rear == MAX-1 && front != 0){
		rear = 0;
	}
	
	// normal flow
	else{
		rear ++;
	}
	
	// push element in queue
	arr[rear] = val;
	return;
}

// creating pushfront fucntion
void pushFront(int arr[], int val){
	
	if(isFull()){
		cout<<"queue is FUll";
		return;
	}
	
	else if(front == -1){
		front = rear = 0;
	}
	
	else if(front == 0){
		front = MAX-1;
	}
	
	else{
		front --;
	}
	
	// push element  in queue
	arr[front] = val;
	return;
}

// creating poprear function
void popRear(){
	if(isEmpty()){
		cout<<"Queue is empty";
		return;
	}
	
	else if(front == 0){
		front = rear = -1;
	}
	
	else if(rear == 0){
		rear = MAX-1;
	}
	
	else
	rear --;
}
// creating dequeue/pop_front function
void dequeue(){
	if(front == -1){
		cout<<"Empty queue";
	}
	
	else if(front == rear){
		front = rear =-1;
	}
	
	// to maintain cyclic nature
	else if(front == MAX-1){
		front = 0;
	}
	
	//normal flow
	else{
		front ++;
	}
	
	return;	
}


// creating IsEmpty function
int isEmpty(){
	if (rear == -1 && front == -1){
		return 1;
	}
	else
	return 0;
}

// crating IsFull function
int isFull(){
	
	if((front == 0 && rear == MAX-1)  || (rear ==(front-1) % (MAX-1) )){
		//cout<<"queue is full";
		return 1;
	}
	else
	return 0;
	
}

// creating front/top function
int Front(){
	if(isEmpty()){
		return -1;
	}
	else
	return array[front];
}


// main function
int main(){
	
	// declaring and initializing array in memory  of size MAX
	array = new int[MAX];
	
	//calling functions
	enqueue(array, 10);
	enqueue(array, 20);
	enqueue(array, 30);
	enqueue(array, 40);
	enqueue(array, 50);
	
	dequeue();
	pushFront(array, 60);
	
	
	
	
	cout<<Front(); 
	
	return 0;
}
