#include <stdio.h>
#include <stdlib.h>

char dizi[20];
int index = 0;
void pop() {
	if (index < 0) {
		return;
	}
	index--;
}
void push(char item) {
	dizi[index] = item;
	index++;
}
void print() {
	printf("stack:");
	for (int i = 0; i < index; i++)
	{
		printf("%c\t", dizi[i]);
	}
	printf("\n");
}

int main() {
	char parantezler[] = "{[[)]]}";
	int len = sizeof(parantezler) / sizeof(char)-1;
	for (int i = 0; i < len; i++)
	{
		if (parantezler[i]=='(' || parantezler[i] == '['|| parantezler[i] == '{')
		{
			push(parantezler[i]);
		}
		else if(parantezler[i] == ')' || parantezler[i] == ']' || parantezler[i] == '}')
		{
			if (((parantezler[i] == ')' && dizi[index-1] == '(') ||
				(parantezler[i] == ']' && dizi[index-1] == '[') ||
				(parantezler[i] == '}' && dizi[index-1] == '{')))
			{
				pop();
			}
			else
			{
				printf("Hata: Uyumlu olmayan parantezler bulundu.\n");
				break;
			}
		}
	}
	if (index == 0)
	{
		printf("hata vermedi ve bu uyumlu demektir");
	}

	return 0;
}
//ver2
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char stack[100];
int top =-1;

void push(char item) {
	stack[++top] = item;
}

void pop() {
	top--;
}

void print2() {
	int k = top;
	for (int i = 0; i < top; i++)
	{
		printf("%c->", stack[i]);
	}
	printf("\n");
}
int main() {

	char dizi[] = "{[[elis]]a}()";
	int length1= strlen(dizi);
	printf("%d\n", length1);
	for (int i = 0; i <length1; i++)
	{
		if (dizi[i]=='['|| dizi[i] == '(' || dizi[i] == '{' ) {
			push(dizi[i]);
		}
		else if (dizi[i] == ']' || dizi[i] == ')' || dizi[i] == '}')
		{
			if (((dizi[i] == ']' && stack[top] == '[') ||
				(dizi[i] == ')' && stack[top] == '(') ||
				(dizi[i] == '}' && stack[top] == '{')))
			{
				pop();
			}
		}
	}
	print2();
	if (top ==-1)
	{
		printf("dengeli");
	}
	else
	{
		printf("durum kotu");
	}

	return 0;
