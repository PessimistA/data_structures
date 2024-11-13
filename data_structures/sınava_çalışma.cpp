//iterative fibonacci
int array[100] = { 2,4,6,7,8 };

int main() {
	int fibonacci[100];
	int first=0,second=1;
	

	for (int i = 0; i < 10; i++)
	{
		if (first==0&&second==1)
		{
			fibonacci[0] = first;
			fibonacci[1] = second;
			i = 2;
		}

			int geç = first + second;
			first = second;
			second = geç;
			fibonacci[i] = geç;
		
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", fibonacci[i]);
	}	
	return 0;
}

//iterative binary search

int array[100] = { 2,4,6,7,8 };
int main() {
	int len = 0;
	for (int i = 0; i < 100; i++)
	{
		if (array[i]!=0)
		{
			len++;
		}
	}
	int search = 4;
	int sol = 0, sağ = len;
	while (sol <= sağ) {
		int middle = (sol + sağ) / 2;
		if (search < array[middle]) {
			sağ = middle - 1;
		}
		else if (search > array[middle]) {
			sol = middle + 1;
		}
		else if (search == array[middle])
		{
			printf("%d", middle);
			break;
		}		
	}	
	return 0;
}

//bir diziyi recursive olarak toplayan

int array[100] = { 2,4,6,7,8 };
void recursive(int start,int len,int* result) {
	if (start==len)
	{
		return;
	}
	else
	{
		*result = *result + array[start];
		recursive(start + 1, len, result);
	}
}
int main() {
	int len = 0;
	for (int i = 0; i < 100; i++)
	{
		if (array[i]!=0)
		{
			len++;
		}
	}
	int result = 0;
	recursive(0, len, &result);
	printf("%d", result);
	return 0;
}

//finding max mim as recursive

int array[100] = { 2,44,6,7,8 };
void recursive(int start,int len,int* result,int max) {
	if (start==len)
	{
		return;
	}
	else
	{
		if (max< array[start])
		{
			max = array[start];
		}
		*result = max;
		recursive(start + 1, len, result,max);
	}
}
int main() {
	int len = 0;
	for (int i = 0; i < 100; i++)
	{
		if (array[i]!=0)
		{
			len++;
		}
	}
	int result = 0;
	int max = array[0];
	recursive(0, len, &result,max);
	printf("%d", result);

	return 0;
}

//polindrom bulan kod
char array[100] = {"assi"};
void recursive(int start,int len,int* result,int len2) {
	if (len%2==0)
	{
		if (start > len)
		{
			printf("bu bir polindromdur");
			return;
		}
		else
		{
			if (array[start] == array[len])
			{
				recursive(start + 1, len - 1, result, len2);
			}
			else
			{
				printf("bu bir polindrom değildir");
			}
		}
	}
	else
	{
		if (start == len)
		{
			printf("bu bir polindromdur");
			return;
		}
		else
		{
			if (array[start] == array[len])
			{
				recursive(start + 1, len - 1, result, len2);
			}
			else
			{
				printf("bu bir polindrom değildir");
			}
		}
	}
}
int main() {
	int len = strlen(array);
	int result = 0;
	recursive(0, len-1, &result,len);
	//printf("%d", result);
	return 0;
}

//binary translater recursive
int* array ;
void recursive(int sayı,int sayaç) {
	if (sayı<=0)
	{
		return;
	}
	else
	{
		array[sayaç] = (sayı % 2);
		sayı = sayı / 2;
		sayaç++;
		recursive(sayı, sayaç);
	}
}
int main() {
	int sayı = 17;
	int len = log2(sayı)+1;
	array = (int*)malloc(len * sizeof(int));
	int result = 0;
	recursive(sayı,result);
	for (int i = len-1; i >= 0; i--)
	{
		printf("%d", array[i]);
	}
	return 0;
}

//towers of hanoi

