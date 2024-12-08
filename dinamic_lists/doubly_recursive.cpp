#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;               
	node* next;
	node* prev;
} ;

void insert_recursive(node** head, int value) {

	if (*head == NULL) {
		node* temp = (node*)malloc(sizeof(node));
		temp->value = value;
		temp->next = NULL;
		temp->prev = NULL;
		*head = temp;
		return;
	}


	if ((*head)->next == NULL) {

		node* temp = (node*)malloc(sizeof(node));
		temp->value = value;
		temp->next = NULL;
		temp->prev = *head;
		(*head)->next = temp; 
		return;
	}

	insert_recursive(&((*head)->next), value);

}

struct node* recursive_reverse(node* current) {
	if (current == NULL || current->next == NULL) {
		return current; 
	}

	struct node* new_head = recursive_reverse(current->next);

	current->next->next = current;
	current->prev = current->next;
	current->next = NULL;

	return new_head;
}

void delete_recursive(node** head,node* location) {//eğer bellekteki yeri bulabilirsen bunu kullan
	if (*head==NULL)
	{
		return;
	}
	if (location == *head )
	{
		if ((*head)->next != NULL) {
			(*head)->next->prev = NULL;
		}
		(*head) = (*head)->next;
		return;
	}
	if ((*head)->next==location)
	{
		(*head)->next = (*head)->next->next;
		if ((*head)->next->next!=NULL)
		{
			(*head)->next->next->prev = *head;
		}
		return;
	}
	delete_recursive(&((*head)->next), location);
}
void delete_recursive2(node** head, int value) {//doğru silme iişlemi budur
	if (*head == NULL)
	{
		return;
	}
	if (value== (*head)->value)
	{
		if ((*head)->next != NULL) {
			(*head)->next->prev = NULL;
		}
		(*head) = (*head)->next;
		return;
	}
	if ((*head)->value == value)
	{
		(*head)->prev->next = (*head)->next;
		if ((*head)->next != NULL)
		{
			(*head)->next->prev = (*head)->prev;
		}
		return;
	}
	delete_recursive2(&((*head)->next), value);
}
void print(node** head) {
	if ((*head)==NULL)
	{
		return;
	}
	else
	{
		printf("%d->", (*head)->value);
		print(&(*head)->next);
	}
}

int main() {

	node* head2 = NULL;
	insert_recursive(&head2, 2);
	insert_recursive(&head2, 3);
	insert_recursive(&head2, 7);
	insert_recursive(&head2, 8);
	printf("list: ");
	print(&head2);
	printf("NULL\n");
	printf("\n");
	
	head2 = recursive_reverse(head2);
	printf("list: ");
	print(&head2);
	printf("NULL\n");
	printf("\n");
	
	delete_recursive2(&head2, 7);
	printf("list: ");
	print(&head2);
	printf("NULL\n");
	printf("\n");

	return 0;
}
