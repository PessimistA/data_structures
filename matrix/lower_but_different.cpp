#include <stdio.h>
#include <stdlib.h>

int** alt;
int index = 0;
int* arraylast_lower;

void arraymaker(int n) {//bu fonksiyon dinamik array oluşturmamı sağlar  ve itemleri ekler
	alt = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		alt[i] = (int*)malloc(n * sizeof(int));//dinamik bellek tasarlamak istedim böylelikle kendim istediğim değeri verebileceğim
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			alt[i][j] = 0;//başlangıçta her bir basamağı 0 ile doldurur
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = n - i - 1; j < n; j++) {
			alt[i][j] = rand() % 20;//20 ye kadar rastgele değerler atar
			if (alt[i][j] == 0)
			{
				j--;//0 değeri atamaması için başa sarar
			}
		}

	}
	int item = (n * (n + 1)) / 2;
	arraylast_lower = (int*)malloc(item * sizeof(int));
}
void append_for_lower(int n) {//bu fonksiyon 2 boyutlu diziyi tek boyuta indirger ve atama işlemini yapar 
	int sayaç = 0;
	int sayaç1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (alt[i][j] != 0)
			{
				arraylast_lower[sayaç] = alt[i][j];
				sayaç++;
			}
		}
	}
}
void print(int n) {
	printf("ilk hali lower\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d\t", alt[i][j]);
		}
		printf("\n");
	}
	printf("toplam nonzero eleman sayisi %d dir\n", (n * (n + 1)) / 2);
	printf("son hali lower\n");
	for (int i = 0; i < (n * (n + 1)) / 2; i++)
	{
		printf("alt_1d_array[%d]=%d\t", i, arraylast_lower[i]);
		printf("\n");
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (alt[i][j] != 0 && k < (n * (n + 1)) / 2)
			{
				printf("alt[%d][%d] = alt_1d_array[%d]=%d\n", i, j, k, arraylast_lower[k]);
				k++;
			}
		}
	}
}
int GetTriangularMatrix(int i, int j, int n) {//bu fonksiyon istediğim i ve j değerlerine göre index döner
	if (i < 0 && j<0 && i>j + 1)
	{
		return -1;
	}
	else
	{
		return ((i + 1) * i) / 2 + j - (n - i);
	}
}

int main() {
	printf("bir n degeri giriniz\n");
	int n, i, j;
	scanf_s("%d", &n);
	arraymaker(n);
	append_for_lower(n);
	print(n);
	printf("\nlutfen bir i ve j degeri giriniz\n");
	scanf_s("%d", &i);
	scanf_s("%d", &j);
	int index = GetTriangularMatrix(i, j, n - 1);
	if (index == -1)
	{
		printf("problem occoured");//bir problem oluştuğunu döndürür
	}
	else
	{
		printf("%d indexinde bulunan sayi %d dir", index, arraylast_lower[index]);
	}
	for (int i = 0; i < n; i++)
	{
		free(alt[i]);
	}
	free(alt);
	free(arraylast_lower);

	return 0;
}
