#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10

typedef struct {
	int value;
};
typedef struct adjacency* stack_pointer;
typedef struct adjacency {// 3 elemanlı ve yaparsan da weight oluşur
	int item;
	adjacency* next;
};
stack_pointer top[MAX];

void push(stack_pointer* top, int item) {
	adjacency* temp = (adjacency*)malloc(sizeof(adjacency));
	temp->item = item;
	temp->next = NULL;
	if (*top==NULL)
	{
		temp->next = *top;
		*top = temp;
	}
	else
	{
		adjacency* current = *top;
		while (current->next!=NULL) {
			current = current->next;
		}
		current->next = temp;
		current = temp;
	}
}
void pop(stack_pointer* top) {
	if (*top == NULL)
	{
		printf("stack is empty\n");
	}
	*top = (*top)->next;
}
void print(stack_pointer* top) {
	for (int i = 0; i <9; i++)//son elemanın indexine kadar yaz
	{
		adjacency* current = top[i];
		printf("list: ");
		while (current != NULL) {
			printf("%d -> ", current->item);
			current = current->next;
		}
		printf("NULL\n");
	}
}
int main() {
	push(&top[0], 2);
	push(&top[0], 5);
	push(&top[1], 6);
	push(&top[2], 6);
	push(&top[3], 4);
	push(&top[4], 5);
	push(&top[5], 7);
	push(&top[7], 2);
	push(&top[7], 8);
	print(&top[0]);

}
