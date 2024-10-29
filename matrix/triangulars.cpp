#include <stdio.h>
#include <stdlib.h>

int** dizi_lower;
int** dizi_upper;
int index=0;
int* arraylast_lower;
int* arraylast_upper;
void arraymaker(int n) {
	dizi_lower = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		dizi_lower[i] = (int*)malloc(n * sizeof(int));
	}
	dizi_upper = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		dizi_upper[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <n; j++) {
			dizi_lower[i][j] = 0;
			dizi_upper[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >=0; j--) {
			dizi_lower[i][j] = rand() % 20;
		}
		for (int j = i; j < n; j++)
		{
			dizi_upper[i][j] = rand() % 20;
		}
	}
	int item = (n * (n + 1)) / 2;
	arraylast_lower = (int*)malloc(item * sizeof(int));
	arraylast_upper = (int*)malloc(item * sizeof(int));
}
void append_for_lower(int n) {
	int sayaç = 0;
	int sayaç1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (dizi_lower[i][j]!=0)
			{
				arraylast_lower[sayaç] = dizi_lower[i][j];
				sayaç++;
			}
			if (dizi_upper[i][j]!=0)
			{
				arraylast_upper[sayaç1] = dizi_upper[i][j];
				sayaç1++;
			}
		}
	}
}


void print(int n) {
	printf("ilk hali lower\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d\t", dizi_lower[i][j]);
		}
		printf("\n");
	}	
	printf("ilk hali upper\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d\t", dizi_upper[i][j]);
		}
		printf("\n");
	}
	printf("son hali lower\n");
	for (int i = 0; i < (n * (n + 1)) / 2-1; i++)
	{
		printf("%d\t", arraylast_lower[i]);
	}
	printf("son hali upper\n");
	for (int i = 0; i < (n * (n + 1)) / 2 - 1; i++)
	{
		printf("%d\t", arraylast_upper[i]);
	}

}
int found_lower(int i,int j) {
	if (i<j)
	{
		return -1;
	}
	else
	{
		return (i * ((i + 1)) / 2 + j);
	}
}
int found_upper(int i, int j,int n) {
	if (i > j)
	{
		return -1;
	}
	else
	{
		return (i * n - (i * ((i + 1)) / 2)+j)-1;
	}
}

int main() {
	printf("bir n degeri giriniz");
	int n, i, j;
	scanf_s("%d", &n);
	arraymaker(n);
	append_for_lower(n);
	print(n);
	printf("lütfen bir i ve j değeri giriniz");
	scanf_s("%d", &i);
	scanf_s("%d", &j);
	int index=found_lower(i, j);
	if (index == -1)
	{
		printf("problem");
	}
	else
	{
		printf("%d indexinde bulunan sayı %d dir",index,arraylast_lower[index]);
	}
	int index1 = found_upper(i, j,n);
	if (index1 == -1)
	{
		printf("problem");
	}
	else
	{
		printf("%d indexinde bulunan sayı %d dir", index1, arraylast_upper[index1]);
	}
	for (int i = 0; i < n; i++)
	{
		free(dizi_lower[i]);
	}
	free(dizi_lower);
	free(arraylast_lower);
	for (int i = 0; i < n; i++)
	{
		free(dizi_upper[i]);
	}
	free(dizi_upper);
	free(arraylast_upper);
	return 0;
}
