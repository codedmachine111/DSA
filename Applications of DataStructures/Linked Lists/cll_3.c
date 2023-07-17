// C  PROGRAM TO SIMULATE A BUS ROUTE USING CIRCULAR LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[100];
    struct node *next;
};

struct node *createNode(char name[])
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    strcpy(temp->name,name);
    temp->next=NULL;
    return temp;
}

struct node *insertEnd(struct node *tail, char name[])
{
    struct node *temp;
    temp=createNode(name);
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

// function to display the route
void display(struct node *tail)
{
    if(tail==NULL)
    {
        printf("\nNo stops to display\n");
        return;
    }
    struct node *cur;
    cur=tail->next;
    do
    {
        printf("%s -> ",cur->name);
        cur=cur->next;
    }while(cur!=tail->next);
    printf("...\n");
}

void navigateRoute(struct node *tail){
    if(tail == NULL){
        printf("\nNo stops to navigate\n");
        return;
    }
    struct node *cur;
    cur=tail->next;
    int choice;
    while(1){
        printf("Press 1 for next stop, 0 to exit");
        scanf("%d",&choice);
        if(choice==0){
            break;
        }
        cur=cur->next;
        printf("\nCurrent Stop: %s\n",cur->name);
    }
}

// main function
int main()
{
    struct node *tail=NULL;
    int choice;
    char name[100];
    while(1)
    {
        printf("\n 1. add a stop\n 2. display the route\n 3. navigate the route\n 0. exit\n ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the name of the stop: ");
                scanf("%s",name);
                tail=insertEnd(tail,name);
                break;
            case 2:
                display(tail);
                break;
            case 3:
                navigateRoute(tail);
                break;
            case 0:
                exit(0);
            default:
                printf("\nInvalid Choice\n");
        }
    }
    return 0;
}