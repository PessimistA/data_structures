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

//ortaya basılan üçgen k sında hata var
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
		int x = (n + 1) / 2;
		int len = x * x;
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
		for (int j = i; j < n - i; j++)
		{
			int k = (n * i) - ((4*j)-(3.5*i));
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
		for (int j = i; j < n-i; j++)
		{
			matrix[i][j] = rand() % 100;
			if (matrix[i][j]==0)
			{
				j--;//-- yapmak eski haline geri getirir
			}
		}
	}
	print(n);
	int x = (n + 1)/2;
	int len = x*x;
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

//sparse matrix

#include <stdio.h>
#include <stdlib.h>

int** alt;
int index = 0;
void print(int n);

struct  kullan{
	int değer;
	int row;
	int col;
}*sparse;
void addarray(int n);
void arraymaker(int n) {//bu fonksiyon dinamik array oluşturmamı sağlar  ve itemleri ekler
	alt = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		alt[i] = (int*)malloc(n * sizeof(int));//dinamik bellek tasarlamak istedim böylelikle kendim istediğim değeri verebileceğim
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			alt[i][j] = 0;//başlangıçta her bir basamağı 0 ile doldurur
		}
	}
	int itemler = (n * n) * 0.4;
	int i, j;
	while (itemler > 0) {
		i = rand() % n;
		j = rand() % n;
		alt[i][j] = rand() % 10;
		if (alt[i][j]==0)
		{
			j--;
			i--;
		}
		itemler--;
	}
	print(n);
	int item = (n * n) * 0.4;
	sparse = (kullan*)malloc(item * sizeof(kullan));
	addarray(n);
}

void print(int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d\t", alt[i][j]);//başlangıçta her bir basamağı 0 ile doldurur
		}
		printf("\n");
	}

}
void addarray(int n) {
	int itemler = 1;
	sparse[0].değer = (n * n) * 0.4-1;
	sparse[0].row = n;
	sparse[0].col = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (alt[i][j]!=0)
			{
				sparse[itemler].değer = alt[i][j];
				sparse[itemler].row = i;
				sparse[itemler].col = j;
				itemler++;
			}
		}
	}
}
void printarray(int n) {
	for (int i = 0; i < (n * n) * 0.4; i++)
	{
		printf("sparse[%d]==alt[%d][%d]=%d\n", i,sparse[i].row, sparse[i].col, sparse[i].değer);
	}
}

int main() {
	int n = 0;
	printf("bir size giriniz\n");
	scanf_s("%d", &n);
	arraymaker(n);
	printarray(n);
	for (int i = 0; i < n; i++)
	{
		free(alt[i]);
	}
	free(alt);
	free(sparse);
	return 0;
}

//sparse ve transpoze hesabı
#include <stdio.h>
#include <stdlib.h>

int** alt;
int index = 0;
void print(int n);

struct  kullan{
	int değer;
	int row;
	int col;
}*sparse,*Transpoze;
void transpoze(int n);

void addarray(int n);
void arraymaker(int n) {//bu fonksiyon dinamik array oluşturmamı sağlar  ve itemleri ekler
	alt = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		alt[i] = (int*)malloc(n * sizeof(int));//dinamik bellek tasarlamak istedim böylelikle kendim istediğim değeri verebileceğim
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			alt[i][j] = 0;//başlangıçta her bir basamağı 0 ile doldurur
		}
	}
	int itemler = (n * n) * 0.4;
	int i, j;
	while (itemler > 0) {
		i = rand() % n;
		j = rand() % n;
		alt[i][j] = rand() % 10;
		if (alt[i][j]==0)
		{
			j--;
			i--;
		}
		itemler--;
	}
	print(n);
	int item = (n * n) * 0.4;
	sparse = (kullan*)malloc(item * sizeof(kullan));
	Transpoze = (kullan*)malloc(item * sizeof(kullan));
	addarray(n);
	transpoze(n);
}

