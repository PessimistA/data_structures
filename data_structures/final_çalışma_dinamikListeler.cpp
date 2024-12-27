#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
	int number;
	node* next;
};
void insert_item_to_left(node** head,int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	temp->next = *head;//geriye sarıyormuş gibi düşün sola doğru eklenir ama sola eklediğinin nexti sağı gösterir
	*head = temp;//yeni head değerini atama
}
void insert_item_to_right(node** head, int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	temp->next = NULL;//geriye sarıyormuş gibi düşün sola doğru eklenir ama sola eklediğinin nexti sağı gösterir
	if (*head==NULL)
	{
		*head = temp;
	}
	else
	{
		node* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
		current = temp;
	}
}
void insert_item_sorted(node** head, int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	temp->next = NULL;//geriye sarıyormuş gibi düşün sola doğru eklenir ama sola eklediğinin nexti sağı gösterir
	if (*head == NULL || (*head)->number >= item)//küçük istiyorsun bu büyük alttaki küçük işareti olacak
	{
		temp->next = *head;
		*head = temp;
	}
	else
	{
		node* current = *head;
		while (current->next != NULL && current->next->number < item) {
			current = current->next;
		}
		current->next = temp;
		current = temp;
	}
}
void insert_wanted_location(node** head, int item,int location) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	temp->next = NULL;//geriye sarıyormuş gibi düşün sola doğru eklenir ama sola eklediğinin nexti sağı gösterir
	if (location == 1)
	{
		temp->next = *head;
		*head = temp;
	}
	else
	{
		node* current = *head;
		for (int i = 1; i <= location - 2; i++) {
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
		current = temp;
	}
}
void delete_wanted_location(node** head,int location) {
	if (location == 1)
	{
		*head = (*head)->next;
	}
	else
	{
		node* current = *head;
		for (int i = 1; i <= location - 2; i++) {
			current = current->next;
		}
		current->next = current->next->next;
		
	}
}
void delete_wanted_item(node** head, int item) {
	node* current = *head;
	while (current->next != NULL) {
		if (current->next->number ==item)
		{
			current->next = current->next->next;
			return;
		}
		current=current->next;
	}
}
void delete_sorted(node** head, int count) {//sırasız dizide en büyük n elemanı siler
	for (int i = 0; i < count; i++)
	{
		node* max_node = *head; // max_node başlangıçta listenin ilk elemanını işaret ediyor
		node* current = *head;
		node* pre = NULL;
		while (current->next != NULL) {

			if (max_node->number < current->next->number) {

				pre = current;
				max_node = current->next; // max_node en büyük elemanı işaret eder
			}
			current = current->next;
		}
		pre->next = max_node->next;
	}
}
struct node* reverse_recursive(struct node* head) {
	// Eğer liste boşsa veya sadece bir eleman varsa, ters çevirmeye gerek yok
	if (head == NULL || head->next == NULL) {
		return head;
	}

	// Kalan listeyi ters çevir
	struct node* new_head = reverse_recursive(head->next);

	// Mevcut düğümü ters çevir
	head->next->next = head;//ters çevirme işlemini burası yapar head değerinin yönünü değiştire değiştire en son head değerini elde ederiz
	head->next = NULL;

	return new_head; // Yeni baş düğümü döndür
}
struct node* reverse_iterative(struct node* head) {

	struct node* prev = NULL; // Bir önceki düğüm
	struct node* current = head; // Şu anki düğüm
	struct node* next = NULL; // Sonraki düğüm

	while (current != NULL) {
		next = current->next;    // Sonraki düğümü sakla
		current->next = prev;    // Mevcut düğümün yönünü değiştir
		prev = current;          // Bir sonraki iterasyonda prev, current olur
		current = next;          // current bir sonraki düğüme geçer
	}

	return prev; // Yeni baş düğümü döndür
}
void print(node* head) {
	node* head1 = head;
	printf("list: ");
	while (head1 != NULL) {
		printf("%d \t", head1->number);
		head1 = head1->next;
	}
	printf("\n");
}

int main() {
	node* head = NULL;
	node* head1 = NULL;
	node* head3 = NULL;
	node* head4 = NULL;
	insert_item_to_left(&head,6);
	insert_item_to_left(&head,7);
	insert_item_to_left(&head, 8);
	insert_item_to_left(&head, 9);
	insert_item_to_left(&head, 1);
	insert_item_to_left(&head, 10);

	insert_item_to_right(&head1, 6);
	insert_item_to_right(&head1, 7);
	insert_item_to_right(&head1, 8);
	insert_item_to_right(&head1, 9);
	insert_item_to_right(&head1, 1);
	insert_item_to_right(&head1, 10);

	insert_wanted_location(&head3, 10, 1); // 1. sıraya ekle
	insert_wanted_location(&head3, 20, 2); // 2. sıraya ekle
	insert_wanted_location(&head3, 15, 2); // 2. sıraya ekle
	insert_wanted_location(&head3, 5, 1);  // 1. sıraya ekle
	
	insert_item_sorted(&head4, 2);
	insert_item_sorted(&head4, 1);
	insert_item_sorted(&head4, 4);
	insert_item_sorted(&head4, 7);
	print(head);
	print(head1);
	print(head3);
	print(head4);
	delete_sorted(&head1, 2);
	print(head1);
	//printf("reverse\n");
	//node* head5 = reverse_iterative(head4);
	//node* head6 = reverse_recursive(head3);
	//print(head5);
	//print(head6);
	//delete_wanted_location(&head3, 4);
	//delete_wanted_item(&head3, 10);
	//print(head3);

	return 0;
}

//stack ve queue
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
	int number;
	node* next;
};
void push(node** head,int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	temp->next = *head;//geriye sarıyormuş gibi düşün sola doğru eklenir ama sola eklediğinin nexti sağı gösterir
	*head = temp;//yeni head değerini atama
}
void pop(node** head) {
	*head = (*head)->next;
} 
void enqueue(node** head, int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	if (*head==NULL)
	{
		temp->next = *head;
		*head = temp;
	}
	else
	{
		node* current = *head;
		while (current->next!=NULL) {
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
	}
}
void dequeue(node** head) {
	node* current = *head;
	while (current->next->next != NULL) {
		current = current->next;
	}
	current->next= NULL;
}

void print(node* head) {
	node* head1 = head;
	printf("list-stack: ");
	while (head1 != NULL) {
		printf("%d  \t", head1->number);
		head1 = head1->next;
	}
	printf("\n");
}

int main() {
	node* head = NULL;
	node* head2 = NULL;
	push(&head,6);
	push(&head,7);
	push(&head, 8);
	push(&head, 9);
	push(&head, 1);
	push(&head, 10);
	print(head);
	pop(&head);
	pop(&head);
	pop(&head);
	print(head);

	enqueue(&head2, 1);
	enqueue(&head2, 2);
	enqueue(&head2, 3);
	enqueue(&head2, 4);
	enqueue(&head2, 5);
	enqueue(&head2, 6);
	print(head2);
	dequeue(&head2);
	dequeue(&head2);
	dequeue(&head2);
	print(head2);

	return 0;
}
