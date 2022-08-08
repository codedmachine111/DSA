#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack
{
    int data[SIZE];
    int top;
};

void push(struct stack* sptr, int num)
{
    if(sptr->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}
int pop(struct stack* sptr)
{
    int num;
    if(sptr->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        num = sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}
void DecToBin(struct stack* sptr, int num)
{
    int rem;
    while(num!=0)
    {
        rem = num%2;
        push(sptr,rem);
        num= num/2;
    }
    while(sptr->top != -1)
    {
        printf("%d", pop(sptr));
    }
    printf("\n");
}

int main()
{
    struct stack* sptr;
    struct stack s[SIZE];
    sptr = &s;
    sptr->top = -1;

    int num,d;
    scanf("%d",&num);
    if(num<=0)
    {
        printf("Number should be greater than 0.");
    }
    DecToBin(sptr,num);

    return 0;
}
