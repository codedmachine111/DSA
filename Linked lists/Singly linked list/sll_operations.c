#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

struct node* getnode()
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
    }
    printf("Enter integer data\n");
    scanf("%d",&newnode->data);
    newnode->link = NULL;
    return newnode;
}
struct node* insert_end(struct node* head)
{
    struct node* cur;
    struct node* newnode;
    newnode = getnode();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->link != NULL)
        {
            cur=cur->link;
        }
        cur->link = newnode;
    }
    return head;

}
struct node* insert_beg(struct node* head)
{

    struct node* newnode = getnode();
    if(head==NULL)
    {
        head= newnode;
    }
    else
    {
        newnode->link = head;
        head=newnode;
    }
    return head;

}
int count_nodes(struct node* head)
{
    struct node* cur;
    int count=0;
    if(head==NULL)
    {
        return count;
    }
    else
    {
        cur=head;
        while(cur !=NULL)
        {
            count++;
            cur=cur->link;
        }
    }


    return count;
}


struct node* insert_pos(struct node* head)
{
    struct node* cur;
    struct node* newnode;
    struct node* prev;
    int pos;
    newnode=getnode();
    int count = count_nodes(head);
    printf("Enter position\n");
    scanf("%d",&pos);
    if(pos==1 && head==NULL)
    {
        head=newnode;
    }
    else if(pos==1)
    {
        newnode->link = head;
        head= newnode;
    }
    else if (pos=count+1)
    {
        cur = head;
        while(cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = newnode;
    }
    else if(pos>1 && pos<=count)
    {
        for(int i=1; i<pos-1; i++)
        {
            prev = cur;
            cur=cur->link;
        }
        prev->link=newnode;
        newnode->link = cur;
    }
    else
    {
        printf("Invalid position\n");
    }

    return head;
}

struct node* delete_end(struct node* head)
{
    struct node* cur;
    struct node* prev;
    if(head==NULL)
    {
        printf("Empty linked list\n");
    }
    else if(head->link == NULL){
        printf("Deleted : %d\n",head->data);
        free(head);
        head=NULL;
    }
    else{
        cur=head;
        prev=NULL;
        while(cur->link !=NULL){
                prev=cur;
                cur=cur->link;
        }
        prev->link=NULL;
        printf("Deleted : %d",cur->data);
        free(cur);
    }


}

struct node* delete_front(struct node* head){
    struct node* cur;
    if(head==NULL){
        printf("Empty linked list\n");
    }
    else{
        cur=head;
        head=head->link;
        printf("Deleted : %d",cur->data);
        cur->link=NULL;
        free(cur);
    }
    return head;
}
void display(struct node* head){
    struct node* cur;
    if(head==NULL){
        printf("Empty linked list\n");
    }
    else{
        cur=head;
        while(cur!=NULL){
            printf("%d->",cur->data);
            cur=cur->link;
        }
    }

}

void search_node(struct node* head){
    struct node* cur;
    int status=0, key;
    printf("Enter key to find\n");
    scanf("%d",&key);
    if(head==NULL){
            printf("Empty linked list\n");
    }
    else{
        cur=head;
        while(cur!=NULL){
            if(cur->data == key){
                status=1;
                break;
            }
            cur=cur->link;
        }
    }
    if(status==1){
        printf("Key found\n");
    }
    else{
        printf("Key not found\n");
    }
}

struct node* search_and_delete(struct node* head){
    struct node* cur;
    struct node* prev;
    struct node* temp;
    int status=0, key;
    printf("Enter key to find and delete\n");
    scanf("%d",&key);
    if(head==NULL){
        printf("Linked list empty\n");
    }
    else if(head->data == key){
        head=delete_front(head);
    }
    else{
        prev=NULL;
        cur=head;
        while(cur!=NULL){
            if(cur->data ==key){
                status=1;
                break;
            }
            prev=cur;
            cur=cur->link;
        }

    }
    if(status==1){
        prev->link = cur->link;
        printf("Deleted : %d",cur->data);
        free(cur);
    }
    else{
        printf("Key not found\n");
    }
    return head;
}
struct node* delete_specified(struct node* head)
    {
        struct node* cur;
        struct node* prev;
        int loc,i;
        printf("Enter position to delete\n");
        scanf("%d",&loc);
        cur=head;
        for(i=1;i<loc;i++)
        {
            prev = cur;
            cur = cur->link;

            if(cur == NULL)
            {
                printf("\nThere are less than %d elements in the list..\n",loc);
                exit(0);
            }
        }
        prev->link = cur ->link;
        free(cur);
        printf("\nDeleted %d node ",loc);

        return head;
    }

int main()
{
    struct node* head;
    head=NULL;
    int ch,count;
    while(1){
        printf("\n");
        printf("Singly linked list operations\n");
        printf("1.Insert End \n2.Insert front \n3.Insert position \n4.Delete front \n5.Delete end \n6.Display \n7.Countnodes \n8.Delete position \n9.Search nodes \n10.Search and delete \n11.Exit\n\n");
        printf("Enter your choice \n\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: head=insert_end(head);
                    break;
            case 2: head = insert_beg(head);
                    break;
            case 3: head = insert_pos(head);
                    break;
            case 4: head= delete_front(head);
                    break;
            case 5: head = delete_end(head);
                    break;
            case 6: display(head);
                    break;
            case 7: count = count_nodes(head);
                    printf("Total Nodes : %d",count);
                    break;
            case 8: head = delete_specified(head);
                    break;
            case 9: search_node(head);
                    break;
            case 10: head =search_and_delete(head);
                    break;
            case 11:
                exit(0);
                break;
            default: printf("Invalid choice\n");
                break;

        }
    }
}
