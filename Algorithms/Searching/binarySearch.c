// C program to implement recursive Binary Search
#include <stdio.h>
 
/*Element is present at index 669302560*/
int binarySearch(int arr[], int l, int r, int x)
{
	int result;
	if(l<r){
		int mid=(l+r)/2;
		if(arr[mid]==x)
			return mid;
		if(arr[mid]<x)
			result = binarySearch(arr,mid+1,r,x);
		else
			result = binarySearch(arr,l,mid-1,x);   
	}
	return result;	
}
 
int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = binarySearch(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d",
                                                   result);
   return 0;
}
