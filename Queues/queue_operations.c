#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct queue
{
    int data[SIZE];
    int front, rear;
};

void enqueue(struct queue* qptr,int num)
{
    if(qptr->rear == SIZE-1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        qptr->rear++;
        qptr->data[qptr->rear]=num;
    }
}
int dequeue(struct queue* qptr)
{
    int num=0;
    if(qptr->front==qptr->rear)
    {
        return num;
    }
    else
    {
        qptr->front++;
        num = qptr->data[qptr->front];
    }
}
void display(struct queue* qptr)
{
    if(qptr->rear == qptr->front)
    {
        printf("Empty array\n");
    }
    else
    {
        for(int i=(qptr->front+1); i<=(qptr->rear); i++)
        {
            printf("%d->",qptr->data[i]);
        }
        printf("\n");
    }
}
int main()
{
    struct queue*qptr,q;
    qptr=&q;
    qptr->front =-1;
    qptr->rear=-1;
    int n,ch,num;
    while(1)
    {
        printf("Enter your choice\n");
        printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter data\n");
            scanf("%d",&n);
            enqueue(qptr,n);
            break;
        case 2:
            num = dequeue(qptr);
            if(num == 0){
                printf("Queue Underflow\n");
            }
            else{
                printf("Dequeued : %d\n",num);
            }
            break;
        case 3:
            display(qptr);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }

    }
}
