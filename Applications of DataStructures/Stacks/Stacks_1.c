#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 100

struct stack{
    char text[MAX_TEXT_LENGTH][MAX_TEXT_LENGTH];
    int top;
};

// function to push a new text into the stack
void push(struct stack *sptr, char *newText){
    if(sptr->top == MAX_TEXT_LENGTH - 1){
        printf("Stack Overflow\n");
    }
    else{
        sptr->top++;
        strcpy(sptr->text[sptr->top], newText);
    }
}

// function to UNDO
void undo(struct stack *sptr){
    if(sptr->top == -1){
        printf("Stack Underflow\n");
    }
    else{
        sptr->top--;
    }
}

// function to REDO
void redo(struct stack *sptr){
    if(sptr->top == MAX_TEXT_LENGTH - 1){
        printf("Stack Overflow\n");
    }
    else{
        sptr->top++;
    }
}   

// function to display the text
void display(struct stack *sptr){
    if(sptr->top == -1){
        printf("Stack empty\n");
    }
    else{
        for(int i = sptr->top; i>=0; i--){
            printf("%s\n", sptr->text[i]);
        }
    }
}

// Main function
int main(){
    struct stack *sptr;
    struct stack s;
    sptr = &s;
    sptr->top = -1;
    int choice;
    char text[MAX_TEXT_LENGTH];

    while(1){
        printf("1. Enter text\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter text: ");
                scanf("%s", text);
                push(&s, text);
                break;
            case 2:
                undo(&s);
                break;
            case 3:
                redo(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
