#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct {
	int number;      // Veriyi tutar
	int next;        // Bir sonraki elemanın işaretçisi
	int prev;        // Bir önceki elemanın işaretçisi
} item;
#define MAX_LIST 10
item linkedlist[MAX_LIST];
int FREE;   // Boş olan düğümlerin işaretçisi
int first;  // İlk düğüm
int last;	//son düğüm

void empty_list_maker() {
	for (int i = 0; i < MAX_LIST; i++) {
		linkedlist[i].next = i + 1;//next ile link aynı işlevli
		linkedlist[i].prev = -1;  // Başta önceki düğüm yok
	}
	linkedlist[MAX_LIST - 1].next = -1; // Son düğümde next işaretçisi yok
	FREE = 0;  // Boş alan başta
	first = -1; // İlk düğüm yok
	last = -1;  // Son düğüm yok
}
void insert_item(int value) {
	int r, q, p;

	// Boş düğüm alın
	if (FREE != -1) {
		r = FREE;//boş olan ilk elemanın indixi atılır
		FREE = linkedlist[FREE].next;//sonra da yeni free elde edilir

		linkedlist[r].number = value;//r burada boş olan ilk index yani boş olanı dolduruyoruz
		linkedlist[r].next = -1;   // şu anda sonrasında eleman yok yani -1 koyulmallı
		linkedlist[r].prev = last; // Bir önceki düğüm son düğüm

		if (last != -1) {
			linkedlist[last].next = r; // Son düğümün next'i yeni düğüm
		}

		last = r; // Son düğüm güncelleniyor
		if (first == -1) {  // Eğer liste boşsa
			first = r;      // İlk düğüm yeni eklenen düğüm olacak
		}
	}
	else {
		printf("\nYeterli boş alan yok!!");
	}
}

void print_forward() {
	printf("List (forward):\n ");
	int current = first;
	printf("index\t number\t next\t before\n");
	while (current != -1) {
		printf("%d\t %d\t %d\t %d\n",current, linkedlist[current].number, linkedlist[current].next, linkedlist[current].prev);
		current = linkedlist[current].next;
	}
	printf("\n");
}
void print_backward() {
	printf("List (backward):\n");
	int current = last;
	printf("index\t number\t next\t before\n");
	while (current != -1) {
		printf("%d\t %d\t %d\t %d\n", current, linkedlist[current].number, linkedlist[current].next, linkedlist[current].prev);
		current = linkedlist[current].prev;
	}
	printf("\n");
}
int main() {
	empty_list_maker();  // Listeyi başlat
	insert_item(10);
	insert_item(20);
	insert_item(30);
	insert_item(40);

	print_forward();  // İleri doğru yazdır
	print_backward(); // Geriye doğru yazdır

	return 0;
}

//ver 2 added
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct {
	int number;      // Veriyi tutar
	int next;        // Bir sonraki elemanın işaretçisi
	int prev;        // Bir önceki elemanın işaretçisi
} item;
#define MAX_LIST 10
item linkedlist[MAX_LIST];
int FREE;   // Boş olan düğümlerin işaretçisi

void empty_list_maker(int* first) {
	for (int i = 0; i < MAX_LIST; i++) {
		linkedlist[i].next = i + 1;//next ile link aynı işlevli
		linkedlist[i].prev = -1;  // Başta önceki düğüm yok
	}
	linkedlist[MAX_LIST - 1].next = -1; // Son düğümde next işaretçisi yok
	FREE = 0;  // Boş alan başta
	*first = -1; // İlk düğüm yok
}
void insert_item(int* first, int value) {
	int r, q, p;

	// Boş düğüm alın
	if (FREE != -1) {
		r = FREE;//boş olan ilk elemanın indixi atılır
		FREE = linkedlist[FREE].next;//sonra da yeni free elde edilir
		p = *first;
		q = -1;
		while (linkedlist[p].next!=-1) {
			q = p;
			p = linkedlist[p].next;
		}

		linkedlist[r].number = value;//r burada boş olan ilk index yani boş olanı dolduruyoruz
		linkedlist[r].next = -1;   // şu anda sonrasında eleman yok yani -1 koyulmallı
		linkedlist[r].prev = p; // Bir önceki düğüm son düğüm

		if (p != -1) {//ya da while da p yaz buraya q ve aşağı ile yukarıdaki atamaları q yap
			linkedlist[p].next = r; // Son düğümün next'i yeni düğüm
		}

		
		if (*first == -1) {  // Eğer liste boşsa
			*first = r;      // İlk düğüm yeni eklenen düğüm olacak
			linkedlist[*first].prev = -1;
		}
	}
	else {
		printf("\nYeterli boş alan yok!!");
	}
}

void print_forward(int* first) {
	printf("List (forward):\n ");
	int current = *first;
	printf("index\t number\t next\t before\n");
	while (current != -1) {
		printf("%d\t %d\t %d\t %d\n", current, linkedlist[current].number, linkedlist[current].next, linkedlist[current].prev);
		current = linkedlist[current].next;
	}
	printf("\n");
}
void print_backward(int* first) {
	printf("List (backward):\n");
	int p, q;
	p = *first;
	q = -1;
	while (linkedlist[p].next != -1) {
		q = p;
		p = linkedlist[p].next;
	}
	int current = p;
	printf("index\t number\t next\t before\n");
	while (current != -1) {
		printf("%d\t %d\t %d\t %d\n", current, linkedlist[current].number, linkedlist[current].next, linkedlist[current].prev);
		current = linkedlist[current].prev;
	}
	printf("\n");
}
int main() {
	int first;  // İlk düğüm
	empty_list_maker(&first);  // Listeyi başlat
	insert_item(&first, 10);
	insert_item(&first, 20);
	insert_item(&first, 30);
	insert_item(&first, 40);

	print_forward(&first);  // İleri doğru yazdır
	print_backward(&first); // Geriye doğru yazdır

	return 0;
}
