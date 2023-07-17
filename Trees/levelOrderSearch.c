// WRITE A C PROGRAM TO INSERT NODES IN A BINARY TREE AND TRAVERSE IT USING INORDER, PREORDER AND POSTORDER

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node
struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// function to find siblings at each level
void printLevelOrder(struct node *node)
{
    int i;
    if (node == NULL)
    {
        return;
    }

    struct node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = node;
    while (front != rear)
    {
        int count = rear - front;
        printf("Sibling count at level %d : %d", i, count);
        while (count--)
        {
            struct node *temp = queue[front++];
            if (temp->left != NULL)
            {
                queue[rear++] = temp->left;
            }
            if (temp->right != NULL)
            {
                queue[rear++] = temp->right;
            }
        }
        printf("\n");
        i++;
    }
}

void findSiblingsAtLevels(struct node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        findSiblingsAtLevels(ptr->right, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("    ");
        printf("%d", ptr->data);
        findSiblingsAtLevels(ptr->left, level + 1);
    }
}

// Function to traverse the tree in inorder
void inorder(struct node *root)
{

    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void display(struct node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("    ");
        printf("%d", ptr->data);
        display(ptr->left, level + 1);
    }
}

void displayVertical(struct node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    displayVertical(root->right, level + 1);
    
    for (int i = 0; i < level; i++)
        printf("\t");
        
    printf("%d\n", root->data);
    
    displayVertical(root->left, level + 1);
}


int main()
{
    struct node *root = NULL;
    FILE *input;
    input = fopen("input.txt", "r+");

    srand(time(0));
    int random;
    for (int i = 0; i < 5; i++)
    {
        random = rand() % 100;
        fprintf(input, "%d ", random);
    }
    fclose(input);

    input = fopen("input.txt", "r");
    int choice;
    while (1)
    {
        printf("\n1. Insert\n2. Display Inorder\n3. Find Siblings\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            while (fscanf(input, "%d", &random) == 1)
            {
                root = insertNode(root, random);
            }
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printLevelOrder(root);
            break;
        case 4:
            displayVertical(root, 1);
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}