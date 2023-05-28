// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// BRUTE FORCE ALGORITHM
// PROGRAM TO FIND ALL PAIRS OF ELEMENTS IN AN ARRAY WHOSE SUM IS EQUAL TO A GIVEN NUMBER
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(n^2)

#include <stdio.h>
#include <stdlib.h>

void find_pairs(int arr[], int n, int sum){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == sum){
                printf("The pair is (%d, %d)\n", arr[i], arr[j]);
            }
        }
    }
}

int main(){
    // INITIALIZING VARIABLES
    int arr[100];
    int n;

    // TAKING INPUT FROM USER
    printf("Enter the number of elements :\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter the element %d of the array :\n", i+1);
        scanf("%d", &arr[i]);
    }

    // TAKING INPUT OF THE SUM
    int sum;
    printf("Enter the sum :\n");
    scanf("%d", &sum);

    // CHECKING FOR PAIRS
    find_pairs(arr, n, sum);

    return 0;
}