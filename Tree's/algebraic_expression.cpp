#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    char data;
    struct node* left;
    struct node* right;
};

struct node* create_node(char data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct node* inorder(struct node* root) {
    if (root == NULL)
    {
        return NULL;
    }
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
    
    
}

int main() {
    struct node* root = create_node('-');
    root->left = create_node('a');
    root->right = create_node('/');
    root->right->left = create_node('b');
    root->right->right = create_node('c');

    inorder(root);
    return 0;
}
