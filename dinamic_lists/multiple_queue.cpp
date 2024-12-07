#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int item;
	node* next;
};
typedef struct node* pointer_front;
pointer_front front[10];
typedef struct node* pointer_rear;
pointer_rear rear[10];
void enqueue(pointer_front* front, pointer_rear* rear ,int item) {
	node* temp = (node*)malloc(sizeof(node));
	temp->item = item;
	temp->next = NULL;
	if (*front == NULL)
	{
		*front = temp;
		*rear = temp;
	}
	else
	{
		(*rear)->next = temp;
		*rear = temp;
	}
}
void dequeue(pointer_front* front, pointer_rear* rear) {
	if (*rear == NULL)
	{
		printf("stack is empty\n");
	}
	*front = (*front)->next;
}
void print(pointer_front* front, pointer_rear* rear) {
	node* current = *front;
	printf("list: ");
	while (current != NULL) {
		printf("%d -> ", current->item);
		current = current->next;
	}
	printf("NULL\n");
}

int main() {
	enqueue(&front[0],&rear[0], 2);
	enqueue(&front[0], &rear[0], 3);
	enqueue(&front[0], &rear[0], 4);
	enqueue(&front[0], &rear[0], 5);
	print(&front[0], &rear[0]);
	dequeue(&front[0], &rear[0]);
	print(&front[0], &rear[0]);
}
