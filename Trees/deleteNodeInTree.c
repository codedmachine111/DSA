#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

struct node* insertNode(struct node *root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    struct node *newNode = createNode(data);
    if(data > root->data){
        root->right = insertNode(root->right, data);
    }else{
        root->left = insertNode(root->left, data);
    }
    return root;
}

void inorder(struct node *root){
    
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ->", root->data);

    inorder(root->right);
}

struct node *findMinNode(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node *deleteNode(struct node *root, int key){
    if(root == NULL){
        return root;
    }
    if (key < root->data){
        root->left = deleteNode(root->left, key);
    }else if(key >root->data){
        root->right = deleteNode(root->right, key);
    }else{
        // key is found
        // case1 DELETING A LEAF
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    struct node *root = NULL;
    FILE *input;
    input = fopen("input.txt", "r+");
    
    srand(time(0));
    int random;
    for(int i = 0; i < 10; i++){
        random = rand() % 100;
        fprintf(input, "%d ", random);
    }
    fclose(input);

    input = fopen("input.txt", "r");
    int num;
    while(!feof(input)){
        fscanf(input, "%d", &num);
        root = insertNode(root, num);
    }
    inorder(root);
    int del;
    printf("Enter the node to delete : \n");
    scanf("%d", &del);
    deleteNode(root, del);
    inorder(root);
}