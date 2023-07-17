// C PROGRAM TO DEVELOP A CALANDER EVENT MANAGEMENT SYSTEM USING SINGLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int day;
    int month;
    int year;
    char event[20];
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
struct node *insertEnd(struct node* head, int day, int month, int year, char event[]){
    struct node* newNode = createNode();
    struct node* cur;

    newNode->day = day;
    newNode->month = month;
    newNode->year = year;
    strcpy(newNode->event, event);
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
        printf("%d/%d/%d\t%s\n",cur->day,cur->month,cur->year,cur->event);
        cur = cur->next;
    }
    printf("\n");
}

// FUNCTION TO DELETE A NODE FROM THE LINKED LIST
struct node* deleteNode(struct node* head, int day, int month, int year){
    struct node* cur;
    struct node* prev;
    if(head == NULL){
        printf("Empty Linked List\n");
        return head;
    }
    cur = head;
    prev = NULL;
    while(cur != NULL){
        if(cur->day == day && cur->month == month && cur->year == year){
            if(prev == NULL){
                head = cur->next;
                free(cur);
                return head;
            }
            prev->next = cur->next;
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Event not found\n");
    return head;
}

// FUNCTION TO SEARCH FOR A NODE IN THE LINKED LIST
void search(struct node* head, int day, int month, int year){
    struct node* cur;
    if(head == NULL){
        printf("Empty Linked List\n");
        return;
    }
    cur = head;
    while(cur != NULL){
        if(cur->day == day && cur->month == month && cur->year == year){
            printf("%d/%d/%d\t%s\n",cur->day,cur->month,cur->year,cur->event);
            return;
        }
        cur = cur->next;
    }
    printf("Event not found\n");
}

// FUNCTION TO UPDATE A NODE IN THE LINKED LIST
void update(struct node* head, int day, int month, int year, char event[]){
    struct node* cur;
    if(head == NULL){
        printf("Empty Linked List\n");
        return;
    }
    cur = head;
    while(cur != NULL){
        if(cur->day == day && cur->month == month && cur->year == year){
            strcpy(cur->event, event);
            return;
        }
        cur = cur->next;
    }
    printf("Event not found\n");
}

// MAIN FUNCTION
int main(){
    struct node* head = NULL;
    int choice, day, month, year;
    char event[20];
    while(1){
        printf("1. Insert an event\n");
        printf("2. Delete an event\n");
        printf("3. Search for an event\n");
        printf("4. Update an event\n");
        printf("5. Display all events\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the date of the event: ");
                scanf("%d%d%d",&day,&month,&year);
                printf("Enter the event: ");
                scanf("%s",event);
                head = insertEnd(head, day, month, year, event);
                break;
            case 2:
                printf("Enter the date of the event: ");
                scanf("%d%d%d",&day,&month,&year);
                head = deleteNode(head, day, month, year);
                break;
            case 3:
                printf("Enter the date of the event: ");
                scanf("%d%d%d",&day,&month,&year);
                search(head, day, month, year);
                break;
            case 4:
                printf("Enter the date of the event: ");
                scanf("%d%d%d",&day,&month,&year);
                printf("Enter the new event: ");
                scanf("%s",event);
                update(head, day, month, year, event);
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