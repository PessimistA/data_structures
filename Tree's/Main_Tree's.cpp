#include <stdio.h>
#include <stdlib.h>

// Düðüm yapýsý
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Yeni düðüm oluþturma fonksiyonu
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}
Node* search(int key, struct Node* root) {
    if (root != NULL)
    {
        if (key == root->data) {
            return root;
        }
        else if (key < root->data) {
            search(key, root->left);
        }
        else if (key > root->data) {
            search(key, root->right);
        }
    }
    else
    {
        return 0;
    }
}

Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;//en soldaki eleman en küçük olandýr sonuçta
}

// Aðaçtan eleman silme
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);//küçükse sol tarafta kalýr
    }
    else if (data > root->data) {//büyükse sað tarafta kalýr
        root->right = deleteNode(root->right, data);
    }
    else {
        // Tek çocuk veya çocuksuz durum
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Ýki çocuklu durum
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Aðacý sýrayla yazdýrma (inorder traversal)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Kök
        preorder(root->left);      // Sol
        preorder(root->right);     // Sað
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Sol
        postorder(root->right);    // Sað
        printf("%d ", root->data); // Kök
    }
}


int main() {
    Node* root = NULL;

    // Aðaç oluþturma ve eleman ekleme
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Eleman silme
    printf("Deleting 20...\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    printf("preorder:\n");
    preorder(root);
    printf("\n");

    printf("postorder:\n");
    postorder(root);
    printf("\n");

    printf("40 sayýsýnýn yerini döndüren\n");
    Node* position = search(40, root);
    printf("%d", position);

    return 0;
}