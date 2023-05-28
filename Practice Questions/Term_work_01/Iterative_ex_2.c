// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// ITERATIVE ANALYSIS
// PROGRAM TO FIND MINIMUN ELEMENT IN AN ARRAY
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(n)

#include <stdio.h>
#include <stdlib.h>

// FUNCTION TO FIND MINIMUM ELEMENT IN THE ARRAY
int find_min(int arr[], int n){
    int min = arr[0];
    for(int i=1; i<n ;i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
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

    // FINDING THE MINIMUM ELEMENT IN THE ARRAY
    int min;
    min = find_min(arr, n);

    // PRINT THE MINIMUM ELEMENT
    printf("Minimum element in the array is : %d\n", min);
    return 0;
}