#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100


typedef struct {
	int col;
	int row;
	int value;
}term;

void transpose(term a[], term b[]);

int main(void) {
	  term c[MAX_SIZE], b[MAX_SIZE];
    int a[5][5] = { {15,0,22,0,-15},{0,11,3,0,0},{2,0,7,0,0},{0,0,0,6,5} };
	int sayaç = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			if (a[i][j] !=0)
			{
				c[sayaç].row = i;
				c[sayaç].col = j;
				c[sayaç].value = a[i][j];
				sayaç++;
			}
		}
	}
	for (int i = 0; i < sayaç; i++)
	{
		printf("[%d][%d]= %d\n", c[i].row ,c[i].col,c[i].value);
	}
	c[0].row = 5;
	c[0].col = 5;
	c[0].value = sayaç;
	transpose(c,b);
	printf("\n\ntranspose verison\n\n");
	for (int i = 0; i < sayaç; i++)
	{
		printf("[%d][%d]= %d\n", b[i].row, b[i].col, b[i].value);
	}
    return 0;
}
void transpose(term a[], term b[]) {
	int n, currentb;
	n = a[0].value;
	b[0].col = a[0].row;
	b[0].row = a[0].col;
	b[0].value = n;

	if (n>0)
	{
		currentb = 1;
		for (int i = 0; i < a[0].col; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[j].col==i)
				{

					b[currentb].col = a[j].row;
					b[currentb].row = a[j].col;
					b[currentb].value = a[j].value;
					currentb++;
				}
			}
		}
	}


}
//ver2
#include <stdio.h>
#include <stdlib.h>

int** dizi_lower;
int** dizi_transpoze;

int itemcount;
struct eleman
{
	int row;
	int col;
	int value;
};

void arraymaker(int n) {
	int item;
	int k, l;
	dizi_lower = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		dizi_lower[i] = (int*)malloc(n * sizeof(int));
	}
	dizi_transpoze = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		dizi_transpoze[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			dizi_lower[i][j] = 0;
			dizi_transpoze[i][j] = 0;
		}
	}
	int itemler = n * n / 4;
	while (itemler > 0) {
		k = rand() % (n);
		l = rand() % (n);
		item = (rand() % 9) + 1;
		if (dizi_lower[k][l] == 0)
		{
			dizi_lower[k][l] = item;
			dizi_transpoze[l][k] = item;
			itemler--;
		}
		else
		{
			continue;
		}
	}
}
void append_for_lower(int n, eleman element[], eleman transpoze[]) {
	element[0].col = n;
	element[0].row = n;
	element[0].value = n * n / 4;
	transpoze[0].col = n;
	transpoze[0].row = n;
	transpoze[0].value = n * n / 4;
	int sayaç = 1;
	int sayaç2 = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dizi_lower[i][j] != 0)
			{
				element[sayaç].col = j;
				element[sayaç].row = i;
				element[sayaç].value = dizi_lower[i][j];
				sayaç++;
			}
			if (dizi_transpoze[i][j] != 0)
			{
				transpoze[sayaç2].col = j;
				transpoze[sayaç2].row = i;
				transpoze[sayaç2].value = dizi_transpoze[i][j];
				sayaç2++;
			}
		}
	}

}
void print(int n, eleman element[], eleman transpoze[]) {
	printf("ilk hali\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d\t", dizi_lower[i][j]);
		}
		printf("\n");
	}
	printf("diğer hali\n");
	for (int i = 0; i < n * n / 4+1; i++)
	{
		printf("%d= row->%d col->%d ve value=%d\n", i, element[i].row, element[i].col, element[i].value);
	}
	printf("transpoze hali\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d\t", dizi_transpoze[i][j]);
		}
		printf("\n");
	}
	printf("diğer hali\n");
	for (int i = 0; i < n * n / 4 +1; i++)
	{
		printf("%d= row->%d col->%d ve value=%d\n", i, transpoze[i].row, transpoze[i].col, transpoze[i].value);
	}
}
int found_lower(int i, int j, int n, eleman element[]) {
	for (int k = 1; k < element[0].value; k++)
	{
		if (element[k].col == j && element[k].row == i)
		{
			return k;
		}
	}
}

int main() {
	struct eleman* element;
	struct eleman* transpose;
	printf("bir n degeri giriniz");
	int n;
	scanf_s("%d", &n);
	itemcount = n / 4;
	arraymaker(n);
	int sizelast = n * n;
	element = (struct eleman*)malloc(sizelast * sizeof(struct eleman));
	transpose = (struct eleman*)malloc(sizelast * sizeof(struct eleman));
	append_for_lower(n, element, transpose);
	print(n, element, transpose);
	int i, j;
	//printf("lütfen bir i ve j değeri giriniz");
	//scanf_s("%d", &i);
	//scanf_s("%d", &j);
	//int yer=found_lower(i, j, n, element);
	//printf("%d ve %d = %d indexte değeri de %d", i, j, yer,element[yer].value);
	for (int i = 0; i < n; i++)
	{
		free(dizi_lower[i]);
	}
	free(dizi_lower);
	free(element);
	for (int i = 0; i < n; i++)
	{
		free(dizi_transpoze[i]);
	}
	free(dizi_transpoze);
	free(transpose);
	return 0;
}

//ver3
#include <stdio.h>
#include <stdlib.h>

struct matrix1 {
	int col;
	int row;
	int value;
};
int** matrix;
matrix1* sparse;
matrix1* sparse_transpose;


void built_matrix1(int x) {
    matrix = (int**)malloc(x * sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		matrix[i] = (int*)malloc(x * sizeof(int));
	}
	int eleman_sayısı = ((x*x)*0.4)+1;
	sparse = (matrix1*)malloc(eleman_sayısı * sizeof(matrix1));
	sparse_transpose = (matrix1*)malloc(eleman_sayısı * sizeof(matrix1));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++) {
			matrix[i][j] = 0;
		}
	}
	int sayaç = eleman_sayısı;
	while (sayaç>=0) {
		int i1 = (rand() % x);
		int j1 = (rand() % x);
		int value = (rand() % 20) + 1;
		matrix[i1][j1] = value;
		sayaç--;
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d  ", matrix[i][j]);
		}
		printf("\n");
	}
	int position=1;
	int position2 = 1;
	sparse[0].value=eleman_sayısı;
	sparse[0].row = x;
	sparse[0].col = x;
	sparse_transpose[0].value = eleman_sayısı;
	sparse_transpose[0].col = x;
	sparse_transpose[0].row = x;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix[i][j]!=0)
			{
				sparse[position].value = matrix[i][j];
				sparse[position].row = i;
				sparse[position].col = j;
				position++;
			}
			if (matrix[j][i] != 0)
			{
				sparse_transpose[position2].value = matrix[j][i];
				sparse_transpose[position2].row = j;
				sparse_transpose[position2].col = i;
				position2++;
			}
		}
	}
	for (int i = 0; i < eleman_sayısı; i++)
	{
		printf("%d ", sparse[i].value);
	}
	printf("\n");
	for (int i = 0; i < eleman_sayısı ; i++)
	{
		printf("%d ", sparse_transpose[i].value);
	}
	printf("\n");

}


int main() {
	int x = 5;
	built_matrix1(x);

	return 0;
}
