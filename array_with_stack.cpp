#include<iostream>
#define MAX 5
using namespace std;

// declaring fix size array
int stack_arr[MAX];
int top = -1;

// creating function to insert element in stack
void push(int x){
	if(top == MAX-1){
		cout<<"STACK OVERFLOW"<<endl;
		return;
	}
	top++;
	stack_arr[top] = x;
}

// creating function to remove element from stack
void pop(){
	if(top == -1){
		cout<<"STACK UNDERFLOW"<<endl;
		return;
	}
	top--;
}

// creating function to return top value
int Top(){
	if(top == -1){
		cout<<"No elements in Stack"<<endl;
		return -1;
	}
	
	return stack_arr[top];
}
int main(){
	push(2);
	push(3);
	push(4);
	
	pop();
	
	cout<<Top();
	
	return 0;
}
