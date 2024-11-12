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
#define EMPTY -1
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
void reverse_list() {//ilkinden başlayarak her bir pre ve next i değiştir first de bu sırada eklenerek değişir
	int current = first;
	int temp = EMPTY;

	while (current != EMPTY) {
		// current düğümün next ve prev işaretçilerini değiştir
		temp = linkedlist[current].prev;
		linkedlist[current].prev = linkedlist[current].next;
		linkedlist[current].next = temp;

		// Sıradaki düğüme ilerle
		current = linkedlist[current].prev;
	}

	// first'i son düğüm olacak şekilde ayarla
	if (temp != EMPTY) {
		first = temp;
	}
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
		printf("\nlast:%d\tr:%d", last, r);
		last = r; // Son düğüm güncelleniyor
		if (first == -1) {  // Eğer liste boşsa
			first = r;      // İlk düğüm yeni eklenen düğüm olacak
		}
		printf("\tlast:%d\tr:%d\n",last,r);
	}
	else {
		printf("\nYeterli boş alan yok!!");
	}
}

void print_forward() {
	printf("List (forward):\n ");
	int current = first+1;
	printf("index\t number\t next\t before\n");
	while (current != -1) {
		printf("%d\t %d\t %d\t %d\n",current, linkedlist[current].number, linkedlist[current].next, linkedlist[current].prev);
		current = linkedlist[current].next;
	}
	printf("\n");
}
int main() {
	empty_list_maker();  // Listeyi başlat
	insert_item(10);
	insert_item(20);
	insert_item(30);
	insert_item(40);
	print_forward();
	printf("\n");
	reverse_list();//tek yapman gereken şey normal bir şekilde atama yapıp sonrasında reverse fonksiyonu kullanmak 

	print_forward();  // İleri doğru yazdır


	return 0;
}
