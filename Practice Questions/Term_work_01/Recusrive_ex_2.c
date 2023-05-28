// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// RECUSRIVE ALGORITHM
// PROGRAM TO GENERATE FIND FACTORIAL OF A NUMBER USING RECURSION
// TIME COMPLEXITY: O(log n)

#include <stdio.h>
#include <stdlib.h>

// FUNCTION TO FIND FACTORIAL OF A NUMBER USING RECURSION
int factorial(int num){
    if(num==0 || num==1){
        return 1;
    }
    else{
        return num * factorial(num-1);
    }
}

int main(){
    // USER INPUT
    int num;
    printf("Enter the number whose factorial is to be found :\n");
    scanf("%d",&num);

    // FUNCTION CALL AND RESULT
    printf("The factorial of %d is %d",num,factorial(num));

    return 0;
}