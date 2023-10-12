#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};
void forwardTraversal(struct Node *head)
{
	struct Node *ptr = head;
	
	while(ptr != NULL )
	{
		printf("Element are : %d\n",ptr->data);
		ptr = ptr->next;
	}
}
void backwardTraversal(struct Node *tail)
{
	struct Node *p = tail;
	while(p != NULL )
	{
		printf("Element are : %d\n",p->data);
		p = p->prev;
	}
}
int main()
{
	struct  Node *head;
	struct  Node *N2;
	struct  Node *N3;
	struct  Node *tail;
	
	head = (struct Node *)malloc(sizeof(struct Node));
	N2 = (struct Node *)malloc(sizeof(struct Node));
	N3 = (struct Node *)malloc(sizeof(struct Node));
	tail = (struct Node *)malloc(sizeof(struct Node));
	
	
	head-> data = 4;
	head-> next = N2;
	head-> prev = NULL;
	
	
	N2-> data = 3;
	N2-> next = N3;
	N2-> prev = head;
	
	N3-> data = 6;
	N3-> next = tail;
	N3-> prev = N2;
	
	tail-> data = 1;
	tail-> next = NULL;
	tail-> prev = N3;
	
	printf("Circular Linked list in forward direction\n");
    forwardTraversal(head);
    
    printf("Circular Linked list in backward direction\n");
    backwardTraversal(tail);

	return 0;	
}
