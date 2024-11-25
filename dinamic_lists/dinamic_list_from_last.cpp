#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
	int number;
	node* next;
};
node* head=NULL;
node* tail= NULL;
node* temp;
void insert_item(int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp tüm iki kutucuğu ifade eder

	temp->number = item;//yeni elemanı ekler
	temp->next = NULL;//bu yeni eklenmiş elemanın next null yapar yeni eleman eklenene kadar

	if (head==NULL)
	{
		head = temp;//başlangıç durumudur head e ekleme bir kez yapılır
		tail = temp;
	}
	else
	{
		tail->next = temp;//mevcut listenin son elemanının yeni adresimize yöneldirecek şekilde güncelleriz
		tail = temp;//mevcut listeyi güncelleriz temp burada yeni elemandır zaten kendi içinde sonraki elemanı null değeri atanmıştır
	}
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
	struct node* head1 = head;//bu ilk elemanı gösterir atama yapınca head 1 de orayı gösteriyor o elemanın  nexti sonuçta sonraki elemanı gösterir 
	printf("list: ");
	while (head1 != NULL) {
		printf("%d\t", head1->number);
		head1 = head1->next;
	}
}

int main() {
	insert_item(6);
	insert_item(15);
	insert_item(30);
	insert_item(40);
	print();
	free_list();
	return 0;
}
