#include<stdio.h>
void printArray(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}

void selectionSort(int A[],int n)
{
	int indexOfMin,temp;                     // 0 index element which we see as a fix at index 0
	
	printf("Running Selection Sort......\n");
	for(int i = 0;i < n-1;i++)
	{									//(start comparing with 2nd index element and upto last n,
		indexOfMin = i;					//because first 0 index element is fix which we have 
		for(int j = i+1; j<n; j++) 		//to compare with 2nd index element and upto last n)       
		{							     
			if(A[j] < A[indexOfMin])    //A[j] is  2nd index element which is going to compare 
			{
				indexOfMin = j; //here indexofmin store the min value from A[j]<A[indexOfMin] cond. 
			}	   
		}
		//Swap A[i] and A[indexOfMin]
		
		temp = A[i];
		A[i] = A[indexOfMin];     
		A[indexOfMin] = temp;
		
	}
}

int main()
{
	// Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12                  

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12								//interchanged with swapped element

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13
    
    
	int A[] = {3, 5, 2, 13, 12};
	int n  = 5;                                    //Size of an Array
	
	printf("This is an Given Array\n");
	printArray(A,n);
	
	selectionSort(A,n);
	
	printArray(A,n);
	
	return 0;
}
