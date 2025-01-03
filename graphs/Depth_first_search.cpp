#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10

int adjMatrix[MAX][MAX]; // Adjacency matrix
int visited[MAX];        // Ziyaret edilen düğümleri tutan dizi

// DFS fonksiyonu
void DFS(int vertex, int numVertices) {
    printf("%d ", vertex); // Mevcut düğümü yazdır
    visited[vertex] = 1;   // Düğümü ziyaret edildi olarak işaretle

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, numVertices); // Ziyaret edilmemiş komşuları dolaş
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

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d", adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Depth First Traversal (DFS):\n");
    DFS(0, numVertices); // 0. düğümden başla

    return 0;
}
