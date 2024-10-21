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
