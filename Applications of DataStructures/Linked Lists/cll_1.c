//  C PROGRAM TO IMPLRMENT A MUSIC PLAYER USING CIRCULAR LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char song[20];
    struct node *next;
};

// CREATING A NODE
struct node *create()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
}

// INSERTING A NODE AT THE END
struct node *insertEnd(struct node *tail, char song[])
{
    struct node *temp;
    temp=create();
    strcpy(temp->song,song);
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

// INSERTING A NODE AT THE BEGINNING
struct node *insertBeg(struct node *tail, char song[])
{
    struct node *temp;
    temp=create();
    strcpy(temp->song,song);
    if(tail==NULL)
    {
        tail=temp;
        tail->next=tail;
    }
    else
    {
        temp->next=tail->next;
        tail->next=temp;
    }
    return tail;
}

// DISPLAYING THE LIST
void display(struct node *tail)
{
    struct node *temp;
    temp=tail->next;
    if(tail==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nSONGS IN THE PLAYLIST ARE:\n");
        while(temp!=tail)
        {
            printf("%s\n",temp->song);
            temp=temp->next;
        }
        printf("%s\n",temp->song);
    }
}

// function to play songs in a loop
void playPlaylist(struct node *tail){
    if(tail == NULL){
        printf("Empty playlist\n");
        return;
    }
    struct node *cur = tail->next;
    printf("Playing %s\n", cur->song);
    while(1){
        printf("Press 1 to play next song and 0 to exit\n");
        int ch;
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        cur = cur->next;
        printf("Playing %s\n", cur->song);
    }
}

// main function
int main()
{
    struct node *tail=NULL;
    int ch;
    char song[20];
    while(1)
    {
        printf("\n1. Add song to the playlist\n2. Display the playlist\n3. Play the playlist\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the name of the song: ");
                scanf("%s",song);
                tail=insertEnd(tail,song);
                break;
            case 2:
                display(tail);
                break;
            case 3:
                playPlaylist(tail);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}