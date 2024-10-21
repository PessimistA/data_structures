//lower triangler
#include <stdio.h>

int gettriangularmatrix(int i, int j, int n);
int readtriangularmatrix(int alt[], int n);

int main() {
	int alt[101];
	int i, n;
	scanf("%d", &n); //matrix size
	int a =readtriangularmatrix(alt, n);
	for (i = 0; i <= n * (n + 1) / 2 - 1; i++)
		printf("%d", alt[i]);
	i = gettriangularmatrix(3, 0, n);
	if (i == 2)
		printf("\n invalid index\n");
	else if (i == 1)
		printf("\n access to the upper triangular\n");
	else
		printf("“\n the position in ‘alt’ matrix : % d value : % d \n“", i, alt[i]);

	return 0;
}

int readtriangularmatrix(int alt[], int n)
{
	int i, j, k;
	if (n * (n + 1) / 2 > 101) {
		printf("\n invalid array size \n");
		return 1;
	}
	else
		for (i = 0; i <= n - 1; i++) {
			k = (i + 1) * i / 2;
			for (j = 0; j <= i; j++)
				scanf("%d", &alt[k + j]);
		}
	return 0;
}
int gettriangularmatrix(int i, int j, int n) {
	if (i < 0 || i >= n || j < 0 || j >= n) {
		printf("“\n invalid index\n“");
		return 2;
	}
	else if (i >= j) //valid index
		return (i + 1) * i / 2 + j;
	else return -1; //outside of the triangular

	//value is zero
}
