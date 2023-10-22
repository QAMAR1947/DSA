// CODE FOR LINEAR SEARCH IN ARRAY
#include <iostream>
using namespace std;

// FUNCTION FOR LINEAR SEARCH
int BinarySearch(int arr[], int s, int k){
	
	// declaring variable for starting and ending index of array along with mid
	int st=0;
	int e = s-1;
	int mid;
	
	// condition till st variable becomes >=
	 e variable
	while(st <= e){
		mid = (st + e)/2;
		
		
		// 3 cases to check
		if(k == arr[mid]){
			cout<<"the element is at index : "<<endl;
			return mid;
		}
		else if(k > arr[mid]){
			st = mid+1;
		}
		else if(k < arr[mid]){
			e = mid-1;
		}
	
	}
	
	// if element is not found in the list
	cout<<"element is not found:"<<endl;
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
	
	// calling BINARYSEARCH function
	cout<<BinarySearch(arr, size, key);
	
	return 0;
}
