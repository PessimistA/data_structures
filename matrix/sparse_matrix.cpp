#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 101
typedef struct {
	int col;
	int row;
	int value;
}term;

int main(void) {
	term c[100];
    int a[5][5] = { {15,0,22,0,-15},{0,11,3,0,0},{2,0,7,0,0},{0,0,0,6,5} };
	int b[100];
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
    return 0;
}
