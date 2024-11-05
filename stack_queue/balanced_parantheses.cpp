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
