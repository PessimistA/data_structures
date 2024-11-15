#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
float num_stack[MAX];
char operator_stack[MAX];
int top_num = -1;
int top_operator = -1;

void push(float value) {
    if (top_num < (MAX - 1)) {
        num_stack[++top_num] = value;
    }
    else {
        printf("Stack Overflow\n");
    }
}

void push_operator(char value) {
    if (top_operator < (MAX - 1)) {
        operator_stack[++top_operator] = value;
    }
    else {
        printf("Stack Overflow\n");
    }
}

float pop() {
    if (top_num >= 0) {
        return num_stack[top_num--];
    }
    return 0;
}

char pop_operator() {
    if (top_operator >= 0) {
        return operator_stack[top_operator--];
    }
    return '\0';
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

float calculate(float op1, float op2, char symbol) {
    switch (symbol) {
    case '+': return op1 + op2;
    case '-': return op1 - op2;
    case '*': return op1 * op2;
    case '/': return op2 != 0 ? op1 / op2 : 0; // Bölme işlemi için kontrol
    default: return 0;
    }
}

float eval(char infix[]) {
    int len = strlen(infix);
    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        if (isspace(ch))
            continue;

        if (isdigit(ch)) {
            float num = 0;
            while (i < len && isdigit(infix[i])) {
                num = num * 10 + (infix[i] - '0'); // '0' olarak düzeltildi
                i++;
            }
            i--;
            push(num);
        }
        else if (ch == '(') {
            push_operator(ch);
        }
        else if (ch == ')') {
            while (top_operator != -1 && operator_stack[top_operator] != '(') {
                float op2 = pop();
                float op1 = pop();
                char symbol = pop_operator();
                push(calculate(op1, op2, symbol));
            }
            pop_operator(); // '(' karakterini yığından çıkar
        }
        else if (isOperator(ch)) {
            while (top_operator != -1 && precedence(operator_stack[top_operator]) >= precedence(ch)) {
                float op2 = pop();
                float op1 = pop();
                char symbol = pop_operator();
                push(calculate(op1, op2, symbol));
            }
            push_operator(ch);
        }
    }

    // Yığındaki kalan işlemleri yap
    while (top_operator != -1) {
        float op2 = pop();
        float op1 = pop();
        char symbol = pop_operator();
        push(calculate(op1, op2, symbol));
    }

    return pop(); // Nihai sonuç
}

int main() {
    char infix[MAX] = "3 + 5 * ( 2 - 8 )";
    float result = eval(infix);
    printf("Sonuç: %.2f\n", result);
    return 0;
}

//ver2 easy version

#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
int stack_number[MAX];
int top_number = -1;
char stack_opeartor[MAX];
int top_operator = -1;

void push_number(int value) {
	top_number++;
	stack_number[top_number]=value ;
}
void pop_number(int* op) {
	if (top_number==-1)
	{
		return;
	}
	*op = stack_number[top_number];
	top_number--;
}
void push_operator(char ch) {
	top_operator++;
	stack_opeartor[top_operator] = ch;
}
void pop_operator(char* op) {
	if (top_operator == -1)
	{
		return;
	}
	*op = stack_opeartor[top_operator];
	top_operator--;
}

int isoperand(char ch) {
	return  isdigit(ch);
}

int isoperator(char ch) {
	return ch=='+' || ch == '-' || ch == '*' || ch == '/' ;
}
int calculate(char ch,int op1,int op2) {
	switch (ch)
	{
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
		break;
	}
}
int precedence(char ch) {
	switch (ch)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
		break;
	}
}
void translater(char value[]) {
	int len = strlen(value);
	int j = 0;
	int op1, op2;
	char op;
	for (int i = 0; i < len; i++)
	{
		char ch = value[i];
		if (isoperand(ch))
		{
			push_number(ch - '0');
		}
		else if(ch == '(')
		{
			push_operator(ch);
		}
		else if (ch==')') {
			while (top_operator!=-1 && stack_opeartor[top_operator] !='(') {
				pop_operator(&op);
				pop_number(&op1);
				pop_number(&op2);
				int answer= calculate(op,op2,op1);
				push_number(answer);
			}
			pop_operator(&op);
		}
		else if(isoperator(ch))
		{
			while (top_operator != -1 && precedence(stack_opeartor[top_operator]) >= precedence(ch)) {
				pop_operator(&op);
				pop_number(&op1);
				pop_number(&op2);
				int answer = calculate(op, op2, op1);
				push_number(answer);
			}
			push_operator(ch);
		}
	}
	while (top_operator != -1) {
		pop_operator(&op);
		pop_number(&op1);
		pop_number(&op2);
		int answer = calculate(op, op2, op1);
		push_number(answer);
	}
}

int main() {
	char value[MAX] = "2*(5*(3+6))/9-2";
	char prefix[MAX];
	//reverseParanteheses(value);
	//printf("%s\n", value);
	translater(value);
	printf("%d", stack_number[top_number]);
	return 0;
}

