#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

struct stack
{
    int data[SIZE];
    int top;
};

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

int pop(struct stack *sptr, FILE *stackfile)
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
    fclose(stackfile);
    stackfile = fopen("stack.txt", "w");
    for(int i= sptr->top; i>=0; i--){
        fprintf(stackfile, "%d ", sptr->data[i]);
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


int main(){
    struct stack* sptr;
    struct stack s[SIZE];
    sptr = &s;
    sptr->top= -1;

    FILE *input;
    FILE *operation;
    FILE *popfile;
    FILE *pushfile;
    FILE *stackfile;

    input = fopen("input.txt", "r+");
    srand(time(0));
    for(int i = 0; i < 10; i++){
        int num = rand() % 100;
        fprintf(input, "%d ", num);
    }
    fclose(input);

    input = fopen("input.txt", "r+");
    operation = fopen("operation.txt", "a");
    popfile = fopen("pop.txt", "a");
    pushfile = fopen("push.txt", "a");
    stackfile = fopen("stack.txt", "w");

    int choice, num;
    while(1){
        printf("1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int pushed;
                fscanf(input, "%d", &pushed);
                push(sptr, pushed);

                fprintf(pushfile, "%d was pushed\n", pushed);
                fprintf(operation, "Pushed %d\n", pushed);
                fprintf(stackfile, "%d ", pushed);
    
                break;
            case 2:
                num = pop(sptr, stackfile);
                printf("The popped element is %d\n", num);
                fprintf(popfile, "%d was popped\n", num);
                fprintf(operation, "Popped %d\n", num);
                break;
            case 3:
                display(sptr);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}