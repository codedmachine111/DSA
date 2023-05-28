#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n){
    int isSorted=0;
    int temp;
    for(int i=0; i<n-1; i++){
        isSorted=1;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
            isSorted=0;
        }
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int arr[], int n){
    int min_idx;
     for (int i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx=j;
            } 
           if(min_idx != i){
            swap(&arr[min_idx], &arr[i]);
           }
        }
          
    }
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void display(int arr[], int n){
    for(int j=0; j<n; j++){
        printf("%d ", arr[j]);
    }
}
int factorial(int n){
    if(n>=1){
        return n* factorial(n-1);
    }else{
        return 1;
    }
}
int main(){
    int arr[10];
    srand(time(NULL));

    for(int i =0; i<10; i++){
        arr[i] = (rand() % 100);
    }
    
    display(arr, 10);
    printf("\n");
    // bubble_sort(arr, 10);
    // selection_sort(arr, 10);
    mergeSort(arr, 0, 10);
    display(arr, 10);
    // int f = factorial(5);
    // printf("%d", f);
    return 0;
}