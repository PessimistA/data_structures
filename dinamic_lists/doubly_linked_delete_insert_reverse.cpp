#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;               
	node* next;
	node* prev;
} ;


void insert_from_left(node** head, int value) {
	node* temp = (node*)malloc(sizeof(node));
	temp->value = value;
	temp->next = *head;
	if (*head !=NULL)
	{
		(*head)->prev = temp; 
	}

	(*head) = temp;
	temp->prev = NULL;
	
}
void insert_from_right(node** head, int value) {
	node* temp = (node*)malloc(sizeof(node));
	temp->value = value;
	temp->next = NULL;
	if (*head==NULL)
	{
		*head = temp;
		(*head)->prev = NULL;
		return;
	}
	node* current = *head;
	while (current->next!= NULL) {
		current = current->next;
	}
	temp->prev = current;
	current->next = temp;
	current = temp;
}
void recursive(node** head) {

}
void iterative(node** head) {
	node* current = *head;
	node* temp = NULL;
	while (current != NULL) {
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = current->next;
	}
	if (current==NULL)
	{
		*head = temp->prev;
	}
}
void delete_from_beginning(node** head) {
	*head = (*head)->next;
}
void delete_from_last(node** head) {
	node* current = *head;
	while (current->next->next != NULL) {
		current = current->next;
	}
	 current->next=NULL;
}

void print(node** head) {
	node* current1 = *head;
	printf("list: ");
	while (current1 != NULL) {//next kullandığından bu kısım tam basilmaz
		printf("%d -> ", current1->value);
		current1 = current1->next;
	}
	printf("NULL\n");
	printf("\n");
	node* current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	printf("list reverse: ");
	while (current!=NULL) {
		printf("%d -> ", current->value);
		current = current->prev;
	}
	printf("NULL\n");
}

int main() {
	node* head = NULL;
	insert_from_left(&head, 2);
	insert_from_left(&head, 4);
	insert_from_left(&head, 5);
	insert_from_left(&head, 6);
	delete_from_beginning(&head);
	print(&head);

	node* head2 = NULL;
	insert_from_right(&head2, 2);
	insert_from_right(&head2, 3);
	insert_from_right(&head2, 7);
	insert_from_right(&head2, 8);
	delete_from_last(&head2);
	print(&head2);
	return 0;
}
