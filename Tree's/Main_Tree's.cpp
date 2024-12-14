#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


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
    return root;
}


Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // 
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
        // 
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


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

    printf("40 sayısının yerini döndüren\n");
    Node* position = search(40, root);
    printf("%d", position);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;


node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* root, int data) {
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
node* search(int key, struct node* root) {
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

node* findMin(node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}


node* deleteNode(node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // 
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        // 
        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int treeLevel(node* root) {
    if (root==NULL)
    {
        return NULL;
    }
    int leftlevel = treeLevel(root->left);
    int rightlevel = treeLevel(root->right);
    return(leftlevel > rightlevel ? leftlevel : rightlevel) + 1;
}
void level_printt(node* root,int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);  // Bu seviyedeki düğümü yazdır
    }
    else if (level > 1) {
        level_printt(root->left, level - 1);  // Sol alt ağacı işle
        level_printt(root->right, level - 1); // Sağ alt ağacı işle
    }
}
void level_order(node* root) {
    int level = treeLevel(root);
    for (int i = 1; i <= level; i++)
    {
        level_printt(root, i);
    }
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Kök
        preorder(root->left);      // Sol
        preorder(root->right);     // Sað
    }
}

void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);     // Sol
        postorder(root->right);    // Sað
        printf("%d ", root->data); // Kök
    }
}


int main() {
    node* root = NULL;


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

    printf("level-order");
    level_order(root);
    printf("\n");

    printf("40 sayısının yerini döndüren\n");
    node* position = search(40, root);
    printf("%d", position);

    return 0;
}
