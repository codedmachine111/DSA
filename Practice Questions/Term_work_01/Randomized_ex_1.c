// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// RANDOMIZED ALGORITHM
// PROGRAM TO SORT AN ARRAY USING RANDOMIZED QUICK SORT
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(nlogn)
// WORST CASE: O(n^2) ==> IMPLEMENATION OF RANDOMIZED QUICK SORT TO AVOID WORST CASE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// FUNCTION TO SWAP TWO ELEMENTS
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// FUNCTION TO FIND THE PARTITION
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    int j;
    for(j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// FUNCTION TO IMPLEMENT RANDOMIZED PARTITION
int random_partition(int arr[], int low, int high){
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);
}

// FUNCTION TO IMPLEMENT RANDOMIZED QUICK SORT
void randomized_quick_sort(int arr[], int low, int high){
    if(low < high){
        int r_pivot = random_partition(arr, low, high);
        randomized_quick_sort(arr, low, r_pivot - 1);
        randomized_quick_sort(arr, r_pivot + 1, high);
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
    randomized_quick_sort(arr, 0, n-1);

    // PRINTING THE SORTED ARRAY
    printf("The sorted array is :\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}
