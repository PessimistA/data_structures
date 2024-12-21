#include <stdio.h>
#include <stdlib.h>

int** matrix;
int** matrix1;
int** matrix2;
int** matrix3;
int* lower;
int* lower1;
int* upper;
int* upper1;


void built_matrix1(int x) {
    matrix = (int**)malloc(x * sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		matrix[i] = (int*)malloc(x * sizeof(int));
	}
	int eleman_sayısı = ((x * (x + 1)) / 2);
	lower = (int*)malloc(eleman_sayısı * sizeof(int));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++) {
			matrix[i][j] = 0;
		}
	}
	int sayaç = 1;
	for (int i = 0; i < x; i++)
	{	
		for (int j = x-i-1; j < x; j++) {
			sayaç++;
			matrix[i][j] =sayaç ;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d  ", matrix[i][j]);
		}
		printf("\n");
	}
	int position;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix[i][j]!=0)
			{
				position = (((i + 1) * i) / 2) + j - (x - i) + 1;
				lower[position] = matrix[i][j];
			}
		}
	}
	for (int i = 0; i < eleman_sayısı; i++)
	{
		printf("%d ", lower[i]);
	}printf("\n");

}

void built_matrix2(int x) {
	matrix1 = (int**)malloc(x * sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		matrix1[i] = (int*)malloc(x * sizeof(int));
	}
	int eleman_sayısı = ((x * (x + 1)) / 2);
	lower1 = (int*)malloc(eleman_sayısı * sizeof(int));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++) {
			matrix1[i][j] = 0;
		}
	}
	int sayaç = 1;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j <= i; j++) {
			sayaç++;
			matrix1[i][j] = sayaç;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d  ", matrix1[i][j]);
		}
		printf("\n");
	}
	int position;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix1[i][j] != 0)
			{
				position = (((i + 1) * i) / 2) + j ;
				lower1[position] = matrix1[i][j];
			}
		}
	}
	for (int i = 0; i < eleman_sayısı ; i++)
	{
		printf("%d ", lower1[i]);
	}
	printf("\n");

}

void built_matrix3(int x) {
	matrix2 = (int**)malloc(x * sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		matrix2[i] = (int*)malloc(x * sizeof(int));
	}
	int eleman_sayısı = ((x * (x + 1)) / 2);
	upper = (int*)malloc(eleman_sayısı * sizeof(int));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++) {
			matrix2[i][j] = 0;
		}
	}
	int sayaç = 1;
	for (int i = 0; i < x; i++)
	{
		for (int j = i; j <x ; j++) {
			sayaç++;
			matrix2[i][j] = sayaç;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d  ", matrix2[i][j]);
		}
		printf("\n");
	}
	int position;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix2[i][j] != 0)
			{
				position = (x*i)- (((i + 1) * i) / 2) + j;
				upper[position] = matrix2[i][j];
			}
		}
	}
	for (int i = 0; i < eleman_sayısı; i++)
	{
		printf("%d ", upper[i]);
	}
	printf("\n");

}
void built_matrix4(int x) {
	matrix3 = (int**)malloc(x * sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		matrix3[i] = (int*)malloc(x * sizeof(int));
	}
	int eleman_sayısı = ((x * (x + 1)) / 2);
	upper1 = (int*)malloc(eleman_sayısı * sizeof(int));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++) {
			matrix3[i][j] = 0;
		}
	}
	int sayaç = 1;
	for (int i = 0; i < x; i++)
	{
		for (int j =0; j < x-i; j++) {
			sayaç++;
			matrix3[i][j] = sayaç;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d  ", matrix3[i][j]);
		}
		printf("\n");
	}
	int position;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix3[i][j] != 0)
			{
				position = ((x+1) * i) + j - (i*(i+1))/2;
				upper1[position] = matrix3[i][j];
			}
		}
	}
	for (int i = 0; i < eleman_sayısı; i++)
	{
		printf("%d ", upper1[i]);
	}printf("\n");

}

