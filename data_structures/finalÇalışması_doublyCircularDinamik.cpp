#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct node {
	int value;
	node* next;
	node* prev;
};


void insert_from_left(node** head,node** tail, int value) {
	node* temp = (node*)malloc(sizeof(node));
	temp->value = value;

	if (*head == NULL) {
		// Liste boşsa, yeni düğüm hem baş hem de son olur
		temp->next = temp;
		temp->prev = temp;
		*head = temp;
		*tail = temp;
	}
	else {
		// Liste doluysa, yeni düğümü başa ekle
		temp->next = *head;
		temp->prev = *tail;
		(*head)->prev = temp;
		(*tail)->next = temp;
		*head = temp;
	}

}
void insert_from_right(node** head,node** tail ,int value) {
	node* temp = (node*)malloc(sizeof(node));
	temp->value = value;
	temp->next = *head;
	if (*head==NULL)
	{
		*head = temp;
		*tail = temp;
		(*head)->prev = *tail;
	}
	else
	{
		(*tail)->next = temp;
		temp->prev = *tail;
		*tail = temp;
	}
}
void insert_nLocation(node** head, node** tail, int value, int location) {
	node* temp = (node*)malloc(sizeof(node));
	temp->value = value;

	// Başa ekleme durumu

	if (*head == NULL)
	{
		temp->next = *head;
		*head = temp;
		(*head)->prev = NULL;
		//temp->prev = *head;
		*tail = temp;
		(*tail)->next = *head;
		(*head)->prev = *tail;
		return;
	}
	// N'inci pozisyona ekleme
	node* current = *head;
	for (int i = 0; i < location - 2; i++) {
		current = current->next;
	}
	temp->prev = current;
	if (current->next != NULL) {
		current->next->prev = temp;
	}
	else
	{
		*tail = temp; // Sona ekleme durumu
	}
	temp->next = current->next;
	current->next = temp;

	// Circular durum için
	(*tail)->next = *head;
	(*head)->prev = *tail;
	
}
struct node* recursive(node* current) {
	if (current == NULL || current->next == NULL) {
		return current; // Base case
	}

	// Recursive çağrı
	struct node* new_head = recursive(current->next);

	// en sondaki elemanla buraya gelir ve en sondaki elemanı bir öne çeker onu da bir öne 
	current->next->next = current;
	current->prev = current->next;
	current->next = NULL;

	return new_head;
}
struct node* iterative(node** head) {
	node* current = *head;
	node* temp = NULL;
	while (current != NULL) {//baştaki elemanı sona taşıyarak işlem yaparsın
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
	while (current->next != *head) {
		current = current->next;
	}
	current->prev->next = *head;
	(*head)->prev = current->prev;
	free(current);
}
void delete_nLocation(node** head, node** tail,int location) {
	node* current = *head;
	if (location == 1)
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
	do
	{
		printf("%d -> ", current1->value);
		current1 = current1->next;
	} while (current1 != *head);
	printf("NULL\n");
}

int main() {
	node* head = NULL;
	node* tail = NULL;
	insert_from_left(&head,&tail ,2);
	insert_from_left(&head,&tail ,4);
	insert_from_left(&head,&tail ,5);
	insert_from_left(&head,&tail ,6);
	//delete_from_beginning(&head);
	print(&head);

	node* head2 = NULL;
	node* tail2 = NULL;
	insert_from_right(&head2,&tail2,2);
	insert_from_right(&head2,&tail2 ,3);
	insert_from_right(&head2,&tail2 ,7);
	insert_from_right(&head2,&tail2 ,8);
	print(&head2);
	delete_from_last(&head2);
	print(&head2);
	//head2 = iterative(&head2);
	////head2 = recursive(head2);
	//print(&head2);

	printf("ucuncu\n");
	node* head3 = NULL;
	node* tail3 = NULL;
	insert_nLocation(&head3,&tail3 ,1, 1);
	insert_nLocation(&head3,&tail3 ,2, 2);
	insert_nLocation(&head3,&tail3 ,3, 3);
	insert_nLocation(&head3,&tail3 ,4, 4);
	print(&head3);
	//delete_nLocation(&head3, 4);
	//print(&head3);

	return 0;
}
