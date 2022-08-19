#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

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

int pop(struct stack* sptr)
{
    int num;
    if(sptr->top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        num = sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}
void display(struct stack* sptr)
{
    if(sptr->top == -1)
    {
        printf("Stack empty\n");
    }
    else
    {
        for(int i= sptr->top; i>=0; i--)
        {
            printf("%d->",sptr->data[i]);
        }
        printf("\n");
    }
}
void check(struct stack* sptr,struct stack* pptr,struct stack* nptr){
    if(sptr->top ==-1){
        printf("stack empty");
    }
    else{
        for(int i=(sptr->top); i>=0; i--){
            if(sptr->data[i]>0){
                push(pptr,sptr->data[i]);
            }
            else{
                push(nptr,sptr->data[i]);
            }
        }
    }
}
int main()
{
    int num,m,digit;

    struct stack* sptr;
    struct stack s[SIZE];
    sptr= &s;
    sptr->top=-1;

    struct stack* pptr;
    struct stack p[SIZE];
    pptr= &p;
    pptr->top=-1;

    struct stack* nptr;
    struct stack n[SIZE];
    nptr= &n;
    nptr->top=-1;

    printf("Enter number of digits\n");
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        printf("Enter digit\n");
        scanf("%d",&digit);
        push(sptr,digit);
    }
    check(sptr,pptr,nptr);
    display(sptr);
    display(pptr);
    display(nptr);
    return 0;
}


