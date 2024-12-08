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
void insert_nLocation_(node** head, int value,int location) {
	node* temp = (node*)malloc(sizeof(node));
	node* current = *head;
	temp->value = value;

	if (*head==NULL)
	{
		temp->next = *head;
		*head = temp;
		(*head)->prev = NULL;
		//temp->prev = *head;
		return;
	}
	for (int i = 0; i < location - 2;i++) {
		current = current->next;
	}
	temp->prev = current;
	if (current->next != NULL)
		current->next->prev = temp;
	temp->next = current->next;
	current->next = temp;


}
struct node* recursive(node* current) {
	if (current == NULL || current->next == NULL) {
		return current; // Base case
	}

	// Recursive çağrı
	struct node* new_head = recursive(current->next);

	// Bağlantıları ters çevir
	current->next->next = current;
	current->prev = current->next;
	current->next = NULL;

	return new_head;
}
struct node* iterative(node** head) {
	node* current = *head;
	node* temp = NULL;
	while (current != NULL) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp != NULL)
	{
		*head = temp->prev;
	}
	return *head;
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
void delete_nLocation(node** head,int location) {
	node* current = *head;
	if (location==1)
	{
		(*head)->next->prev = NULL;
		*head = (*head)->next;
		return;
	}
		for (int i = 0; i < location - 1; i++) {
			current = current->next;
		}
		if (current->prev != NULL) {
			current->prev->next = current->next;
		}
		if (current->next != NULL) {
			current->next->prev = current->prev;
		}
	

}

void print(node** head) {
	node* current1 = *head;
	printf("list: ");
	while (current1 != NULL) {//next kullandığından bu kısım tam basilmaz
		printf("%d -> ", current1->value);
		current1 = current1->next;
	}
	printf("NULL\n");
	//printf("\n");
	//node* current = *head;
	//while (current->next != NULL) {
	//	current = current->next;
	//}
	//printf("list reverse: ");
	//while (current!=NULL) {
	//	printf("%d -> ", current->value);
	//	current = current->prev;
	//}
	//printf("NULL\n");
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
	//delete_from_last(&head2);
	print(&head2);
	head2= iterative(&head2);
	//head2 = recursive(head2);
	print(&head2);

	printf("ucuncu\n");
	node* head3 = NULL;
	insert_nLocation_(&head3, 1, 1);
	insert_nLocation_(&head3, 2, 2);
	insert_nLocation_(&head3, 3, 3);
	insert_nLocation_(&head3, 4, 2);
	print(&head3);
	delete_nLocation(&head3, 4);
	print(&head3);

	return 0;
}
