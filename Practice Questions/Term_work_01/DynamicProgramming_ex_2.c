// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// DYNAMIC PROGRAMMING
// PROGRAM TO FIND FACTORIAL OF A NUMBER USING DYNAMIC PROGRAMMING
// TIME COMPLEXITY: O(n)

#include<stdio.h>
#include<stdlib.h>

int factorialDp(int n){
    // INITIALIZE ARRAY TO STORE THE FACTORIAL
    int fact[n+1];
    // INITIALIZE THE FIRST VALUE OF THE FACTORIAL
    fact[0] = 1;

    // ITERATE THROUGH THE ARRAY TO FIND THE FACTORIAL
    for(int i=1; i<=n; i++){
        fact[i] = i*fact[i-1];
    }

    return fact[n];
}

int main(){
    int n;
    printf("Enter the number : \n");
    scanf("%d",&n);
    printf("The factorial of %d is : %d \n",n, factorialDp(n));
    return 0;
}