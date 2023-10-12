#include<stdio.h>

int linearSearch(int arr[],int size,int element)
{	
	for(int i = 0;i < size; i++)
	{
		if(arr[i] == element)
		{
			return i;
		}		
	}
	return (-1);
}
int main()
{
	// unsorted array for linear search;
	int arr[] = {1,4,7,9,3,5,4,6,8,11,0,2};
	int element = 9;
	int size = 12;
	int searchIndex = linearSearch(arr,size,element);
	
	printf("The Element %d is in index %d ",element,searchIndex);
	return 0;
}        
