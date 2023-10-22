// CODE FOR LINEAR SEARCH IN ARRAY
#include <iostream>
using namespace std;

// FUNCTION FOR LINEAR SEARCH
int LinearSearch(int arr[], int s, int k){
	
	for(int i=0; i<s; i++){
		
		// condition to check if value is pressent or not
		if(arr[i] == k){
			// return the index of that value
			return i;;
		}
		
	}
	// otherwise return -1
	cout<<"No Value in the Array:";
	return -1;
}
int main(){
	// declare variable for size and take size as input from user
	int size;
	
	cout<<"ENTER SIZE OF ARRAY"<<endl;
	cin>>size;
	
	// declare array of size
	int arr[size];
	
	// loop to insert values at each index of array given by user
	cout<<"ENTER "<<size<<" VALUES"<<endl;
	for(int i=0; i<size; i++){
		cin>>arr[i];
	}
	
	// declare variable to take value to check if it's present in array or not
	int key;
	
	cout<<"ENTER VALUE YOU WANT TO SEARCH FOR: "<<endl;
	cin>>key;
	
	// calling LINEARSEARCH function
	cout<<"Value is at Index: "<<LinearSearch(arr, size, key);
	
	
	return 0;
}
