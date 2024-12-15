#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char stack[100];
int top = -1;

//bu push ve pop infix-prefix infix-postfix için kullanılmıştır
void push(char value) {
	if (top < (MAX - 1)) {
		top++;
		stack[top] = value;
		
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
	switch (ch) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^'://en üstün olan
		return 3;
	default:
		return -1;
	}
}
int isoperand(char ch) {
	return isalpha(ch) || isdigit(ch);
}
int isOperator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
void infix_to_postfix(char infix[],char postfix[]) {
	int len = strlen(infix);
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		int ch = infix[i];
		if (isoperand(ch))
		{
			postfix[j++] = ch;
		}
		
		else if(ch=='(')//parantez açılımı
		{
			push(ch);
		}
		else if (ch==')') {//parantez kapatılması
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
	// Kalan tüm operatörleri postfix'e ekle
	while (top != -1) {
		postfix[j++] = pop();
	}
	postfix[j] = '\0';  // Postfix ifadesini sonlandır
}
void reverse(char infix[]) {
    int len = strlen(infix);
    for (int i = 0; i < len / 2; i++) {
        char temp = infix[i];
        infix[i] = infix[len - i - 1];
        infix[len - i - 1] = temp;
    }
}
void reverseParentheses(char infix[]) {
	int len = strlen(infix);
	for (int i = 0; i < len; i++) {
		if (infix[i] == '(') infix[i] = ')';
		else if (infix[i] == ')') infix[i] = '(';
	}
}
void infix_to_prefix(char infix[],char prefix[]) {
	char infix2[100];
	strcpy(infix2, infix);
	reverse(infix2);
	reverseParentheses(infix2);
	int len = strlen(infix2);
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		int ch = infix2[i];
		if (isoperand(ch))
		{
			prefix[j++] = ch;
		}

		else if (ch == '(')//parantez açılımı
		{
			push(ch);
		}
		else if (ch == ')') {//parantez kapatılması
			while (top != -1 && stack[top] != '(') {//parantez kapanınca aradakiler dömüşür
				prefix[j++] = pop();
			}
			pop();
		}
		else if (isOperator(ch)) {
			while (top != -1 && precedence(stack[top]) > precedence(ch)) {//eşitlik prefixte yok
				prefix[j++] = pop();
			}
			push(ch);
		}
	}
	// Kalan tüm operatörleri postfix'e ekle
	while (top != -1) {
		prefix[j++] = pop();
	}
	prefix[j] = '\0';
	reverse(prefix);

}

//buradaki push1 ve pop1 prefix-postfix ve tam tersi ile bu ikisinin infix dönüşümlerinde kullanılmıştır
char stack1[100][100];
int top1 = -1;
// Yığına veri ekleme fonksiyonu
void push1(char value[]) {
	if (top1 < (MAX - 1)) {
		top1++;
		strcpy(stack1[top1], value);
	}
	else {
		printf("Stack Overflow\n");
	}
}

// Yığından veri çekme fonksiyonu
void pop1(char op[]) {
	if (top1 >= 0) {
		strcpy(op, stack1[top1]);
		top1--;
	}
}
void postfix_to_prefix(char postfix[],char prefix[]) {
	int len = strlen(postfix);

	for (int i = 0; i < len; i++) {
		char ch = postfix[i];

		if (isoperand(ch)) {
			char operand[2] = { ch, '\0' };
			push1(operand);
		}
		else {
			char op1[MAX], op2[MAX];
			pop1(op1); // Birinci operand
			pop1(op2); // İkinci operand

			char newexp[MAX];
			strncat(newexp, &ch, 1);
			strcat(newexp, op2); // İkinci operand
			strcat(newexp, op1); // Birinci operand
			push1(newexp); // Yeni ifadenin yığına eklenmesi
		}
	}

	// Prefix ifadesini almak (yığındaki son eleman)
	strcpy(prefix, stack1[top1]);
}
void prefix_to_postfix(char prefix[], char postfix[]) {
	int len = strlen(prefix);
	int j = 0;

	// Prefix ifadesini sağdan sola doğru okuma
	for (int i = len - 1; i >= 0; i--) {
		char ch = prefix[i];

		if (isoperand(ch)) {
			// Operand: Yığına ekle
			char operand[2] = { ch, '\0' };
			push1(operand);
		}
		else {
			// Operatör: Yığına iki operand al
			char op1[MAX], op2[MAX];
			pop1(op1);
			pop1(op2);

			// Operatörü ve operandları Postfix formatında birleştir
			char newexp[MAX];
			strcpy(newexp, op1);
			strcat(newexp, op2);
			strncat(newexp, &ch, 1);

			// Yeni postfix ifadesini yığına ekle
			push1(newexp);
		}
	}

	// Postfix ifadesini almak (yığındaki son eleman)
	strcpy(postfix, stack1[top1]);
}