int main() {
	int x = 5;
	built_matrix1(x);

	built_matrix2(x);

	built_matrix3(x);

	built_matrix4(x);
	return 0;
}


//

#include <stdio.h>
#include <stdlib.h>

int** matrix;
int** matrix1;
int** matrix2;
int** matrix3;
int* lower;
int* lower1;
int* upper;
int* upper1;


void built_matrix1(int x) {
	matrix = (int**)malloc(x * sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		matrix[i] = (int*)malloc(x * sizeof(int));
	}
	int eleman_sayısı = ((x * (x + 1)) / 2);
	lower = (int*)malloc(eleman_sayısı * sizeof(int));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			matrix[i][j] = 0;
		}
	}
	int sayaç = 1;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			matrix[i][j] = sayaç;
			sayaç++;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	int count = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			int index = j+((i * (i + 1)) / 2);
			lower[index] = matrix[i][j];
		}
	}printf("\n");
	for (int i = 0; i < eleman_sayısı; i++)
	{
		printf("%d  ", lower[i]);
	}
	
}

void built_matrix2(int x) {
	matrix1 = (int**)malloc(x * sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		matrix1[i] = (int*)malloc(x * sizeof(int));
	}
	int eleman_sayısı = ((x * (x + 1)) / 2);
	lower1 = (int*)malloc(eleman_sayısı * sizeof(int));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++) {
			matrix1[i][j] = 0;
		}
	}
	int sayaç = 1;
	for (int i = 0; i < x; i++)
	{
		for (int j = x-i-1; j < x; j++) {
			matrix1[i][j] = sayaç;
			sayaç++;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++) {
			printf("%d\t", matrix1[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix1[i][j] != 0)
			{
				int position = ((i * (i + 1)) / 2) + (j - (x - i - 1));
				lower1[position] = matrix1[i][j];
			}

		}
	}
	for (int i = 0; i < eleman_sayısı; i++)
	{
		printf("%d ", lower1[i]);
	}

}

void built_matrix3(int x) {
	matrix2 = (int**)malloc(x * sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		matrix2[i] = (int*)malloc(x * sizeof(int));
	}
	int eleman_sayısı = ((x * (x + 1)) / 2);
	upper = (int*)malloc(eleman_sayısı * sizeof(int));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++) {
			matrix2[i][j] = 0;
		}
	}
	int sayaç = 1;
	for (int i = 0; i < x; i++)
	{
		for (int j = i; j < x; j++) {
			matrix2[i][j] = sayaç;
			sayaç++;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d  ", matrix2[i][j]);
		}
		printf("\n");
	}
	int position;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix2[i][j] != 0)
			{
				position = (x * i) - (((i + 1) * i) / 2) + j;
				upper[position] = matrix2[i][j];
			}
		}
	}
	for (int i = 0; i < eleman_sayısı; i++)
	{
		printf("%d ", upper[i]);
	}
	printf("\n");

}
void built_matrix4(int x) {
	matrix3 = (int**)malloc(x * sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		matrix3[i] = (int*)malloc(x * sizeof(int));
	}
	int eleman_sayısı = ((x * (x + 1)) / 2);
	upper1 = (int*)malloc(eleman_sayısı * sizeof(int));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++) {
			matrix3[i][j] = 0;
		}
	}
	int sayaç = 1;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x - i; j++) {
			sayaç++;
			matrix3[i][j] = sayaç;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d  ", matrix3[i][j]);
		}
		printf("\n");
	}
	int position;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix3[i][j] != 0)
			{
				position = ((x + 1) * i) + j - (i * (i + 1)) / 2;
				upper1[position] = matrix3[i][j];
			}
		}
	}
	for (int i = 0; i < eleman_sayısı; i++)
	{
		printf("%d ", upper1[i]);
	}printf("\n");

}

int main() {
	int x = 5;
	//built_matrix1(x);

	//built_matrix2(x);

	//built_matrix3(x);

	built_matrix4(x);
	return 0;
}
