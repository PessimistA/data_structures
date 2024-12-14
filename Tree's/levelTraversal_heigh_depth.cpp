#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

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

struct node* inorder(struct node* root,int* count) {
    if (root == NULL)
    {
        return NULL;
    }
    inorder(root->left,count);
    printf("%c", root->data);

    (*count)++;

    inorder(root->right,count);     
}


// Ağacın derinliğini hesaplama (Maximum derinlik)
int treeLevel(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftlevel = treeLevel(root->left);
    int rightlevel = treeLevel(root->right);
    return (leftlevel > rightlevel ? leftlevel : rightlevel) + 1;
}
int treeDepth(struct node* root, char değer, int level) {
    if (root == NULL) {
        return -1; // Düğüm bulunamadı
    }

    // Eğer düğüm aradığımız değeri taşıyorsa, derinliği döndür
    if (root->data == değer) {
        return level;
    }

    // Sol alt ağaçta arama
    int leftDepth = treeDepth(root->left, değer, level + 1);
    if (leftDepth != -1) {
        return leftDepth; // Sol alt ağaçta bulunduysa derinliği döndür
    }

    // Sağ alt ağaçta arama
    return treeDepth(root->right, değer, level + 1);
}

// Belirli bir seviyedeki düğümleri yazdırma
void printLevel(struct node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%c ", root->data);  // Bu seviyedeki düğümü yazdır
    }
    else if (level > 1) {
        printLevel(root->left, level - 1);  // Sol alt ağacı işle
        printLevel(root->right, level - 1); // Sağ alt ağacı işle
    }
}
void levelOrderTraversal(struct node* root) {
    int level= treeLevel(root);  // Ağacın derinliğini al
    for (int i = 1; i <= level; i++) {
        printLevel(root, i);  // Her seviyedeki düğümleri yazdır
        printf("\n");
    }
}

int main() {
    struct node* root = create_node('a');
    root->left = create_node('b');
    root->right = create_node('c');
    root->right->left = create_node('d');
    root->right->right = create_node('e');
    root->left->right = create_node('f');
    root->left->left = create_node('g');

    int count = 0;
    
    inorder(root,&count);
    printf("%d\n", count);
    
    int height = log2(count + 1) - 1;
    int height2 = floor(log2(count));
    
    printf("full binary height=%d\n", height);

    printf("complete binary height=%d\n", height2);

    printf("bir değer giriniz lütfen\n");
    char değer;
    scanf_s("%c\n", &değer);
    int depth = treeDepth(root, değer, 0);
    printf("depth:%d", depth);
    levelOrderTraversal(root);


    return 0;
}
