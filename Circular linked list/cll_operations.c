#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node* getnode()
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter integer data\n");
    scanf("%d",&newnode->data);
    newnode->link=newnode;
    return newnode;
}

struct node* insert_end(struct node* last)
{
    struct node* newnode;
    newnode = getnode();
    if(last==NULL)
    {
        last=newnode;
    }
    else
    {
        newnode->link = last->link;
        last->link = newnode;
        last = newnode;
    }
    return last;
}

struct node* insert_beg(struct node* last){
    struct node* cur;
    struct node* newnode;
    newnode = getnode();
    if(last == NULL){
        last = newnode;
    }
    else{
        cur=last->link;
        last->link = newnode;
        newnode->link = cur;

    }
    return last;
}

struct node* delete_front(struct node* last){
    struct node* cur;
    if(last == NULL){
        printf("Empty linked list\n");
    }
    else{
        cur = last->link;
        last->link = cur->link;
        printf("Deleted : %d",cur->data);
        free(cur);
    }
    return last;
}
struct node* delete_end(struct node* last){
    struct node* cur;
    struct node* temp;
    if(last == NULL){
        printf("Empty linked list\n");
    }
    else{
        cur = last->link;
        while(cur->link != last){
            cur = cur->link;
        }
        cur->link = last->link;
        temp=last;
        last=cur;
        printf("Deleted : %d",temp->data);
        free(temp);
    }
    return last;
}
void display(struct node* last)
{

    struct node* cur;
    if(last==NULL)
    {
        printf("Empty linked list \n");
    }
    else{
        cur = last->link;
        do
        {
            printf("%d->",cur->data);
            cur=cur->link;
        }while(cur != last->link);
    }
}
void search_node(struct node* last){
    struct node* cur;
    int status=0, key;
    printf("Enter key to search :\n");
    scanf("%d",&key);
    if(last ==NULL){
        printf("Empty linked list\n");
    }
    else
    {
        cur=last->link;
        do{
            if(cur->data==key){
                status=1;
                break;
            }
            else{
                return status;
            }
        }while(cur != last->link);
        if(status==0){
            printf("Key not found\n");
        }
        else{
            printf("Key found\n");
        }
    }
}
struct node* search_and_delete(struct node* last){
    struct node* cur;
    struct node* temp;
    int status=0, key;
    printf("Enter key to delete\n");
    scanf("%d",&key);
    if(last ==NULL){
        printf("Empty linked list\n");
    }
    else{
        cur=last->link;
        do{
            if(cur->data==key){
                status=1;
                break;
            }
            else{
                return status;
            }
        }while(cur!=last->link);
        if(status==1){
            temp=cur;
            cur=last->link;
            do{
                cur=cur->link;
            }while(cur->link != temp);
            cur->link = temp->link;
            free(temp);
        }
        else{
            printf("Key not found\n");
        }
    }
    return last;
}
int count_nodes(struct node* last){
    int count=0;
    struct node* cur;
    if(last==NULL){
        return count;
    }
    else{
        cur=last->link;
        do{
            count++;
            cur=cur->link;
        }while(cur!= last->link);
    }
    return count;
}
int main()
{
    struct node* last;
    last=NULL;
    int ch,c;
    while(1){
        printf("\n");
        printf("Circular linked list operations\n");
        printf("1.Insert end \n2.Display \n3.Exit \n4.Insert_beg \n5.Delete_front \n6.Delete_end \n7.Count \n8.Search\n\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: last =insert_end(last);
                break;
            case 2: display(last);
                break;
            case 3: exit(1);
                break;
            case 4: last = insert_beg(last);
                break;
            case 5: last = delete_front(last);
                break;
            case 6: last = delete_end(last);
                break;
            case 7: c = count_nodes(last);
                    printf("Number of nodes : %d",c);
                break;
            case 8: search_node(last);
                break;
            case 9: last =search_and_delete(last);
                break;
        }
    }

    return 0;
}
