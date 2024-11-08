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

char expr[] = "- / * 20* 50 + 3 6 300 2";
char expr2[MAX];

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
void reverse(char symbol[]) {
	int len = strlen(symbol);
	for (int i = 0; i < len/2; i++)
	{
		char geçiçi = symbol[i];
		symbol[i] = symbol[len - i - 1];
		symbol[len - i - 1] = geçiçi;
	}
}
void düzenleyici() {
	reverse(expr); 

	char* kelime = strtok(expr, " ");
	expr2[0] = '\0';  

	while (kelime != NULL) {
		reverse(kelime);  // Her kelimeyi ters çeviriyoruz

		strcat(expr2, kelime); 
		strcat(expr2, " ");    

		kelime = strtok(NULL, " ");
	}

	int len = strlen(expr2);
	if (len > 0 && expr2[len - 1] == ' ') {
		expr2[len - 1] = '\0';
	}
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
	int i = 0;

	// Boşlukları geç
	while (expr2[*n] == ' ') {
		(*n)++;
	}

	// Operand veya operator karakteri oku
	if (isdigit(expr2[*n])) {
		while (isdigit(expr2[*n]) || expr2[*n] == '.') {
			symbol[i++] = expr2[(*n)++];
		}
		symbol[i] = '\0';
		return operand;
	}

	symbol[i++] = expr2[(*n)++];
	symbol[i] = '\0';

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
	char symbol[10];
	precedence token;
	float op1, op2;
	int n = 0;

	düzenleyici(); // Prefix ifadeyi düzenleyici fonksiyonu ile tersine çeviriyoruz

	token = get_token(symbol, &n);
	while (token != eos) {
		if (token == operand) {
			float operand_value = strtof(symbol, NULL); // Sayıyı float'a çeviriyoruz
			push(operand_value);
		}
		else {
			op1 = pop();
			op2 = pop();

			if (token == add)
			{
				push(op1 + op2);
			}
			if (token == subtract)
			{
				push(op1 - op2);
			}
			if (token == multiply)
			{
				push(op2 * op1);
			}
			if (token == divide)
			{
				if (op2 != 0)
				{
					push(op1 / op2);
				}
			}
		}
		token = get_token(symbol, &n);
	}
	return pop();
}
	
int main() {
	float c = eval();
	printf("%.2f", c);


	return 0;
}
