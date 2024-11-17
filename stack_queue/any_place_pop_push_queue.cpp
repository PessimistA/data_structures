#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 100
char stack[Max];
char queue2[Max];
int rear = 0;
int front = 0;

void pop() {
	if (front == -1)
	{
		printf("empty");
	}
	else
	{
		++front;
	}
}
void dequeueelement(int n) {
	if (front == -1)
	{
		printf("empty");
	}
	for (int i = front, j = front; i < rear; i++)
	{
		if (i == n) {
			continue;
		}
		else
		{
			queue2[j++] = stack[i];
		}
	}
	for (int i = front; i <= rear; i++)
	{
		stack[i] = queue2[i];
	}
}
void enqueue(char value) {
	stack[rear++] = value;
}
void enqueueelement(char value, int n) {
	for (int i = front, j = front; i < rear; i++)
	{
		if (i == n) {
			queue2[i] = value;
		}
		else
		{
			queue2[i] = stack[j++];
		}
	}
	for (int i = front; i <= rear; i++)
	{
		stack[i] = queue2[i];
	}
}
void print() {
	printf("\nqueue");
	for (int i = front; i <= rear; i++)
	{
		printf(" %d ", stack[i]);
	}
}

int main() {
	enqueue(5);
	enqueue(3);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	print();
	dequeueelement(3);
	print();
	enqueueelement(2, 3);
	print();
	return 0;
}
