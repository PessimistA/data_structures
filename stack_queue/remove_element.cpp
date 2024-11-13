#include <stdio.h>
#include <stdlib.h>

int* dizi;
int* dizi2;
int index = 0;

void pop(int index) {
	index--;
}
void push(int item) {
	dizi[index] = item;
	index++;
}

void print() {
	printf("stack:");
	for (int i = 0; i < index; i++)
	{
		printf("%d\t", dizi[i]);
	}
	printf("\n");
}

int main() {
	int n;
	printf("lütfen istediğiniz tek n değerini giriniz");
	scanf_s("%d", &n);
	dizi = (int*)malloc(n * sizeof(int));
	dizi2 = (int*)malloc(n * sizeof(int));

	for (int i = 1; i <= n; i++)
	{
		push(i);
	}
	print();
	int middle = (index ) / 2;//int değer olduğundan direk ortadaki değeri verir
	printf("%d", middle);
	for (int i = 0, j = 0; i < index; i++) {
		if (i != middle) {
			dizi2[j++] = dizi[i];
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		dizi[i] = dizi2[i];
	}
	printf("stack:");
	for (int i = 0; i < index-1; i++)
	{
		printf("%d\t", dizi[i]);
	}
	free(dizi);
	free(dizi2);
	return 0;
}
