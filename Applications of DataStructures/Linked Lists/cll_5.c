// C PROGRAM TO IMPLEMENT A MESSAGING APPLICATION USING CIRCULAR LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char message[100];
    struct node *next;
};

// create a node
struct node *createNode(char message[])
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    strcpy(temp->message,message);
    temp->next=NULL;
    return temp;
}

// insert a node at the end
struct node *insertEnd(struct node *tail, char message[])
{
    struct node *temp;
    temp=createNode(message);
    if(tail==NULL)
    {
        tail=temp;
        tail->next=tail;
    }
    else
    {
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
    }
    return tail;
}

// display the messages
void display(struct node *tail)
{
    if(tail==NULL)
    {
        printf("\nNo messages to display\n");
        return;
    }
    struct node *cur;
    cur=tail->next;
    do
    {
        printf("%s -> ",cur->message);
        cur=cur->next;
    }while(cur!=tail->next);
    printf("...\n");
}

// main function
int main()
{
    struct node *tail=NULL;
    int choice;
    char message[100];
    do
    {
        printf("\nMessaging Application\n");
        printf("1. Send a message\n");
        printf("2. Display all messages\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the message: ");
                scanf("%s",message);
                tail=insertEnd(tail,message);
                break;
            case 2:
                display(tail);
                break;
            case 3:
                printf("\nExiting from the application\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }while(choice!=3);
    return 0;
}