//								***CIRCULAR LINKED LIST***
#include<iostream>
using namespace std;

// CREATING STRUCTURE OF CIRCULAR LINKED LIST
struct NODE{
	int data;
	NODE* next;
};

// CREATING TAIL POINTER THAT WILL STORE LAST NODE
NODE* tail;
// GLOBALLY STORE THE SIZE OF NODES
int count = 0;



//					***FUNCTIONS***

// INSERT NODE AT BEGINING
void insert_first(int x) {
    NODE* new_node = new NODE();
    new_node->data = x;

    if (tail == NULL) {
        new_node->next = new_node;
        tail = new_node;
    } else {
        new_node->next = tail->next;
        tail->next = new_node;
    }

    count++;
}

// ISERTING NODE AT THE END
void insert_end(int x){
	NODE* new_node = new NODE();
	new_node->data = x;
	
	if(tail == NULL){
		new_node->next = new_node;
		tail = new_node;
	}
	else{
		NODE* temp = tail;
		new_node->next = tail->next;
		temp->next = new_node;
		tail = new_node;
	}
	
	count ++;
}

// DELETE FIRST NODE
void delete_first(){
	// IF THERE IS NO NODE (CORNER CASE)
	if(tail == NULL){
		cout<<"LIST IS EMPTY";
		return;
	}
	
	// IF ONLY 1 NODE EXIST (CORNER CASE)
	if(tail->next == tail){
		delete(tail);
		tail = NULL; 
		count --;
		return;
	}
	
	NODE* temp = tail->next;
	tail->next = temp->next;
	delete(temp);
	
	count --;
}

// DELETE LAST NODE OF LIST
void delete_last(){
	// IF NO NODE EXIST
	if(tail == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		return;
	}
	
	// IF ONEY 1 NODE EXIST
	if(tail->next == tail){
		delete(tail);
		tail = NULL;
		count --;
		return;
	}
	
	NODE* temp = tail->next;
	while(temp->next != tail){
		temp = temp->next;
	}
	temp->next = tail->next;
	delete(tail);
	tail = temp;
	
	count --;
}

// TRAVERSING AND PRINTING 
void print() {
    if (tail == NULL) {
        cout <<"\nLIST IS EMPTY NOW" << endl;
        return;
    }

    NODE* temp = tail->next;
    cout << "\nLIST IS: ";
    do {
        cout << temp->data << ", ";
        temp = temp->next;
    } while (temp != tail->next);
}

int main(){
	tail = NULL;
	
	insert_end(10);
	insert_end(11);
	insert_end(12);
	insert_end(13);
	
	print();
	cout<<"\n\nTOTAL NUMBER OF NODES : "<<count;
	
	delete_last();
	print();
	
	cout<<"\n\nTOTAL NUMBER OF NODES : "<<count;
	
	return 0;
}
