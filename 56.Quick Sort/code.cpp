#include<stdio.h>

void printArray(int A[],int n)
{
	for(int i = 0;i < n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}

int partition(int A[],int low , int high)
{
	int pivot = A[low];   // taking first element of an array is pivot
	int i = low+1;
	int j = high;
	int temp;
	do
	{

		while(A[i] <= pivot)
		{
			i++;
		}
		while(A[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	} while(i<j);
	
	//swap pivot and A[j]
	temp = A[low];
	A[low] = A[j];
	A[j] = temp;
	return j;	
}

void quickSort(int A[],int low, int high)
{
	int partitionIndex;              //INdex of Pivot after partition
	
	partitionIndex = partition(A,low,high);    //(divide pivot like right side of element are big
	printArray(A,9);
												// and left side of pivot small than pivot element)
	if(low<high)
	{
	//partitionIndex or (pivot) is that which fix or correct placed at array
	quickSort(A,low,partitionIndex-1);         // sort left sub Array
	quickSort(A,partitionIndex+1,high);        // sort right sub Array
	}
	
}
int main()
{	   //low side(i)   	 //high side(j)



	int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    //int A[] = {9, 4, 4, 8, 7, 5, 6};
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3

	int n = 9;                         //size of an array
	
	
	printf("Array that is given\n");
	printArray(A,n);
	
	printf("Array after quick sort\n");
	quickSort(A,0,n-1);
	
	printArray(A,n);
	
return 0;
}
