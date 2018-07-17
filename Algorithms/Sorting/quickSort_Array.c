/* C implementation QuickSort */
#include<stdio.h>
 
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/*Error: Sorted array: 
9 7 8 9 1 5 4 6 10 12 2 
*/
int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int j=low-1;
	for (int i=low;i<high;i++){
		if(arr[i]<=pivot){
			j++;
			swap(&arr[i],&arr[j]);		
		}			
	}
	swap(&arr[j+1],&arr[high]);
	return j+1;
}
 

void quickSort(int arr[], int low, int high)
{
	if(low<high){
		int pivot_new=partition(arr,low,high);
		quickSort(arr,low,pivot_new);
		quickSort(arr,pivot_new+1,high);	
	}    
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 12, 4, 6, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
