// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// DIVIDE AND CONQUER ALGORITHM
// PROGRAM TO SORT AN ARRAY USING QUICK SORT
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(nlogn)

#include <stdio.h>
#include <stdlib.h>

// FUNCTION TO SWAP TWO ELEMENTS
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// PARTITION FUNCTION
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<= high-1; j++){

        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);

    return (i+1);
}

// QUICK SORT FUNCTION
void quickSort(int arr[], int low, int high){
    if(low <high){
        int part_idx = partition(arr, low, high);

        // SORT ELEMENTS BEFORE AND AFTER PARTITION
        quickSort(arr, low, part_idx-1);
        quickSort(arr, part_idx+1, high);
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
    quickSort(arr, 0, n-1);
    
    // PRINT THE SORTED ARRAY
    printf("Sorted array is : \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}