//					SINGLE LINKED LIST
#include<iostream>
using namespace std;

// CREATING STRUCTURE OF SINGLE LINKED LIST
struct NODE{
	int data;
	NODE* next;
};

// CREATING START POINTER THAT WILL STORE FIRST NODE
NODE* head;
// GLOBALLY STORE THE SIZE OF NODES
int count = 0;



//					***FUNCTIONS***

// INSERT NODE AT BEGINING
void insert_beg(int x){
	NODE* new_node = new NODE();		//-> CREATE NEW NODE IN MEMORY
	new_node -> data = x;
	new_node -> next = NULL;
	
	// IF THERE IS NO NODE (CORNER CASE)
	if(head == NULL){
		head = new_node;
		count ++;
		return;
	}
	
	new_node->next = head;				//NEW NODE POINTS TOWARDS 1rst NODE
	head = new_node; 
	count ++;
}

// INSERT NODE AT END
void insert_end(int x){	
	NODE* new_node = new NODE();
	new_node -> data = x;
	new_node -> next = NULL; 
	
		// IF THERE IS NO NODE IN LIST (CORNER CASE)
		if(head == NULL){
		head = new_node;
		count ++;
		return;
	}
	
	NODE *current = head;
	
	while(current -> next != NULL){
		current = current->next;
	}
	current->next = new_node;
	
	count ++; 
}

// INSERTING NODE AT SPECIFIC POSITION
void insert_specific(int x, int pos){
	// IF POSITION EXCEEDS THE TOTAL NODES
	if(pos > count){
		cout<<"SORRY! YOUR POSITION IS GREATER THAN TOTAL NODES"<<endl;
	}

	NODE* new_node = new NODE();
	new_node->data = x;
	new_node->next = NULL;
	
	// INSERTING AT FIRST INDEX
	if(pos == 1){
		new_node->next = head;
		head = new_node;
		count ++;
		return;
	}
	
	NODE* temp = head;
	// traversing till that position
	for(int i=1; i<pos-1; i++){
		temp = temp->next;
	}
	// UPDATING ADDRESSES
	new_node->next = temp->next;
	temp->next = new_node;
	count ++;
}

// DELETE NODE AT BEGINNING
void delete_first(){
	// IF LIST IS ALREADY EMPTY
	if(head == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		count --;
		return;
	}
	
	NODE* temp = head;
	// UPDATING ADDRESSES 
	head = temp->next;
	delete(temp);
	count--;
}

// DELETE NODE AT END
void delete_end(){
	if(head == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		return;
	}
	//If a single node in the list
	if(head->next == NULL){
		delete(head);
		head = NULL;
		count --;
		return;
	}
	NODE *temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	// deleting last node
	delete(temp->next);
	// updating the address of the last node
	temp->next = NULL;
	
	count --;
}

// DELETE NODE AT SPECIFIC LOCATION
void delete_specific(int pos){
	// IF POSITION EXCEEDS THE TOTAL NODES
	if(pos > count){
		cout<<"SORRY! YOUR POSITION IS GREATER THAN TOTAL NODES"<<endl;
	}
	// When no nodes in the list
	if(head == NULL){
		return;
	}
	// If the first node is to be deleted
	if (pos == 1) {
        NODE* temp = head;
        head = head->next;
        delete temp;
        count--;
        return;
    }
	// otherwise
	NODE* temp= head;
	//traversing

	for(int i=1; i<pos-1; i++){
		temp = temp->next;
	}
	NODE* next_node = temp->next;
	if(next_node->next == NULL){
		temp->next = NULL;
		delete(next_node);
		count --;
	}
	else
	{
		temp->next = next-node->next;
		delete(next_node);
		count --;
	}
}

// REVERSE THE LIST
void reverse(){
	if(head == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		return;
	}
	if(head -> next == NULL){
		cout<<"LIST CONTAINS ONLY ONE NODE"<<endl;
		return;
	}
	cout<<"REVERSE OF LINK LIST: ";
	NODE* prev_node = head;
	NODE* current_node = head->next;
	while(current_node != NULL){
		NODE* next_node = current_node->next;
		current_node->next = prev_node;
		//updating
		prev_node = current_node;
		current_node = next_node;
	}
	head->next = NULL;
	head = prev_node;
}

// TRAVERSING AND PRINTING NODES
void print(){
	
	if(head == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		return;
	}
	
	NODE* current = new NODE();
	current = head;
	
	while (current != NULL){
		cout<<current->data<<", ";
		current = current->next;
	}
	cout<<endl;
	
}

//FUNCTION TO COUNT SIZE OF NODES IN LINK LIST
int get_size(){
	
	if(head == NULL){
		return count;
	}
	
	NODE* temp = head;
	while(temp != NULL){
		temp = temp->next;
		count++;
	}
	return count;
}

int main(){
	
	insert_end(11);
	insert_end(12);
	insert_end(13);
	insert_end(14);
	print();

	delete_specific(3);
	print();
	
	
	return 0;
}
