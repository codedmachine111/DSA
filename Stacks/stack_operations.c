#include <stdio.h>
#include <stdlib.h>
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
void peek(struct stack* sptr)
{
    if(sptr->top== -1)
    {
        printf("Empty stack\n");
    }
    else
    {
        printf("\nTOP ELEMENT : %d\n",sptr->data[sptr->top]);
    }
}

int main()
{
    struct stack* sptr;
    struct stack s[SIZE];
    sptr = &s;
    sptr->top= -1;
    int num,ch;
    while(1)
    {
        printf("\nStack operations\n");
        printf("1.Push \n2.Pop \n3.Display \n4.Peek \n5.Exit\n");
        printf("Enter your choice\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d",&num);
            push(sptr,num);
            break;
        case 2:
            num=pop(sptr);
            printf("POPPED %d\n",num);
            break;
        case 3:
            display(sptr);
            break;
        case 4:
            peek(sptr);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

