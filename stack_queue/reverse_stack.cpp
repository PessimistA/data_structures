
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
