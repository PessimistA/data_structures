#include <stdio.h>
#include <stdlib.h>

// General Tree Düğüm Yapısı
typedef struct Node {
    int data;
    struct Node* firstChild;  // İlk çocuk
    struct Node* nextSibling; // Kardeş
} Node;

// Yeni düğüm oluşturma
Node* createNode(int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = number;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

// Çocuğu ekleme
void addChild(Node* parent, int childData) {
    if (parent == NULL) {
        printf("Parent node is NULL. Cannot add child %d.\n", childData);
        return;
    }
    Node* child = createNode(childData);
    if (parent->firstChild == NULL) {
        parent->firstChild = child; // Eğer ilk çocuk yoksa, direkt ekle
    }
    else {
        Node* sibling = parent->firstChild;
        while (sibling->nextSibling != NULL) {
            sibling = sibling->nextSibling; // Son kardeşe git
        }
        sibling->nextSibling = child; // Kardeşi ekle
    }
}

// Ağacı preorder (Öncelikli) yazdırma
void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    // Düğümü yazdır
    for (int i = 0; i < level; i++) {
        printf("  "); // Seviyeye göre boşluk bırak
    }
    printf("%d\n", root->data);

    // İlk çocuğu yazdır
    printTree(root->firstChild, level + 1);

    // Kardeşi yazdır
    printTree(root->nextSibling, level);
}

// Örnek kullanım
int main() {
    // Root düğümünü oluştur
    Node* root = createNode(1);

    // Çocukları ekle
    addChild(root, 2);
    addChild(root, 3);
    addChild(root, 4);

    // Alt çocukları ekle
    addChild(root->firstChild, 5);
    addChild(root->firstChild, 6);

    addChild(root->firstChild->nextSibling, 7);

    // Ağacı yazdır
    printf("General Tree Structure:\n");
    printTree(root, 0);

    return 0;
}
