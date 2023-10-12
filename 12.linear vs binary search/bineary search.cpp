#include<stdio.h>

int binarySearch(int arr[],int size,int element)
{
	int low;
	int mid;
	int high;
	
	low = 0;
	high = size-1;
	
	//keep searching until low >= high;
	while(low <= high)
	{
	mid = (low + high)/2;
		if(arr[mid] == element)
		{
			return mid;
		}
		if(arr[mid]<element)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int main()
{
	//sorted array for binary search;
	int arr[] = {10,20,30,40,50,60,70,80,90,100};
	int element = 70;
	int size = 10;
	int searchIndex = binarySearch(arr,size,element);
	
	printf("The element %d is in %d index",element,searchIndex);
	
	return 0;
}
