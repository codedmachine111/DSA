#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int length(char a[100])
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}

void stringfn(int num)
{
    char lines[10][100];
    int line_lengths[100];

    for(int i=0;i<=num;i++)
    {
        gets(lines[i]);
    }
    
    for(int j=0; j<=num; j++){
        line_lengths[j] = length(lines[j]);
    }

    int max,j;
    max = line_lengths[0];
    for(int k=0; k<=num; k++){
        if(line_lengths[k]>max){
            max = line_lengths[k];
            j=k;
        }
    }

    printf("the longest line is \n");
    puts(lines[j]);
}

void main()
{
    int num;
    printf("number of lines to be printed=");
    scanf("%d",&num);
    stringfn(num);
}