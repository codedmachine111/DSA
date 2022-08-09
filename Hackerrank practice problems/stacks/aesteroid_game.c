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
void check_collision(struct stack* s1ptr, struct stack* s2ptr)
{
    int status;
    int c_count=0, n_count=0;
    for(int i=s1ptr->top; i>=0; i--)
    {
        if(s1ptr->data[i]>0 && s2ptr->data[i]>0)
        {
            status=0;
            n_count++;
        }
        else if(s1ptr->data[i]<0 && s2ptr->data[i]<0)
        {
            status=0;
            n_count++;
        }
        else
        {
            status = 1;
            c_count++;
        }
        printf("%d ",status);
    }
    printf("%d ",c_count);
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
    printf("Enter the number of colls\n");
    scanf("%d",&num);
    if(num>0)
    {
        for(int i=0; i<num; i++)
        {
            printf("Enter size for s1\n");
            scanf("%d",&s1);
            push(s1ptr,s1);
        }
        for(int i=0; i<num; i++)
        {
            printf("Enter size for s2\n");
            scanf("%d",&s2);
            push(s2ptr,s2);
        }
        check_collision(s1ptr,s2ptr);
    }
    else
    {
        printf("Invalid input.");
    }

}
