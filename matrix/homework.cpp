#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int** normal_array;
int** transPose;
void transpose(int col, int row);

void normal(int row,int col)
{
	(normal_array) = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		(normal_array)[i] = (int*)malloc(col * sizeof(int));
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			(normal_array)[i][j] = 0;
		}
	}
}
void yerleştirici(int col, int row) {
	double item_number = col * row *0.3;
	transpose(col, row);
	for (int i = 0; i < item_number; i++)
	{
		int row_ran = rand() % row;
		int col_ran = rand() % col;
		int value = rand() % 9;
		if ((normal_array)[row_ran][col_ran] == 0)
		{
			(normal_array)[row_ran][col_ran] = value;
			(transPose)[col_ran][row_ran] = value;
		}
		else
		{
			i--;
		}
	}
}
void print(int col, int row) {
	printf("normal array\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d", (normal_array)[i][j]);
		}
		printf("\n");
	}
	printf("transpoze array\n");
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%d", (transPose)[i][j]);
		}
		printf("\n");
	}
}
void transpose(int col, int row) {
	(transPose) = (int**)malloc(col * sizeof(int*));
	for (int i = 0; i < col; i++)
	{
		transPose[i] = (int*)malloc(row * sizeof(int));
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			(transPose)[i][j] = 0;
		}
	}

}


int main() {
	int row;
	int col;
	int value;

	printf("row sayısını giriniz");
	scanf_s("%d", &row);
	printf("colum sayısını giriniz");
	scanf_s("%d", &col);
	normal(row,col);
	yerleştirici(col,row);
	print(col,row);
	for (int i = 0; i < row; i++)
	{
		free(normal_array[i]);
	}free(normal_array);
	for (int i = 0; i < col; i++)
	{
		free(transPose[i]);
	}free(transPose);
	return 0;
}

