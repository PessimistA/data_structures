#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Yığın için bir yapı
char stack[MAX][MAX];
int top = -1;

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
    if (top >= 0) {
        strcpy(op, stack[top]);
        top--;
    }
}

// Operand kontrol fonksiyonu
int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch); // Operand: harf ya da rakam
}

// Postfix'ten Prefix'e dönüşüm fonksiyonu
void postfixToPrefix(char* postfix, char* prefix) {
    int len = strlen(postfix);

    // Postfix ifadesini sağdan sola doğru okuma
    for (int i = 0; i < len; i++) {
        char ch = postfix[i];

        if (isOperand(ch)) {
            // Operand: Yığına ekle
            char operand[2] = { ch, '\0' };
            push(operand);
        }
        else {
            // Operatör: Yığına iki operand al
            char op1[MAX], op2[MAX];
            pop(op1); // Birinci operand
            pop(op2); // İkinci operand

            // Operatörü ve iki operand'ı Prefix formatında birleştir
            char newexp[MAX]="";
            strncat(newexp, &ch, 1);
            strcat(newexp, op2); // İkinci operand
            strcat(newexp, op1);// Birinci operand
            push(newexp); // Yeni ifadenin yığına eklenmesi
        }
    }

    // Prefix ifadesini almak (yığındaki son eleman)
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
