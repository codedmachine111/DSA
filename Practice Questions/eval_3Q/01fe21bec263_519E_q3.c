#include<stdio.h>
#include<stdlib.h>

void readArray(int (*matrix)[100],int r1,int c1)
{
    int i,j;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",(*(matrix+i)+j));
        }
    }
}
void display(int (*matrix)[100], int r2, int c2)
{
    int i, j;
    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            printf("%d ", *(*(matrix+i) + j));
        }
        printf("\n");
    }
}
void multiply(int (*matrix1)[100],int (*matrix2)[100],int r1,int c2,int r2)
{
    int ans[100][100];

    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
          ans[i][j]=0;
          for(int k=0;k<r2;k++)
          {
            ans[i][j]+=(*(*(matrix1+i)+k))  * (*(*(matrix2+k)+j));
          }
        }
    }
    printf("Multiplied array elements\n");
    display(ans,r1,c2);
}
void main()
{
    int matrix1[100][100],matrix2[100][100];
    int r1,c1,r2,c2;

    printf("Enter value for r1,c1,r2,c2\n");
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2);

    printf("Enter 1 array elements\n");
    readArray(matrix1,r1,c1);

    printf("Enter 2 array elements\n");
    readArray(matrix2,r2,c2);

    printf("1 array elements\n");
    display(matrix1,r1,c1);
    printf("2 array elements\n");
    display(matrix2,r2,c2);
    
    multiply(matrix1,matrix2,r1,c2,r2);
}