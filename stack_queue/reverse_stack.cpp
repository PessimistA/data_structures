
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 100
char stack[Max];
int top = -1;


void pop() {
	if (top==-1)
	{
		printf("empty");
	}
	else
	{
		top--;
	}
}
void push(char value) {
	stack[++top] = value;
}

void print() {
	printf("\nstack");
	for (int i = 0; i <= top; i++)
	{
		printf(" %d ", stack[i]);
	}
}

int main() {
	char kelime[Max] = { "merhaba bu bir ters çevirici" };
	int len = strlen(kelime);
	for (int i = 0; i < len; i++)
	{
		push(kelime[i]);
	}
	char kelimeson[Max] = {};
	for (int i = 0; i < len; i++)
	{
		kelimeson[i] = kelimeson[i] + stack[top--];
	}
	printf("%s", kelimeson);
	return 0;
}

//ver2
#include <stdio.h>
#define MAX_STACK_SIZE 100


void push(int stack[], int* top, int item) {
	if (*top >= MAX_STACK_SIZE - 1) {
		return;
	}
	else
	{
		stack[++(*top)] = item;
	}
}
int pop(int stack[], int* top)
{
	if (*top == -1) {
		return -1; //empty
	}
	return stack[(*top)--];
}
void reverse(int stack[], int* top, int stack2[], int* top2) {
	while (*top != -1) {
		push(stack2, top2, pop(stack, top));
	}
}
void print(int stack[], int* top) {
	printf("\nstack: ");
	for (int i = 0; i <= *top; i++)
	{
		printf(" %d ", stack[i]);
	}
	printf("\n");
}

int main() {
	int top = -1;
	int top2 = -1;
	int stack[MAX_STACK_SIZE];
	int stack2[MAX_STACK_SIZE];
	push(stack,&top,1);
	push(stack, &top, 2);
	push(stack, &top, 3);
	push(stack, &top, 4);
	push(stack, &top, 5);
	print(stack,&top);
	reverse(stack, &top, stack2, &top2);
	print(stack2, &top2);
	return 0;
}
