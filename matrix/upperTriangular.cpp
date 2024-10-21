
#include <stdio.h>

int gettriangularmatrix(int i, int j, int n);
void readtriangularmatrix(int alt[], int n);

int main() {
    int alt[101];
    int i, n;

    // Matris boyutunu kullanıcıdan al
    printf("Lütfen matris boyutunu giriniz: ");
    scanf_s("%d", &n);

    // Matris elemanlarını oku
    readtriangularmatrix(alt, n);

    // İstenen indeksi test et
    int row = 3, col = 0;
    int index = gettriangularmatrix(row, col, n);

    // İndeks geçerliliğini kontrol et ve sonucu yazdır
    if (index == -1) {
        printf("\n Geçersiz indeks.\n");
    }
    else if (index == -2) {
        printf("\n Üçgen dışında (alt üçgen).\n");
    }
    else {
        printf("\n Alt dizideki pozisyon: %d, değer: %d\n", index, alt[index]);
    }

    return 0;
}

void readtriangularmatrix(int alt[], int n) {
    int i, j, index;

    // Dizinin boyutu üst üçgen elemanlarını alabilecek mi kontrol et
    if (n * (n + 1) / 2 > 101) {
        printf("\n Geçersiz dizi boyutu\n");
        return;
    }

    // Matrisin üst üçgen kısmını oku
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            index = (i * n - (i * (i + 1)) / 2) + (j);
            printf("Matris[%d][%d] elemanını giriniz: ", i, j);
            scanf_s("%d", &alt[index]);
        }
    }
}

int gettriangularmatrix(int i, int j, int n) {
    // Geçersiz indeks kontrolü
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return -1;
    }

    // Üçgen dışında kalan alt üçgen için kontrol
    if (i > j) {
        return -2;
    }

    // Üst üçgenin geçerli bir indeksinin tek boyutlu dizideki yeri
    return (i * n - (i * (i + 1)) / 2) + (j);
}
