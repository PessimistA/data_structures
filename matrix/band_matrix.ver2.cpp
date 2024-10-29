#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* band;
int* search;
int** arrays;

void sizing3(int n,int a,int b) {
	int sayaç = 1;
	arrays = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		arrays[i] = (int*)malloc(n * sizeof(int));
	}
	printf("array normal hali\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arrays[i][j] = sayaç;
			sayaç++;
		}
	}

	// Satırlar için 0'ların yerleştirilmesi (a kadar satırda 0 olacak)
	for (int i = a; i < n; i++) { // a'dan itibaren başlıyor
		for (int j = 0; j <= i - a; j++) { // i - a kadar sütunda 0 olacak
			arrays[i][j] = 0;
		}
	}

	// Sütunlar için 0'ların yerleştirilmesi (b kadar sütunda 0 olacak)
	for (int j = b; j < n; j++) { // b'den itibaren başlıyor
		for (int i = 0; i <= j - b; i++) { // j - b kadar satırda 0 olacak
			arrays[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d\t", arrays[i][j]);
		}
		printf("\n");
	}

}

void sizing(int n,int a,int b) {
	int size = n*(a + b - 1);
	band = (int*)malloc(size * sizeof(int));
}
void sizing2(int n,int a,int b) {
	int size = a + b - 1;
	search = (int*)malloc(size* sizeof(int));
}
void build_band_matrix(int n, int a, int b) {
	sizing(n, a, b);
	sizing2(n, a, b);
	sizing3(n, a, b);
	int itemnumber = 0;//bu toplam item sayısını sayacak
	//-a+1 değeri köşegendeki j-i sayısını verir
	for (int k = -a + 1; k < b; k++) {//search her bir köşegenin başlanıç noktasını hesaplar
		search[k + a - 1] = itemnumber;
		itemnumber += (n - abs(k));  // köşegenlerdeki eleman sayısı eklenip bir sonraki köşegene kadar olan sayıyı bulur
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int k = j - i;
			if (k >= -a + 1 && k < b) {
				if (k >= 0)
				{
					band[search[k + a - 1] + i] = arrays[i][j];
				}
				else
				{
					band[search[k + a - 1] + (j)] = arrays[i][j];
				}
			}
		}
	}
	printf("\nBand matrisi:\n");
	for (int i = 0; i < itemnumber; i++) {
		printf("Band[%d] = %d\n", i, band[i]);
	}
	//int i = a - 1, j = 0;
	//while (i < n && j < n ) {
	//	if (i > j ) {
	//		int başlangıç = i;
	//		while (i < n && j < n  && arrays[i][j] != 0) {
	//			band[search[j - i + a - 1] + j] = arrays[i][j];
	//			j++;
	//			i++;
	//		}
	//		i = başlangıç;
	//		i--;
	//		j = 0;
	//	}
	//	else if(j>i) {
	//		int başlangıç = j;
	//		while (i < n && j < n && arrays[i][j] != 0 ) {
	//			band[search[j - i + a - 1] + i] = arrays[i][j];
	//			j++;
	//			i++;
	//		}
	//		j = başlangıç;
	//		i = 0; 
	//		j++;
	//	}
	//	else if (i == j) {
	//		band[search[a - 1]+i] = arrays[i][j];
	//	}
	//	j++;
	//}

}


int get_value(int i,int j, int n, int a,int b,int k) {
	if (k>0) {
		if (k<b)
		{
			return search[a-1+k]+i;
		}
		else
		{
			return -1;
		}
	}
	else if(-k<a){
		return search[j - i + a - 1] + j;
	}
	else
	{
		return -1;
	}

}

