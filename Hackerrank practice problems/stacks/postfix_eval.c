#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 100

struct stack
{
    int data[SIZE];
    int top;
};
void push(struct stack* sptr,int num)
{
    if(sptr->top== SIZE-1)
    {
        printf("Stack overflow\n");
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
    if(sptr->top==-1)
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
int main()
{
    int eval;
    char str[SIZE];
    struct stack* sptr;
    struct stack s[SIZE];
    sptr= &s;

    printf("Enter postfix expression\n");
    gets(str);
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        if(isdigit(str[i]))
        {
            push(sptr, str[i]-'0');
        }
        else
        {
            int val2 = pop(sptr);
            int val1 = pop(sptr);
            switch(str[i])
            {
            case '+':
                push(sptr, val1+ val2);
                break;
            case '-':
                push(sptr, val1- val2);
                break;
            case '*':
                push(sptr, val1* val2);
                break;
            case '/':
                push(sptr, val1/ val2);
                break;
            default:
                printf("operator not identified\n");
                break;
            }
        }
    }

    eval = pop(sptr);
    printf("Evaluated result : %d",eval);
}

