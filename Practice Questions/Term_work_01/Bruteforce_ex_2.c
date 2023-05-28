// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// BRUTE FORCE ALGORITHM
// PROGRAM TO CRACK A 4 DIGIT pin
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(n^4)

#include <stdio.h>
#include <stdlib.h>

int main(){

    // INITIALIZING VARIABLES
    int i,j,k,l;
    char pin[4];
    char try[4];
    char ch;

    // TAKING INPUT
    printf("Enter your  pin: ");
    for(i=0;i<4;i++){
        scanf("%c",&pin[i]);
    }

    printf("\n");
    // BRUTE FORCE ALGORITHM TO FIND ALL POSSIBLE COMBINATIONS AND CHECK IF IT MATCHES THE PIN
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            for(k=0;k<4;k++){
                for(l=0;l<4;l++){
                    // TRYING ALL POSSIBLE COMBINATIONS
                    try[0]=pin[i];
                    try[1]=pin[j];
                    try[2]=pin[k];
                    try[3]=pin[l];
                    
                    // CHECKING IF THE GUESS MATCHES THE PIN
                    if(try[0]==pin[0] && try[1]==pin[1] && try[2]==pin[2] && try[3]==pin[3]){
                        printf("The pin is: ");
                        for(int m=0;m<4;m++){
                            printf("%c",try[m]);
                        }
                        // IF THE GUESS MATCHES THE PIN, END THE PROGRAM
                        printf("\n");
                        printf("The pin is cracked\n");
                        return 0;
                    }
                }
            }
        }
    }
    // IF THE GUESS DOES NOT MATCH THE PIN, PIN IS NOT CRACKED
    printf("The pin is not cracked\n");
    return 0;
}