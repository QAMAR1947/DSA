#include <iostream>
using namespace std;

// TOH FUNCTION
void toh(int disk, char source, char temp, char dest){
	if(disk > 0){
		toh(disk-1, source, dest, temp);
		cout<<"\nMOVE DISK \n"<<disk<<source<<dest;
		toh(disk-1, temp, source, dest);
	}
	
}

// MAIN FUNCTION
int main(){
	
	char source = 's', temp = 't', dest = 'd';
	int disk;
	
	cout<<"Enter size of disk"<<endl;
	cin>>disk;
	cout<<"sequence is: "<<endl;
	toh(disk, source, temp, dest);
	
	return 0;
}
