//postfix to prefix
#define _CRT_SECURE_NO_WARNINGS//visual studio kullanıyorum 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Yığın için bir yapı
char stack[MAX][MAX];
int top = -1;
char* op1;
char* op2;

// Yığına veri ekleme fonksiyonu
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
    if (top >=0) {
        strcpy(op, stack[top]);
        top--;
    }
}

// Operand kontrol fonksiyonu
int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch);
}

// Postfix'ten Prefix'e dönüşüm fonksiyonu
void postfixToPrefix(char* postfix, char* prefix) {
    int len = strlen(postfix);
    int j = 0;

    // Postfix ifadesini sağdan sola doğru okuma
    for (int i = 0; i <len; i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            char operand[2] = { ch, '\0' };
            push(operand);
        }
        else {
            // Operatör: Yığına iki operand al
            pop(op1);
            pop(op2);

            // Operatörü ve iki operand'ı Prefix formatında birleştir
            char newexp[100];
            newexp[0] = ch;
            newexp[1] = '\0';
            strcat(newexp, op2);
            strcat(newexp, op1);
            push(newexp);
        }
    }

    // Prefix ifadesini almak
    strcpy(prefix, stack[top]);
}

int main() {
    char postfix[MAX] = "AB+CD-*";  // Örnek Postfix ifadesi: AB+CD-* (için: (A+B)*(C-D))
    char prefix[MAX];

    postfixToPrefix(postfix, prefix);

    printf("Postfix Expression: %s\n", postfix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
