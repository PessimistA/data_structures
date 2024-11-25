#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
	int number;
	node* next;
};
node* head = NULL;
node* temp;
void insert_item(int item) {
	struct node* temp = (node*)malloc(sizeof(node));
	temp->number = item;
	temp->next = head;
	head = temp;

}
void free_list() {
	struct node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}
void print() {
	struct node* head1 = head;
	printf("list: ");
	while (head1 != NULL) {
		printf("%d\t", head1->number);
		head1 = head1->next;
	}
}

int main() {
	insert_item(6);
	insert_item(15);
	print();
	free_list();
	return 0;
}