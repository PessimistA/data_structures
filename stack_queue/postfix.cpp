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
