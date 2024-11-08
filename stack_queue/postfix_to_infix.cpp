#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char stack[MAX][MAX];
int top = -1;
void push(char value[]) {
	if (top < (MAX - 1)) {
		top++;
		strcpy(stack[top], value);
	}
	else {
		printf("Stack Overflow\n");
	}
}

// Yığından veri çekme fonksiyonu
void pop(char op[]) {
	if (top >= 0) {
		strcpy(op, stack[top]);
		top--;
	}
}

int isoperand(char ch) {
	return isalpha(ch) || isdigit(ch);
}

void postfix_to_infix(char postfix[], char infix[]) {
	int len = strlen(postfix);
	int j = 0;

	for (int i = 0; i < len; i++)
	{
		char ch = postfix[i];
		if (isoperand(ch))
		{
			char operand2[2] = { ch,'\0' };
			push(operand2);
		}
		else
		{
			char op1[MAX], op2[MAX];
			pop(op1);
			pop(op2);

			char newexp[MAX] = "";
			strcat(newexp, op2);
			strncat(newexp, &ch, 1);
			strcat(newexp, op1);

			push(newexp);
		}
	}
	strcpy(infix, stack[top]);
}
int main() {
	char postfix[MAX] = "ABC/-AK/L-*";//alınmazsa yukarıdakini açarak kendi değerinizi girebilirsiniz
	char infix[100];
	postfix_to_infix(postfix,infix);
	printf("son hali:%s", infix);
	return 0;
}
