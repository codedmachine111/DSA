#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to find how many times a number is duplicated
void findAllDuplicates(int arr[], int n){
    int count = 0;
    int flag=0;
    for(int i=0; i<n; i++){
        count = 1;
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
                arr[j] = -1; // to avoid counting the same element again
            }
        }
        if(count > 1 && arr[i] != -1){ // if the element is not -1, then it is not counted yet
            printf("%d is repeated %d times\n", arr[i], count);
        }
    }
}


int main(){
    int arr[20];
    FILE *fp;
    fp = fopen("random.txt", "r+");

    srand(time(0));
    for(int i=0; i<20; i++){
        arr[i] = rand()%(20-10 +1)+10;
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
    fp = fopen("random.txt", "r+");

    for(int j=0; j<20; j++){
        fscanf(fp, "%d", &arr[j]);
    }

    printf("The array is : \n");
    for(int l=0; l<20; l++){
        printf("%d ", arr[l]);
    }

    printf("\n");
    findAllDuplicates(arr, 20);
    return 0;
}