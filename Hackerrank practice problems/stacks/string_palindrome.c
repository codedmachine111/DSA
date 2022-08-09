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
int main()
{
    int front =0;
    int len,mid;
    char str[SIZE];
    struct stack *sptr;
    struct stack s;

    sptr = &s;
    sptr->top = -1;
    printf("Enter string\n");
    gets(str);
    len = strlen(str);
    mid = len/2;

    for(int i=0; i<len; i++)
    {
        push(sptr,str[i]);
    }

    for(int j=0; j<mid; j++)
    {
        if(sptr->data[sptr->top]==sptr->data[front])
        {
            pop(sptr);
            front++;
        }
        else
        {
            printf("%s is not a palindrome\n",str);
            break;
        }
    }
    if(mid == front)
    {
        printf("%s is a palindrome",str);
    }

}
