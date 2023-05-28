// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// BRANCH AND BOUND ALGORITHM
// PROGRAM TO SOLVE THE 0/1 KNAPSACK PROBLEM USING BRANCH AND BOUND ALGORITHM
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(2^n)

#include <stdio.h>
#include <stdlib.h>

#define N 4
#define W 10

typedef struct{
    int weight;
    int value;
    double ratio;
} item;

// FUNCTION TO SORT RATIOS IN DESCENDING ORDER
int compare_items(const void*a, const void*b){
    item *item1 = (item *)a;
    item *item2 = (item *)b;
    double diff = item2->ratio - item1->ratio;
    if(diff > 0)
        return 1;
    else if(diff < 0)
        return -1;
    else
        return 0;
}

// FUNCTION TO CALCULATE THE LOWER BOUND
double lower_bound(int depth, int weight, int value, item* items, int n){
    double bound = value;
    int w = weight;
    for(int i = depth; i < n; i++){
        if(w + items[i].weight <= W){
            w += items[i].weight;
            bound += items[i].value;
        }
        else{
            int remain = W - w;
            bound += items[i].ratio * remain;
            break;
        }
    }
    return bound;
}

// BRANCH AND BOUND FUNCTION
int branch_n_bound(int depth, int weight, int value, item* items, int n, int *solution){
    // BASE CASE
    if(depth == n){
        return value;
    }

    // COMPUTING THE LOWER BOUND
    double bound = lower_bound(depth, weight, value, items, n);
    if(bound < solution[1]){
        return -1;
    }

    // BRANCH ON NEXT ITEM
    int include =0, exclude = 0;
    if(weight + items[depth].weight <= W){
        include = branch_n_bound(depth + 1, weight + items[depth].weight, value + items[depth].value, items, n, solution);
    }
    exclude = branch_n_bound(depth + 1, weight, value, items, n, solution);

    // UPDATE THE SOLUTION
    if(include > exclude){
        solution[0] = depth;
        solution[1] = include;
        return include;
    }else{
        return exclude;
    }
    
}
int main(){
    // INITIALISING THE ITEMS
    item items[N];
    items[0].weight = 2;
    items[0].value = 40;
    items[1].weight = 3;
    items[1].value = 50;
    items[2].weight = 5;
    items[2].value = 100;
    items[3].weight = 7;
    items[3].value = 150;

    // COMPUTING THE RATIO
    for(int i = 0; i < N; i++){
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // SORTING THE ITEMS IN DESCENDING ORDER OF RATIO
    qsort(items, N, sizeof(item), compare_items);

    // CALLING THE BRANCH AND BOUND FUNCTION
    int solution[2] = {-1, 0};
    branch_n_bound(0, 0, 0, items, N, solution);

    // PRINTING THE SOLUTION
    printf("The selected items are : ");
    for(int i = 0; i < N; i++){
        if(solution[0] == i){
            printf("1 ");
        }else{
            printf("0 ");
        }
    }

    return 0;
}