// C PROGRAM TO EVALUATE BRACKETS USING STACKS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100

// structure to represent a stack
struct stack {
    char expression[MAX_EXPRESSION_LENGTH];
    int top;
};

// function to push an element into the stack
void push(struct stack *sptr, char newElement) {
    if(sptr->top == MAX_EXPRESSION_LENGTH - 1) {
        printf("Stack Overflow\n");
    } else {
        sptr->top++;
        sptr->expression[sptr->top] = newElement;
    }
}

// function to pop an element from the stack
void pop(struct stack *sptr) {
    if(sptr->top == -1) {
        printf("Stack Underflow\n");
        return;
    } else {
        sptr->top--;
    }
}

// function to evaluate all types of brackets in the given exxpression
void evaluateBrackets(struct stack *sptr, char *expression) {
    int i;
    for(i = 0; i < strlen(expression); i++) {
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(sptr, expression[i]);
        } else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if(sptr->top == -1) {
                printf("The brackets are not balanced\n");
                return;
            } else {
                pop(sptr);
            }
        }
    }
    if(sptr->top == -1) {
        printf("The brackets are balanced\n");
    } else {
        printf("The brackets are not balanced\n");
    }
}

// main function
int main() {
    struct stack *sptr;
    struct stack s;
    sptr = &s;
    sptr->top = -1;
    char expression[MAX_EXPRESSION_LENGTH] = "((a+b)*(c+d))";
    evaluateBrackets(sptr, expression); // The brackets are balanced
}