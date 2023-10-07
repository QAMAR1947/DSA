 #include<iostream>
using namespace std;
// CREATING STRUCTURE OF DOUBLE LINKED LIST
struct NODE{
	NODE* prev;
	int data;
	NODE* next;
};

// CREATING START POINTER THAT WILL STORE FIRST NODE
NODE* head;

// CREATING GLOBAL VARIABLE TO STORE SIZE OF LIST
int count;



//						***FUNCTIONS***

// INSERTING NODE AT THE BEGINING
void insert_first(int x){
	NODE* new_node = new NODE();
	
	new_node->prev = NULL;
	new_node->data = x;
	new_node->next = NULL;
	
	if(head == NULL){
		head = new_node;
		count ++;
		return;
	}
	//updating addresses
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
	
	count ++;
}

// INSERTING NODE AT THE END
void insert_end(int x){
	NODE* new_node = new NODE();
	new_node->prev = NULL;
	new_node->data = x;
	new_node->next = NULL;
	
	// IF THE LIST IS EMPTY (CORNER CASE)
	if(head == NULL){
		head = new_node;
		count ++;
		return;
	}
	
	NODE* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	// updating addresses
	new_node->prev = temp->next;
	temp->next = new_node;
	
	count++;
}

// INSERTING NODE AT SPECIFIC LOCATION
void insert_specific(int x, int pos){
	NODE* new_node = new NODE();
	new_node->prev = NULL;
	new_node->data = x;
	new_node->next = NULL;
	
	if(head == NULL || pos == 0){
		insert_first(x);
		return;
	}
	
	NODE* temp1 = head;
	
	if(temp1->next == NULL ){
		insert_end(x);
		return;
	}
	
	
	while(pos != 1){
		temp1 = temp1->next;
		pos --;
	}
	
	
	
	NODE* temp2 = temp1->next;
	// updating addresses to insert new_node
	temp1->next = new_node;
	temp2->prev = new_node;
	new_node->prev = temp1;
	new_node->next = temp2;
	
	count++;
}

// DELETING FIRST NODE OF THE LIST
void delete_first(){
	if(head == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		return;
	}
	
	NODE* temp1 = head;
	// updating addresses
	head = temp1->next;
	delete(temp1);
	head->prev = NULL;
	
	count --;
}

// DELETEING LAST OF THE LIST
void delete_last(){
	
	// IF NO NODE EXIST (CORNER CASE)
	if(head == NULL){
		return;
	}
	// IF ONLY 1 NODE EXIST (CORNER CASE)
	if(head->next == NULL){
		delete_first();
		return;
	}
	
	NODE* last_node = head;
	while(last_node->next != NULL){
		last_node = last_node->next;
	}
	
	// updating addresses (AS POINTER IS POINTING AT THE LAST NODE)
	NODE* prev_node = last_node->prev;
	prev_node->next = NULL;
	delete(last_node);
	
	count --;
}

// REVERSING THE LIST 
void reverse(){
	 
	// IF NO NODE EXIST (CORNER CASE)
	if(head == NULL){
		cout<<"List is Empty"<<endl;
		return;
	}
	
	// IF ONLY 1 NODE EXIST
	if(head->next == NULL){
		cout<<"NO REVERSING POSSIBLE --> ONLY 1 NODE"<<endl;
		return;
	}
	
	NODE* temp1 = head;
	NODE* temp2 = NULL;
	
	
	while(temp1 != NULL){
		temp1->prev = temp1->next;
		temp1->next = temp2;
		temp2 = temp1;
		temp1 = temp1->prev;
	}
	
		head = temp2;
	
}


// PRINTING AND TRAVERSING NODES
void print(){
	
	// IF LIST IS EMPTY (CORNER CASE)
	if(head == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		return;
	}
	
	NODE* temp = head;
	while(temp != NULL){
		cout<<temp->data<<", ";
		temp = temp->next;
	}
}

int main(){
	insert_end(10);
	insert_end(11);
	insert_end(12);
	insert_end(14);
	cout<<"SIMPLE LIST"<<endl;
	print();
	
	cout<<"\n\nAFTER INSERTING 1 NODE"<<endl;
	insert_specific(13,3);
	print();
	
	cout<<"\n\nTOTAL NODES : "<<count<<endl;
	
	cout<<"\n\n AFTER DELETING FIRST NODE"<<endl;
	delete_first();
	
	
//	cout<<"\n\nAFTER REVERSING"<<endl;
//	reverse();
	print();
	
	

	return 0;
	
}
