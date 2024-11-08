#define _CRT_SECURE_NO_WARNINGS//visual studio kullanıyorum 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef enum {
    left_parent, right_parent, add, subtract, multiply, divide, mod, eos, operand
} precedence;

char expr[] = " (4/(2-2+3))*(3-4)*2";
static int stack_pre[] = { 0, 19, 12, 12, 13, 13, 13, 0 };  // Öncelik sırası: parantezler, operatörler, eos
static int pre[] = { 20, 19, 12, 12, 13, 13, 13, 0 };        // Aynı sırayla öncelik değerleri
precedence stack[100];  // Yığın tanımı
int top = -1;           // Yığının tepe noktası

// Yığından veri çekme fonksiyonu
precedence pop(int* top) {
    if (*top == -1) return eos;
    return stack[(*top)--];
}

// Yığına veri ekleme fonksiyonu
void push(int* top, precedence token) {
    stack[++(*top)] = token;
}

// Karakter sembolünü ve pozisyonu kullanarak token alma fonksiyonu
precedence get_token(char* symbol, int* n) {
    *symbol = expr[(*n)++];
    switch (*symbol) {
    case '(': return left_parent;
    case ')': return right_parent;
    case '+': return add;
    case '-': return subtract;
    case '*': return multiply;
    case '/': return divide;
    case '%': return mod;
    case '\0': return eos;
    default: return operand;
    }
}

// Tokenleri yazdırma fonksiyonu
void print_token(precedence token) {
    switch (token) {
    case add: printf("+"); break;
    case subtract: printf("-"); break;
    case multiply: printf("*"); break;
    case divide: printf("/"); break;
    case mod: printf("%%"); break;
    default: break;
    }
}

// Postfix dönüşüm fonksiyonu
void postfix(void) {
    char symbol;
    precedence token;
    int n = 0;
    top = 0;
    stack[0] = eos;

    for (token = get_token(&symbol, &n); token != eos; token = get_token(&symbol, &n)) {
        if (token == operand)
            printf("%c", symbol);  // Operandları direkt yazdırıyoruz
        else if (token == right_parent) {
            while (stack[top] != left_parent)
                print_token(pop(&top));
            pop(&top);  // Sol parantezi atla
        }
        else {
            while (stack_pre[stack[top]] >= pre[token])
                print_token(pop(&top));
            push(&top, token);
        }
    }
    while ((token = pop(&top)) != eos)
        print_token(token);
    printf("\n");
}

int main() {
    printf("Postfix Notation: ");
    postfix();

    return 0;
}
//ver2
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char stack[100];
int top = -1;
void push(char value) {
	if (top < (MAX - 1)) {
		stack[++top] = value;

	}
}

char pop() {
	if (top >= 0) {
		return stack[top--];
	}
	else {
		printf("Stack Underflow\n");
		return -1;
	}
}

int precedence(char ch) {//öncelik kontrolü
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
	}
}
int isoperand(char ch) {
	return isalpha(ch) || isdigit(ch);
}
int isOperator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
void infix_to_postfix(char infix[], char postfix[]) {
	int len = strlen(infix);
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		int ch = infix[i];
		if (isoperand(ch))
		{
			postfix[j++] = ch;
		}

		else if (ch == '(')//parantez açılımı
		{
			push(ch);
		}
		else if (ch == ')') {//parantez kapatılması
			while (top != -1 && stack[top] != '(') {//parantez kapanınca aradakiler dömüşür
				postfix[j++] = pop();
			}
			pop();
		}
		else if (isOperator(ch)) {
			while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
				postfix[j++] = pop();
			}
			push(ch);
		}
	}
	while (top != -1) {
		postfix[j++] = pop();
	}
	postfix[j] = '\0';
}
int main() {
	char infix[MAX] = "A+B*(C-D)";//alınmazsa yukarıdakini açarak kendi değerinizi girebilirsiniz
	char postfix[100];
	infix_to_postfix(infix,postfix);
	printf("son hali:%s", postfix);
	return 0;
}
