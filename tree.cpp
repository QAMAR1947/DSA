#include<iostream>
using namespace std;

struct Node{
	int info;
	Node* lchild = NULL;
	Node* rchild = NULL;
}*root = NULL;

// function to find the element in tree
void find(int item, Node* &parent, Node* &loc){
	// case 1: tree is empty
	if(root == NULL)
	{
		loc = NULL;
		parent = NULL;
		return;
	}
	// case 2 : item already present
	if(item == root->info)
	{
		loc = root;
		parent = NULL;
		return;
	}
	// case 3: if item is > or < than parent/root value
	if(item > root->info)
	{
		loc = root->rchild;
		parent = root;
	}
	else if(item < root->info)
	{
		loc = root->lchild;
		parent = root;
	}
	// loop to continue searching till loc becomes NULL
	while(loc != NULL)
	{
		if(loc->info == item)
		{
			return;
		}
		else if(item > loc->info)
		{
			parent = loc;
			loc = loc->rchild;
		}
		else
		{
			parent = loc;
			loc = loc->lchild;
		}
	}
	
	
}

// function to insert element in tree
void insert(int item){
	Node* temp, *parent = NULL, *loc = NULL;
	find(item, parent, loc);
	
	if(loc != NULL)
	{
		cout<<"Item already present";
		return;
	}
	// creating node with new item
	temp = new Node();
	temp->info = item;
	
	if(parent == NULL)
	{
		root = temp;
	}
	else if(item > parent->info)
	{
		parent->rchild = temp;
	}
	else
	{
		parent->lchild = temp;
	}
}

// function of case a
void case_a(Node* &parent, Node* &loc)
{
	// if only 1 element(root) is in tree
	if(parent == NULL)
	{
		root = NULL;
	}
	
	// otherwise check the element is in left or right of parent
	else if(parent->rchild == loc)
	{
		parent->rchild = NULL;
	}
	else if(parent->lchild == loc)
	{
		parent->lchild = NULL;
	}
}

// function of case b
void case_b(Node* &parent, Node* &loc)
{
	// pointer that will store that 1 child of parent which we want to delete
	Node* child;
	
	// checking whether left or right child exist
	if(loc->lchild == NULL)
	{
		child = loc->rchild;
	}
	else //if(loc->rchild == NULL)
	{
		child = loc->lchild;
	}
	
	// if element to be delete is root and root has only 1 child
	if(parent == NULL)
	{
		root = child;
	}
	// otherwise 
	else if(parent->lchild = loc)
	{
		parent->lchild = child;
	}
	else if(parent->rchild = loc)
	{
		parent->rchild = child;
	}
	
}

// function of case c
void case_c(Node* &parent, Node* &loc)
{
	
}

//									TRAVERSAL IN BINARY TREE
// function of in_order traversal(also gives sorted elements)
void inorder(Node *ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	else
	{
		inorder(ptr->lchild);
		cout<<ptr->info<<endl;
		inorder(ptr->rchild);
	}
}

// funtion of pre_order traversal
void pre_order(Node *ptr)
{
	if(ptr== NULL)
	{
		return;
	}
	else
	{
		cout<<ptr->info<<endl;
		pre_order(ptr->lchild);
		pre_order(ptr->rchild);
	}
}

// function of post_order traversal
void post_order(Node *ptr)
{
	if(ptr== NULL)
	{
		return;
	}
	else
	{
		post_order(ptr->lchild);
		post_order(ptr->rchild);
		cout<<ptr->info<<endl;
	}
}


// function to delete the elements in tree
void del(int item){
	Node *parent, *loc;
	//if no element in tree
	if(root == NULL){
		cout<<"tree is empty";
		return;
	}
	// otherwise find the element through find function
	find(item, parent, loc);
	
	// if deleting node is leaf
	if(loc->lchild == NULL && loc->rchild == NULL)
	{
		case_a(parent, loc);
	}
	
	// if deleting node has 1 child
	else if(loc->rchild == NULL && loc->lchild != NULL)
	{
		case_b(parent, loc);
	}
	
	// if deleting node has 1 child
	else if(loc->rchild != NULL && loc->lchild == NULL)
	{
		case_b(parent, loc);
	}
	
	// if deleting node has 2 child
	else
	{
		case_c(parent, loc);
	}
}

