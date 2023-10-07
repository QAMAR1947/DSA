#include<iostream>
#include<string>
using namespace std;

// CREATING STRUCTURE OF SINGLE LINKED LIST
struct NODE{
	string name;
	string reg_no;
	string cls;
	
	NODE* next;
};

NODE* head;

// INSERT NODE AT END
void insert_end(string n,string reg, string clas){	
	NODE* new_node = new NODE();
	new_node -> name = n;
	new_node -> reg_no = n;
	new_node -> cls = clas;
	
	new_node -> next = NULL; 
	
		// IF THERE IS NO NODE IN LIST (CORNER CASE)
		if(head == NULL){
		head = new_node;
		return;
	}
	
	NODE *current = head;
	
	while(current -> next != NULL){
		current = current->next;
	}
	current->next = new_node;
	
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
		cout<<current->name<<", "<<current->reg_no<<", "<<current->cls<<endl;
		current = current->next;
	}
	cout<<endl;
	
}

// UPDATE FUNCTION
void update(int pos, int att, string data){
	NODE* current = head;
	
	
	while(pos != 1){
		if(current != NULL){
			current = current->next;
			pos --;
		}else{
			return;
		}
		
	}
	
	switch(att){
		case 1:
			current->name = data;
			break;
			
		case 2:
			current->reg_no = data;
			break;
			
		case 3:
			current->cls = data;
			break;
	}
}

int main(){
	
	insert_end("Qamar","SP22-BCS-015","BCS-4");
	insert_end("Umair","SP22-BCS-047","BCS-4");
	insert_end("Danial","SP22-BCS-038","BCS-4");
	
	print();
	
	update(2,2,"SP22-BCS-000");
	print();
	
	
	return 0;
}
