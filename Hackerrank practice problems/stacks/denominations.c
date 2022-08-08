#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack
{
    int data[SIZE];
    int top;
};
void push(struct stack* sptr)
{
    int num;
    printf("Enter coin value\n");
    scanf("%d",&num);
    if(sptr->top ==  SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}
void denomination(struct stack* sptr)
{
    int co,ct,cf,cten,cinvalid;
    co=ct=cf=cten=cinvalid=0;
    if(sptr->top==-1)
    {
        printf("No coins\n");
    }
    for(int i=sptr->top; i>=0; i--)
    {
        if(sptr->data[i]==1)
        {
            co++;
        }
        else if(sptr->data[i]==2)
        {
            ct++;
        }
        else if(sptr->data[i]==5)
        {
            cf++;
        }
        else if(sptr->data[i]==10)
        {
            cten++;
        }
        else
        {
            cinvalid++;
        }
    }
    printf("Coins of 1 re = %d\n",co);
    printf("Coins of 2 rs = %d\n",ct);
    printf("Coins of 5 rs = %d\n",cf);
    printf("Coins of 10 rs = %d\n",cten);
    printf("Coins of invalid denominations = %d\n",cinvalid);
}

int main()
{
    int n;
    struct stack *sptr;
    struct stack s[SIZE];
    sptr=&s;
    sptr->top = -1;
    printf("Enter number of coins\n");
    scanf("%d",&n);
    if(n>0)
    {
        for(int i=0; i<n; i++)
        {
            push(sptr);
        }
        denomination(sptr);
    }
    else{
        printf("Invalid number of coins\n");
    }
}
