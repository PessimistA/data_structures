#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 100
int stack[Max];
int stack2[Max];
int top = -1;

void popvalue(int n) {
	for (int i = 0, j = 0; i <= top; i++)
	{
		if (n != i)
		{
			stack2[j++] = stack[i];
		}
	}
	for (int i = 0; i <= top; i++)
	{
		stack[i] = stack2[i];
	}
}
void pop() {
	if (top == -1)
	{
		printf("empty");
	}
	else
	{
		top--;
	}
}
void push(int value) {
	stack[++top] = value;
}
void pushvalue(int value, int n) {
	for (int i = 0, j = 0; i <= top + 1; i++)
	{
		if (n == i)
		{
			stack2[i] = value;

		}
		else
		{
			stack2[i] = stack[j++];
		}
	}
	for (int i = 0; i <= top; i++)
	{
		stack[i] = stack2[i];
	}
}
void print() {
	printf("\nstack");
	for (int i = 0; i <= top; i++)
	{
		printf(" %d ", stack[i]);
	}
}
int main() {
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	print();
	popvalue(top / 2);
	print();
	pushvalue(1, top / 2);
	print();

	print();
	return 0;
}
