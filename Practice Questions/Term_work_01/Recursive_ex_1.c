// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// RECUSRIVE ALGORITHM
// PROGRAM TO FIND AN ELEMENT USING BINARY SEARCH
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(log n)

#include <stdio.h>
#include <stdlib.h>

// FUNCTION TO FIND KEY IN THE ARRAY USING BINARY SEARCH
int binary_search(int arr[], int start, int end, int target){
    // BASE CONDITION
    if(start>end){
        return -1;
    }
    int mid = start + (end-start)/2;

    // IF KEY IS FOUND, RETURN INDEX
    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid] > target){
        // SEARCH FROM START TO MID-1
        return binary_search(arr, start, mid-1, target);
    }
    else{
        // SEARCH FROM MID+1 TO END
        return binary_search(arr, mid+1, end, target);
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

    // KEY TO BE SEARCHED IN ARRAY
    printf("Enter the element to be searched :\n");
    int key;
    scanf("%d", &key);

   // RESULT FROM BINARY SEARCH
   int res;
   res = binary_search(arr, 0, n-1, key);

   if(res == -1){
        printf("Key not found in array\n");
   }else{
        printf("Key found at index %d\n", res);
   }

   return 0;
}