// function to display depth of binary tree
int depth(Node* ptr){
	// base case
	if(ptr == NULL)
	{
		return 0;
	}
	int ld = depth(ptr->lchild);
	int rd = depth(ptr->rchild);
	
	// check which subtree is greator
	if(ld > rd)
	{
		return ld+1;
	}
	else
	{
		return rd+1;
	}
	
}

// function to display terminal nodes of tree
void display_terminal(Node* ptr)
{
	// 1st base case:
	if(ptr == NULL){
		cout<<"No elements in Tree";
		return;
	}
	// 2nd base case:
	if(ptr->lchild == NULL && ptr->rchild == NULL)
	{
		cout<<ptr->info;
	}
	// otherwise traverse to the root of each subtree and displays it using recursive call
	else
	{
		display_terminal(ptr->lchild);
		display_terminal(ptr->rchild);
	}
}

// function to display depth of specific node
int display_specific(int item, Node* ptr, int count){
	// 1st base case:
	if(ptr == NULL)
	{
		cout<<"node does not exist";
	}
	// 2nd base case: if item is root node
	else if(item == ptr->info){
		return count;
	}
	else
	{
		 if(item > ptr->info)
		 {
		 	display_specific(item, ptr->rchild, count+1);
		 }
		 else // if(item < ptr->info)
		 {
		 	display_specific(item, ptr->lchild, count+1);
		 }
		
	}
}

// function to find a node having two child
void node_with_two_child(Node* ptr){
	if(ptr == NULL)
	{
		return;	
	}
	else
	{
		if(ptr->lchild != NULL && ptr->rchild != NULL)
		{
			cout<<ptr->info<<endl;
		}
		else
		{
			node_with_two_child(ptr->lchild);
			node_with_two_child(ptr->rchild);
		}
	}
}

// function to find node having 1 child
void node_eith_one_child(Node* ptr){
	if(ptr == NULL)
	{
		return;
	}
	else
	{
		if((ptr->rchild != NULL && ptr->lchild == NULL) || (ptr->rchild == NULL && ptr->lchild != NULL))
		{
			cout<<ptr->info<<endl;
		}
		else
		{
			node_eith_one_child(ptr->lchild);
			node_eith_one_child(ptr->rchild);
		}
	}
}

// function to find the position of child to its parent
void parent_position(int item){
	// pointers to get the location of parent and its child node
	Node *parent, *loc;
	find(item, parent, loc);
	// now check where the child lies
	if(parent->lchild == loc){
		cout<<"it's on the left side";
	}
	else
	{
		cout<<"it's on the right side";
	}
}

// funtion to print level nodes
void print_level_nodes(Node* ptr, int level){
	if(ptr == NULL){
		cout<<"no Tree Exist";
		return;
	}
	// if only root exist
	else if(level == 0){
		cout<<ptr->info<<", ";
	}
	else
	{
		print_level_nodes(ptr->lchild, level-1);
		print_level_nodes(ptr->rchild, level-1);
	}
	
}
// function to get the total level
void level_order_traversal(){
	int height = max_depth(root);	// stores the number of level
	for(int i=0; i<height; i++){
		print_level_nodes(root, i);
		cout<<endl;
	}
}

// main function
int main(){
	insert(19);
	insert(9);
	insert(25);
	insert(6);
	insert(20);
	insert(13);
	insert(22);
	insert(12);
	insert(11);
	insert(4);
	insert(7);
	insert(3);
	
//	inorder(root);
//	cout<<depth(root);
//	cout<<display_specific(3,root,0);
	
	
	
	return 0;
}
