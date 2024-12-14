#include <stdio.h>
#include <stdlib.h>

// Düğüm yapısı
struct Node {
    int data;
    int childCount;
    struct Node** children;
};

// Yeni düğüm oluşturma
struct Node* createNode(int data, int n) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->childCount = n;
    newNode->children = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Pre-order traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    // Kök düğümü yazdır
    printf("%d ", root->data);

    // Çocukları dolaş
    for (int i = 0; i < root->childCount; i++) {
        preorderTraversal(root->children[i]);
    }
}

int main() {
    // Ağacı oluşturma
    struct Node* root = createNode(1, 3); // Kök düğüm ve 3 çocuk
    root->children[0] = createNode(2, 2); // İlk çocuk ve 2 çocuk
    root->children[1] = createNode(3, 0); // İkinci çocuk (yaprak düğüm)
    root->children[2] = createNode(4, 1); // Üçüncü çocuk ve 1 çocuk

    root->children[0]->children[0] = createNode(5, 0); // Çocuk 2.1
    root->children[0]->children[1] = createNode(6, 0); // Çocuk 2.2
    root->children[2]->children[0] = createNode(7, 0); // Çocuk 4.1

    // Ağacı pre-order dolaş
    printf("Pre-order Traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
