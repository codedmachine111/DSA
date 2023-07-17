// C PROGRAM TO DEVELOP A BROWSER TAB MANAGEMENT SYSTEM USING STACKS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

// structure to represent a stack
struct stack {
    char command[MAX_COMMAND_LENGTH][MAX_COMMAND_LENGTH];
    int top;
};

// function to push an element into the stack
void push(struct stack *sptr, char newElement[]) {
    if(sptr->top == MAX_COMMAND_LENGTH - 1) {
        printf("Stack Overflow\n");
    } else {
        sptr->top++;
        strcpy(sptr->command[sptr->top], newElement);
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

// function to display the current tab
void displayCurrentTab(struct stack *sptr) {
    if(sptr->top == -1) {
        printf("Stack empty\n");
    } else {
        printf("Current tab: %s\n", sptr->command[sptr->top]);
    }
}

// function to display the previous tab
void displayPreviousTab(struct stack *sptr) {
    if(sptr->top == -1) {
        printf("Stack empty\n");
    } else if(sptr->top == 0) {
        printf("No previous tab\n");
    } else {
        printf("Previous tab: %s\n", sptr->command[sptr->top - 1]);
    }
}

// main function
int main() {
    struct stack *sptr;
    struct stack s;
    sptr = &s;
    sptr->top = -1;

    int choice;
    char newCommand[MAX_COMMAND_LENGTH];

    while(1) {
        printf("1. Open a new tab\n");
        printf("2. Close current tab\n");
        printf("3. Display current tab\n");
        printf("4. Display previous tab\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the URL: ");
                scanf("%s", newCommand);
                push(sptr, newCommand);
                break;
            case 2:
                pop(sptr);
                break;
            case 3:
                displayCurrentTab(sptr);
                break;
            case 4:
                displayPreviousTab(sptr);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}