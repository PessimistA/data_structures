#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LIST 10
#define TRUE 1
#define FALSE 0
#define EMPTY -1

typedef struct {
	int number;
	int link;
} item;

item linkedlist[MAX_LIST];
item reverselinkedlist[MAX_LIST];
int FREE;
int first;
int first2;

void empty_list_maker() {
	for (int i = 0; i < MAX_LIST; i++) {
		linkedlist[i].link = i + 1;
		reverselinkedlist[i].link=i+1;
	}
	linkedlist[MAX_LIST - 1].link = EMPTY;
	reverselinkedlist[MAX_LIST - 1].link = EMPTY;
	FREE = 0;
	first = EMPTY;
	first2 = EMPTY;
}

int get_item(int* r) {
	if (FREE == EMPTY) {
		return FALSE;
	} else {
		*r = FREE;
		FREE = linkedlist[FREE].link;
		return TRUE;
	}
}

void return_item(int r) {
	linkedlist[r].link = FREE;
	FREE = r;
}

void insert_item(int numbers[], int* list,int len) {
	int r, q, p;
	for (int i = 0; i < len; i++) {
		if (get_item(&r)) {
			linkedlist[r].number = numbers[i];  // Yeni öğeyi ekliyoruz
			q = EMPTY;
			p = *list;

			// Doğru konumu bulmak için mevcut listeyi tarıyoruz
			while (p != EMPTY && linkedlist[p].number < numbers[i]) {
				q = p;
				p = linkedlist[p].link;
			}

			if (q == EMPTY) {
	
				*list = r;
				linkedlist[r].link = p;
			}
			else {
				linkedlist[q].link = r;
				linkedlist[r].link = p;
			}
		}
		else {
			printf("\nYeterli boş alan yok!!");
		}
	}
}

void delete_item(int numbers[], int* list) {
	int q, p;
	q = EMPTY;
	p = *list;
	int l;

	while (p != EMPTY ) {
		q = p;
		p = linkedlist[p].link;
	}

	if (p == EMPTY ) {
		printf("\n%s cannot be found!!", numbers);
	} else if (q == EMPTY) {
		*list = linkedlist[p].link;
		return_item(p);
	} else {
		linkedlist[q].link = linkedlist[p].link;
		return_item(p);
	}
}

void print() {
	printf("\nFull array:\n");
	printf("index\tname\tlink\n");
	for (int i = 0; i < MAX_LIST; i++)
	{
		printf("%d\t%d\t%d\n", i, linkedlist[i].number, linkedlist[i].link);
	}
	printf("\n first not Full array:\n");
	int position = 0;
	int j = 0;
	for (int i = 0; i < MAX_LIST; i++) {
		if (linkedlist[i].link == EMPTY) { // En son düğümü bul
			position = i; // Son elemanın pozisyonu
			reverselinkedlist[j].number = linkedlist[i].number;
			reverselinkedlist[j].link = -1; // Yeni son elemanın linkini -1 yap
			j++;

			while (1) { // Bağlantıları takip ederek tersine git
				int z = -1; // Önceki elemanı bulmak için
				for (int k = 0; k < MAX_LIST; k++) {
					if (linkedlist[k].link == position) {
						z = k;
						break;
					}
				}
				if (z == -1) break; // Önceki eleman yoksa çık
				reverselinkedlist[j].number = linkedlist[z].number; // Elemanı ekle
				reverselinkedlist[j].link = j - 1; // Yeni bağlantıyı ayarla
				j++;
				position = z; // Yeni pozisyonu güncelle
			}
			break; // En son düğüm bulunduğunda işlem tamam
		}
	}
	printf("\nFull array for reverse:\n");
	printf("index\tname\tlink\n");
	for (int i = 0; i < MAX_LIST; i++)
	{
		printf("%d\t%d\t%d\n", i, reverselinkedlist[i].number, reverselinkedlist[i].link);
	}
	
	int sayaç = first;
	printf("index\tname\tlink\n");
	while (sayaç != EMPTY) {
		printf("%d\t%d\t%d\n", sayaç, linkedlist[sayaç].number, linkedlist[sayaç].link);
		sayaç = linkedlist[sayaç].link;
	}
	printf("FREE: %d\n", FREE);
	printf("First: %d\n", first);
	//printf("First2: %d\n", first2);
}

int main() {
	empty_list_maker();

	int numbers[5] = {9,2,1,4,3};
	int len = sizeof(numbers) / sizeof(numbers[0]);
	insert_item(numbers, &first,len);
	print();



	return 0;
}
