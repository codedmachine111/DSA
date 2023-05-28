// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// DIVIDE AND CONQUER ALGORITHM
// PROGRAM TO SORT AN ARRAY USING MERGE SORT
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(nlogn)

#include <stdio.h>
#include <stdlib.h>

// MERGE TWO SUBARRAYS OF arr[]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// MERGE SORT FUNCTION
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int main(){
     // INITIALIZING VARIABLES
    int arr[100];
    int n = 0;

    // TAKING INPUT FROM USER
    printf("Enter the number of elements :\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter the element %d of the array :\n", i+1);
        scanf("%d", &arr[i]);
    }

    // SORTING THE ARRAY
    mergeSort(arr, 0, n-1);
    
    // PRINT THE SORTED ARRAY
    printf("Sorted array is : \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}