
// Write a program to check whether two matrices are symmetric or not.

#include <stdio.h>
#include <stdlib.h>

int rows1, cols1, rows2, cols2;

void checkSymmetry(int mat1[][cols1], int mat2[][cols2], int rows, int cols){
    int flag = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(mat1[i][j] != mat2[i][j]){
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0){
        printf("The matrices are symmetric\n");
    }
    else{
        printf("The matrices are not symmetric\n");
    }
}

int main(){

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if(rows1 != cols1 && rows2 != cols2){
        printf("They are not square matrices, hence not symmetric");
        exit(0);
    }

    if(rows1 != rows2 || cols1 != cols2){
        printf("The matrices are not symmetric\n");
        exit(0);
    }

    int mat1[rows1][cols1], mat2[rows2][cols2];
    printf("Enter the elements of the first matrix: \n");
    for(int i=0; i<rows1; i++){
        for(int j=0; j<cols1; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix: \n");
    for(int i=0; i<rows2; i++){
        for(int j=0; j<cols2; j++){
            scanf("%d", &mat2[i][j]);
        }
    }

    checkSymmetry(mat1, mat2, rows1, cols1);
    return 0;
}