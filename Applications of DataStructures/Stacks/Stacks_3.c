// C PROGRAM TO DEVELOP A CALCULATOR USING STACKS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

// structure to represent a stack
struct stack {
    int data[MAX_COMMAND_LENGTH];
    int top;
};

// function to push an element into the stack
void push(struct stack *sptr, int newElement) {
    if(sptr->top == MAX_COMMAND_LENGTH - 1) {
        printf("Stack Overflow\n");
    } else {
        sptr->top++;
        sptr->data[sptr->top] = newElement;
    }
}

// function to pop an element from the stack
int pop(struct stack *sptr) {
    if(sptr->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int element = sptr->data[sptr->top];
        sptr->top--;
        return element;
    }
}

// FUNCTION TO EVALUATE THE POSTFIX EXPRESSION
int evaluatePostfix(char *postfix) {
    struct stack *sptr;
    struct stack s;
    sptr = &s;
    sptr->top = -1;

    int i=0;
    while(postfix[i] != '\0') {
        if(postfix[i] >= '0' && postfix[i] <= '9') {
            push(sptr, postfix[i] - '0');
        } else {
            int operand1 = pop(sptr);
            int operand2 = pop(sptr);
            switch(postfix[i]) {
                case '+':
                    push(sptr, operand2 + operand1);
                    break;
                case '-':
                    push(sptr, operand2 - operand1);
                    break;
                case '*':
                    push(sptr, operand2 * operand1);
                    break;
                case '/':
                    push(sptr, operand2 / operand1);
                    break;
                case '%':
                    push(sptr, operand2 % operand1);
                    break;
            }
        }
        i++;
    }
    return pop(sptr);
}

// main function
int main() {
    char postfix[MAX_COMMAND_LENGTH] = "23*54*+9-";

    printf("Result: %d\n", evaluatePostfix(postfix));
    // prints 17 because 2*3 + 5*4 - 9 = 17
    return 0;
}