#include <stdio.h>
#define MAX_STACK_SIZE 100

int front = -1;
int rear = -1;
int a[MAX_STACK_SIZE] ;

void enqueue(int item) {
	if (rear >= MAX_STACK_SIZE - 1) {
		return;
	}
	if (front == -1) {
		// First element being enqueued
		front = 0;
	}
	a[++rear] = item;
}
void dequeue() {
	if (front == -1 || front > rear) {
		printf("no element to return\n");
		return; // empty queue
	}
	front++; // move front forward
}
int Top() {

	return a[front];
}
void print() {

	printf("\nqueue: ");
	for (int i = front; i <= rear; i++) {//i fronttan başlar rear a kada
		printf("%d ", a[i]);
	}
}

int main() {
	enqueue(3);
	print();
	enqueue(4);
	print();
	enqueue(5);
	print();
	dequeue();
	print();
	return 0;
}

//ver2
#include <stdio.h>
#include <stdlib.h>

int* dizi;
int index=0;
int firstone = 0;
void dequeue() {
	firstone++;
}
void enqueque(int item) {
	dizi[index] = item;
	index++;
}
void print() {
	printf("queque:");
	for (int i = firstone; i < index; i++)
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
	enqueque(4);
	enqueque(5);
	print();
	dequeue();
	print();
	return 0;
}
