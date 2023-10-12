#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printArray(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}
int maximum(int A[],int n)
{	
	int max = INT_MIN;

	for(int i = 0; i<n;i++)
	{
		if(max<A[i])
		{
			max = A[i];
		}
		
	}
	return max;
}

void countSort(int A[],int n)
{
	int k,j;
	
	//Finding Maximum element
	int max = maximum(A,n);
	
	// Dyanamically memory allocation of an array i.e,count array
	//size of count array is max value of given element +1.
	int* count = (int*)malloc((max+1)*sizeof(int));
	
	//Initalize the count array element to 0
	for(int i = 0;i<max+1;i++)
	{
		count[i] = 0;
	}
	
	//Increment the corresponding index in the count array with 1
	for(int i=0;i<n;i++)
	{
		count[A[i]] = count[A[i]]+1; //coverting 0 to 1
	}
	
	k = 0; //index counter for count array
	j = 0; //index counter for given A array
	
	
	//This process is for Coping element from count array to given array
	while(k < max+1)
	{
		if(count[k]>0)
		{
			A[j] = k;              //coping index in A[j]
			count[k] = count[k]-1; // increment the count array with -1
			j++;					//coverting 1 to 0
		}
		else
		{
			k++;
		}
	}
}
int main()
{
	int A[] = {9, 1, 4, 14, 4, 15, 6};
	int n = 7;
	
	printf("Given array is ");
	printArray(A,n);
	
	printf("Array after sorting is ");
	countSort(A,n);
	printArray(A,n);
	
	
	return 0;
}
