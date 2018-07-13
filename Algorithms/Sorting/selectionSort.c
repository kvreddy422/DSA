// C program for implementation of Selection sort
#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement selection sort
void bubbleSort(int arr[], int n)
{
	for (int i=0;i<n;i++){
		int swap;
		for (int j=i;j<n;j++){
			swap=arr[i];
			if(arr[j]<swap)
			{
			 	arr[i]=arr[j];
				arr[j]=swap;
						
		}	}	
	}
	
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
