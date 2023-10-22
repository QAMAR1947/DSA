#include<iostream>
using namespace std;

void sorting(int arr[], int s){
	int temp;
	
	for(int i=0; i<s; i++){
		
		for(int j=i+1; j<s; j++){
			
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	cout<<"\nAFTER SORTING"<<endl;
	for(int i=0; i<s; i++){
		cout<<arr[i]<<", ";
	}
}

int main(){
	int size;
	cout<<"ENTER SIZE OF ARRAY"<<endl;
	cin>>size;
	
	int arr[size];
	
	cout<<"ENTER "<<size<<" VALUES"<<endl;
	for(int i=0; i<size; i++){
		cin>>arr[i];
	}
	
	cout<<"BEFORE SORTING"<<endl;
	for(int i=0; i<size; i++){
		cout<<arr[i]<<", ";
	}
	
	sorting(arr, size);
	
	
	return 0;
}
