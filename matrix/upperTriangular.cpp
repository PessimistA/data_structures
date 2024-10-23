
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

//version 2
#include <stdio.h>
#include <stdlib.h>

int** arrays;
int* onedarray;

void sizing(int n) {
	arrays = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		arrays[i] = (int*)malloc(n * sizeof(int));
	}
}
void sizing2(int n) {
	onedarray = (int*)malloc(n*(n+1)/2 * sizeof(int));
}
void print(int n) {
	printf("normal version\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arrays[i][j]);  
		}
		printf("\n");
	}
	printf("\none d array version\n");
	for (int i = 0; i < n*(n+1)/2; i++)
	{
		printf("%d sirada = %d\n", i, onedarray[i]);
	}
}
int find_index(int i, int j, int n) {
	if (i >= j)
	{
		return n*i-((i * (i + 1)) / 2) + j;
	}
	else
	{
		return -1;
	}
}
void readingoftriangular(int n) {
	sizing(n);
	sizing2(n);
	int counter = 1;
	int index = 0;
	for (int i = 0; i < n; i++) {//hepsine sıfır ataması yapar
		for (int j = 0; j < n; j++) {
			arrays[i][j] = 0; 
		}
	}

	for (int i = 0; i < n; i++) {//2 boyutlu diziye atanma yapar 
		for (int j = i; j <n; j++) {//bir i>j olmalı bu yüzden j den başlar
			arrays[i][j] = counter;  
			counter++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int index = n*i-(i * (i + 1)) / 2 + j;//upper formulü işler
			onedarray[index] = arrays[i][j];
		}
	}

	print(n);  
	printf("lutfen bulunmasini istediğiniz i ve j numaralarini giriniz\n");
	int k, f;
	scanf_s("%d", &k);
	scanf_s("%d", &f);
	int index1 =find_index(k, f, n);
	if (index1==-1)
	{
		printf("problem");
	}
	else
	{
		printf("aradiginiz sayi arrays[%d][%d]= onedarray[%d]= %d", k, f, index1, onedarray[index1]);
	}
}


int main() {
	printf("lutfen bir size giriniz");
	int n;
	scanf_s("%d", &n);
	readingoftriangular(n);
	for (int i = 0; i < n; i++)
	{
		free(arrays[i]);
	}
	free(arrays);
	free(onedarray);
	return 0;
}