void print(int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d\t", alt[i][j]);//başlangıçta her bir basamağı 0 ile doldurur
		}
		printf("\n");
	}

}
void addarray(int n) {
	int itemler = 1;
	sparse[0].değer = (n * n) * 0.4-1;
	sparse[0].row = n;
	sparse[0].col = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (alt[i][j]!=0)
			{
				sparse[itemler].değer = alt[i][j];
				sparse[itemler].row = i;
				sparse[itemler].col = j;
				itemler++;
			}
		}
	}
}

void transpoze(int n) {
	int sayaç = 1;
	Transpoze[0].değer =sparse[0].değer;
	Transpoze[0].col =sparse[0].row;
	Transpoze[0].row =sparse[0].col;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (alt[j][i] != 0)
			{
				Transpoze[sayaç].değer = alt[j][i];
				Transpoze[sayaç].row = j;
				Transpoze[sayaç].col = i;
				sayaç++;
			}
		}
	}
}
void printarray(int n) {
	printf("normal hali\n");
	for (int i = 0; i < (n * n) * 0.4; i++)
	{
		printf("sparse[%d]==alt[%d][%d]=%d\n", i,sparse[i].row, sparse[i].col, sparse[i].değer);
	}
	printf("transpoze hali\n");
	for (int i = 0; i < (n * n) * 0.4; i++)
	{
		printf("transpoze[%d]==alt[%d][%d]=%d\n", i, Transpoze[i].col, Transpoze[i].row, Transpoze[i].değer);
	}
}

int main() {
	int n = 0;
	printf("bir size giriniz\n");
	scanf_s("%d", &n);
	arraymaker(n);
	printarray(n);
	for (int i = 0; i < n; i++)
	{
		free(alt[i]);
	}
	free(alt);
	free(sparse);
	return 0;
}

//band matrix

#include <stdio.h>
#include <stdlib.h>

int** alt;
int index = 0;
void print(int n);
int* band;
int* search;

void addarray(int n, int a, int b);

void arraymaker(int n,int a,int b) {//bu fonksiyon dinamik array oluşturmamı sağlar  ve itemleri ekler
	alt = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		alt[i] = (int*)malloc(n * sizeof(int));//dinamik bellek tasarlamak istedim böylelikle kendim istediğim değeri verebileceğim
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			alt[i][j] = 0;//başlangıçta her bir basamağı 0 ile doldurur
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			alt[i][j] = rand()%10;
			if (alt[i][j]==0)
			{
				j--;
			}
		}
	}
	int k = 0;
	for (int i = n-1; i >=a-1; i--)
	{
		for (int j = 0; j <= i-a; j++) {
			alt[i][j] = 0;
		
		}
	}
	for (int j = n-1; j >=b-1; j--)
	{
		for (int i = 0; i <=j-b; i++) {
			alt[i][j] = 0;

		}
	}
	int len = n * (a + b - 1) - ((a - 1) * a) / 2 - (b * (b - 1)) / 2;
	band = (int*)malloc(len * sizeof(int));
	int len2 = a + b - 1;
	search = (int*)malloc(len2 * sizeof(int));
	addarray(n, a, b);

}

void print(int n,int a,int b) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d\t", alt[i][j]);//başlangıçta her bir basamağı 0 ile doldurur
		}
		printf("\n");
	}

	for (int i = 0; i < n * (a + b - 1) - ((a - 1) * a) / 2 - (b * (b - 1)) / 2; i++)
	{
		printf("%d\t", band[i]);//başlangıçta her bir basamağı 0 ile doldurur
	}


}
void addarray(int n,int a,int b) {
	int itemnum =0 ;
	for (int i = -a + 1; i <= b - 1; i++)
	{
		search[i + a - 1] = itemnum;
		itemnum = itemnum + (n - abs(i));
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j > i)//büyükse b ye olanı değerlendir
			{
				if (j - i < b)
				{
					band[search[a - 1 + j - i] + i] = alt[i][j];
				}
			}
			else if(i-j<a)
			{
				band[search[a - 1 + j - i] + j] = alt[i][j];
			}
			
		}
	}
	
}