void towerOfHanoi(int n, char ilk_çubuk, char ikinci_çubuk, char yardımcı_çubuk) {
	if (n == 1) {
		printf("Move disk 1 from %c to %c\n", ilk_çubuk, ikinci_çubuk);
		return;
	}

	towerOfHanoi(n - 1, ilk_çubuk, yardımcı_çubuk, ikinci_çubuk);

	printf("Move disk %d from %c to %c\n", n, ilk_çubuk, ikinci_çubuk);

	towerOfHanoi(n - 1, yardımcı_çubuk, ikinci_çubuk, ilk_çubuk);
}

int main() {
	int n;
	printf("Enter the number of disks: ");
	scanf("%d", &n);
	printf("Steps to solve Tower of Hanoi with %d disks:\n", n);
	towerOfHanoi(n, 'A', 'C', 'B'); 
	return 0;
}

//ters çeviren fonksiyon
int array[10] = {1,2,3,4,5,6};
void recursive(int start,int last,int len) {
	if (len % 2 == 0)
	{
		if (start > last)
		{
			return;
		}
		else
		{
			int geç = array[start];
			array[start] = array[last];
			array[last] = geç;
			recursive(start + 1, last - 1, len);
		}
	}
	else
	{
		if (start == last)
		{
			return;
		}
		else
		{
			int geç = array[start];
			array[start] = array[last];
			array[last] = geç;
			recursive(start + 1, last - 1, len);
		}
	}
}
int main() {
	int len=0;
	for (int i = 0; i < 10; i++)
	{
		if (array[i]!=0)
		{
			len++;
		}
	}
	recursive(0,len-1,len);
	for (int i = 0; i< len; i++)
	{
		printf("%d", array[i]);
	}
	return 0;
}

//triangular matrix
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<math.h>

#define MAX 100
int** matrix;
int* storage;
void print(int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	if (storage!=NULL)
	{
		int len = n * (n + 1) / 2;
		for (int j = 0; j < len; j++)
		{
			printf("%d\t", storage[j]);
		}
	}
}
void readtriangularmatrix(int n) {
	int sayaç = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int k = (i * (i + 1) / 2) + j;
			storage[k] = matrix[i][j];
		}
	}
}
void matrixMAker(int n) {
	matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}	
	int sayaç = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >=0; j--)
		{
			matrix[i][j] = rand() % 100;
			if (matrix[i][j]==0)
			{
				j++;//++ yapmak eski haline geri getirir
			}
		}
	}
	print(n);
	int len = n * (n + 1) / 2;//parantez önemli
	storage= (int*)malloc(len * sizeof(int));
	readtriangularmatrix(n);
	print(n);

}
int main() {
	int n;
	printf("lütfen bir n değeri alınız");
	scanf_s("%d", &n);
	matrixMAker(n);

	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	free(storage);
}

//upper triangular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<math.h>

#define MAX 100
int** matrix;
int* storage;
void print(int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	if (storage!=NULL)
	{
		int len = n * (n + 1) / 2;
		for (int j = 0; j < len; j++)
		{
			printf("%d\t", storage[j]);
		}
	}
}
void readtriangularmatrix(int n) {
	int sayaç = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j <n; j++)
		{
			int k = (n * i) - ((i * (i + 1) / 2) - j);
			storage[k] = matrix[i][j];
		}
	}
}
void matrixMAker(int n) {
	matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}	
	int sayaç = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j <n; j++)
		{
			matrix[i][j] = rand() % 100;
			if (matrix[i][j]==0)
			{
				j--;//++ yapmak eski haline geri getirir
			}
		}
	}
	print(n);
	int len = n * (n + 1) / 2;
	storage= (int*)malloc(len * sizeof(int));
	readtriangularmatrix(n);
	print(n);

}
int main() {
	int n;
	printf("lütfen bir n değeri alınız");
	scanf_s("%d", &n);
	matrixMAker(n);

	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	free(storage);
}
