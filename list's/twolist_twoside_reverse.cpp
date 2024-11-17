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
int first2;  
int last2;
void empty_list_maker() {
	for (int i = 0; i < MAX_LIST; i++) {
		linkedlist[i].next = i + 1;//next ile link aynı işlevli
		linkedlist[i].prev = -1;  // Başta önceki düğüm yok
	}
	linkedlist[MAX_LIST - 1].next = -1; // Son düğümde next işaretçisi yok
	FREE = 0;  // Boş alan başta
	first = -1; // İlk düğüm yok
	last = -1;  // Son düğüm yok
	first2 = -1; // İlk düğüm yok
	last2 = -1;
}
void reverse_list(int* first) {//ilkinden başlayarak her bir pre ve next i değiştir first de bu sırada eklenerek değişir
	int current = *first;
	int temp = EMPTY;//0 da diyebilirsin

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
		*first = temp;
	}
}
void insert_item(int value[],int len,int* first,int* last) {
	int r, q, p;

	// Boş düğüm alın
	for (int i = 0; i < len; i++)
	{
		if (FREE != -1) {
			r = FREE;//boş olan ilk elemanın indixi atılır
			FREE = linkedlist[FREE].next;//sonra da yeni free elde edilir

			linkedlist[r].number = value[i];//r burada boş olan ilk index yani boş olanı dolduruyoruz
			linkedlist[r].next = -1;   // şu anda sonrasında eleman yok yani -1 koyulmallı
			linkedlist[r].prev = *last; // Bir önceki düğüm son düğüm

			if (*last != -1) {
				linkedlist[*last].next = r; // Son düğümün next'i yeni düğüm
			}

			*last = r; // Son düğüm güncelleniyor
			if (*first == -1) {  // Eğer liste boşsa
				*first = r;      // İlk düğüm yeni eklenen düğüm olacak
			}
		}
		else {
			printf("\nYeterli boş alan yok!!");
		}
	}
}

void print_forward() {
	printf("List (forward):\n ");
	int current = first;
	printf("index\t number\t next\t before\n");
	while (current != -1) {
		printf("%d\t %d\t %d\t %d\n", current, linkedlist[current].number, linkedlist[current].next, linkedlist[current].prev);
		current = linkedlist[current].next;
	}
	printf("\n");
}
void print() {
	int current = first;
	printf("index\t number\t next\t before\n");
	for (int i =current; i < MAX_LIST; i++)
	{
		printf("%d\t %d\t %d\t %d\n", i, linkedlist[i].number, linkedlist[i].next, linkedlist[i].prev);
	}	printf("\n");
}

int main() {
	empty_list_maker();  // Listeyi başlat
	int liste[] = { 2,3,4,5 };
	int len = sizeof(liste) / sizeof(liste[0]);
	insert_item(liste, len,&first,&last);
	//print_forward();  // İleri doğru yazdır
	print();
	int liste2[] = { 6,7,8,9 };
	int len2 = sizeof(liste2) / sizeof(liste2[0]);//farklı first kullanınca farklı bir liste eklemiş olursun
	insert_item(liste2, len2, &first2,&last2);//aynı first ve last ile kullanırsan aynısına devam edersin ya da birisini eksik yazarsan
	printf("buradan sonrası ikisinin birleşmiş hali\n");
	print();
	//eğer ikincisini ters çevirip eklemek istersen
	reverse_list(&first2);
	print();
	return 0;
}
