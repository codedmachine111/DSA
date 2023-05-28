// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// GREEDY ALGORITHM
// PROGRAM TO SOLVE THE COIN CHANGE PROBLEM USING GREEDY ALGORITHM
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(n)

#include <stdio.h>
#include <stdlib.h>

void coinChange(int coins[], int size, int amount){
    int count=0;
    for(int i=0; i<size; i++){

        // USING THE GREEDY APPROACH
        while(amount >= coins[i]){
            amount -= coins[i];
            count++;
        }

        if(amount==0){
            break;
        }
    }

    if (amount==0)
    {
        printf("Minimum number of coins required: %d\n", count);
    }
    else
    {
        printf("Change not possible\n");
    }
}

int main(){
    // INITIALIZING THE COINS ARRAY (DENOMINATIONS IN DESCENDING ORDER)
    int coins_arr[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int size = sizeof(coins_arr)/sizeof(coins_arr[0]);

    // TAKING THE AMOUNT AS INPUT FROM USER
    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);
    
    // FUNCTION CALL TO FIND THE MINIMUM NUMBER OF COINS REQUIRED
    coinChange(coins_arr, size, amount);

    return 0;
}