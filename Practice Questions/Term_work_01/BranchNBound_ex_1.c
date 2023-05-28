// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// BRANCH AND BOUND ALGORITHM
// PROGRAM TO SOLVE THE TRAVELLING SALESMAN PROBLEM USING BRANCH AND BOUND ALGORITHM
// DATA STRUCTURE USED: 2D ARRAY
// TIME COMPLEXITY: O(n^2)

#include <stdio.h>
#include <stdlib.h>

int a[10][10], visited[10], n, cost = 0;

int least(int currCity){

    int i, nearest = 999;
    int min = 999, minKey;
    // FINDING THE MINIMUM COST EDGE
    for(i = 0; i < n; i++){
        // CHECKING IF THE EDGE IS VISITED OR NOT
        if((a[currCity][i] != 0) && (visited[i] == 0)){
            // CHECKING IF THE EDGE IS MINIMUM OR NOT
            if(a[currCity][i] < min){
                // UPDATING THE MINIMUM COST EDGE
                min = a[i][0] + a[currCity][i];
                minKey = a[currCity][i];
                nearest = i;
            }
        }
    }
    // UPDATING THE COST
    if(min != 999){
        cost += minKey;
    }
    
    return nearest;
}

// FUNCTION TO FIND THE MINIMUM COST
void minCost(int city){
    int i;
    int ncity;
    visited[city] = 1;
    printf("%d --> ", city + 1);
    // FINDING THE NEXT NEAREST CITY
    ncity = least(city);

    if(ncity == 999){
        // IF ALL THE CITIES ARE VISITED
        ncity = 0;
        printf("%d", ncity + 1);
        cost += a[city][ncity];
        return;
    }   
    // RECURSION TO FIND THE MINIMUM COST
    minCost(ncity);
}

int main(){
    int i, j;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++){
        printf("Enter elements of row %d: ", i + 1);
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }
    printf("\nThe cost matrix is:\n");
    for(i = 0; i < n; i++){
        printf("\n");
        for(j = 0; j < n; j++){
            printf("\t%d", a[i][j]);
        }
    }

    printf("\nThe path is:\n");
    minCost(0);
    printf("\nMinimum cost is %d\n", cost);

    return 0;
}