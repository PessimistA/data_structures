#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
};
typedef struct stack *stack_pointer;
typedef struct stack{
	int item;
	stack* next;
};
stack_pointer top[10];

void push(stack_pointer* top, int item) {
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->item = item;
	temp->next = *top;
	*top = temp;
}
void pop(stack_pointer* top) {
	if (*top == NULL)
	{
		printf("stack is empty\n");
	}
	*top = (*top)->next;
}
void print(stack_pointer* top ) {
	stack* current = *top;
	printf("list: ");
	while (current != NULL) {
		printf("%d -> ", current->item);
		current = current->next;
	}
	printf("NULL\n");
}
int main() {
	push(&top[0], 2);
	push(&top[0], 3);
	push(&top[0], 4);
	push(&top[0], 5);
	push(&top[1], 2);
	push(&top[1], 3);
	push(&top[1], 4);
	push(&top[1], 5);
	print(&top[0]);
	pop(&top[0]);
	print(&top[0]);
	print(&top[1]);
}
