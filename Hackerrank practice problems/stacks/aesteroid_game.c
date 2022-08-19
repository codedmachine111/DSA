#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack
{
    int data[SIZE];
    int top;
};
void push(struct stack* sptr,int num)
{
    if(sptr->top == SIZE-1)
    {
        printf("Stack overflow");
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

void display(struct stack* sptr)
{
    if(sptr->top ==-1)
    {
        printf("Empty stack\n");
    }
    else
    {
        for(int i= sptr->top; i>=0; i--)
        {
            printf("%c ",sptr->data[i]);
        }
        printf("\n");
    }
}

int peek(struct stack* sptr)
{
    int num;
    if(sptr->top== -1)
    {
        printf("Empty stack \n");
    }
    else
    {
       num =sptr->data[sptr->top];
    }
    return num;
}

void check_collision(struct stack* s1ptr, struct stack* s2ptr)
{
    int status;
    int c_count=0, n_count=0;
    int n1,n2;
    while(s1ptr->top!=-1 && s2ptr->top!=-1)
    {
        n1=peek(s1ptr);
        n2=peek(s2ptr);
        if(n1>0 && n2>0){
            n_count++;
            printf("0 ");
            pop(s1ptr);
            pop(s2ptr);
        }
        else if(n1<0 && n2<0){
            n_count++;
            printf("0 ");
            pop(s1ptr);
            pop(s2ptr);
        }
        else if(n1<0 && n2>0){
            c_count++;
            printf("1 ");
            pop(s1ptr);
            pop(s2ptr);
        }
        else if(n1>0 && n2<0){
            c_count++;
            printf("1 ");
            pop(s1ptr);
            pop(s2ptr);
        }
        else{
            if(n1 == 0){
                pop(s1ptr);
            }
            if(n2 == 0){
                pop(s2ptr);
            }
        }
    }
    printf("\n");
    printf("%d \n",c_count);
    printf("%d ",n_count);
}
int main()
{
    int num;
    struct stack* s1ptr;
    struct stack p[SIZE];
    struct stack* s2ptr;
    struct stack n[SIZE];
    s1ptr = &p;
    s2ptr = &n;
    s1ptr->top = -1;
    s2ptr->top = -1;

    int s1,s2;
    scanf("%d",&num);
    if(num>0)
    {
        for(int i=0; i<num; i++)
        {
            scanf("%d",&s1);
            push(s1ptr,s1);
        }
        for(int i=0; i<num; i++)
        {
            scanf("%d",&s2);
            push(s2ptr,s2);
        }
        check_collision(s1ptr,s2ptr);
    }
    else
    {
        printf("Invalid input");
    }

}
