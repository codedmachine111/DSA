// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// BACKTRACKING ALGORITHM
// PROGRAM TO FIND ALL POSSIBLE SUBSETS OF INTEGERS THAT SUM UP TO A GIVEN NUMBER
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(2^n)

#include <stdio.h>
#include <stdlib.h>

int arr[100];
int subset[100];

// FUNCTION TO FIND ALL POSSIBLE SUBSETS
void subsetSum(int sum, int subsetSize, int currentIndex, int currentSum){
    if(currentSum == sum){
        // PRINTING THE SUBSET
        printf("Subset : ");
        for(int i=0; i<subsetSize; i++){
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }
    // IF THE CURRENT SUM IS LESS THAN THE REQUIRED SUM, CONTINUE ADDING ELEMENTS TO THE SUBSET
    else if(currentSum < sum){
        // ITERATING THROUGH THE ARRAY
        for(int i=currentIndex; i>=0; i--){
            if(currentSum + arr[i] <= sum){
                // ADDING THE ELEMENT TO THE SUBSET
                subset[subsetSize] = arr[i];
                // RECURSIVE CALL TO CHECK FOR THE NEXT ELEMENT
                subsetSum(sum, subsetSize+1, i-1, currentSum+arr[i]);
            }
        }
    }
}
int main(){

    int n, sum;

    // TAKING INPUT FROM USER
    printf("Enter the number of elements :\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter the element %d of the array :\n", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the sum :\n");
    scanf("%d", &sum);

    // FUNCTION CALL TO FIND ALL POSSIBLE SUBSETS
    subsetSum(sum, 0, n-1, 0);

    return 0;
}