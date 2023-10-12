#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

void linkListTraversal(struct node *ptr)
{
	while(ptr != NULL)
	{
		printf("Elements is %d\n",ptr->data);
		ptr = ptr->next; 
	}
}

int isEmpty(struct node *top)
{
	if(top==NULL)
	{
		printf("Stack is Empty!");
		return 1;
	}
	else 
	{
		return 0;
	}
}
int isFull(struct node *top)
{

	//struct node *p = (struct node*)malloc(sizeof(struct node));
	if(top->next==NULL)
	{
		printf("Stack is Full!\n");
		return 1;
	}
	else 
	{
		return 0;
	}
}

struct node* push(struct node* top,int x)
{
	if(isFull(top))
	{
		printf("Stack is Overflow\n");
	}
	else 
	{
		struct node *n = (struct node*)malloc(sizeof(struct node));
		n->data = x;
		n->next = top;
		n = top;
		
		return top;
	}
}

int main()
{
	struct StackNode * top = NULL;
	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *second = (struct node*)malloc(sizeof(struct node));
	struct node *third = (struct node*)malloc(sizeof(struct node));
	struct node *forth = (struct node*)malloc(sizeof(struct node));
	
	
	head->data=2;
	head->next=second;
    second->data=8;
	second->next=third;
	third->data=890;
	third->next=forth;
	forth->data=8200;
	forth->next=push(head,78);
	
	

	
	linkListTraversal(head);
	return 0;
}
