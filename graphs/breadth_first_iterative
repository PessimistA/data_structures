#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10


int adjMatrix[MAX][MAX]; // Adjacency matrix
int visited[MAX];        // Ziyaret edilen düğümleri tutan dizi

int queue[MAX];
int front = 0, rear = -1; // Kuyruk için başlangıç değerleri

// BFS Iterative
void BFSIterative(int startVertex, int numVertices) {
    queue[++rear] = startVertex; // Başlangıç düğümünü kuyruğa ekle
    visited[startVertex] = 1;   // Ziyaret edildi olarak işaretle

    while (front <= rear) { // Kuyruk boşalana kadar devam et
        int currentVertex = queue[front++]; // Kuyruktan bir düğüm çıkar
        printf("%d ", currentVertex);

        // Komşuları kuyruğa ekle
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i; // Kuyruğa ekle
                visited[i] = 1;   // Ziyaret edildi olarak işaretle
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

    printf("Breadth First Traversal (Iterative):\n");
    BFSIterative(0, numVertices); // 0. düğümden başla

    return 0;
}
