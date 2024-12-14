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
//ver2
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 100
int stack[Max];
int queue2[Max];
int top=-1;
int rear = -1;
int front = -1;
void print() {
	printf("\nstack");
	for (int i = 0; i <= top; i++)
	{
		printf(" %d ", stack[i]);
	}
}
int pop() {
	return stack[top--];
}
void push(int item) {
	stack[++top] = item;
}
void enqueue(int value) {
	queue2[++rear] = value;
}
int dequeue() {
	return queue2[front++] ;
}
void enqueueelement(int value, int n) {
	int top1 = top;
	for (int i = 0; i <= top1+1; i++)
	{
		enqueue(pop());
	}
	print();
	int front1 = front;
	int rear1 = rear;
	int position = 0;
	while (front<=rear) {
		if (position==n)
		{
			push(value);
			
		}
		push(dequeue());
		position++;	
	}
}
void dequeueelement( int n) {
	int top1 = top;
	for (int i = 0; i <= top1 + 1; i++)
	{
		enqueue(pop());
	}
	print();
	int front1 = front;
	int rear1 = rear;
	int position = 0;
	while (front <= rear) {
		if (position == n)
		{
			front++;

		}
		push(dequeue());
		position++;
	}
}

int main() {
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	print();
	enqueueelement(7, 2);
	print();
	dequeueelement(2);
	print();
	return 0;
}
