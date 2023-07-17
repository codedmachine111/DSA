// C PROGRAM TO DEVELOP A PHONE CALL LOG MANAGEMENT SYSTEM USING SINGLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    long long int ph_no;
    char name[20];
    char call_type[20];
    int duration;
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
struct node *insertEnd(struct node* head, int ph_no, char name[], char call_type[], int duration){
    struct node* newNode = createNode();
    struct node* cur;

    newNode->ph_no = ph_no;
    newNode->duration = duration;
    strcpy(newNode->name, name);
    strcpy(newNode->call_type, call_type);
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
        printf("%lld\t%s\t%s\t%d\n",cur->ph_no,cur->name,cur->call_type,cur->duration);
        cur = cur->next;
    }
    printf("\n");
}

// FUNCTION TO DELETE A NODE FROM THE BEGINNING
struct node* deleteBeg(struct node* head){
    struct node* temp;
    if(head == NULL){
        printf("Empty Linked List\n");
        return head;
    }
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

// FUNCTION TO DELETE A NODE FROM THE END
struct node* deleteEnd(struct node* head){
    struct node* cur;
    struct node* prev;
    if(head == NULL){
        printf("Empty Linked List\n");
        return head;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    cur = head;
    while(cur->next != NULL){
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    free(cur);
    return head;
}

// MAIN FUNCTION
int main(){
    struct node* head = NULL;
    int choice, duration;
    long long int ph_no;
    char name[20], call_type[20];
    while(1){
        printf("1. Insert a call log\n");
        printf("2. Delete a call log\n");
        printf("3. Display the call log\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the phone number: ");
                scanf("%lld",&ph_no);
                printf("Enter the name: ");
                scanf("%s",name);
                printf("Enter the call type: ");
                scanf("%s",call_type);
                printf("Enter the duration (MINUTES): ");
                scanf("%d",&duration);
                head = insertEnd(head, ph_no, name, call_type, duration);
                break;
            case 2:
                head = deleteEnd(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}