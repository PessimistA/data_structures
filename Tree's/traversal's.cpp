#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* postorder(struct node* root, int değer) {
    if (root == NULL)
    {
        return NULL;
    }
    node* left= postorder(root->left, değer);
    if (left!=NULL)
    {
        return left;
    }
    node* right = postorder(root->right, değer);
    if (right != NULL)
    {
        return right;
    }
    else if (root->data==değer)
    {
        return root;
    }

    else
    {
        return NULL;
    }
}
struct node* inorder(struct node* root, int değer) {
    if (root == NULL)
    {
        return NULL;
    }
    node* left = inorder(root->left, değer);
    if (left != NULL)
    {
        return left;
    }
    else if (root->data == değer)
    {
        return root;
    }
    node* right = inorder(root->right, değer);
    if (right != NULL)
    {
        return right;
    }

    else
    {
        return NULL;
    }
}
struct node* preorder(struct node* root, int değer) {
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == değer)
    {
        return root;
    }
    node* left = preorder(root->left, değer);
    if (left != NULL)
    {
        return left;
    }
    node* right = preorder(root->right, değer);
    if (right != NULL)
    {
        return right;
    }

    else
    {
        return NULL;
    }
}
int main() {
    struct node* root = create_node(10);
    root->left = create_node(20);
    root->right = create_node(30);
    root->left->left = create_node(40);
    root->right->left = create_node(50);
    root->right->right = create_node(60);

    printf("Bir değer giriniz: ");
    int değer;
    scanf_s("%d", &değer); // Using scanf for portability

    printf("Postorder traversal: ");
    struct node* yer = postorder(root, değer);
    struct node* yer2 = inorder(root, değer);
    struct node* yer3 = preorder(root, değer);
    printf("\n");

    if (yer != NULL) {
        printf("postorder bulundu: %p\n", yer);
    }
    else {
        printf("postoerder Bulunamadı\n");
    }
    if (yer2 != NULL) {
        printf("inorder Değer bulundu: %p\n", yer2);
    }
    else {
        printf("inorder Bulunamadı\n");
    }
    if (yer3 != NULL) {
        printf("preorder Değer bulundu: %p\n", yer3);
    }
    else {
        printf("preorder Bulunamadı\n");
    }
    return 0;
}
