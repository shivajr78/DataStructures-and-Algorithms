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
void inOrder(struct node* root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);	
	}
}

int isBST(struct  node* root)
{

    static struct node *prev = NULL;//here prev node points the parents node
    
    if(root!=NULL)
	{
//if the left subtree is a Binary Search Tree  is not a BST,then return 0 itself
    if(!isBST(root->left))
		{  
            return 0; 
        }
        
//If the prev node(left node) is not NULL and the current node(left node),which is the 
//root node(here left node is root) of the current subtree(left node subtree),is smaller 
//than or equal to the prev node then we would return 0
	if(prev!=NULL && root->data <= prev->data) 
	 
		{
            return 0; 
        }
        
//If it still passes all the if conditions we have structured above, we will store the current node in the
//prev and move it recursively to the right subtree. And this is nothing but a modified version of the
//InOrder Traversal.
        prev = root;
        return isBST(root->right);//same type of search in right sided sub tree
    }
    else
	{
        return 1; //for it is an Binary Search tree
    }
}
int main()
{
   	struct node* p  = createNode(5);
   	struct node* p1 = createNode(6);
   	struct node* p2 = createNode(3);
   	struct node* p3 = createNode(4);
   	struct node* p4 = createNode(1);
   	
   	p->right = p1;
   	p->left  = p2;
   	p2->right= p3;
   	p2->left = p4;
	
	
	inOrder(p);
	printf("\n");
	//printf("%d ",isBST(p));
	if(isBST(p))
	{
		printf("It is an Binary Tree");
	}
   	return 0;
}
