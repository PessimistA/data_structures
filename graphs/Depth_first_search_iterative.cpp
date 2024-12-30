#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10

int adjMatrix[MAX][MAX]; // Adjacency matrix
int visited[MAX];        // Ziyaret edilen düğümleri tutan dizi

int stack[MAX];
int top = -1;
// Yığına eleman ekleme
void push( int value) {
    stack[++top] = value;
}

// Yığından eleman çıkarma
int pop() {
    return stack[top--];
}

// Yığının boş olup olmadığını kontrol etme
int isEmpty() {
    return top== -1;
}

// Iteratif DFS algoritması
void DFSIterative(int startVertex, int numVertices) {
    push(startVertex); // Başlangıç düğümünü yığına ekle

    while (!isEmpty()) {
        int currentVertex = pop(); // Yığından bir düğüm çıkar

        if (!visited[currentVertex]) { // Eğer düğüm ziyaret edilmediyse
            printf("%d ", currentVertex); // Düğümü yazdır
            visited[currentVertex] = 1;  // Ziyaret edildi olarak işaretle

            // Komşuları yığına ekle
            for (int i = numVertices - 1; i >= 0; i--) {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }

}

int main() {
    int numVertices = 5;

    // Adjacency matrix başlangıçta sıfır
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0; // Başlangıçta tüm düğümler ziyaret edilmedi
    }

    // Graf kenarlarını tanımla
    adjMatrix[0][1] = 1; adjMatrix[1][0] = 1;
    adjMatrix[0][2] = 1; adjMatrix[2][0] = 1;
    adjMatrix[1][3] = 1; adjMatrix[3][1] = 1;
    adjMatrix[1][4] = 1; adjMatrix[4][1] = 1;
    adjMatrix[2][4] = 1; adjMatrix[4][2] = 1;

    printf("Depth First Traversal (Iterative):\n");
    DFSIterative(0, numVertices); // 0. düğümden başla

    return 0;
}
