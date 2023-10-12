#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
// for head k liye functions used hai
void linkedListTraversal(struct Node *ptr)
{
	// loop chalegii till ptr not be null
	while (ptr != NULL)
	{
		printf("Element = %d\n",ptr->data);
		ptr = ptr->next;
	}	
}

int main()
{
	struct Node * head;
	struct Node * second;
	struct Node * third;
	struct Node * fourth;
	
	// Allocated memory for node in the linked list in heap memory
	head = (struct Node *)malloc(sizeof (struct Node));
	second = (struct Node *)malloc(sizeof (struct Node));
	third = (struct Node *)malloc(sizeof (struct Node));
	fourth = (struct Node *)malloc(sizeof (struct Node)); 
	
	//link first node with second node
	head -> data = 7;
	head -> next = second;
	
	//link second node with third node
	second -> data = 11;
	second -> next = third;
	
	//link third node with fourth node
	third -> data = 44;
	third -> next = fourth;
	
	
	//terminate link list at fourth node
	fourth -> data = 66;
	fourth -> next = NULL;
	
	linkedListTraversal(head);
	
	return 0;
}

	






