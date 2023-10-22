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

// creating function to check stack is full or not
int isFull(){
	if(top == MAX-1){
		return 1;
	}
	else
	return 0;
}

// creating function to check stack is empty or not
int isEmpty(){
	if(top == -1){
		return 1;
	}
	else
	return 0;
}

// creating function to print all elements of stack
void print(){
	
	for(int i=0; i<= top; i++){
		cout<<stack_arr[i]<<", ";
	}
}

// MAIN FUNCTION
int main(){
	
	int choice,data;
	while(1){
		cout<<"\n";
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Print the Top Element\n";
		cout<<"4. Print all the Element of Stack\n";
		cout<<"5. Quit\n\n";
		cout<<"Please Enter Your Choice"<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter the Element to be Pushed: \n";
				cin>>data;
				push(data);
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				cout<<"The Topmost Element of Stack is : "<<Top();
				break;
				
			case 4:
				print();
				break;
				
			case 5:
				exit(1);
				
			default:
				cout<<"Wrong choice, Please enter correct number"<<endl;
				
		}
	}
	
	return 0;
}
