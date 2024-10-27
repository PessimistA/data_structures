#include <stdio.h>
#include <stdlib.h>


void buble_sort(int dizi[], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (dizi[i]>dizi[j])//büyükten küçüğe sıralar
			{
				int temp = dizi[i];
				dizi[i] = dizi[j];
				dizi[j] = temp;
			}
		}
	}
}
void selection_Sort(int dizi[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++) {
			if (dizi[i] > dizi[j])//küçükten büyüğe sıralar
			{
				int temp = dizi[i];
				dizi[i] = dizi[j];
				dizi[j] = temp;
			}
		}
	}
}
void insertion_Sort(int dizi[], int n) {
	for (int i = 1; i < n ; i++)
	{
		for (int j = i ; j > 0; j--) {
			if (dizi[j] < dizi[j-1])// küçükten büyüğe sıralar
			{
				int temp = dizi[j];
				dizi[j] = dizi[j-1];
				dizi[j-1] = temp;
			}
		}
	}
}
int binary_search(int dizi[], int n,int search_number) {
	int start = 0, ending = n;
	int middle=0;
	while (search_number != dizi[middle]) {//ya da (start<=ending)
		middle = ((start + ending) / 2);
		if (search_number < dizi[middle])
		{
			ending = middle;
		}
		else if (search_number > dizi[middle])
		{
			start = middle;
		}
		else if (search_number == dizi[middle])
		{
			return middle;
			break;
		}
	}
		
}
int linear_search(int dizi[], int n, int search_number) {
	for (int i = 0; i < n; i++)
	{
		if (dizi[i] == search_number) {
			return i;
		}
	}
}
void print(int dizi[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", dizi[i]);
	}
}

int main() {
	int* dizi;
	int n;
	printf("lütfen bir n değeri giriniz");
	scanf_s("%d", &n);
	dizi = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		dizi[i] = rand() % 100;
	}
	print(dizi, n);
	//buble_sort(dizi, n);
	//printf("buble sort için\n");
	//print(dizi,n);
	//selection_Sort(dizi, n);
	//print(dizi, n);
	//insertion_Sort(dizi, n);
	//print(dizi, n);
	//int sayi;
	//printf("\naradığınız sayıyı giriniz\n");
	//scanf_s("%d", &sayi);
	//int index=binary_search(dizi, n, sayi);
	//printf("bulundugu index = %d\n", index);
	//int index2 = linear_search(dizi, n, sayi);
	//printf("bulundugu index2 = %d\n", index2);
	return 0;
}
