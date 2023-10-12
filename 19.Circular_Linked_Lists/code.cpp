#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void linkedListTraversal(struct Node *head)
{// take ptr that points to head of linked list
	struct Node *ptr = head;
	{//it is used to to link or print upto last node of the link list
		do
		{
			printf("Element is : %d\n",ptr->data);
			ptr = ptr->next;
		}// it is used to link last node to head node
		while(ptr != head);
	
	}
}
/*
// case : Insertation at beginning of link list
struct Node * insertAtFirst(struct Node *head, int data)
{  // memory request for ptr node// ptr point at head!
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
 
    struct Node * p = head->next;
    while(p->next != head) //p point at next of element of head
	{
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list
 
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
 
}
*/

int main()
{
	struct  Node *head;
	struct  Node *second;
	struct  Node *third;
	struct  Node *fourth;
	
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	fourth = (struct Node *)malloc(sizeof(struct Node));
	
	
	head-> data = 4;
	head-> next = second;
	
	second-> data = 3;
	second-> next = third;
	
	third-> data = 6;
	third-> next = fourth;
	
	fourth-> data = 1;
	fourth-> next = head;
	
/*	  printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 58);
    head = insertAtFirst(head, 59);
    printf("Circular Linked list after insertion\n");
    */
    
    linkedListTraversal(head);
	
	
	return 0;	
}




