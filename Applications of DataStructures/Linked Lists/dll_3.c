// C program for Text Editor: Implement a text editor using a doubly linked list to represent the lines of text, enabling operations like insertion, deletion, and navigation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char line[20];
    struct node *right;
    struct node *left;
};

// CREATE NODE
struct node *createNode(char *line)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->line, line);
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

// function to add a line
struct node *insertLine(struct node *head, char *line){
    struct node *newNode = createNode(line);
    if(head == NULL){
        head = newNode;
    }
    else{
        struct node *temp = head;
        while(temp->right != NULL){
            temp = temp->right;
        }
        temp->right = newNode;
        newNode->left = temp;
    }
    return head;
}

// function to delete a line
struct node *deleteLine(struct node *head, int lineNo){
    if(head == NULL){
        printf("No lines to delete\n");
    }
    else{
        struct node *temp = head;
        int count = 1;
        while(temp != NULL){
            if(count == lineNo){
                if(temp->left == NULL){
                    head = temp->right;
                    head->left = NULL;
                    free(temp);
                    break;
                }
                else if(temp->right == NULL){
                    temp->left->right = NULL;
                    free(temp);
                    break;
                }
                else{
                    temp->left->right = temp->right;
                    temp->right->left = temp->left;
                    free(temp);
                    break;
                }
            }
            temp = temp->right;
            count++;
        }
    }
    return head;
}

// function to display all lines
void displayAllLines(struct node *head){
    if(head == NULL){
        printf("No lines to display\n");
    }
    else{
        struct node *temp = head;
        int lineNum =1;
        while(temp != NULL){
            printf("%d. %s\n",lineNum, temp->line);
            temp = temp->right;
            lineNum++;
        }
    }
}


// main function
int main()
{
    struct node *head = NULL;
    int choice;
    char line[20];
    int lineNo;
    while(1){
        printf("1. Add a line\n");
        printf("2. Delete a line\n");
        printf("3. Display all lines\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the line to add: ");
                scanf("%s", line);
                head = insertLine(head, line);
                break;
            case 2:
                printf("Enter the line number to delete: ");
                scanf("%d", &lineNo);
                head = deleteLine(head, lineNo);
                break;
            case 3:
                displayAllLines(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}