#define _CRT_SECURE_NO_WARNINGS//visual studio kullanýyorum 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Malloc_2D(int*** a, int x, int y);
void Malloc_3D(int**** a, int x, int y, int z);
void twoD_array();
void threeD_array();
void itemadd(int*** a, int x, int y);
void itemadd2(int**** a, int x, int y, int z);

int main() {

	//{ 2 boyutlu
	//int** a;
	//printf("please enter a x count for a[x][y]");
	//int x, y;
	//scanf_s("%d", &x);
	//printf("please enter a y count for a[x][y]");
	//scanf_s("%d", &y);
	//itemadd(&a, x, y);//&a kullanýmý önemli// bu 2 boyutlu dinamik
	//for (int i = 0; i < x; i++) {
	//	free(a[i]);  // y serbest býrakýlýr
	//}
	//free(a);// x serbest býrakýlýr
	//}


	//{ 3 boyutlu
	//int*** b;
	//printf("please enter a x count for a[x][y][f]");
	//int s, d, f;
	//scanf_s("%d", &s);
	//printf("please enter a y count for a[x][y][f]");
	//scanf_s("%d", &d);
	//printf("please enter a y count for a[x][y][f]");
	//scanf_s("%d", &f);
	//Malloc_3D(&b, s, d, f);

	//for (int i = 0; i < s; i++) {
	//	for (int j = 0; j < d; j++) {
	//		free(b[i][j]);  // Z boyutunu serbest býrak
	//	}
	//	free(b[i]);  // Y boyutunu serbest býrak
	//}
	//free(b);// x serbest býrakýr 
	//}


	//{
	//twoD_array();//döngülerle 2 boyutlu
	//threeD_array();//döngülerle üç boyutlu 
	//}


	return 0;
}
void Malloc_3D(int**** a, int x, int y, int z) {
	(*a) = (int***)malloc(x * sizeof(int**));
	for (int i = 0; i < x; i++)
	{
		(*a)[i] = ((int**)malloc(y * sizeof(int*)));
		for (int j = 0; j < y; j++)
		{
			(*a)[i][j] = ((int*)malloc(z * sizeof(int)));
		}
	}
	itemadd2(a, x, y, z);// normal a yaz buraya 
}

void itemadd2(int**** a, int x, int y, int z) {
	int sayaç = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				sayaç++;
				(*a)[i][j][k] = sayaç;
			}
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{

				printf("%d\t", (*a)[i][j][k]);//(*a) kullanýmý önemlli
			}
			printf("\n");
		}
		printf("\n");
	}
}

void Malloc_2D(int*** a, int x, int y) {
	*a = (int**)malloc(x * sizeof(int*));
	for (int i = 0; i < x; i++)
	{
		(*a)[i] = ((int*)malloc(y * sizeof(int)));
	}
}
void itemadd(int*** a, int x, int y) {
	int sayaç = 0;
	Malloc_2D(a, x, y);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			sayaç++;
			(*a)[i][j] = sayaç;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{

			printf("%d", (*a)[i][j]);//(*a) kullanýmý önemlli
		}
		printf("\n");
	}
}

void twoD_array() {
	int sayaç = 0;
	int a[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			sayaç++;
			a[i][j] = sayaç;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			printf("%d\t", a[i][j]);

		}
		printf("\n");
	}
}
void threeD_array() {
	int sayaç = 0;
	int a[3][3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				sayaç++;
				a[i][j][k] = sayaç;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				printf("%d\t", a[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}