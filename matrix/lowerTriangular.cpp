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

//kullanılmalık

#include <stdio.h>

int gettriangularmatrix(int i, int j, int n);
void readtriangularmatrix(int alt[], int n);

int a[3][3] = { { 1, 0, 0 }, { 2,3,0 }, { 4,5,6 } };

void print() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int alt[101];
    int i, n;

    // Matris boyutunu kullanıcıdan al
    n = 3;



    readtriangularmatrix(alt,n);


    int row , col  ;
    printf("lutfen sirayla i ve j degerlerini giriniz");
    scanf_s("%d", &row);
    scanf_s("%d", &col);
    
    int index = gettriangularmatrix(row, col, n);


    if (index == -1) {
        printf("\n Gecersiz indeks.\n");
    }
    else if (index == -2) {
        printf("\n Ucgen dişinda (alt ucgen).\n");
    }
    else {
        printf("istenilen indexteki arkadas\n");
        printf("\n Alt dizideki pozisyon: %d, deger: %d\n", index, alt[index]);
    }
    printf("\n");
    printf("tek boyutlu olan dizi\n");
    for (int i = 0; i < n*(n+1)/2; i++)
    {
        printf("\n Alt dizideki pozisyon: %d, deger: %d\n", i, alt[i]);
    }
    printf("\n");
    printf("3 boyutlu hali\n");
    print();
    

    return 0;
}

void readtriangularmatrix(int alt[], int n) {
    int i, j, index;

    if (n * (n + 1) / 2 > 101) {
        printf("\n Gecersiz dizi boyutu\n");
        return;
    }


    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= i; j++) {
            if (a[i][j] != 0)
            {
                index = ((i * (i + 1)) / 2) + (j);
                alt[index] = a[i][j];
            }
        }
    }
}

int gettriangularmatrix(int i, int j, int n) {
    // Geçersiz indeks kontrolü
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return -1;
    }

    // Üçgen dışında kalan alt üçgen için kontrol
    if (i < j) {
        return -2;
    }

    // alt üçgenin geçerli bir indeksinin tek boyutlu dizideki yeri
    return ((i * (i + 1)) / 2) + (j);
}


//version 3
#include <stdio.h>
#include <stdlib.h>

int** arrays;
int* onedarray;

void sizing(int n) {
	arrays = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		arrays[i] = (int*)malloc(n * sizeof(int));
	}
}
void sizing2(int n) {
	onedarray = (int*)malloc(n*(n+1)/2 * sizeof(int));
}
void print(int n) {
	printf("normal version\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arrays[i][j]);  
		}
		printf("\n");
	}
	printf("\none d array version\n");
	for (int i = 0; i < n*(n+1)/2; i++)
	{
		printf("%d sirada = %d\n", i, onedarray[i]);
	}
}
int find_index(int i, int j, int n) {
	if (i <= j)
	{
		return (i * (i + 1) )/2 + j;
	}
	else
	{
		return -1;
	}
}
void readingoftriangular(int n) {//O(n2)
	sizing(n);
	sizing2(n);
	int counter = 1;
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arrays[i][j] = 0; 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			arrays[i][j] = counter;  
			counter++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int index = (i * (i + 1)) / 2 + j;
			onedarray[index] = arrays[i][j];
		}
	}

	print(n);  
	printf("lutfen bulunmasini istediğiniz i ve j numaralarini giriniz\n");
	int k, f;
	scanf_s("%d", &k);
	scanf_s("%d", &f);
	int index1 =find_index(k, f, n);
	if (index1==-1)
	{
		printf("problem");
	}
	else
	{
		printf("aradiginiz sayi arrays[%d][%d]= onedarray[%d]= %d", k, f, index1, onedarray[index1]);
	}
}


int main() {
	printf("lutfen bir size giriniz");
	int n;
	scanf_s("%d", &n);
	readingoftriangular(n);
	for (int i = 0; i < n; i++)
	{
		free(arrays[i]);
	}
	free(arrays);
	free(onedarray);
	return 0;
}
