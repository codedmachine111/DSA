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
struct node *createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node
struct node *insertNode(struct node *root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = insertNode(root->left, data);
    }
    else{
        root->right = insertNode(root->right, data);
    }
    return root;
}
// function to display the tree
void display(struct node *root, int level){
    if(root == NULL){
        return;
    }
    display(root->right, level + 1);
    printf("\n");
    for(int i = 0; i < level; i++){
        printf("    ");
    }
    printf("%d", root->data);
    display(root->left, level + 1);
}

// Function to traverse the tree in inorder
void inorder(struct node *root, FILE *fp){
    
    if(root == NULL){
        return;
    }
    inorder(root->left, fp);
    printf("%d ", root->data);
    fprintf(fp, "%d ", root->data);
    inorder(root->right, fp);
}

void printLeafNodes(struct node *root){
    if(root==NULL){
        return;
    }

    if(root->left == NULL && root->right==NULL){
        printf("%d ", root->data);
        return;
    }

    if(root->left!=NULL){
        printLeafNodes(root->left);
    }
    if(root->right!=NULL){
        printLeafNodes(root->right);
    }
}
// Function to traverse the tree in preorder
void preorder(struct node *root, FILE *fp){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    fprintf(fp, "%d ", root->data);
    preorder(root->left, fp);
    preorder(root->right, fp);
}

void descendingOrder(struct node *root){
    FILE *descending_output;
    descending_output = fopen("descending_output.txt", "a");
    if(root == NULL){
        return;
    }
    descendingOrder(root->right);
    printf("%d ", root->data);
    descendingOrder(root->left);
    fclose(descending_output);
}
// Function to traverse the tree in postorder
void postorder(struct node *root, FILE *fp){
    if(root == NULL){
        return;
    }
    postorder(root->left, fp);
    postorder(root->right, fp);
    printf("%d ", root->data);
    fprintf(fp, "%d ", root->data);
}

int main(){
    struct node *root = NULL;
    FILE *input;
    input = fopen("input.txt", "r+");

    FILE *inorder_output;
    inorder_output = fopen("inorder.txt", "a");
    FILE *preorder_output;
    preorder_output = fopen("preorder.txt", "a");
    FILE *postorder_output;
    postorder_output = fopen("postorder.txt", "a");

    srand(time(0));
    int random;
    for(int i = 0; i < 10; i++){
        random = rand() % 100;
        fprintf(input, "%d ", random);
    }
    fclose(input);
    input = fopen("input.txt", "r");
    int choice;
    while(1){
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Descending\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                while(!feof(input)){
                    fscanf(input, "%d", &random);
                    root = insertNode(root, random);
                }
                break;
            case 2:
                inorder(root, inorder_output);
                fclose(inorder_output);
                break;
            case 3:
                preorder(root, preorder_output);
                fclose(preorder_output);
                break;
            case 4:
                postorder(root, postorder_output);
                fclose(postorder_output);
                break;
            case 5:
                printLeafNodes(root);
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}