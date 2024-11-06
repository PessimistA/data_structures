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
    return isalpha(ch) || isdigit(ch);
}

// Prefix'ten Postfix'e dönüşüm fonksiyonu
void prefixToPostfix(char* prefix, char* postfix) {
    int len = strlen(prefix);
    int j = 0;

    // Prefix ifadesini sağdan sola doğru okuma
    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isOperand(ch)) {
            // Operand: Yığına ekle
            char operand[2] = { ch, '\0' };
            push(operand);
        }
        else {
            // Operatör: Yığına iki operand al
            char op1[MAX], op2[MAX];
            pop(op1);
            pop(op2);

            // Operatörü ve operandları Postfix formatında birleştir
            char newexp[MAX];
            strcpy(newexp, op1);
            strcat(newexp, op2);
            strncat(newexp, &ch, 1);

            // Yeni postfix ifadesini yığına ekle
            push(newexp);
        }
    }

    // Postfix ifadesini almak (yığındaki son eleman)
    strcpy(postfix, stack[top]);
}

int main() {
    char prefix[MAX] = "*+AB-CD";  // Örnek Prefix ifadesi: *+AB-CD (için: (A+B)*(C-D))
    char postfix[MAX];

    prefixToPostfix(prefix, postfix);

    printf("Prefix Expression: %s\n", prefix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
