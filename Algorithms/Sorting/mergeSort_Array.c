#include<stdlib.h>
#include<stdio.h>
 
void merge(int arr[], int temp[], int left, int mid, int right)
{
	int left_boundary=mid-1;
	int temp_counter=left;
	int size=right-left+1;
	while(left<=left_boundary && mid<= right ){
		if(arr[left]<arr[left_boundary]){
			temp[temp_counter]=arr[left];
			temp_counter++;
			left++;
					
		}
		else{
			temp[temp_counter]=arr[mid];
			temp_counter++;
			mid++;
		}	
	}
	while(left<=left_boundary){
		temp[temp_counter]=arr[left];
		temp_counter++;
		left++;	
	}
	while(mid<=right){
		temp[temp_counter]=arr[mid];
		temp_counter++;
		mid++;	
	}
	for(int i=0;i<size;i++){
		arr[right]=temp[right];
		right--; 	
	}
				
}
 
void mergeSort(int arr[],int temp[], int left, int right)
{
	int mid;
	if (left<right){
		mid=(left+right)/2;
		mergeSort(arr,temp, left,mid);
		mergeSort(arr,temp, mid+1,right);
		merge(arr,temp,left,mid,right);   
	}
}
 

/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int temp[arr_size];	
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, temp, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
