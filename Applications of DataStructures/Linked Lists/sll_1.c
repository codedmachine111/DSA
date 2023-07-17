// C PROGRAM TO DEVELOP A BANK USER DATABASE SYSTEM USING SINGLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int acc_no;
    char name[20];
    float bal;
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
struct node *insertEnd(struct node* head, int acc_no, char name[], float bal){
    struct node* newNode = createNode();
    struct node* cur;

    newNode->acc_no = acc_no;
    newNode->bal = bal;
    strcpy(newNode->name, name);
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
        printf("%d\t%s\t%f\n",cur->acc_no,cur->name,cur->bal);
        cur = cur->next;
    }
    printf("\n");
}

// Function to search for a node in the linked list
struct node *search(int key,struct node *head)
{
    struct node *cur;
    if(head==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    cur=head;
    while(cur!=NULL)
    {
        if(key==cur->acc_no){
            printf("Search is successfull\n");
            return cur;
        }else{
            cur=cur->next;
        }
    }
    printf("Search is unsuccessfull\n");
    return NULL;
}

// Function to delete a node from the linked list
struct node *delete(int key,struct node *head)
{
    struct node *prev;
    struct node *cur;
    if(head==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(key==head->acc_no)
    {
        cur=head;
        head=head->next;
        free(cur);
        return head;
    }
    prev=NULL;
    cur=head;
    while(cur!=NULL)
    {
        if(key==cur->acc_no){
            break;
        }else{
            prev=cur;
            cur=cur->next;
        }
    }
    if(cur==NULL)
    {
        printf("Search is unsuccessfull\n");
        return head;
    }
    prev->next=cur->next;
    free(cur);
    return head;
}

// Function to update the balance of a node in the linked list
void update(int key,float bal,struct node *head)
{
    struct node *cur;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    cur=head;
    while(cur!=NULL)
    {
        if(key==cur->acc_no)
        {
            cur->bal=bal;
            return;
        }
        cur=cur->next;
    }
    printf("Search is unsuccessfull\n");
}

// Function to count the number of nodes in the linked list
int count(struct node *head)
{
    struct node *cur;
    int count=0;
    if(head==NULL){
        return 0;
    }
    cur=head;
    while(cur!=NULL)
    {
        count++;
        cur=cur->next;
    }
    return count;
}

// Main function
int main()
{
    struct node *head=NULL;
    int ch,key,c;
    float bal;
    char name[20];
    while(1){
        printf("1.Insert\n2.Display\n3.Search\n4.Delete\n5.Update\n6.Count\n7.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the account number\n");
                    scanf("%d",&key);
                    printf("Enter the name\n");
                    scanf("%s",name);
                    printf("Enter the balance\n");
                    scanf("%f",&bal);
                    head=insertEnd(head,key,name,bal);
                    break;
            case 2: display(head);
                    break;
            case 3: printf("Enter the account number to be searched\n");
                    scanf("%d",&key);
                    search(key,head);
                    break;
            case 4: printf("Enter the account number to be deleted\n");
                    scanf("%d",&key);
                    head=delete(key,head);
                    break;
            case 5: printf("Enter the account number to be updated\n");
                    scanf("%d",&key);
                    printf("Enter the new balance\n");
                    scanf("%f",&bal);
                    update(key,bal,head);
                    break;
            case 6: c=count(head);
                    printf("Number of nodes in the list is %d\n",c);
                    break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}