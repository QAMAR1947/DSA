/*
	Insertion sorting
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
	
	cout<<"\n\n";
	cout<<"Insertion Sort is Applied Successfully"<<endl;
	
	// start from 2nd index
	for(int i=1; i<size; i++)
	{
		int current = array[i];		// to be replaced at the end
		int j = i-1;
		
		// while the 1st element is greator than the next the loop will keep running
		while(array[j] > current && j>= 0)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = current;
	}
	
	cout<<"Now, Your array contains elements: ";
	for(int i=0; i<size; i++)
	{
		cout<<array[i]<<", ";
	}
	
	return 0;
}
