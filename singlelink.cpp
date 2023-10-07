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
	// INSERTING AT FIRST INDEX
	if(pos == 1){
		NODE* new_node = new NODE();
		new_node->data = x;
		new_node->next = head;
		head = new_node;
		count ++;
		return;
	}
	
	// IF POSITION EXCEEDS THE TOTAL NODES
	if(pos > count){
		cout<<"SORRY! YOUR POSITION IS GREATOR THAN TOTAL NODES"<<endl;
	}
	
	NODE* temp = head;
	
	NODE* new_node = new NODE();
	new_node->data = x;
	new_node->next = NULL;
	
	for(int i=1; i<pos-1; i++){
		temp = temp->next;
	}
	// UPDATING ADDRESSES
	new_node->next = temp->next;
	temp->next = new_node;
	count ++;
}

// DELETE NODE AT BEGINING
void delete_first(){
	// IF LIST IS ALREADY EMPTY
	if(head == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		count --;
		return;
	}
	
	NODE* current_node = new NODE();
	
	// UPDATING ADDRESSES 
	current_node  = head;
	current_node = current_node -> next;
	delete(head);
	head = current_node;	
	
	count--;
}

// DELETE NODE AT END
void delete_end(){
	if(head == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		return;
	}
	
	if(head->next == NULL){
		delete(head);
		head = NULL;
		count --;
		return;
	}
	
	
	NODE* s_l_node = new NODE();
	NODE* c_node = new NODE();
	
	s_l_node = head;
	c_node = head -> next;
	
	while(c_node -> next != NULL){
		s_l_node = s_l_node -> next;
		c_node = c_node -> next;
	}
	
	delete(c_node);
	s_l_node ->next = NULL;
	
	count --;
}

// DELETE NODE AT SPECIFIC LOCATION
void delete_specific(int pos){
	if(head == NULL){
		return;
	}
	
	if (pos == 1) {
        NODE* temp = head;
        head = head->next;
        delete temp;
        count--;
        return;
    }
	
	NODE* current_node = head;
	NODE* prev_node = NULL;
	//traversing
	int current_pos = 1;
    while (current_node != NULL && current_pos != pos) {
        prev_node = current_node;
        current_node = current_node->next;
        current_pos++;
    }

    if (current_node == NULL) {
        cout << "Position " << pos << " not found in the list." << endl;
        return;
    }
    
	prev_node->next = current_node->next;
	delete(current_node);
	
	count --;
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
	cout<<"REVERSE OF LINK LIST : ";
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
