// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// GREEDY ALGORITHM
// PROGRAM TO SOLVE THE FRACTIONAL KNAPSACK PROBLEM
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(2^n)

#include <stdio.h>
#include <stdlib.h>

// STRUCTURE TO STORE THE WEIGHT AND VALUE OF THE ITEMS
struct item{
    int weight;
    int value;
};
// FUNCTION TO SWAP TWO STRUCTURES
int swap(struct item *a, struct item *b){
    struct item temp = *a;
    *a = *b;
    *b = temp;
}

//  FUNCTION TO IMPLEMENT PARTITION IN QUICK SORT
int partition(struct item arr[], int low, int high){
    int pivot = arr[high].value / arr[high].weight;
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j].value / arr[j].weight < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// FUNCTION TO IMPLEMENT QUICK SORT TO SORT THE ARRAY OF STRUCTURES IN DESCENDING ORDER
void quickSort(struct item arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// FUNCTION TO COMPARE THE RATIO OF VALUE AND WEIGHT
int compare(const void *a, const void *b){
    // TYPECASTING THE PARAMETERS
    struct item *item1 = (struct item *)a;
    struct item *item2 = (struct item *)b;

    // CALCULATING THE RATIO
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;

    // COMPARING THE RATIO
    if(ratio1 > ratio2)
        return -1;
    else if(ratio1 < ratio2)
        return 1;
    else
        return 0;
}

// FUNCTION TO SOLVE THE FRACTIONAL KNAPSACK PROBLEM
double fractionalKnapsack(int weight, struct item arr[], int n){
    quickSort(arr, 0, n - 1);
    double totalValue = 0.0;
    int i;
    for(i=0; i<n; i++){
        // USING THE GREEDY APPROACH
        if(weight == 0){
            return totalValue;
        }
        else if(arr[i].weight <= weight){
            totalValue += arr[i].value;
            weight -= arr[i].weight;   
        }else{
            totalValue += ((double)arr[i].value / arr[i].weight) * weight;
            weight = 0;
        }
    }
    return totalValue;
}

int main(){
    // INITIALISING THE ARRAY OF STRUCTURES
    int weight = 50;
    struct item arr[] = {{10, 60}, {20, 100}, {30, 120}}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum value we can obtain = %lf", fractionalKnapsack(weight, arr, size));

    return 0;
}