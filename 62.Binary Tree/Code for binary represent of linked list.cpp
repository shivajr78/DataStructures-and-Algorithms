#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*right;
	struct node*left;
};

struct node* createNode(int data)
{
	struct node *n; //creating the node pointer
	n = (struct node*)malloc(sizeof(struct node));//Allocate mermory in the heap
	n->data = data;			//setting the Data
	n->right = NULL;  //setting the right child with the NULL
	n->left = NULL;   //setting the left child with the NULL
	
	return n; //Finally returing the created node
}

int main()
{/* 
	//constructing the root node - without usage of function
	struct node *p; 
	p = (struct node*)malloc(sizeof(struct node));
	p->data = 2;       
	p->right = NULL;
	p->left =  NULL;
	
	//consturcting the second node
	struct node *p1;
	p1 =  (struct node*)malloc(sizeof(struct node));
	p1->data = 1;
	p1->right = NULL;
	p1->left =  NULL;
	
	//constructing the third node
	struct node *p2;
	p2 =  (struct node*)malloc(sizeof(struct node));
	p2->data = 4;
	p2->right = NULL;
	p2->left =  NULL;
	
	//Linking the root with right and left children
	p->right = p1;
	p->left =  p2;
	
	*/
	////constructing root node - using function
	struct node *p = createNode(2);
	struct node *p1 = createNode(1);
	struct node *p2 = createNode(4);
	
	//Linking the root with right and left children
	p->right = p1;
	p->left =  p2;
	
	
	
	return 0;
}
