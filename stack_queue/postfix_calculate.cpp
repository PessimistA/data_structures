#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	left_parent, right_parent, add, subtract, multiply, divide, eos, operand
}precedence;

char expr[] = "422-3+/34-*2*";

float dizi[20];
int index = 0;
float pop() {
	if (index <= 0) {
		printf("Stack is empty\n");
		return 0;
	}
	return dizi[--index];
}
void push(float item) {
	dizi[index++] = item;
	
}
void print() {
	printf("stack:");
	for (int i = 0; i < index; i++)
	{
		printf("%.2f\t", dizi[i]);
	}
	printf("\n");
}
precedence get_token(char* symbol, int* n) {
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(': return left_parent;
	case ')': return right_parent;
	case '+': return add;
	case '-': return subtract;
	case '/': return divide;
	case '*': return multiply;
	case '\0': return eos;
	default: return operand;
	}
}
float eval(void) {
	char symbol;
	precedence token;
	float op1, op2;
	int n = 0;
	int top = -1;
	token = get_token(&symbol, &n); 
	while (token != eos) { 
		if (token == operand)
			push(symbol - '0');
		else {
			op2 = pop();
			op1 = pop();
			switch (token) {
			case add:
				push(op1 + op2);
				break;
			case subtract:
				push(op1 - op2);
				break;
			case multiply:
				push(op1 * op2);
				break;
			case divide:
				if (op2 != 0)
					push(op1 / op2);
				else
					printf("Error: Division by zero\n");
				break;
			}
		}
		token = get_token(&symbol, &n);
	}
	return pop();
}

int main() {
	float c = eval();
	printf("%.2f", c);


	return 0;
}
//ver2
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
typedef enum
{
	left_parent, right_parent, add, subtract, multiply, divide, eos, operand
}precedence;

char expr[] = "2536+**5/2-";

float dizi[MAX];
int top = 0;
float pop() {
	if (top <= 0) {
		printf("Stack is empty\n");
		return 0;
	}
	return dizi[--top];
}
void push(float item) {
	dizi[top++] = item;

}
void print() {
	printf("stack:");
	for (int i = 0; i < top; i++)
	{
		printf("%.2f\t", dizi[i]);
	}
	printf("\n");
}
precedence get_token(char* symbol, int* n) {
	*symbol = expr[(*n)++];
	if (*symbol=='(')
	{
		return left_parent;
	}
	if (*symbol == ')')
	{
		return right_parent;
	}
	if (*symbol == '+')
	{
		return add;
	}
	if (*symbol == '-')
	{
		return subtract;
	}
	if (*symbol == '*')
	{
		return multiply;
	}
	if (*symbol == '/')
	{
		return divide;
	}
	if (*symbol == '\0')
	{
		return eos;
	}
	else
	{
		return operand;
	}
}
float eval(void) {
	char symbol;
	precedence token;
	float op1, op2;
	int n = 0;
	int top = -1;
	token = get_token(&symbol, &n);//buradan o yerdeki değeri alırsın
	while (token != eos) {
		if (token == operand)
			push(symbol - '0');
		else {
			op1 = pop();
			op2 = pop();

			if (token==add)
			{
				push(op1 + op2);
			}
			if (token == subtract)
			{
				push(op2 - op1);
			}
			if (token == multiply)
			{
				push(op2 * op1);
			}
			if (token == divide)
			{
				if (op1!=0)
				{
					push(op2 / op1);
				}
			}
		}
		token = get_token(&symbol, &n);
	}
	return pop();
}

int main() {
	float c = eval();
	printf("%.2f", c);


	return 0;
}

//ver 3
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void translater(char value[]);
#define MAX 100
int stack_number[MAX];
int top_number = -1;
char stack_opeartor[MAX];
int top_operator = -1;

void push_number(int value) {
	top_number++;
	stack_number[top_number] = value;
	for (int i = 0; i < top_number; i++)
	{
		printf("number:%d\n", stack_number[i]);
	}
}

void pop_number(int* op) {
	if (top_number == -1) {
		return;
	}
	*op = stack_number[top_number];
	top_number--;
}

int isoperand(char ch) {
	return isdigit(ch);
}

int isoperator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int calculate(char ch, int op1, int op2) {
	switch (ch) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	default:
		return -1;
	}
}

void translater(char value[]) {
	int op1, op2;
	char op;
	int len = strlen(value);
	for (int i = 0; i < len; i++)
	{
		char ch = value[i];
		if (isoperand(ch)) {
			push_number(ch-'0');
		}
		else if (isoperator(ch)) {
			pop_number(&op1);
			pop_number(&op2);
			int answer = calculate(ch, op2, op1); // Dikkat: Sıra önemli!
			push_number(answer);
		}
	}	
}

int main() {
	char value[MAX] = "2536+**5/2-";
	translater(value);
	printf("Sonuç: %d\n", stack_number[top_number]);
	return 0;
}
