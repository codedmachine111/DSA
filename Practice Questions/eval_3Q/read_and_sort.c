#include <stdio.h>
#include <string.h>
#include <time.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void generate_random_numbers(int p,int q, int n, FILE* fp){
    srand(time(NULL));
    for(int i=0; i< n; i++){
        int num = rand() % (q-p+1) + p;
        fprintf(fp, "%d ", num);
    }
    fclose(fp);
}

void bubble_sort(int arr[], int n){
    int isSorted=0;
    int temp;
    for(int i=0; i<n-1; i++){
        isSorted=1;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
            isSorted=0;
        }
    }
}
void selection_sort(int arr[], int n){
    int min_idx;
    for(int i=0; i<n-1; i++){
        min_idx=i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx=j;
            }
            if(min_idx != i){
                swap(&arr[min_idx], &arr[i]);
            }
        }
    }
}

void merge(int arr[], int left, int right, int mid){
    
    int left_arr[mid-left+1];
    int right_arr[right-mid];
    int i,j,k;

    for(int i=0; i<(mid-left+1); i++){
        left_arr[i] = arr[left+i];
    }
    for(int j=0; j<(right-mid); j++){
        right_arr[j] = arr[mid+1+j];
    }

    i=0;
    j=0;
    k=left;

    while(i<(mid-left+1) && j<(right-mid)){
        if(left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            i++;
        }else{
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while(i<(mid-left+1)){
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while(j<(right-mid)){
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right-left)/2;

        mergeSort(arr,left, mid);
        mergeSort(arr,mid+1, right);

        merge(arr, left, right, mid);
    }
}
void read_and_sort(FILE *fp1, FILE *fp2, int x){

    int arr[x];
    for(int i=0; i<x; i++){
        fscanf(fp1, "%d", &arr[i]);
    }

    bubble_sort(arr,x);

    for(int j=0; j<x; j++){
        fprintf(fp2, "%d ", arr[j]);
    }
    printf("Sorted array written successfully\n\n");
}

int main(){
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("random_nums.txt", "r+");
    fp2 = fopen("output_sorted_array.txt", "w");

    // generate_random_numbers(0,100,10,fp1);

    read_and_sort(fp1,fp2,10);
    fclose(fp1);
    fclose(fp2);
    return 0;
}