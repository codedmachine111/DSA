// c program to implement an image viewer using a doubly linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char image[100];
    struct node *right;
    struct node *left;
};

// CREATE NODE
struct node *createNode(char *image)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->image, image);
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

// INSERT NODE AT THE END
void insertAtEnd(struct node **head, char *image)
{
    struct node *newNode = createNode(image);
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

// view current image
void viewCurrentImage(struct node *head)
{
    if(head == NULL)
    {
        printf("No image to view\n");
    }
    else
    {
        printf("Current image: %s\n", head->image);
    }
}

// view right image
void viewrightImage(struct node **head)
{
    if(*head == NULL)
    {
        printf("No image to view\n");
    }
    else if((*head)->right == NULL)
    {
        printf("No right image\n");
    }
    else
    {
        *head = (*head)->right;
        printf("Current image: %s\n", (*head)->image);
    }
}

// view left image
void viewleftImage(struct node **head)
{
    if(*head == NULL)
    {
        printf("No image to view\n");
    }
    else if((*head)->left == NULL)
    {
        printf("No left image\n");
    }
    else
    {
        *head = (*head)->left;
        printf("Current image: %s\n", (*head)->image);
    }
}

// main function
int main()
{
    struct node *head = NULL;
    int choice;
    char image[100];
    while(1)
    {
        printf("1. Insert image\n");
        printf("2. View current image\n");
        printf("3. View next image\n");
        printf("4. View previous image\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter image name: ");
                scanf("%s", image);
                insertAtEnd(&head, image);
                break;
            case 2:
                viewCurrentImage(head);
                break;
            case 3:
                viewrightImage(&head);
                break;
            case 4:
                viewleftImage(&head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