void postfix_to_infix(char postfix[], char infix[]) {
	int len = strlen(postfix);
	int j = 0;

	// Prefix ifadesini sağdan sola doğru okuma
	for (int i = 0; i < len; i++) {
		char ch = postfix[i];

		if (isoperand(ch)) {
			// Operand: Yığına ekle
			char operand[2] = { ch, '\0' };
			push1(operand);
		}
		else {
			// Operatör: Yığına iki operand al
			char op1[MAX], op2[MAX];
			pop1(op1);
			pop1(op2);

			// Operatörü ve operandları Postfix formatında birleştir
			char newexp[MAX];//bunun içinde birleştireceğiz
			strcpy(newexp, op2);//bu harflerin 2. olanının ilk olarak yazılmasını sağlar
			strncat(newexp, &ch, 1);//bu işareti koyar
			strcat(newexp, op1);
			// Yeni infix ifadesini yığına ekle
			push1(newexp);
		}
	}

	// Postfix ifadesini almak (yığındaki son eleman)
	strcpy(infix, stack1[top1]);
}
void prefix_to_infix(char prefix[], char infix[]) {
	int len = strlen(prefix);

	// Prefix ifadesini sağdan sola doğru okuma
	for (int i = len-1; i >=0 ; i--) {
		char ch = prefix[i];

		if (isoperand(ch)) {
			// Operand: Yığına ekle
			char operand[2] = { ch, '\0' };
			push1(operand);
		}
		else {
			// Operatör: Yığına iki operand al
			char op1[MAX], op2[MAX];
			pop1(op1);
			pop1(op2);

			// Operatörü ve operandları Postfix formatında birleştir
			char newexp[MAX];//bunun içinde birleştireceğiz
			strcpy(newexp, op1);//bu harflerin 2. olanının ilk olarak yazılmasını sağlar
			strncat(newexp, &ch, 1);//bu işareti koyar
			strcat(newexp, op2);
			// Yeni infix ifadesini yığına ekle
			push1(newexp);
		}
	}

	// Postfix ifadesini almak (yığındaki son eleman)
	strcpy(infix, stack1[top1]);
}

int main() {
	//printf("lütfen bir infix ifade giriniz");
	//char infix[100];
	//scanf_s("%s", infix,sizeof(infix));
	
	char infix[MAX]= "A+B*(C-D)";//alınmazsa yukarıdakini açarak kendi değerinizi girebilirsiniz
	char postfix[100];
	//char postfix[100] = "ABC/-AK/L-*";
	char prefix[100];
	//char prefix[100] = "*-A/BC-/AkL";

	//infix-postfix hesaplama
	//infix_to_postfix(infix, postfix);
	//printf("infix:%s\n", infix);
	//printf("postfix:%s\n", postfix);
	
	//infix -prefix hesaplama
	//infix_to_prefix(infix, prefix);
	//printf("infix:%s\n", infix);
	//printf("prefix:%s\n", prefix);

	//prefix-postfix hesaplama
	infix_to_prefix(infix, prefix);
	printf("infix:%s\n", infix);
	printf("prefix:%s\n", prefix);
	prefix_to_postfix(prefix, postfix);
	printf("postfix:%s\n", postfix);

	//prefix-postfix hesaplama
	//infix_to_prefix(infix, prefix);
	//prefix_to_postfix(prefix, postfix);
	//printf("infix:%s\n", infix);
	//printf("prefix:%s\n", prefix);
	//printf("postfix:%s\n", postfix);

	//postfix-infix hesaplama
	//postfix_to_infix(postfix, infix);
	//printf("infix:%s\n", infix);
	//printf("postfix:%s\n", postfix);

	//prefix-infix hesaplama
	//prefix_to_infix(prefix, infix);
	//printf("prefix:%s\n", prefix);
	//printf("infix:%s\n", infix);

	return 0;
}
