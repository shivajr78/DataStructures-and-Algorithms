#include<stdio.h>

//For Traversal : That is read all elements of array;
void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

int main()
{
	int size = 5;
	int arr[100] = {7, 8, 12, 27, 88};
	display(arr,size);
	
	return 0;
}

