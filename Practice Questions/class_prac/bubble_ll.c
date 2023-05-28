
// BUBBLE SORT USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *link;
}NODE;

NODE* getNode(){
    NODE *newNode = (NODE*)malloc(sizeof(struct node));
    int data;
    // generate a new random number everytime
    data = (rand()%100);
    
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void insertEnd(NODE **head){
    NODE *newNode = getNode();
    if(*head == NULL){
        *head = newNode;
        return;
    }
    NODE *cur = *head;
    while(cur->link != NULL){
        cur = cur->link;
    }
    cur->link = newNode;
}

void bubbleSort(NODE **head){
    NODE *cur = *head;
    NODE *temp = NULL;
    int swapped;
    do{
        swapped = 0;
        cur = *head;
        while(cur->link != temp){
            if(cur->data > cur->link->data){
                int t = cur->data;
                cur->data = cur->link->data;
                cur->link->data = t;
                swapped = 1;
            }
            cur = cur->link;
        }
        temp = cur;
    }while(swapped);
}

void display(NODE *head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    NODE *temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){     
    NODE *head = NULL;
    int choice;
    srand(time(0));
    while(1){
        printf("1. Insert\n2. Display\n3. Exit\n4. Bubble Sort\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: for(int i =0; i<100; i++){
                        insertEnd(&head);
                    }
                    break;
            case 2: display(head);
                    break;
            case 3: exit(0);
                    break;
            case 4: bubbleSort(&head);
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}