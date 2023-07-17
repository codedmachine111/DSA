// C PROGRAM TO IMPLEMENT A SLIDESHOW PRESENTATION IN A LOOP

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int number;
    char content[100];
    struct node *next;
};

struct node *createSlide(int number, char content[])
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->number=number;
    strcpy(temp->content,content);
    temp->next=NULL;
    return temp;
}

// function to add new slide at the end
struct node *insertEnd(struct node *tail, int number, char content[])
{
    struct node *temp;
    temp=createSlide(number,content);
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

// function to display all slides
void display(struct node *tail)
{
    struct node *cur;
    cur=tail->next;
    do
    {
        printf("\nSlide Number: %d\n",cur->number);
        printf("Slide Content: %s\n",cur->content);
        cur=cur->next;
    }while(cur!=tail->next);
}

void navigateSlideshow(struct node *tail){
    if(tail==NULL)
    {
        printf("\nNo slides to display\n");
        return;
    }
    struct node *cur;
    cur = tail->next;
    int choice;
    while(1){
        printf("Enter 1 to go to next slide and 0 to exit\n");
        scanf("%d",&choice);
        if(choice==0){
            break;
        }else{
            printf("\nSlide Number: %d\n",cur->number);
            printf("Slide Content: %s\n",cur->content);
            cur=cur->next;
        }
    }
}

// main function
int main()
{
    struct node *tail=NULL;
    int number;
    char content[100];
    int choice;
    while(1)
    {
        printf("\n1. Add new slide\n");
        printf("2. Display all slides\n");
        printf("3. Navigate slideshow\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter slide number: ");
                scanf("%d",&number);
                printf("Enter slide content: ");
                scanf("%s",content);
                tail=insertEnd(tail,number,content);
                break;
            case 2:
                display(tail);
                break;
            case 3:
                navigateSlideshow(tail);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}