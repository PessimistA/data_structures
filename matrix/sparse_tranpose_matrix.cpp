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
		for (int j = 0; j <n; j++) {
			dizi_lower[i][j] = 0;
			dizi_transpoze[i][j] = 0;
		}
	}
	int itemler = n * n / 4;
	while (itemler > 0) {
		k = rand() % (n);
		l = rand() % (n);
		item = (rand() % 9 )+1;
		if (dizi_lower[k][l]==0)
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
void append_for_lower(int n,eleman element[],eleman transpoze[]) {
	element[0].col = n;
	element[0].row = n;
	element[0].value = n*n/4;
	transpoze[0].col = n;
	transpoze[0].row = n;
	transpoze[0].value = n * n / 4;
	int sayaç = 1;
	int sayaç2 = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dizi_lower[i][j]!=0)
			{
				element[sayaç].col = j;
				element[sayaç].row = i;
				element[sayaç].value = dizi_lower[i][j];
				sayaç++;
			}
			if (dizi_transpoze[i][j] != 0)
			{
				element[sayaç2].col = j;
				element[sayaç2].row = i;
				element[sayaç2].value = dizi_transpoze[i][j];
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
	for (int i = 0; i < n*n/4; i++)
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
	for (int i = 0; i < n * n / 4; i++)
	{
		printf("%d= row->%d col->%d ve value=%d\n", i, transpoze[i].row, transpoze[i].col, transpoze[i].value);
	}
}
int found_lower(int i,int j,int n, eleman element[]) {
	for (int k = 1; k <element[0].value ; k++)
	{
		if (element[k].col==j && element[k].row==i)
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
	element = (struct eleman*)malloc(n * n / 4 * sizeof(struct eleman));
	transpose = (struct eleman*)malloc(n * n / 4 * sizeof(struct eleman));
	append_for_lower(n, element ,transpose);
	print(n, element,transpose);
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
