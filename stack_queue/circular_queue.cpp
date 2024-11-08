#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int dizi[SIZE];
int rear = 0;
int front = 0;
void dequeue() {
	if (front == -1)
	{
		printf("queue is empty");
		return;
	}
	else if (front==rear)
	{
		front = rear = -1;
		printf("sadece bir item var");
	}
	front = (front + 1) % SIZE;
}
void enqueque(int item) {
	if ((rear + 1) %SIZE == front)
	{
		printf("queue is full");
		return;
	}
	else if (front == -1)
	{
		printf("queue is empty");
		return;
	}
	dizi[rear] = item;
	rear = (rear + 1) % SIZE;
}
void print() {
	if (front == rear) { // Kuyruk boşsa
		printf("Queue is empty\n");
		return;
	}
	printf("Queue: ");
	int i = front;
	while (i != rear) {
		printf("%d ", dizi[i]);
		i = (i + 1) % SIZE; // Dairesel kuyruğa göre devam ediyoruz
	}
	printf("\n");
}

int main() {
	enqueque(4);
	enqueque(5);
	enqueque(6);
	print();
	dequeue();
	print();
	enqueque(7);
	enqueque(8);
	print();
	dequeue();
	print();
	return 0;
}
