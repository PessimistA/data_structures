
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
void inorder_traversal(node* root) {
    if (root==NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}
void preorder_traversal(node* root) {
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    inorder_traversal(root->left);
    inorder_traversal(root->right);
}
void postorder_traversal(node* root) {
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    inorder_traversal(root->right);
    printf("%d ", root->data);
}
void preorder_mim(node* root,int* mim) {
    if (root == NULL)
    {
        return;
    }
    if (root->data<*mim)
    {
        *mim = root->data;
    }
    preorder_mim(root->left, mim);
    preorder_mim(root->right, mim);
}
void preorder_max(node* root, int* max) {
    if (root == NULL)
    {
        return ;
    }
    if (root->data > *max)
    {
        *max = root->data;
    }
    preorder_max(root->left, max);
    preorder_max(root->right, max);

}
void inorder_mim(node* root, int* mim) {
    if (root == NULL)
    {
        return;
    }
    if (root->data < *mim)
    {
        *mim = root->data;
    }
    inorder_mim(root->left, mim);
    inorder_mim(root->right, mim);
}
void inorder_max(node* root, int* max) {
    if (root == NULL)
    {
        return;
    }
    inorder_max(root->left, max);
    if (root->data > *max)
    {
        *max = root->data;
    }
    inorder_max(root->right, max);

}
void postorder_mim(node* root, int* mim) {
    if (root == NULL)
    {
        return;
    }
    postorder_mim(root->left, mim);
    postorder_mim(root->right, mim);
    if (root->data < *mim)
    {
        *mim = root->data;
    }
}
void postorder_max(node* root, int* max) {
    if (root == NULL)
    {
        return;
    }
    postorder_max(root->left, max);
    postorder_max(root->right, max);
    if (root->data > *max)
    {
        *max = root->data;
    }
}
void inorder_count(node* root, int* count) {
    if (root == NULL)
    {
        return;
    }
    inorder_count(root->left, count);
    *count= *count+1;
    inorder_count(root->right, count);

}
void inorder_addition(node* root, int* addition) {
    if (root == NULL)
    {
        return;
    }
    inorder_addition(root->left, addition);
    (*addition) += root->data;
    inorder_addition(root->right, addition);

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
    scanf_s("%d", &değer); 

    printf("inorder traversal: \n");
    inorder_traversal(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");
    printf("preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    int ilk = root->data;
    preorder_mim(root,&ilk);
    printf("mim==%d\n", ilk);
    
    int ilk2 = root->data;
    preorder_max(root, &ilk2);
    printf("max==%d\n", ilk2);

    int ilk3 = root->data;
    inorder_mim(root, &ilk3);
    printf("mim==%d\n", ilk3);
    
    int ilk4 = root->data;
    inorder_max(root, &ilk4);
    printf("mim==%d\n", ilk4);

    int ilk5 = root->data;
    postorder_mim(root, &ilk5);
    printf("mim==%d\n", ilk5);

    int ilk6 = root->data;
    postorder_max(root, &ilk6);
    printf("mim==%d\n", ilk6);

    int count = 0;
    inorder_count(root, &count);
    printf("toplam =%d\n", count);

    int toplam = 0; 
    inorder_addition(root, &toplam);
    printf("dugumlerin toplamı: %d\n", toplam);

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
