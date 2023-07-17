//  C PROGRAM TO IMPLEMENT A MUSIC SYSTEM USING DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char song[20];
    char artist[20];
    struct node *right;
    struct node *left;
};

// CREATE NODE
struct node *createNode(char *song, char *artist)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->song, song);
    strcpy(newNode->artist, artist);
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

// INSERT NODE AT THE BEGINNING
void insertAtBeginning(struct node **head, char *song, char *artist)
{
    struct node *newNode = createNode(song, artist);
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
void insertAtEnd(struct node **head, char *song, char *artist)
{
    struct node *newNode = createNode(song, artist);
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
            printf("%s - %s\n", temp->song, temp->artist);
            temp = temp->right;
        }
    }
}

// DELETE A SONG
void deleteSong(struct node **head, char *song)
{
    if(*head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct node *temp = *head;
        while(temp != NULL)
        {
            if(strcmp(temp->song, song) == 0)
            {
                if(temp == *head)
                {
                    *head = (*head)->right;
                    (*head)->left = NULL;
                    free(temp);
                    return;
                }
                else if(temp->right == NULL)
                {
                    temp->left->right = NULL;
                    free(temp);
                    return;
                }
                else
                {
                    temp->left->right = temp->right;
                    temp->right->left = temp->left;
                    free(temp);
                    return;
                }
            }
            temp = temp->right;
        }
        printf("The song is not found\n");
    }
}

// MAIN FUNCTION
int main()
{
    struct node *head = NULL;
    int choice;
    char song[20], artist[20];
    while(1)
    {
        printf("1. Insert a song at the beginning\n");
        printf("2. Insert a song at the end\n");
        printf("3. Display the list\n");
        printf("4. Delete a song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the song name: ");
                scanf("%s", song);
                printf("Enter the artist name: ");
                scanf("%s", artist);
                insertAtBeginning(&head, song, artist);
                break;
            case 2:
                printf("Enter the song name: ");
                scanf("%s", song);
                printf("Enter the artist name: ");
                scanf("%s", artist);
                insertAtEnd(&head, song, artist);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Enter the song name: ");
                scanf("%s", song);
                deleteSong(&head, song);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}