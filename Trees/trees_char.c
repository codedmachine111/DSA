#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(char data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

struct node* insertNode(struct node* root, char data){
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

void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if(root == NULL){
        return;
    }
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

int main(){
    FILE *fp;
    fp = fopen("input.txt", "r");
    char ch;
    struct node *root = NULL;
    while((ch = fgetc(fp)) != EOF){
        root = insertNode(root, ch);
    }
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");
}