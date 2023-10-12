#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	int * arr;
};

void push(struct stack *ptr,int value)
{
	if(ptr->top == ptr->size-1)
	{
		printf("Stack is overflow at %d\n");
		return;
	}
	else
	{
		ptr->top++;
		ptr->arr[ptr->top] = value;
		
		//for push
		printf("The pushing the value %d is sucessfully\n",value);
	}
}
int pop(struct stack *ptr)
{
	if(ptr->top == -1)
	{
		printf("Stack is Underflow\n");
	}
	else
	{
		int value = ptr->top;
		ptr->top--;
		ptr->arr[ptr->top];
		printf("The pushing the value %d is sucessfully\n",value);
	}
	
}

int peek(struct stack *ptr,int i) //i = position of element in array,which starts from 1 not from 0!
{								  //index = array element address start from 0;
	int arrayInd = ptr->top-i+1;
	if(arrayInd<0)
	{
		printf("Invalid Position in the stack\n");
	}
	else
	{
		return ptr->arr[arrayInd];
	}
}
int main()
{
	struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
	sp->size = 5;
	sp->top = -1;
	sp->arr = (int*)malloc(sp->size*sizeof(int));
	
	push(sp,11);
	push(sp,22);
	push(sp,33);
	push(sp,44);
	push(sp,55);

	
	//for Pop
	for(int k=1;k<=sp->top+1;k++)
	{
		printf("The value %d is pop at position %d\n",peek(sp,k),k);
	}
	
	//for Peek
	for(int j=1;j<=sp->top+1;j++)
	{
		printf("The %d is a peek element at position %d\n",peek(sp,j),j);
	}
	return 0;
}
