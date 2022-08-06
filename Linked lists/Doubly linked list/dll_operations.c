#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};

struct node *create_node();
struct node *insertend(struct node *head);
struct node *insertfront(struct node *head);
struct node *delte_end(struct node *head);
struct node *delte_front(struct node *head);
void display_all(struct node *head);
void display_ulta(struct node *head);
int count(struct node *head);
void search(struct node *head);
struct node *search_delete(struct node *head);

int main()
{
    struct node *head=NULL;
    int ch,d;
    while(1)
    {
        printf("Doubly linked list operations\n");
        printf("1.Insert End\n2.Delete End\n3.Display\n4.Display Reverse\n5.Count \n6.Search \n7.Insert Front \n8.Delete Front \n9.Search and Delete \n10.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=insertend(head);
                   break;
            case 2: head=delte_end(head);
                    break;
            case 3: display_all(head);
                    break;
            case 4:display_ulta(head);
                    break;
            case 5:d=count(head);
                   printf("Number of nodes = %d",d);
                   break;
            case 6:search(head);
                   break;
            case 7:head=insertfront(head);
                   break;
            case 8: head=delte_front(head);
                    break;
            case 9: head=search_delete(head);
                    break;
            case 10:exit(0);
                   break;
             default: printf("Invalid choice\n");
                     break;
        }
    }
}
struct node *create_node()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("No memory allocated\n");
        exit(0);
    }
    printf("Enter integer data\n");
    scanf("%d",&newnode->data);
    newnode->llink=newnode->rlink=NULL;
    return newnode;
}
struct node *insertend(struct node *head)
{
     struct node *newnode;
     newnode=create_node();
     if(head==NULL)
        head=newnode;
     else
     {
        struct node *cur;
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

struct node *insertfront(struct node *head)
{
    struct node *newnode;
    newnode=create_node();
    if(head==NULL)
        head=newnode;
    else
    {
      newnode->rlink=head;
      head->llink=newnode;
      head=newnode;
    }
     return head;
}

struct node *delte_end(struct node *head)
{
  struct node *cur;
  if(head==NULL)
        printf("Doubly Linked List empty\n");
  else if(head->rlink==NULL)
  {
      printf("Deleted : %d",head->data);
      free(head);
      head=NULL;
  }
  else
  {
      cur=head;
      struct node *prev;
      while(cur->rlink!=NULL)
      {
          cur=cur->rlink;
      }
      prev=cur->llink;
      prev->rlink=NULL;
      cur->llink=NULL;
      printf("Deleted : %d",cur->data);
      free(cur);
      return head;
  }

}
struct node *delte_front(struct node *head)
{
   struct node *temp;
    if(head==NULL)
        printf("Doubly Linked List empty\n");
  else if(head->rlink==NULL)
  {
      printf("Deleted : %d",head->data);
      free(head);
      head=NULL;
  }
  else
  {
      temp=head;
      head=head->rlink;
      head->llink=NULL;
      temp->rlink=NULL;
      printf("Deleted : %d\n",temp->data);
      free(temp);
  }
  return head;
}
void display_all(struct node *head)
{
    struct node *cur;
    if(head==NULL)
        printf("Doubly Linked List empty\n");
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
void display_ulta(struct node *head)
{
    struct node *cur;
    if(head==NULL)
        printf("Doubly Linked List empty\n");
        else
      {
          cur=head;
          while(cur->rlink!=NULL)
          {
              cur=cur->rlink;
          }
          while(cur!=NULL)
          {
               printf("%d->",cur->data);
               cur=cur->llink;
          }
          printf("\n");
      }

}
int count(struct node *head)
{
    int countn=0;
    struct node *cur;
    if(head==NULL)
        printf("Doubly Linked List empty\n");
        else
      {
          cur=head;
          while(cur!=NULL)
          {
              countn++;
              cur=cur->rlink;
          }
      }
      return countn;
}
void search(struct node *head)
{
    struct node *cur;
    int k,status=0;
    printf("Enter key to search\n");
    scanf("%d",&k);
    if(head==NULL)
        printf("Doubly Linked List empty\n");
        else
        {
            cur=head;
            while(cur!=NULL)
            {
                if(cur->data==k)
                {
                    status=1;
                    break;
                }
                else
                    status=0;
                    cur=cur->rlink;
            }
            if(status==1)
                printf("Search successful. %d found\n",k);
            else
                printf("Search failed. %d not found\n",k);
        }
}
struct node *search_delete(struct node *head)
{
    struct node *cur;
    struct node *prev=NULL;
    struct node *temp=NULL;
    int k,status=1;
    printf("Enter key to be delete\n");
    scanf("%d",&k);
    if(head==NULL)
        printf("Doubly Linked List empty\n");
        else if(head->data==k)
            head=delte_front(head);
        else
        {
            cur=head;
            while(cur->rlink!=NULL)
            {
                if(cur->data==k)
                {
                    prev->rlink=cur->rlink;
                    temp=cur;
                    cur=cur->rlink;
                    cur->llink=prev;
                    printf("Deleted : %d",k);
                    free(temp);
                    prev=prev->llink;
                    cur=cur->llink;

                }
                else
                {
                    status=0;
                    prev=cur;
                    cur=cur->rlink;
                }

            }
            if(status==0)
            printf("Element not found\n");
        }
        return head;
}
