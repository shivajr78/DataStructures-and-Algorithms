#include<stdio.h>
#include<stdlib.h>

struct node *frontind = NULL;
struct node *backind = NULL;

struct node {
	int data;
	struct node *next;
};

void linkListTraversal(struct node *ptr)
{
	printf("Printing the Elements of linklist\n");
	while(ptr!=NULL)
	{
		printf("Element are %d\n",ptr->data);
		ptr = ptr->next;
	}
}
void Enqueue(int value) 
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	if(n == NULL)
	{
		printf("Queue is Full\n");
	}
	else
	{
		n->data = value;
		n->next = NULL;
	if(frontind == NULL)
	{
	frontind = backind = n;//coz frontind & backind both point at the last node that also point null
	}
		else
		{
		backind->next = n;
		backind=n;    //back pointer now points to last pointer n,coz now n points is the last node
		}
	}
}

int Dequeue()
{
	int value = -1;
	struct node *ptr = frontind;
	if(frontind == NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		frontind = frontind->next;
		value = ptr->data;
		free(ptr);
	}
	return value;
}
	
int main() {
	
	linkListTraversal(frontind);
	

	printf("Dequeuing elements are %d\n",Dequeue());
		
	Enqueue(11);
	Enqueue(33);
	Enqueue(66);
	Enqueue(99);
	printf("Dequeuing elements are %d\n",Dequeue());
	printf("Dequeuing elements are %d\n",Dequeue());
	printf("Dequeuing elements are %d\n",Dequeue());
	printf("Dequeuing elements are %d\n",Dequeue());
	
	Enqueue(33);
	Enqueue(44);
					
	
	
	linkListTraversal(frontind);
	
	


	
	return 0;
}
