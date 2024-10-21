#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 101

void buildbandmatrix(int band[], int search[], int n, int a, int b);
int getbandmatrix(int i, int j, int n, int a, int b, int search[]);

int main(void) {
    int band[MAX_SIZE];
    int search[MAX_SIZE];
    int i, n, a, b;

    // Kullanıcıdan değerleri al
    printf("n: ");
    scanf_s("%d", &n);
    printf("a: ");
    scanf_s("%d", &a);
    printf("b: ");
    scanf_s("%d", &b);

    // Band matrisini oluştur
    buildbandmatrix(band, search, n, a, b);

    // Band matrisini yazdır
    for (i = 0; i <= n * (a + b - 1) - a * (a - 1) / 2 - b * (b - 1) / 2 - 1; i++) {
        printf(" %d ", band[i]);
    }
    printf("\n");

    // Search dizisini yazdır
    for (i = 0; i <= a + b - 2; i++) {
        printf(" %d ", search[i]);
    }
    printf("\n");

    // İndeksle kontrol yap
    i = getbandmatrix(3, 3, n, a, b, search);

    if (i == -2)
        printf("\n Invalid index.\n");
    else if (i == -1)
        printf("\n Item to be searched: 0\n");
    else
        printf("\n Item to be searched: %d → %d\n", i, band[i]);

    return 0;
}

void buildbandmatrix(int band[], int search[], int n, int a, int b) {
    int i, k, itemnum;

    // Bellek kontrolü
    if (n * (a + b - 1) - a * (a - 1) / 2 - b * (b - 1) / 2 > MAX_SIZE) {
        printf("\n Not enough memory\n");
        exit(-1);
    }
    else {
        itemnum = 0;
        for (i = -a + 1; i <= b - 1; i++) { // Her diyagonal için
            search[i + a - 1] = itemnum;
            for (k = 0; k <= n - abs(i) - 1; k++) { // Şu anki diyagonal için
                printf("Enter element for diagonal %d: ", i);
                scanf_s("%d", &band[search[i + a - 1] + k]);
            }
            itemnum = itemnum + (n - abs(i));
        }
    }
}

int getbandmatrix(int i, int j, int n, int a, int b, int search[]) {
    // Geçersiz indeks kontrolü
    if (i >= n || i < 0 || j >= n || j < 0) {
        printf("\n Invalid index\n");
        return -2;
    }
    else {
        if (j > i) { // Diagonal üstü
            if (j - i < b) { // Upper band sınırında mı
                return (search[a - 1 + j - i] + i); // Evet
            }
            else {
                return -1; // Band dışında
            }
        }
        else if (i - j < a) { // Diagonal veya altı
            return (search[j - i + a - 1] + j);
        }
        else {
            return -1; // Band dışında
        }
    }
}
