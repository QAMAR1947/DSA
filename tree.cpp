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

// function to display terminal node
void display_terminal(Node *dummy_root)
{
	if(dummy_root == NULL)
	{
		cout<<"Tree is Empty"<<endl;
		return ;
	}
	else if(dummy_root->lchild == NULL && dummy_root ->rchild== NULL)
	{
		cout<<dummy_root->info<<endl;
	}
	else
	{
		display_terminal(dummy_root->lchild);
		display_terminal(dummy_root->rchild);
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
	
	inorder(root);
	
	
	
	return 0;
}
