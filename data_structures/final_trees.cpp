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
Node* findMax(Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
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
int left_most(struct Node** root) {
    if ((*root)->left == NULL)
    {
        int key = (*root)->data;
        Node* deleted = *root;
        (*root) = (*root)->right;
        deleted->right = NULL;
        free(deleted);
        return key;
    }
    else
    {
        return left_most(&(*root)->left);
    }
}
void delete_node(Node** root) {
    Node* deleted = NULL;
    //case 1
    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        free(*root);
        *root = NULL;
    }
    //case 2 only left
    else if ((*root)->left != NULL && (*root)->right == NULL)
    {
        deleted = *root;//eski değeri koru
        (*root) = (*root)->left;//soldakini atadık
        deleted->left = NULL;//eski değerin yerinin solunu boşalt
        free(deleted);
    }
    else if ((*root)->left == NULL && (*root)->right != NULL)
    {
        deleted = *root;//eski değeri koru
        (*root) = (*root)->right;//soldakini atadık
        deleted->right = NULL;//eski değerin yerinin solunu boşalt
        free(deleted);
    }
    else
    {
        (*root)->data = left_most(&(*root)->right);
    }
}

void Delete(int key, Node** root) {
    if (*root == NULL)
    {
        return;
    }
    else if (key == (*root)->data) {
        delete_node(root);
    }
    else if (key < (*root)->data) {
        Delete(key, &(*root)->left);
    }
    else if (key > (*root)->data) {
        Delete(key, &(*root)->right);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void inorder_iterative(Node* root) {
    Node* stack[100]; // Stack boyutunu ağacın derinliğine göre ayarlayabilirsiniz.
    int top = -1; // Stack'in başlangıç durumu.
    Node* current = root;

    while (current != NULL || top != -1) {
        // Sol alt ağaca git
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        // Stack'ten bir düğüm al ve işleyin
        current = stack[top--];
        printf("%d ", current->data);

        // Sağ alt ağaca geç
        current = current->right;
    }
}

void preorder_iterative(Node* root) {
    Node* stack[100]; // Stack boyutunu ağacın derinliğine göre ayarlayabilirsiniz.
    int top = -1; // Stack'in başlangıç durumu.

    // Stack'e kök düğümünü ekleyin
    stack[++top] = root;

    while (top != -1) {
        // Stack'ten bir düğüm alın
        Node* current = stack[top--];

        // Mevcut düğümün değerini yazdırın
        printf("%d ", current->data);

        // Sağ alt ağacı önce ekleyin (çünkü stack LIFO yapısına sahiptir)
        if (current->right != NULL) {
            stack[++top] = current->right;
        }

        // Sol alt ağacı ekleyin
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}
Node* binary_search(Node* root,int key){
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
}
void Reverse_inorder(Node* root) {
    if (root != NULL) {
        Reverse_inorder(root->right);
        printf("%d ", root->data);
        Reverse_inorder(root->left);
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
void mirrot_recursive(Node* root) {
    if (root != NULL) {

        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrot_recursive(root->left);      // Sol
        mirrot_recursive(root->right);     // Sað
    }
}
void mirror(Node* root) {
    if (root == NULL) {
        return;
    }

    // Stack kullanarak iteratif mirror işlemi
    Node* stack[100]; // Stack boyutunu ağacın derinliğine göre ayarlayabilirsiniz.
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        Node* current = stack[top--];

        // Sol ve sağ çocukları takas et
        Node* temp = current->left;
        current->left = current->right;
        current->right = temp;

        // Sağ çocuğu önce ekleyin (çünkü stack LIFO yapısına sahiptir)
        if (current->left != NULL) {
            stack[++top] = current->left;
        }

        // Sol çocuğu ekleyin
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
    }
}


int main() {
    Node* root = NULL;


    root = insert(root, 90);
    root = insert(root, 70);
    root = insert(root, 110);
    root = insert(root, 50);
    root = insert(root, 25);
    root = insert(root, 75);
    root = insert(root, 125);
    root = insert(root, 175);
    root = insert(root, 10);
    root = insert(root, 30);

    Node* root2 = NULL;


    root2 = insert(root2, 90);
    root2 = insert(root2, 70);
    root2 = insert(root2, 110);
    root2 = insert(root2, 50);
    root2 = insert(root2, 25);
    root2 = insert(root2, 75);
    root2 = insert(root2, 125);
    root2 = insert(root2, 175);
    root2 = insert(root2, 10);
    root2 = insert(root2, 30);

    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    printf("reverse inorder traversal:\n");
    Reverse_inorder(root);
    printf("\n");

    printf("inorder iterative traversal:\n");
    inorder_iterative(root);
    printf("\n");

    Node* max= findMax(root);
    printf("max=%d\n", max->data);
    Node* mim = findMin(root);
    printf("mim=%d\n", mim->data);
    //printf("Deleting 20...\n");
    //root = deleteNode(root, 20);
    //printf("Inorder traversal after deletion: ");
    //inorder(root);
    //printf("\n");

    printf("preorder:\n");
    preorder(root);
    printf("\n");

    printf("preorder iterative traversal:\n");
    preorder_iterative(root);
    printf("\n");

    printf("postorder:\n");
    postorder(root);
    printf("\n");

    //printf("mirror recursive\n");
    //mirrot_recursive(root);
    //inorder(root);
    //printf("\n");

    printf("mirror inorder\n");
    mirror(root2);
    inorder(root2);

    Node* found = binary_search(root, 75);
    printf("\nbulunan eleman %d\n", found->data);

    //printf("40 sayısının yerini döndüren\n");
    //Node* position = search(40, root);
    //printf("%d", position);

    return 0;
}
