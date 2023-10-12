#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	int *arr;
};

void push(struct stack *sp,int value)
{
	if(sp->top == sp->size-1)
	{
		printf("Stack is overflow\n");
		return;
	}
	else
	sp->top++;
	sp->arr[sp->top] = value;
	printf("The %d value pushed is sucessfull\n",value);
}

stacktop(struct stack *sp)
{
	return(sp->arr[sp->top]);
}

stackbottom(struct stack *sp)
{
	return(sp->arr[0]);
}

int main()
{
	struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
	sp->size = 5;
	sp->top = -1;
	sp->arr = (int*)malloc(sp->size*sizeof(int));
	
	push(sp,33);
	push(sp,66);
	push(sp,99);
	push(sp,22);
	push(sp,55);
	
	printf("The Top of Stack is %d\n",stacktop(sp));
	printf("The Bottom of Stack is %d\n",stackbottom(sp));
	
	return 0;
}
