#include<stdio.h>

void printArray(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}

void merge(int A[],int low,int mid,int high)
{
	int i,j,k;
	int B[100];
	
	i = low;
	j = mid + 1;
	k = low;
	
	while(i<=mid && j<=high)
	{
		if(A[i] < A[j])
		{
			B[k] = A[i];
			i++;
			k++;
		}
		else
		{
			B[k] = A[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		B[k] = A[i]; //Coping all the elements from A[i] to B
		i++;
		k++;
	}
	while(j <= high)
	{
		B[k] = A[j]; //Coping all the elements from A[j] to B
		j++;
		k++;
	}// upto here we copied all element from A[] to B[] and B is now sorted array
	
	for (int i = low; i <= high; i++) //coping all sorted element from B[] to A[]
    {
        A[i] = B[i];
    }
}
void mergeSort(int A[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = (low + high) /2; 					 // finding mid point in array A[]
		mergeSort(A,low,mid);		// Sort i side array
		mergeSort(A,mid+1,high);	// sort j side array
		merge(A, low, mid, high); // after sorting merge it again	
	}
	
}

int main()
{
	int A[] = {9, 1, 4, 14, 4, 15, 6};
	int n = 7;
	
	printf("Given Array is: ");
	printArray(A,n);
	
	printf("Array after sorting is: ");
	mergeSort(A,0,6);//giving A array and low index i.e, 0 and high index (n-1)i.e,6
	printArray(A,n);
	
	
	return 0;
}
