#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};
typedef struct node* NODE;

NODE create_node()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("No memory allocated\n");
        exit(0);
    }
    printf("Enter number of candies\n");
    scanf("%d",&newnode->data);
    newnode->llink = NULL;
    newnode->rlink = NULL;
    return newnode;
}
NODE insert_end(NODE head)
{
    NODE newnode;
    NODE cur;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->rlink!=NULL)
        {
            cur=cur->rlink;
        }
        cur->rlink=newnode;
        newnode->llink=cur;
    }
    return head;
}
NODE delete_left(NODE head, int pos, int d)
{
    NODE cur;
    int sum=0;
    if(head==NULL)
    {
        printf("No group of candies\n");
    }
    cur=head;
    for(int i=0; i<pos; i++)
    {
        cur->data= cur->data -d;
        sum = sum + cur->data;
        cur=cur->rlink;
    }
    printf("ALICE was not able to eat %d candies\n",sum);
    return head;
}
NODE delete_right(NODE head, int pos, int d)
{
    NODE cur;
    int sum=0;
    if(head==NULL)
    {
        printf("No group of candies\n");
    }
    cur=head;
    while(cur->rlink !=NULL)
    {
        cur=cur->rlink;
    }
    for(int i=0; i<pos; i++)
    {
        cur->data= cur->data -d;
        sum = sum + cur->data;
        cur=cur->llink;
    }
    printf("BOB was not able to eat %d candies\n",sum);
    return head;
}

void display(NODE head)
{
    NODE cur;
    if(head==NULL)
        printf("No group of candies\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->rlink;
        }
        printf("\n");
    }

}
int main()
{
    NODE head=NULL;
    int n,pos,d;
    printf("Enter number of groups\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        head=insert_end(head);
    }
    display(head);
    pos=n/2;
    printf("\nEnter the number of candies they both eat\n");
    scanf("%d",&d);
    head=delete_left(head,pos,d);
    head=delete_right(head,pos,d);
    display(head);

    return 0;
}


