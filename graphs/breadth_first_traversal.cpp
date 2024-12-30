#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10


int adjMatrix[MAX][MAX]; // Adjacency matrix
int visited[MAX];        // Ziyaret edilen düğümleri tutan dizi

void BFSRecursive(int queue[], int* front, int* rear, int numVertices) {
    if (*front > *rear) return; // Kuyruk boşsa çık

    int currentVertex = queue[(*front)++]; // Kuyruktan bir düğüm çıkar
    printf("%d ", currentVertex);

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
            visited[i] = 1; // Ziyaret edildi olarak işaretle
            queue[++(*rear)] = i; // Kuyruğa ekle
        }
    }

    BFSRecursive(queue, front, rear, numVertices); // Özyineleme ile devam et
}

int main() {
    int numVertices = 5;
    int queue[MAX];
    int front = 0, rear = -1;

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

    printf("Breadth First Traversal (Recursive):\n");
    visited[0] = 1; // Başlangıç düğümünü ziyaret edilmiş olarak işaretle
    queue[++rear] = 0; // Kuyruğa başlangıç düğümünü ekle
    BFSRecursive(queue, &front, &rear, numVertices);

    return 0;
}
