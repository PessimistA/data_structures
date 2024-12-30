#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 9

int matrix[MAX][MAX];
int Weighted_Matrix[MAX][MAX];
int sparse[MAX];

void build() {
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			matrix[i][j] = 0;
			Weighted_Matrix[i][j] = 0;
		}
	}
}
void insert_weighted(int i, int j, int weight) {
	Weighted_Matrix[i][j] = weight;
}
void insert(int i, int j) {
	matrix[i][j] = 1;
}
void print() {
	printf("sparse matrix \n");
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			printf("%d ", Weighted_Matrix[i][j]);
		}
		printf("\n");
	}
}
void sparse_to_1d() {
	int sayaç = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (matrix[i][j] != 0)
			{
				sparse[sayaç] = matrix[i][j];
				sayaç++;
			}
		}
	}
	for (int j = 0; j < MAX; j++)
	{
		printf("%d->", sparse[j]);
	}
}

int main() {
	build();
	insert(0, 2);
	insert(0, 5);
	insert(5, 7);
	insert(7, 8);
	insert(5, 3);
	insert(3, 4);
	insert(4, 5);
	insert(2, 6);
	insert(1, 6);

	insert_weighted(0, 2, 3);
	insert_weighted(0, 5, 1);
	insert_weighted(5, 7, 2);
	insert_weighted(7, 8, 9);
	insert_weighted(5, 3, 6);
	insert_weighted(3, 4, 21);
	insert_weighted(4, 5, 43);
	insert_weighted(2, 6, 13);
	insert_weighted(1, 6, 90);

	print();

	sparse_to_1d();
}