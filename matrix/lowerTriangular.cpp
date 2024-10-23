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


int main() {
    int alt[101];
    int i, n;

    // Matris boyutunu kullanıcıdan al
    n = 3;



    readtriangularmatrix(alt,n);


    int row , col  ;
    printf("lütfen sırayla i ve j değerlerini giriniz");
    scanf_s("%d", &row);
    scanf_s("%d", &col);
    
    int index = gettriangularmatrix(row, col, n);


    if (index == -1) {
        printf("\n Geçersiz indeks.\n");
    }
    else if (index == -2) {
        printf("\n Üçgen dışında (alt üçgen).\n");
    }
    else {
        printf("\n Alt dizideki pozisyon: %d, deger: %d\n", index, alt[index]);
    }
    for (int i = 0; i < n*(n+1)/2; i++)
    {
        printf("\n Alt dizideki pozisyon: %d, deger: %d\n", i, alt[i]);
    }

    return 0;
}

void readtriangularmatrix(int alt[], int n) {
    int i, j, index;

    // Dizinin boyutu üst üçgen elemanlarını alabilecek mi kontrol et
    if (n * (n + 1) / 2 > 101) {
        printf("\n Geçersiz dizi boyutu\n");
        return;
    }

    // Matrisin üst üçgen kısmını oku
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

    // Üst üçgenin geçerli bir indeksinin tek boyutlu dizideki yeri
    return ((i * (i + 1)) / 2) + (j);
}
