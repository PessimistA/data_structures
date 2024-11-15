//with buble sort
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
int FREE;
int first;
int first2;

void empty_list_maker() {
	for (int i = 0; i < MAX_LIST; i++) {
		linkedlist[i].link = i + 1;
	}
	linkedlist[MAX_LIST - 1].link = EMPTY;
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
void bublesort(int numbers[],int len) {

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (numbers[i]<numbers[j]) {
				int geç = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = geç;
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", numbers[i]);
	}
}
void insert_item(int numbers[], int* list,int len) {
	int r, q, p;
	bublesort(numbers,len);
	for (int i = 0; i < len; i++) {
		if (get_item(&r)) {
			linkedlist[r].number = numbers[i];  // Yeni öğeyi ekliyoruz
			q = EMPTY;
			p = *list;

			// Doğru konumu bulmak için mevcut listeyi tarıyoruz
			while (p != EMPTY && linkedlist[p].number < linkedlist[r].number) {
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
	int sayaç = first;
	while (sayaç != EMPTY) {
		printf("index\tname\tlink\n");
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
//without buble sort
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
int FREE;
int first;
int first2;

void empty_list_maker() {
	for (int i = 0; i < MAX_LIST; i++) {
		linkedlist[i].link = i + 1;
	}
	linkedlist[MAX_LIST - 1].link = EMPTY;
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
	for (int i = 0; i < MAX_LIST; i++)
	{
		printf("index\tname\tlink\n");
		printf("%d\t%d\t%d\n", i, linkedlist[i].number, linkedlist[i].link);
	}
	printf("\n not Full array:\n");
	int sayaç = first;
	while (sayaç != EMPTY) {
		printf("index\tname\tlink\n");
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

//sıralayan ve bastıran linked list hocanın yoluyla
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 10
#define EMPTY -1
#define TRUE 1
#define FALSE 0

struct kullan {
	int link;
	int sayı;
}dizi[Max];
int FREE ;
int first;
int first2;

void makelist() {
	for (int i = 0; i < Max; i++)
	{
		dizi[i].link = i + 1;
	}
	FREE = 0;
	first = EMPTY;
	first2 = EMPTY;
}
int get_item(int* r) {
	*r = FREE;
	FREE = dizi[FREE].link;
	return true;
}
int compare(int x, int y) {
	if (x<y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void insert_item(int value,int* list) {
	int q, r, p;
	if (get_item(&r))
	{
		dizi[r].sayı= value;
		q = EMPTY;
		p = *list;
		while (p!=EMPTY&& compare(dizi[p].sayı,value)) {
			q = p;//p değişken p yi ilk eleman olarak düşün  q ya bu değer verilip kendisi artıyor kontrol için zaten kontrolü de p ile yaparız dikkat et
			p = dizi[p].link;
		}
		if (q==EMPTY)//dizinin ilk elemanı ataması burada yapılır
		{
			*list = r;//		*list = dizi[p].link;
			dizi[r].link = p;//		return_item(p);
		}
		else
		{
			dizi[q].link = r;//		dizi[q].link = dizi[p].link;//aradan r yi çıkart
			dizi[r].link = p;//		return_item(p);
		}
	}
}
void return_item(int r) {
	dizi[r].link = FREE;
	FREE = r;
}
void delete_item(int value, int* list) {
	int q, p;
	q = EMPTY;
	p = *list;
	int i=0;
	while (p != EMPTY && (compare(dizi[p].sayı, value))!=0) {
		q = p;
		p = dizi[p].link;
	}
	if (p==EMPTY)// listenin sonundan 
	{
		printf("bulunamadı");
	}
	else if (q==EMPTY) {
		*list = dizi[p].link;
		return_item(p);//yeni free belirlenir bununla
	}
	else
	{
		dizi[q].link = dizi[p].link;//aradan r yi çıkart
		return_item(p);
	}

}
void print() {
	int sayaç = first;	
	printf("index\tisim\tlink\n");
	for (int i = 0; i < Max; i++)
	{
		printf("%d\t%d\t%d\n", i, dizi[i].sayı, dizi[i].link);
	}	printf("index\tisim\tlink\n");
	while (sayaç != EMPTY) {
		printf("%d\t%d\t%d\n", sayaç, dizi[sayaç].sayı, dizi[sayaç].link);
		sayaç = dizi[sayaç].link;
	}

}

int main() {
	makelist();
	int names[Max] = {2,1,7,3,5,4};
	for (int i = 0; i < 6; i++)
	{
		insert_item(names[i], &first);
	}
	char names2[Max] = {3};
	print();
	delete_item(names2[0], &first);
	print();
	return 0;
}
