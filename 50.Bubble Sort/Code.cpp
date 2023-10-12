#include<stdio.h>
#include<stdlib.h>

void printArray(int A[],int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n\n");
}
void bubbleSort(int A[],int n)

{
	int temp;
	for(int i = 0;i < n-1;i++)     								//For number of passes of Array
	{
		printf("Working on pass number %d\n", i+1); 
		for(int j = 0;j < n-1-i;j++)  									//For comparsions in pass
		{							  				// n-1-i,coz for each pass we - one comparsions	
			if(A[j]>A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1]; 		//Swapping the large element backside and small in front side
				A[j+1] = temp;	
			}								
		}
	}
	printf("\n");
}
void AdaptivebubbleSort(int A[],int n)					      //not use of comparsion and swapping
										                  
{
	int temp;
	int isSorted = 0;
	for(int i = 0;i < n-1;i++)                                //For number of passes of Array
	{
		printf("Working on pass number %d\n", i+1); 
		int isSorted = 1;
		for(int j = 0;j < n-1-i;j++)                                   //For comparsions in pass
		{							               // n-1-i,coz for each pass we - one comparsions	
			if(A[j]>A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1]; 		//Swapping the large element backside and small in front side
				A[j+1] = temp;
				isSorted = 0;	
			}								
		}
		if(isSorted)
		{
			return;
		}
	}
}
int main()
{
 // int A[] = {78,2,11,82,9,44};                                //For Sorting
//	int A[] = {1,2,3,4,5,6};	 	                            //Sorting Array for For Adaptive
	int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
	int n = 6;    //Size of an Array
	
	printf("Array Before Sorting\n");
	printArray(A,n);		                                   //Printing the Array Before sorting
	
	//(comment out bubble sort function for adaptive function work)
	
	printf("Array After bubble Sorting\n");
	bubbleSort(A,n);										   //Function to sort the array
	
	
	printf("Array After Sorting from bubble\n");
	AdaptivebubbleSort(A,n);                                  //Adaptive Function to sort the array
			
	printf("\n");
	printArray(A,n);										   //Printing the Array After sorting
	
 return 0;		
}

