// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// RANDOMIZED ALGORITHM
// PROGRAM TO IMPLEMENT MONTE CARLO METHOD TO FIND THE VALUE OF PI
// DATA STRUCTURE USED: ARRAY
// TIME COMPLEXITY: O(n)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    // INITIALIZING THE SEED
    int n= 10000;
    int count = 0;
    // TAKING THE NUMBER OF POINTS
    for(int i=0; i<n; i++){
        // GENERATING RANDOM POINTS
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        // CHECKING IF THE POINTS LIE INSIDE THE CIRCLE
        if(x*x + y*y <= 1){
            count++;
        }
    }
    // CALCULATING THE VALUE OF PI
    double pi = (double)count / n * 4;
    printf("The value of pi is %lf\n", pi);
}