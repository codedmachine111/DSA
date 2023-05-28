// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// ITERATIVE ANALYSIS
// PROGRAM TO SORT NUMBERS IN AN ARRAY USING BUBBLE SORT ALGORITHM
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(n^2)

#include <stdio.h>
#include <stdlib.h>

// FUNCTION TO SWAP TWO NUMBERS
void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

// FUNCTION TO SORT THE GIVEN ARRAY USING BUBBLE SORT
void bubble_sort(int arr[], int n){
    int isSorted = 0;
    for(int i=0; i<n-1; i++){
        isSorted = 1;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                isSorted = 0;
            }
        }
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

    // SORT THE GIVEN ARRAY USING BUBBLE SORT
    bubble_sort(arr, n);

    // PRINT THE SORTED ARRAY
    printf("Sorted array :\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}