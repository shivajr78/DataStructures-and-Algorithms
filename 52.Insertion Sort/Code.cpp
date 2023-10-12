#include<stdio.h>
#include<stdlib.h>

void printArray(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}

void insertSort(int A[],int n)
{	
	int key,j;

//loop for passes					//Here is an index of element in complete given array
	for(int i = 1;i<=n-1;i++)		//going form index 1 to n-1,coz n-1 is an no.of passes
	{
		
		key= A[i];                //key is an element that going to insert
		j = i-1;				  //j is an index of last element in sorted side of array
								  // The index variable j holds the value i-1.
		//loop for each pass
		
		while(j>=0 && A[j] > key)           //j[A] is an element present in sorted arrray side
		{
			A[j+1] = A[j];
			j--;	
		}
		A[j+1] = key;
	}
	
	
	
}

int main()
{			// 0, 1,  2,3, 4,5      index
	int A[] = {12,54,65,7,23,9};
	                                                    //here j = i-1 nd i is key value index
	// -1   0    1   2   3   4   5                   
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0      //  (comparing j value with i
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!   //j is value is changing with i-1 of
   															 //index and i value is store in key 
   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1		 //so,value does not change)
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2   (here condition j[A] > key is true that is 
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1    why j value is changing with j-1 of index)
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1  (here condition j>=0 is false so,that key
   //                                                     value stored at j=0)
   
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3    
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass
   
   
	int n = 6;												//size of an array
	
	printf("This is an Given Array\n");
	printArray(A,n);
	
	printf("Array After an Insertion\n");
	insertSort(A,n);
	
	printArray(A,n);
}
