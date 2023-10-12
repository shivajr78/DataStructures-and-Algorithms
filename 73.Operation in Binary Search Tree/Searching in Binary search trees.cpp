#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* right;
	struct node* left;
};

struct node* createNode(int data)
{
	struct node *n;
	n = (struct node*)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	
	return n;
}

struct node* search(struct node*root,int key)
{
	if(root == NULL)       //if root is null 
	{
		return NULL;	//than return null
	}
	if(key == root->data)  //if key data @isequal to root data than return root data
		{
			return root;
		}
	else if(key < root->data)    //if key data @isless than root data,
	{
		return search(root->left, key); //than search in left side subtree
	}
	else    //if key data @isgreater than root data,
	{
		return search(root->right, key); //than search in right side subtree
	}
	
}
int main()
{
   	struct node* p  = createNode(5);
   	struct node* p1 = createNode(6);
   	struct node* p2 = createNode(3);
   	struct node* p3 = createNode(4);
   	struct node* p4 = createNode(1);
   	
   	// Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  
    
   	
   	p->right = p1;
   	p->left  = p2;
   	p2->right= p3;
   	p2->left = p4;
	
	struct node *n = search(p,4);
	
	if(n != NULL)
	{
		printf("Found: %d",n->data);
	}
	else
	{
		printf("Element Not Found");
	}
   	return 0;
}
