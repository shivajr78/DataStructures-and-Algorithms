#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* sp, char val){
    if(isFull(sp)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        sp->top++;
        sp->arr[sp->top] = val;
    }
}
 
char pop(struct stack* sp){
    if(isEmpty(sp)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}

int precedence(char ch)
{
	if(ch == '*' || ch == '/')
	return 3;
	
	else if(ch == '+' || ch == '-')
	return 2;
	
	else
	return 0;
}
int isOperator(char ch)
{
	if(ch == '*' || ch == '/' || ch == '+' || ch == '-')
	return 1;
	
	else 
	{
		return 0;
	}
}

char* infixToPostfix(char *infix)
{
	struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
	sp->size = 10;
	sp->top = -1;
	sp->arr = (char*)malloc(sp->size * sizeof(char)); //making infix char array
	char * postfix = (char*)malloc((strlen(infix)+1) * sizeof(char));//copy of infix char array//
	//making postfix char array to write expression char and oprator which are pop from stack//
	
	int i = 0; //track the infix traversal
	int j = 0; //track the postfix traversal or addition
	
	while(infix[i]!='\0')
	{
		if(!isOperator(infix[i]))
		{
		 postfix[j] = infix[i];
		 j++;
		 i++;
		}
		else
		{
			if(precedence(infix[i]) > precedence(stackTop(sp)))
			{
				push(sp,infix[i]);
				i++;
			}
			else
			{
				postfix[j] = pop(sp); //pop the char from stack and put in postfix array
				j++;
			}
		}
	}

while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char * infix = "x-y/z-k*d"; //Expression
    printf("Postfix is %s",infixToPostfix(infix));
   
    return 0;
}

