#include<iostream>
#define MAX 5
using namespace std;

// declaring variables to control queue
int front = 0;
int rear = -1;
int *array;	// pointer array that will store address of 0 index

// creating enqueue/push function
void enqueue(int arr[], int val){
	if(rear == MAX-1){
		cout<<"queue overflow";
		return;
	}
	
	rear ++;
	arr[rear] = val;
}

// creating dequeue/pop function
void dequeue(){
	if(front == MAX){
		cout<<"queue underflow";
		return;
	}
	
	front++;
}

// creating IsEmpty function
int isEmpty(){
	if (rear == -1 || front == MAX){
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

int main(){
	// declaring and initializing array in memory  of size MAX
	array = new int[MAX];
	
	//calling functions
	enqueue(array, 10);
	enqueue(array, 20);
	enqueue(array, 30);
	enqueue(array, 40);
	enqueue(array, 50);
	
	
	cout<<Front(); 
	
	return 0;
}
