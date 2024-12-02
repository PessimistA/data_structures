#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
	int katsayı;
	int exponen;
	node* next;
	node* prev;
};
int sayaç = 0;
void insert_item(node** head,int katsayı,int exponen) {
	struct node* temp = (node*)malloc(sizeof(node));//temp tüm iki kutucuğu ifade eder

	temp->exponen = exponen;//yeni elemanı ekler
	temp->katsayı = katsayı;
	temp->next = NULL;
	if (*head==NULL)
	{
		*head = temp;
	}
	else
	{
		struct node* current = *head;
		while (current->next!=NULL) {
			current = current->next;
		}
		current->next = temp;
		current = temp;
	}
	sayaç++;
}
int compare(int exponen, int exponen2) {
	if (exponen > exponen2)
	{
		return 1;
	}
	if (exponen == exponen2)
	{
		return 0;
	}
	if (exponen < exponen2)
	{
		return -1;
	}
}

void addition(node** head, node** head2,node** head3) {
	struct node* head1 = *head;
	struct node* head4 = *head2;
	while (head1 != NULL && head4 != NULL) {
		switch (compare(head1->exponen, head4->exponen)) {
		case 1:  // head1'in üssü büyük
			insert_item(head3, head1->katsayı, head1->exponen);
			head1 = head1->next;
			break;

		case -1: // head2'nin üssü büyük
			insert_item(head3, head4->katsayı, head4->exponen);
			head4 = head4->next;
			break;

		case 0:  // Üsler eşit
			insert_item(head3, head1->katsayı + head4->katsayı, head1->exponen);
			head1 = head1->next;
			head4 = head4->next;
			break;
		}
	}
	while (head1 != NULL) {
		insert_item(head3, head1->katsayı, head1->exponen);
		head1 = head1->next;
	}

	while (head4 != NULL) {
		insert_item(head3, head4->katsayı, head4->exponen);
		head4 = head4->next;
	}
}

void free_list(node** head) {
	struct node* temp;
	while (*head != NULL) {
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
void print(node** head) {

	struct node* head3 = *head;//bu ilk elemanı gösterir atama yapınca head 1 de orayı gösteriyor o elemanın  nexti sonuçta sonraki elemanı gösterir 
	printf("\ndüz list: ");
	while (head3 != NULL) {
		printf("%d-%d\t", head3->katsayı, head3->exponen);
		head3 = head3->next;
	}
}

int main() {
	node* head = NULL;
	node* head2 = NULL;
	node* head3 = NULL;
	insert_item(&head,6,3);
	insert_item(&head,15,4);
	insert_item(&head,30,5);
	insert_item(&head,40,6);
	printf("\nlist 1\n");
	print(&head);
	insert_item(&head2, 7, 3);
	insert_item(&head2, 16, 4);
	insert_item(&head2, 31, 1);
	insert_item(&head2, 42, 0);
	printf("\nlist 2");
	print(&head2);
	addition(&head, &head2, &head3);
	printf("\ntoplanmış liste\n");
	print(&head3);
	free_list(&head);
	free_list(&head2);
	free_list(&head3);
	
	return 0;
}
