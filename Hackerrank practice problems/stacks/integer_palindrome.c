#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

struct stack
{
    int data[SIZE];
    int top;
};

void push(struct stack *sptr, int num)
{
    if(sptr->top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
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
int main()
{
    int front =0,count=0;
    int num,mid;
    struct stack *sptr;
    struct stack s;

    sptr = &s;
    sptr->top = -1;
    scanf("%d",&num);
    if(num>0)
    {
        int temp = num;
        while(temp >0)
        {
            int d = temp % 10;
            push(sptr,d);
            count++;
            temp= temp /10;
        }

        mid = count/2;

        for(int j=0; j<mid; j++)
        {
            if(sptr->data[sptr->top]==sptr->data[front])
            {
                pop(sptr);
                front++;
            }
            else
            {
                printf("%d is not a palindrome number\n",num);
                break;
            }
        }
        if(mid == front)
        {
            printf("%d is a palindrome number",num);
        }

    }
    else
    {
        printf("Invalid number\n");
    }
}
