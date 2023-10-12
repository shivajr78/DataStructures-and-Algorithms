#include<stdio.h>
#include<stdlib.h>

struct circularqueue
{
	int size;
	int frontind;
	int backind;
	int *arr;
};

int isFull(struct circularqueue *q)
{
	if((q->backind+1)%q->size == q->frontind)
	{
		return 1;
	}
	return 0;
}
int isEmpty(struct circularqueue *q)
{
	if(q->backind == q->frontind)
	{
		return 1;
	}
	return 0;
}

void Enqueue(struct circularqueue *q,int value)
{
	if(isFull(q))
	{
		printf("Circular Queue is Overflow\n");
	}
	else
	{
		q->backind = (q->backind+1)%q->size;
		q->arr[q->backind] = value;
		printf("Enqueue element is %d\n",value);
	
	}

}
int Dequeue(struct circularqueue *q)
{
	int a = -1;
	if(isEmpty(q))
	{
		printf("Circular Queue is underflow\n");
	}
	else
	{
		q->frontind = (q->frontind+1)%q->size;
		a = q->arr[q->frontind];	
	}
	return a;
}

int main()
{
	struct circularqueue q;
	q.size = 4;
	q.backind  = q.frontind = 0;  // (q->backind+1)%q->size is never = to -1 and that will be over write the elements
	
	// 0 index is reserved for frontind and backind	 and 
	// so, actuall can used size is 3							
	q.arr      = (int*)malloc(q.size*sizeof(int));
	
	Enqueue(&q,12);
	Enqueue(&q,15);
	Enqueue(&q,1);
	//Enqueue(&q,1);
	
	
	printf("\n");
	printf("Dequeue element is %d\n",Dequeue(&q));
	printf("Dequeue element is %d\n",Dequeue(&q));
	printf("Dequeue element is %d\n",Dequeue(&q));

	
	printf("\n");
	Enqueue(&q,66);//In Circularqueue after dequeuing the space is empty and we can enqueue now!
	Enqueue(&q,77);
	Enqueue(&q,88);
	
	if(isFull(&q))
	{
		printf("Queue is Full\n");
	}
	if(isEmpty(&q))
	{
		printf("Queue is Empty\n");
	}
	
	return 0;
}
//At last in output: queue is full coz after enqueue Enqueue(&q,66) are not dequeued so.i.e,reason 
