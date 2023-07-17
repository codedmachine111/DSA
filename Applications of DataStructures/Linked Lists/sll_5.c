// C PROGRAM TO CREATE AN EMAIL INBOX USING SINGLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char from[20];
    char to[20];
    char subject[20];
    char body[100];
    struct node *next;
};

// FUNCTION TO CREATE A NODE
struct node* createNode(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory is full\n");
        exit(0);
    }
    return newNode;
}

// FUNCTION TO INSERT A NODE AT THE END
struct node *insertEnd(struct node* head, char from[], char to[], char subject[], char body[]){
    struct node* newNode = createNode();
    struct node* cur;

    strcpy(newNode->from, from);
    strcpy(newNode->to, to);
    strcpy(newNode->subject, subject);
    strcpy(newNode->body, body);
    newNode->next = NULL;

    if(head==NULL){
        head = newNode;
        return head;
    }
    cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = newNode;

    return head;
}

// FUNCTION TO DISPLAY THE CONTENTS OF THE LINKED LIST
void display(struct node* head){
    struct node* cur;
    if(head == NULL){
        printf("Empty Linked List\n");
        return;
    }
    cur = head;
    while(cur != NULL){
        printf("From: %s\n",cur->from);
        printf("To: %s\n",cur->to);
        printf("Subject: %s\n",cur->subject);
        printf("Body: %s\n",cur->body);
        printf("\n");
        cur = cur->next;
    }
}

int main(){
    struct node *head = NULL;
    int choice;
    char from[20], to[20], subject[20], body[100];

    while(1){
        printf("1. Compose\n");
        printf("2. Inbox\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("From: ");
                scanf("%s",from);
                printf("To: ");
                scanf("%s",to);
                printf("Subject: ");
                scanf("%s",subject);
                printf("Body: ");
                scanf("%s",body);
                head = insertEnd(head, from, to, subject, body);
                break;
            case 2:
                display(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}