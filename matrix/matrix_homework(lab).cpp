#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct c {
    int value;
    int row;
    int col;
};

int** normal_array;
int** transPose;
struct c d[200];
struct c e[200];

void transpose(int col, int row) {
    transPose = (int**)malloc(col * sizeof(int*));
    for (int i = 0; i < col; i++) {
        transPose[i] = (int*)malloc(row * sizeof(int));
    }
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            transPose[i][j] = 0;
        }
    }
}

void normal(int row, int col) {
    normal_array = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        normal_array[i] = (int*)malloc(col * sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            normal_array[i][j] = 0;
        }
    }
}

void fast_transpose(int row, int col) {
    int ItemNum[200], StartPos[200];
    int i, j;
    int ColNum = col;
    int TermNum = d[0].value;  // Terim sayısı

    if (TermNum > 0) {
        for (i = 0; i < ColNum; i++) {
            ItemNum[i] = 0;
        }
        for (i = 1; i <= TermNum; i++) {
            ItemNum[d[i].col]++;
        }
        StartPos[0] = 1;
        for (i = 1; i < ColNum; i++) {
            StartPos[i] = StartPos[i - 1] + ItemNum[i - 1];
        }
        for (i = 1; i <= TermNum; i++) {
            j = StartPos[d[i].col]++;
            e[j].row = d[i].col;
            e[j].col = d[i].row;
            e[j].value = d[i].value;
        }
    }
}

void yerleştirici(int col, int row) {
    int item_number = (int)(col * row * 0.3);
    d[0].value = item_number;

    for (int i = 1; i <= item_number; i++) {
        int row_ran = rand() % row;
        int col_ran = rand() % col;
        int value = rand() % 9 + 1;  

        if (normal_array[row_ran][col_ran] == 0) {
            normal_array[row_ran][col_ran] = value;
            d[i].row = row_ran;
            d[i].col = col_ran;
            d[i].value = value;
        }
        else {
            i--;
        }
    }
}
void transpose_yerleştirme(int row, int col) {
    transpose(col, row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++) {
            transPose[j][i] = (normal_array)[i][j];
        }
    }
}

void print(int col, int row) {
    printf("Normal array:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", normal_array[i][j]);
        }
        printf("\n");
    }

    printf("Transpoze array:\n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", transPose[i][j]);
        }
        printf("\n");
    }
}

void print2(int col, int row) {
    printf("Normal sparse matrix (d array):\n");
    for (int i = 1; i <= d[0].value; i++) {
        printf("[%d][%d] = %d\n", d[i].row, d[i].col, d[i].value);
    }

    printf("Transposed sparse matrix (e array):\n");
    for (int i = 1; i <= d[0].value; i++) {
        printf("[%d][%d] = %d\n", e[i].row, e[i].col, e[i].value);
    }
}

int main() {
    int row, col;

    printf("Satır sayısını giriniz: ");
    scanf_s("%d", &row);
    printf("Sütun sayısını giriniz: ");
    scanf_s("%d", &col);

    clock_t start, end;
    start = clock();
    normal(row, col);
    yerleştirici(col, row);
    transpose_yerleştirme(row, col);
    print(col, row);
    end = clock();
    double times = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("normal transpose için geçen süre = %.3f ms\n", times);

    // Bellek boşaltma
    for (int i = 0; i < row; i++) {
        free(normal_array[i]);
    }
    free(normal_array);

    for (int i = 0; i < col; i++) {
        free(transPose[i]);
    }
    free(transPose);

    clock_t start2, end2;
    start2 = clock();
    normal(row, col);
    yerleştirici(col, row);
    fast_transpose(row, col);
    print2(col, row);
    end2 = clock();
    double times2 = (double)(end2 - start2) / CLOCKS_PER_SEC * 1000;
    printf("fast transpose için geçen süre = %.3f ms\n", times2);

    // Bellek boşaltma
    for (int i = 0; i < row; i++) {
        free(normal_array[i]);
    }
    free(normal_array);

    for (int i = 0; i < col; i++) {
        free(transPose[i]);
    }
    free(transPose);

    return 0;
}
