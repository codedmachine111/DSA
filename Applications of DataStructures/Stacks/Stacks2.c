//  C PROGRAM TO IMPLEMENT TERMINAL COMMAND HISTORY USING STACKS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

struct stack {
    char command[MAX_COMMAND_LENGTH][MAX_COMMAND_LENGTH];
    int top;
};


void push(struct stack *sptr, char *newCommand) {
    if(sptr->top == MAX_COMMAND_LENGTH - 1) {
        printf("Stack Overflow\n");
    } else {
        sptr->top++;
        strcpy(sptr->command[sptr->top], newCommand);
    }
}

// fucntion to execute previous command
void executePrevious(struct stack *sptr) {
    if(sptr->top == -1) {
        printf("Stack empty\n");
    } else {
        printf("Executing command: %s\n", sptr->command[sptr->top]);
        // system(sptr->command[sptr->top]);
    }
}

// function to display command history
void display(struct stack *sptr) {
    if(sptr->top == NULL) {
        printf("Stack empty\n");
    } else {
        for(int i=sptr->top; i>=0; i--) {
            printf("%s\n", sptr->command[i]);
        }
    }
}

// fucntion to display previous command
void displayPrevious(struct stack *sptr) {
    if(sptr->top == -1) {
        printf("Stack empty\n");
    } else {
        printf("%s\n", sptr->command[sptr->top]);
    }
}

// main function
int main() {
    struct stack *sptr;
    struct stack s;
    sptr = &s;
    sptr->top = -1;

    int choice;
    char command[MAX_COMMAND_LENGTH];
    while(1) {
        printf("1. Enter a command\n");
        printf("2. Display command history\n");
        printf("3. Display previous command\n");
        printf("4. Execute previous command\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter a command: ");
                scanf("%s", command);
                push(sptr, command);
                break;
            case 2:
                display(sptr);
                break;
            case 3:
                displayPrevious(sptr);
                break;
            case 4:
                executePrevious(sptr);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}