int main() {
	int n = 0,a=0,b=0;
	printf("bir size giriniz\n");
	scanf_s("%d", &n);
	printf("bir a giriniz\n");
	scanf_s("%d", &a);
	printf("bir b giriniz\n");
	scanf_s("%d", &b);
	arraymaker(n,a,b);
	print(n,a,b);
	for (int i = 0; i < n; i++)
	{
		free(alt[i]);
	}
	free(alt);
	free(band);
	free(search);
	return 0;
}
//parantez kontrol etme
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 100
char stack[Max];
int top = -1;


void pop() {
	if (top==-1)
	{
		printf("empty");
	}
	else
	{
		top--;
	}
}
void push(char value) {
	stack[++top] = value;
}

void print() {
	printf("\nstack");
	for (int i = 0; i <= top; i++)
	{
		printf(" %d ", stack[i]);
	}
}
int topreturn() {
	if (stack[top]=='(')
	{
		return -1;
	}
	if (stack[top] == '[')
	{
		return -2;
	}
	if (stack[top] == '{')
	{
		return -3;
	}
}
int main() {
	char kelime[Max] = { "(alisa)[{}2.]" };
	int len = strlen(kelime);
	for (int i = 0; i <= len; i++)
	{
		if (kelime[i] == '(' || kelime[i] == '[' || kelime[i] == '{') {
			push(kelime[i]);
		}
		else 
		{
			if (kelime[i] == ')')
			{
				if (topreturn() == -1)
				{
					pop();
				}
				else
				{
					printf("tüm parantezler uyumlu değildir");
				}
			}
			if (kelime[i] == ']')
			{
				if (topreturn() == -2)
				{
					pop();
				}
				else
				{
					printf("tüm parantezler uyumlu değildir");
				}
			}
			if (kelime[i] == '}')
			{
				if (topreturn() == -3)
				{
					pop();
				}
				else
				{
					printf("tüm parantezler uyumlu değildir");
				}
			}
		}
	}
	if (top==-1)
	{
		printf("uyumludur");
	}
	return 0;
}

//linked list özellikleri
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 10
#define EMPTY -1
#define TRUE 1
#define FALSE 0

struct kullan {
	int link;
	char isim[Max];
}dizi[Max];
int FREE ;
int first;
int first2;

void makelist() {
	for (int i = 0; i < Max; i++)
	{
		dizi[i].link = i + 1;
	}
	FREE = 0;
	first = EMPTY;
	first2 = EMPTY;
}
int get_item(int* r) {
	*r = FREE;
	FREE = dizi[FREE].link;
	return true;
}
void insert_item(char value[],int* list) {
	int q, r, p;
	if (get_item(&r))
	{
		strcpy(dizi[r].isim, value);
		q = EMPTY;
		p = *list;
		while (p!=EMPTY && strcmp(dizi[p].isim,value)<0) {
			q = p;//p değişken p yi ilk eleman olarak düşün  q ya bu değer verilip kendisi artıyor kontrol için zaten kontrolü de p ile yaparız dikkat et
			p = dizi[p].link;
		}
		if (q==EMPTY)//dizinin ilk elemanı ataması burada yapılır
		{
			*list = r;//ilk elemanın indeximi belirler
			dizi[r].link = p;//r ilk elemanın indexiydi p de first idi üstteki while daha burada olmamış durumda unutma
		}
		else
		{
			dizi[q].link = r;
			dizi[r].link = p;
		}
	}
}
void return_item(int r) {
	dizi[r].link = FREE;
	FREE = r;
}
void delete_item(char value[], int* list) {
	int q, p;
	q = EMPTY;
	p = *list;
	int i;
	while (p != EMPTY && (i=strcmp(dizi[p].isim, value)) < 0) {
		q = p;
		p = dizi[p].link;
	}
	if (p==EMPTY&& i>0)// listenin sonundan 
	{
		printf("bulunamadı");
	}
	else if (q==EMPTY) {//listenin başından çıkarır
		*list = dizi[p].link;
		return_item(p);//yeni free belirlenir bununla
	}
	else//listenin ortasından çıkarır
	{
		dizi[q].link = dizi[p].link;//aradan r yi çıkart
		return_item(p);
	}

}
void print() {
	int sayaç = first;	int sayaç2 = first2;
	printf("index\tisim\tlink\n");
	for (int i = 0; i < Max; i++)
	{
		printf("%d\t%s\t%d\n", i, dizi[i].isim, dizi[i].link);
	}	printf("index\tisim\tlink\n");
	while (sayaç != EMPTY) {
		printf("%d\t%s\t%d\n", sayaç, dizi[sayaç].isim, dizi[sayaç].link);
		sayaç = dizi[sayaç].link;
	}
	if (first2!=EMPTY)
	{
		while (sayaç2 != EMPTY) {
			printf("%d\t%s\t%d\n", sayaç2, dizi[sayaç2].isim, dizi[sayaç2].link);
			sayaç2 = dizi[sayaç2].link;
		}
	}

}

