#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Case 4: Deleting the element with a given value from the linked list
struct Node * deleteByValue(struct Node * head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL) // q points the data and runs upto we can not
    {				//get the finding value && also upto the q next will not be a Null
        p = p->next;
        q = q->next;
    }
    //after q will null.the q get outside from while loop and move to if condition
    //to check given value is in data or not!
    
    if(q->data == value){ // if value will get i.e, data of q is equal to given value than! 
        p->next = q->next;
        free(q);
    }
    return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;                                 //not completed  
    fourth->next = NULL;								//not completed  
														//not completed  
    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    
    head = deleteByValue(head,3);

    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}
