#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS 

struct node {
	int item;
	node* next;
};

void delete_from_left(node** head) {
	node* temp = *head;
	*head = (*head)->next;
}

void insert_to_right(node** head, int item) {
	node* temp = (node*)malloc(sizeof(node));
	temp->item = item;
	temp->next = NULL;
	if (*head == NULL || (*head)->item >= item)
	{
		temp->next = *head;
		*head = temp;
		return;
	}
	else
	{
		node* current = *head;
		while (current->next != NULL&& current->next->item<item) {
			current = current->next;
		}
		temp->next = current->next;//temp şu anki elemanım current koyacağım yerin öncesindeki 3 ve 5 düşün 4 ü koyacaksın 3 ün next i 4 ün next i olur sonra da 3. next ine 4 ü atarım
		current->next = temp;
	}
}

void print(node** head) {
	node* current = *head;
	printf("list: ");
	while (current != NULL) {
		printf("%d -> ", current->item);
		current = current->next;
	}
	printf("NULL\n");
}

int main() {
	node* head = NULL;
	node* head2 = NULL;
	insert_to_right(&head, 4);
	insert_to_right(&head, 2);
	insert_to_right(&head, 3);
	insert_to_right(&head, 8);
	insert_to_right(&head, 1);
	printf("\n");
	print(&head);
	delete_from_left(&head);
	print(&head);

}
