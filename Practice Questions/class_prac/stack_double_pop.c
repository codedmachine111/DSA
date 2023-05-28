// PUSHING ELEMENTS TO STACK AND POPPING OUT DOUBLE OF THEM AND STORING IN ANOTHER FILE

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack
{
    int data[SIZE];
    int top;
};


// using linked list
struct stack_ll
{
    int data;
    struct stack_ll *next;
};

struct stack_ll *top = NULL;

void push_ll(int num)
{
    struct stack_ll *new_node;
    new_node = (struct stack_ll *)malloc(sizeof(struct stack_ll));
    new_node->data = num;
    new_node->next = top;
    top = new_node;
}

void pop_ll()
{
    struct stack_ll *temp;
    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}

void display_ll()
{
    struct stack_ll *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Stack empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void push(struct stack *sptr, int num)
{
    if (sptr->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top] = num;
    }
}

int pop(struct stack *sptr)
{
    int num;
    if (sptr->top == -1)
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

void display(struct stack *sptr)
{
    if (sptr->top == -1)
    {
        printf("Stack empty\n");
    }
    else
    {
        for (int i = sptr->top; i >= 0; i--)
        {
            printf("%d->", sptr->data[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct stack s;
    s.top = -1;
    int num;

    FILE *fp1, *fp2;
    fp1 = fopen("data.txt", "r");
    fp2 = fopen("output.txt", "w");

    while(!feof(fp1)){
        fscanf(fp1, "%d", &num);
        push(&s, num);
    }

    display(&s);

    while(s.top != -1){
        num = pop(&s);
        fprintf(fp2, "%d ", 2*num);
    }
    display(&s);

    fclose(fp1);
    fclose(fp2);

    FILE *fp3;
    fp3 = fopen("output.txt", "r");
    while(!feof(fp3)){
        fscanf(fp3, "%d", &num);
        push(&s, num);
    }
    
    display(&s);
    return 0;
}
