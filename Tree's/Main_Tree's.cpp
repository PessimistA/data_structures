#include <stdio.h>
#include <stdlib.h>

// D���m yap�s�
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Yeni d���m olu�turma fonksiyonu
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
    return root;//en soldaki eleman en k���k oland�r sonu�ta
}

// A�a�tan eleman silme
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);//k���kse sol tarafta kal�r
    }
    else if (data > root->data) {//b�y�kse sa� tarafta kal�r
        root->right = deleteNode(root->right, data);
    }
    else {
        // Tek �ocuk veya �ocuksuz durum
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
        // �ki �ocuklu durum
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// A�ac� s�rayla yazd�rma (inorder traversal)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // K�k
        preorder(root->left);      // Sol
        preorder(root->right);     // Sa�
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Sol
        postorder(root->right);    // Sa�
        printf("%d ", root->data); // K�k
    }
}


int main() {
    Node* root = NULL;

    // A�a� olu�turma ve eleman ekleme
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

    printf("40 say�s�n�n yerini d�nd�ren\n");
    Node* position = search(40, root);
    printf("%d", position);

    return 0;
}