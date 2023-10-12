#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* right;
	struct node* left;
};
void inOrder(struct node *root )
{
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}
struct node* createNode(int data)
{
	struct node *n;
	n = (struct node*)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	
	return n;
}
struct node* inorderPredecessor(struct node* root)
{
	root = root->left;
	while(root->right != NULL)
	{
		root=root->right;
	}
	return root;
}

struct node* deleteNode(struct node* root,int value) //this function run recursively
{
	struct node* iPre;
	
	if(root == NULL)
	{
		return NULL;
	}
	
	if(root->left == NULL && root->right == NULL)
	{
		free(root);  //free that last searched node where root is stand bcoz next is NULL
		return 0;
	}
	//search for a node to be deleted
	if(value < root->data)
	{
		root->left = deleteNode(root->left, value);
	}
	else if(value > root->data)
	{
		root->right = deleteNode(root->right, value);
	}
	// Deleting strategy when node is found
	else
	{
		iPre = inorderPredecessor(root); //@left node of deleting value(i.e,root)
		
		root->data = iPre->data; //here replacing @deleting value(i.e,root) data with @left node data
		
		root->left = deleteNode(root->left,iPre->data); //deleting the @left node of deleting value(i.e, be root)
		
	}
	return root;
}
int main()
{
   	struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
   	
   	// Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  
    
   	
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
	
	
	inOrder(p);
	deleteNode(p,5);
	printf("\n");
//	printf("|Data is %d|\n",p->data); This used when you want to delete root and print the new root value
	inOrder(p);	
	
	
   	return 0;
}
