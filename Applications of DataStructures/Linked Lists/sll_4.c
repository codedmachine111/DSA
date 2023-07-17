// C PROGRAM TO DEVELOP A SHOPPING LIST USING SINGLY LINKED LIST ENABLING USER TO ADD, DELETE, MARK AS PURCHASED, DISPLAY ITEMS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char item[20];
    int purchased;
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
struct node *insertEnd(struct node* head, char item[]){
    struct node* newNode = createNode();
    struct node* cur;

    strcpy(newNode->item, item);
    newNode->purchased = 0;
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
        if(cur->purchased == 0){
            printf("%s\n",cur->item);
        }
        cur = cur->next;
    }
    printf("\n");
}

// FUNCTION TO DELETE A NODE
struct node* deleteNode(struct node* head, char item[]){
    struct node* cur;
    struct node* prev;
    if(head == NULL){
        printf("Empty Linked List\n");
        return head;
    }
    cur = head;
    prev = NULL;
    while(cur != NULL){
        if(strcmp(cur->item, item) == 0){
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
    printf("Item not found\n");
    return head;
}

// FUNCTION TO MARK AN ITEM AS PURCHASED
struct node* markPurchased(struct node* head, char item[]){
    struct node* cur;
    if(head == NULL){
        printf("Empty Linked List\n");
        return head;
    }
    cur = head;
    while(cur != NULL){
        if(strcmp(cur->item, item) == 0){
            cur->purchased = 1;
            return head;
        }
        cur = cur->next;
    }
    printf("Item not found\n");
    return head;
}

// FUNCTION TO DISPLAY THE CONTENTS OF THE LINKED LIST
void displayPurchased(struct node* head){
    struct node* cur;
    if(head == NULL){
        printf("Empty Linked List\n");
        return;
    }
    cur = head;
    while(cur != NULL){
        if(cur->purchased == 1){
            printf("%s\n",cur->item);
        }
        cur = cur->next;
    }
    printf("\n");
}

// MAIN FUNCTION
int main(){
    struct node* head = NULL;
    int choice;
    char item[20];
    while(1){
        printf("1. Add an item\n");
        printf("2. Delete an item\n");
        printf("3. Mark an item as purchased\n");
        printf("4. Display items to be purchased\n");
        printf("5. Display purchased items\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the item to be added: ");
                scanf("%s",item);
                head = insertEnd(head, item);
                break;
            case 2:
                printf("Enter the item to be deleted: ");
                scanf("%s",item);
                head = deleteNode(head, item);
                break;
            case 3:
                printf("Enter the item to be marked as purchased: ");
                scanf("%s",item);
                head = markPurchased(head, item);
                break;
            case 4:
                printf("Items to be purchased:\n");
                display(head);
                break;
            case 5:
                printf("Purchased items:\n");
                displayPurchased(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
