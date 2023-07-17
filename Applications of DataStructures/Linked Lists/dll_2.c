//  C PROGRAM TO IMPLEMENT A FILE MANAGEMENT SYSTEM USING DOUBLY LINKED LIST TO ADD DELETE AND NAVIGATE FILES

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char fileName[20];
    struct node *right;
    struct node *left;
};

// CREATE NODE
struct node *createNode(char *fileName)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->fileName, fileName);
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

// INSERT NODE AT THE BEGINNING
void insertAtBeginning(struct node **head, char *fileName)
{
    struct node *newNode = createNode(fileName);
    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->right = *head;
        (*head)->left = newNode;
        *head = newNode;
    }
}

// INSERT NODE AT THE END
void insertAtEnd(struct node **head, char *fileName)
{
    struct node *newNode = createNode(fileName);
    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *temp = *head;
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = newNode;
        newNode->left = temp;
    }
}

// DELETE NODE AT THE BEGINNING
void deleteAtBeginning(struct node **head)
{
    if(*head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct node *temp = *head;
        *head = (*head)->right;
        (*head)->left = NULL;
        free(temp);
    }
}

// DELETE NODE AT THE END
void deleteAtEnd(struct node **head)
{
    if(*head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct node *temp = *head;
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->left->right = NULL;
        free(temp);
    }
}

// DISPLAY THE LIST
void display(struct node *head)
{
    if(head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct node *temp = head;
        while(temp != NULL)
        {
            printf("%s\n", temp->fileName);
            temp = temp->right;
        }
    }
}

// MAIN FUNCTION
int main()
{
    struct node *head = NULL;
    int choice;
    char fileName[20];
    while(1)
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the file name: ");
                scanf("%s", fileName);
                insertAtBeginning(&head, fileName);
                break;
            case 2:
                printf("Enter the file name: ");
                scanf("%s", fileName);
                insertAtEnd(&head, fileName);
                break;
            case 3:
                deleteAtBeginning(&head);
                break;
            case 4:
                deleteAtEnd(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}