#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack yapısı
char stack[MAX];
int top = -1;

// Stack işlemleri
void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// İnfix'i tersine çevir
void reverse(char* expr) {
    int len = strlen(expr);
    for (int i = 0; i < len / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[len - i - 1];
        expr[len - i - 1] = temp;
    }
}

// Parantezleri ters çevir
void reverseParentheses(char* expr) {
    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        if (expr[i] == '(') expr[i] = ')';
        else if (expr[i] == ')') expr[i] = '(';
    }
}

// İnfix'i Prefix'e dönüştür
void infixToPrefix(char* infix, char* prefix) {
    reverse(infix);  // İfadenin tersini al
    reverseParentheses(infix);  // Parantezleri ters çevir

    int len = strlen(infix);
    int j = 0;

    // Postfix benzeri işlemleri yap
    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            prefix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                prefix[j++] = pop();
            }
            pop();  // '(' karakterini pop et
        }
        else if (isOperator(ch)) {
            while (top != -1 && precedence(stack[top]) > precedence(ch)) {//eşitlik postfix de var
                prefix[j++] = pop();
            }
            push(ch);
        }
    }

    // Kalan operatörleri prefix'e ekle
    while (top != -1) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';  // Null terminate
    reverse(prefix);   // Prefix'i tersine çevir
}

int main() {
    char infix[] = "(A-B/C)*(A/K-L)";
    char prefix[MAX];

    infixToPrefix(infix, prefix);
    printf("Infix: %s\n", infix);
    printf("Prefix: %s\n", prefix);

    return 0;
}
