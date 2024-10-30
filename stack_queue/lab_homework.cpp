#include <stdio.h>
#include <stdlib.h>

int* dizi;
int front = 0;
int top = 0;
void push(int item) {
	dizi[top++] = item;
}
void pop() {
	top--;
}
void dequeue() {
	front++;
}
void enqueque(int item) {
	dizi[top++] = item;
}
void print() {
	printf("array:");
	for (int i = front; i < top; i++)
	{
		printf("%d ", dizi[i]);
	}
	printf("\n");
}

int main() {
	int n,j,sayı,seçim;
	printf("lutfen istediginiz n degerini giriniz");
	scanf_s("%d", &n);
	dizi = (int*)malloc(n * sizeof(int));
	while (true) {
		printf("devam etmek için 1 cıkıs icin 0");
		scanf_s("%d", &j);
		if (j==1)
		{
			printf("push icin:1\npop icin:2\nenqueue icin:3\ndequeue icin:4\n ");
			scanf_s("%d", &seçim);
			if (seçim==1)
			{
				printf("sayıyı giriniz");
				scanf_s("%d", &sayı);
				push(sayı);
				print();
			}
			if (seçim == 2)
			{
				pop();
				print();
			}
			if (seçim == 3)
			{
				printf("sayıyı giriniz");
				scanf_s("%d", &sayı);
				enqueque(sayı);
				print();
			}
			if (seçim == 4)
			{
				dequeue();
				print();
			}
		}
		else
		{
			false;
			break;
		}

	}

	print();
	return 0;
}