int main() {
	makelist();
	char names[Max][Max] = { "alisa","basil","olimi","agroda","vibril","albina" };
	for (int i = 0; i < 6; i++)
	{
		insert_item(names[i], &first);
	}
	print();
	char names3[Max][Max] = { "asa","asil" };
	char names2[Max] = "alisa";
	delete_item(names2, &first);
	print();
	for (int i = 0; i < 2; i++)
	{
		insert_item(names3[i], &first2);
	}
	print();
	return 0;
}

//insert ve delete arasındaki fark

void insert_item(char value[],int* list) {
	int q, r, p;
	if (get_item(&r))
	{
		strcpy(dizi[r].isim, value);
		q = EMPTY;
		p = *list;
		while (p!=EMPTY ) {
			q = p;//p değişken p yi ilk eleman olarak düşün  q ya bu değer verilip kendisi artıyor kontrol için zaten kontrolü de p ile yaparız dikkat et
			p = dizi[p].link;
		}
		if (q==EMPTY)//dizinin ilk elemanı ataması burada yapılır
		{
			*list = r;//		*list = dizi[p].link;
			dizi[r].link = p;//		return_item(p);
		}
		else
		{
			dizi[q].link = r;//		dizi[q].link = dizi[p].link;//aradan r yi çıkart
			dizi[r].link = p;//		return_item(p);
		}
	}
}
//postfix prefix için yöntem önce bunlar olursa bunu kullan diğerinde öncelik ve operatorlerde var
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char stack[MAX][MAX];
int top = -1;

void push(char* value) {
	top++;
	strcpy(stack[top],value) ;
}
void pop(char* op) {
	if (top==-1)
	{
		return;
	}
	strcpy(op, stack[top]);
	top--;
}

int isoperand(char ch) {
	return isalpha(ch) || isdigit(ch);
}
void reverse(char* value) {
	int len = strlen(value);
	int start = 0;
	while (!(start > len)) {
		char geç = value[len-1];
		value[len-1] = value[start];
		value[start] = geç;
		start++;
		len--;
	}
}
void reverseParanteheses(char* value) {
	reverse(value);
	int len = strlen(value);
	for (int i = 0; i < len; i++)
	{
		if (value[i] == '(') {
			value[i] = ')';
		}
		else if (value[i] == ')') {
			value[i] = '(';
		}
	}
}
void translater(char value[],char prefix[]) {
	int len = strlen(value);
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		char ch = value[i];
		if (isoperand(ch))
		{
			char operand[2] = {ch,'\0'};
			push(operand);
		}
		else
		{
			char op1[MAX], op2[MAX];
			pop(op1);
			pop(op2);

			char newep[MAX]="";//çok önemli boş tanıman gerekir
			
			strcat(newep, op1);//op1 başta olursa prefix kullanırsın yani reverse aç//op2 olursa postfix reverse kullanma
			strncat(newep, &ch, 1);//infix için ortaya postfix e dönüşürse sona prefix e dönüşürse başa
			strcat(newep, op2);
			push(newep);//
		}
	}
	strcpy(prefix, stack[top]);
}

int main() {
	char value[MAX] = "*-a/bc-/akl";
	char prefix[MAX];
	reverseParanteheses(value);
	printf("%s\n", value);
	translater(value, prefix);
	printf("%s", prefix);
	return 0;
}
//infix başta ise bunu kullan
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack yapısı
char stack[MAX];
int top = -1;

