#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

struct stack
{
    char data[SIZE];
    int top;
};

void push(struct stack *sptr, char letter)
{
    if(sptr->top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=letter;
    }
}

void pop(struct stack* sptr)
{
    if(sptr->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        sptr->top--;
    }
}
void check(struct stack* sptr, int mid)
{
    int front =0;

    for(int j=0; j<mid; j++)
    {
        if(sptr->data[sptr->top]==sptr->data[front])
        {
            pop(sptr);
            front++;
        }
        else
        {
            printf("Invalid parking\n");
            break;
        }
    }
    if(mid == front)
    {
        printf("Valid parking");
    }
}
int main()
{
    int len,mid;
    int n,j;
    char str[SIZE];
    struct stack *sptr;
    struct stack s;

    sptr = &s;
    sptr->top = -1;
    scanf("%d ",&n);
    gets(str);

    len = strlen(str);
    mid = len/2;

    for(int k=0; k<len; k++)
    {
        if(str[k]=='G' ||str[k]=='Y' ||str[k]=='R' ||str[k]=='B')
        {
            push(sptr,str[k]);
        }

    }
    check(sptr,mid);
}
