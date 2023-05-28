// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// DYNAMIC PROGRAMMING
// PROGRAM TO FIND FIBONACCI SERIES USING DYNAMIC PROGRAMMING
// TIME COMPLEXITY: O(n)

#include<stdio.h>
#include<stdlib.h>

int fibbonacciDp(int n){
    // INITIALIZE ARRAY TO STORE THE FIBONACCI SERIES
    int fib[n+1];
    int i;

    // INITIALIZE THE FIRST TWO VALUES OF THE SERIES
    fib[0] = 0;
    fib[1] = 1;

    // ITERATE THROUGH THE ARRAY TO FIND THE FIBONACCI SERIES
    for(i=2; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

int main(){
    int n;
    printf("Enter the number : \n");
    scanf("%d",&n);
    printf("The nth fibonacci number is %d: \n", fibbonacciDp(n));
    return 0;
}