int main() {
	int a,b, n;
	printf("lutfen bir size giriniz");
	scanf_s("%d", &n);
	printf("lutfen bir a değeri giriniz");//köşegenden kaç tane sağda veya aşağıda var
	scanf_s("%d", &a);
	printf("lutfen bir b değeri giriniz");//köşegenden kaç tane sağda veya aşağıda var
	scanf_s("%d", &b);
	build_band_matrix(n, a, b);

	printf("lütfen istediğiniz bir i ve j değeri girin");
	int i, j;
	scanf_s("%d", &i);
	scanf_s("%d", &j);
	int k = j - i;
	int index = get_value(i,j,n,a,b,k);
	if (index==-1)
	{
		printf("problem");
	}
	else
	{
		printf("arrays[%d][%d] =band[%d]=%d",i,j,index,band[index]);
	}

	for (int i = 0; i < n; i++)
	{
		free(arrays[i]);
	}
	free(arrays);
	free(search);
	free(band);
	return 0;
}


//ver2 düzeltilmiş hali

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int* band;
int* search;
int** arrays;

void arraymaker(int n,int a,int b) {
	int sayaç = 1;
	int band_size = (n * (a + b + 1)) - (a * (a + 1) / 2) - (b * (b + 1) / 2);//+1 li formül çünkü a ve b 1 azalmış durumda
	int search_size = a + b + 1;
	arrays = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		arrays[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arrays[i][j] = sayaç;
			sayaç++;
		}
	}
	for (int i = a; i < n; i++) {
		for (int j = 0; j < i-a; j++) {
			arrays[i][j] = 0;
		}
	}
	for (int j = b; j < n; j++) {
		for (int i = 0; i < j-b; i++) {
			arrays[i][j] = 0;
		}
	}
	printf("band size %d\n", (n * (a + b + 1)) - (a * (a + 1) / 2) - (b * (b + 1) / 2));
	band = (int*)malloc(band_size * sizeof(int));
	search = (int*)malloc(search_size * sizeof(int));
}
void append_for_lower(int n,int a,int b){
	int itemnumber = 0;
	//-a+1 değeri köşegendeki j-i sayısını verir
	for (int k = -a + 1; k < b; k++) {//search her bir köşegenin başlanıç noktasını hesaplar
		search[k + a - 1] = itemnumber;
		itemnumber += (n - abs(k));  // köşegenlerdeki eleman sayısı eklenip bir sonraki köşegene kadar olan sayıyı bulur
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int k = j - i;
			if (k >= -a + 1 && k < b) {
				if (k >= 0)
				{
					band[search[k + a - 1] + i] = arrays[i][j];
				}
				else
				{
					band[search[k + a - 1] + (j)] = arrays[i][j];
				}
			}
		}
	}	

	printf("itemnumber %d\n", itemnumber);
}
void print(int n,int a,int b) {
	printf("ilk hali\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d\t", arrays[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", (n * (a + b - 1)) - (a * (a - 1) / 2) - (b * (b - 1) / 2));
	for (int i = 0; i < (n * (a + b - 1))-(a*(a-1)/2)-(b*(b-1)/2); i++)
	{
		printf("Band[%d] = %d\n", i, band[i]);
	}
}
int found_lower(int i,int j,int n,int a,int b) {
	int k = j - i;
	if (k>=-a+1 && k<b)
	{
		if (k > 0)
		{
			return search[k + a - 1] + i;
		}
		else
		{
			return search[k + a - 1] + j;
		}
	}
	else
	{
		return -1;
	}
}

int main() {

	printf("bir n  degeri giriniz");
	int n,a,b,i,j;
	scanf_s("%d", &n);
	printf("bir a  degeri giriniz");
	scanf_s("%d", &a);
	printf("bir b  degeri giriniz");
	scanf_s("%d", &b);
	arraymaker(n, a-1, b-1);
	append_for_lower(n, a, b);
	print(n, a, b);
	printf("bir i  degeri giriniz");
	scanf_s("%d", &i);
	printf("bir j  degeri giriniz");
	scanf_s("%d", &j);
	int index = found_lower(i, j, n, a, b);
	if (index==-1)
	{
		printf("error");
	}
	else {
		printf("%d ve %d konumlarındaki %d indexi %d dir", i, j, index, band[index]);
	}
	for (int i = 0; i < n; i++)
	{
		free(arrays[i]);
	}
	free(arrays);
	free(band);
	free(search);
	return 0;
}
