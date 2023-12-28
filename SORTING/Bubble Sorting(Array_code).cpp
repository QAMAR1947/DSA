/*
	Bubble sorting
	Array Code
	Author : Qamar
*/
#include<iostream>
using namespace std;

int main()
{
	int size;
	cout<<"Enter the size of Array"<<endl;
	cin>>size;
	int array[size];
	
	cout<<"Enter ["<<size<<"] elements in array"<<endl;
	for(int i=0; i<size; i++)
	{
		cin>>array[i];
	}
	
	cout<<"Your array contains elements: ";
	for(int i=0; i<size; i++)
	{
		cout<<array[i]<<", ";
	}
	
	cout<<"Bubble Sort is Applied Successfully"<<endl;
	int counter = 1;
	
	while(counter <= size-1)
	{
		for(int i=0; i<size-counter; i++)
		{
			if(array[i] > array[i+1])
			{
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
		}
		counter ++;
	}
	
	cout<<"Your array contains elements: ";
	for(int i=0; i<size; i++)
	{
		cout<<array[i]<<", ";
	}
	
	return 0;
}
