// C PROGRAM TO ADD TASKS TO A TO-DO LIST USING DOUBLY LINKED LIST BASED ON PRIORITY

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char task[100];
    int priority;
    struct node *right;
    struct node *left;
};

// CREATE A NEW NODE
struct node *create_node(char task[], int priority)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->task, task);
    new_node->priority = priority;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

// INSERT A NEW TASK BASED ON PRIORITY
struct node *insertTask(struct node *head, char task[], int priority)
{
    struct node *new_node = create_node(task, priority);
    struct node *temp = head;
    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->priority > priority)
            {
                if(temp->left == NULL)
                {
                    new_node->right = temp;
                    temp->left = new_node;
                    head = new_node;
                    break;
                }
                else
                {
                    new_node->right = temp;
                    new_node->left = temp->left;
                    temp->left->right = new_node;
                    temp->left = new_node;
                    break;
                }
            }
            else if(temp->right == NULL)
            {
                temp->right = new_node;
                new_node->left = temp;
                break;
            }
            temp = temp->right;
        }
    }
    return head;
}

// DELETE A TASK FROM THE LIST
struct node *deleteTask(struct node *head, char task[])
{
    struct node *temp = head;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            if(strcmp(temp->task, task) == 0)
            {
                if(temp->left == NULL)
                {
                    head = temp->right;
                    head->left = NULL;
                    free(temp);
                    break;
                }
                else if(temp->right == NULL)
                {
                    temp->left->right = NULL;
                    free(temp);
                    break;
                }
                else
                {
                    temp->left->right = temp->right;
                    temp->right->left = temp->left;
                    free(temp);
                    break;
                }
            }
            temp = temp->right;
        }
    }
    return head;
}

// DISPLAY THE LIST
void display(struct node *head)
{
    struct node *temp = head;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%s\t%d\n", temp->task, temp->priority);
            temp = temp->right;
        }
    }
}

// MAIN FUNCTION
int main()
{
    struct node *head = NULL;
    int choice, priority;
    char task[100];
    while(1)
    {
        printf("1. Add a task\n");
        printf("2. Delete a task\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the task: ");
                scanf("%s", task);
                printf("Enter the priority: ");
                scanf("%d", &priority);
                head = insertTask(head, task, priority);
                break;
            case 2:
                printf("Enter the task to be deleted: ");
                scanf("%s", task);
                head = deleteTask(head, task);
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