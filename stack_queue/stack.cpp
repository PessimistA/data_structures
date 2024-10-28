#include <stdio.h>
#define MAX_STACK_SIZE 100

int top = -1;
int a[MAX_STACK_SIZE];

void push(int item) {
	if (top >= MAX_STACK_SIZE - 1) {
		return;
	}
	else
	{
		a[++top] = item;
	}
}
void pop()
{
	if (top == -1) {
		printf("no element to return");
		return; //empty
	}
	top--;
}
int Top() {
	return a[top];
}
void print() {
	int len = sizeof(a) / sizeof(a[0]);
	printf("\nstack: ");
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", a[i]);
	}
}

int main() {
	push(3);
	print();
	push(4);
	print();
	pop();
	print();
	return 0;
}

//ver2
#include <stdio.h>
#include <stdlib.h>

int* dizi;
int index=0;
void pop() {
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
	printf("lütfen istediğiniz n değerini giriniz");
	scanf_s("%d", &n);
	dizi = (int*)malloc(n * sizeof(int));
	push(4);
	push(5);
	print();
	pop();
	print();
	return 0;
}