// Stack işlemleri
void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// İnfix'i tersine çevir
void reverse(char* value) {
	int len = strlen(value);
	int start = 0;
	while (!(start > len)) {
		char geç = value[len-1];
		value[len-1] = value[start];
		value[start] = geç;
		start++;
		len--;
	}
}

// Parantezleri ters çevir
void reverseParanteheses(char* value) {
	reverse(value);
	int len = strlen(value);
	for (int i = 0; i < len; i++)
	{
		if (value[i] == '(') {
			value[i] = ')';
		}
		else if (value[i] == ')') {
			value[i] = '(';
		}
	}
}

// İnfix'i Prefix'e dönüştür
void infixToPrefix(char* infix, char* prefix) {
    reverse(infix);  // İfadenin tersini al
    reverseParentheses(infix);  // Parantezleri ters çevir

    int len = strlen(infix);
    int j = 0;

    // Postfix benzeri işlemleri yap
    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            prefix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);//işaretleri ve parantezleri ekleriz
        }
        else if (ch == ')') {//kapanıyorsa arada olanları eklemeliyiz
            while (top != -1 && stack[top] != '(') {
                prefix[j++] = pop();//çıkanları ekle
            }
            pop();  // '(' karakterini pop et
        }
        else if (isOperator(ch)) {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {//en üstteli* mesela + gelirse ve büyükse * çıkar
                prefix[j++] = pop();
            }
            push(ch);
        }
    }

    // Kalan operatörleri prefix'e ekle
    while (top != -1) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';  // Null terminate
    reverse(prefix);   // Prefix'i tersine çevir
}

int main() {
    char infix[] = "(A-B/C)*(A/K-L)";
    char prefix[MAX];

    infixToPrefix(infix, prefix);
    printf("Infix: %s\n", infix);
    printf("Prefix: %s\n", prefix);

    return 0;
}

//infix calculate
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
int stack_number[MAX];
int top_number = -1;
char stack_opeartor[MAX];
int top_operator = -1;

void push_number(int value) {
	top_number++;
	stack_number[top_number]=value ;
}
void pop_number(int* op) {
	if (top_number==-1)
	{
		return;
	}
	*op = stack_number[top_number];
	top_number--;
}
void push_operator(char ch) {
	top_operator++;
	stack_opeartor[top_operator] = ch;
}
void pop_operator(char* op) {
	if (top_operator == -1)
	{
		return;
	}
	*op = stack_opeartor[top_operator];
	top_operator--;
}

int isoperand(char ch) {
	return  isdigit(ch);
}

int isoperator(char ch) {
	return ch=='+' || ch == '-' || ch == '*' || ch == '/' ;
}
int calculate(char ch,int op1,int op2) {
	switch (ch)
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	default:
		return -1;
		break;
	}
}
int precedence(char ch) {
	switch (ch)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
		break;
	}
}
void translater(char value[]) {
	int len = strlen(value);
	int j = 0;
	int op1, op2;
	char op;
	for (int i = 0; i < len; i++)
	{
		char ch = value[i];
		if (isoperand(ch))
		{
			push_number(ch - '0');
		}
		else if(ch == '(')
		{
			push_operator(ch);
		}
		else if (ch==')') {
			while (top_operator!=-1 && stack_opeartor[top_operator] !='(') {
				pop_operator(&op);
				pop_number(&op1);
				pop_number(&op2);
				int answer= calculate(op,op2,op1);
				push_number(answer);
			}
			pop_operator(&op);
		}
		else if(isoperator(ch))
		{
			while (top_operator != -1 && precedence(stack_opeartor[top_operator]) >= precedence(ch)) {
				pop_operator(&op);
				pop_number(&op1);
				pop_number(&op2);
				int answer = calculate(op, op2, op1);
				push_number(answer);
			}
			push_operator(ch);
		}
	}
	while (top_operator != -1) {
		pop_operator(&op);
		pop_number(&op1);
		pop_number(&op2);
		int answer = calculate(op, op2, op1);
		push_number(answer);
	}
}

int main() {
	char value[MAX] = "2*(5*(3+6))/9-2";
	char prefix[MAX];
	//reverseParanteheses(value);
	//printf("%s\n", value);
	translater(value);
	printf("%d", stack_number[top_number]);
	return 0;
}


