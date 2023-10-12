#include<stdio.h>
//For Insertion : insert new elements in array;
	void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);	
	}
	printf("\n");
}
 int indInsertion(int arr[],int size,int element,int capacity,int index)
 {
 	if(size>=capacity)
 	{
 		return -1;     //return -1 means insertion not take place //
	}
	for(int i = size; i >= index;i--)
	{
		arr[i+1]	 = arr[i];	
	}
	arr[index] = element;
		return 1; 		// return 1 means insertion take place//
 }
 
 
int main()
{
	int arr[100] = {7,8,12,27,88};
	int size = 5;
	int element = 45;
	int index = 3;
	display(arr,size);
	
//  Index*Insert(takingarray,used size in array,new element,capacity of an array i.e 100,at 
//  which no the changes take place i.e index)
	
	indInsertion(arr, size, element,100,index);
	size += 1;
	
	display(arr,size);
	
	return 0;
}


