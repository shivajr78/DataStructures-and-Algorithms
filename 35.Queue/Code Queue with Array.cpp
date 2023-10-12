#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int size;
	int frontind;
	int backind;
	int* arr;
};

int isFull(struct queue *q)
{
	if(q->backind == q->size-1)
	{
		return 1;
	}
	return 0;
}

int isEmpty(struct queue *q)
{
	if(q->backind == q->frontind)
	{
		return 1;
	}
	return 0;
}
void Enqueue(struct queue *q,int value)
{
	if(isFull(q))
	{
		printf("Queue is Overflow\n");
	}
	else
	{
		q->backind++;
		q->arr[q->backind]=value;
		printf("Enqued element:%d\n",value);
	}
}

int Dequeue(struct queue *q)
{
	int a = -1;
	if(isEmpty(q))
	{
		printf("Queue is Underflow\n");
	}
	else
	{
		q->frontind++;
		a =	q->arr[q->frontind];
	}
	return 	a;
}
int main()
{
	struct queue q;						// here q is index value not a pointer
	q.size = 4;							// . because q is not a pointer
	q.frontind = q.backind = -1;      
	q.arr = (int*)malloc(q.size*sizeof(int));

	
	//Enqueue the element
	Enqueue(&q,12);  //Here &q is a pointer for address
	Enqueue(&q,15);
	Enqueue(&q,1);
	Enqueue(&q,1);
//	Enqueue(&q,55);
//	Enqueue(&q,66);
//	Enqueue(&q,77);
//	Enqueue(&q,88);
//	Enqueue(&q,99);
//	
	printf("Dequeuing Element is %d\n",Dequeue(&q));
	printf("Dequeuing Element is %d\n",Dequeue(&q));
	printf("Dequeuing Element is %d\n",Dequeue(&q));
	printf("Dequeuing Element is %d\n",Dequeue(&q));
//	printf("Dequeuing Element is %d\n",Dequeue(&q));

	Enqueue(&q,66);
	Enqueue(&q,77);
	Enqueue(&q,88);//In queue after dequeuing the space is empty but cannot  inject element 
	// and we can not enqueue now!
	//output be : queue is overflow
	
	if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
	
	return 0;
	
}
