// as 2 different list
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LIST 20
#define TRUE 1
#define FALSE 0
#define EMPTY -1
typedef struct {
	char name[10];
	//other fields
	int link;
}item;
item linkedlist[MAX_LIST];
int FREE;
int first;
int first2;

void empty_list_maker() {
	for (int i = 0; i < MAX_LIST; i++)
	{
		linkedlist[i].link = i+1;//link değerlerini 1 fazla olarak atama yap
	}
	linkedlist[MAX_LIST - 1].link = EMPTY;//son eleman linki -1 olmlaı null da -1 durumda
	FREE = 0;//bu indextir yani bellekteki yeri
	first = EMPTY;//başlangıça eleman yokken first ile son eleman aynıdır ve ikisi de -1 dedir
	first2 = EMPTY; 
}
int get_item(int* r) {
	if (FREE==EMPTY)//dizi için düşün 0 ın altında olursa eleman yoktur boş 
	{
		return FALSE;
	}
	else
	{
		*r = FREE;//bellekteki yeri döneriz
		FREE = linkedlist[FREE].link;//burada freenin index numarasını verip link adresini atayarak yeni bir free elde etmiş oluyoruz
		return TRUE;//üstte link ataması yaparak bellekteki yeri değiştirir
	}//free yeni kounumu üstte atanır
}
void return_item(int r) {
	linkedlist[r].link = FREE;
	FREE = r;
}
void insert_item(char name[], int* list)//liste bağlı listenin başını point eden bir pointer
{
	int r, q, p;
	if (get_item(&r)) {//yeni free değeri ve hala free olan kutunun indexi r olarak verilir
		strcpy(linkedlist[r].name, name);
		q = EMPTY;
		p = *list;//listenin başlangıç noktasu yani FİRST
		while (p != EMPTY && strcmp(linkedlist[p].name, name) < 0) { //compare yapılır a dan z ye olacak şekilde
			q = p;//q yani -1 e eleman eklenir burada listenin son boş kısmı atılır 
			p = linkedlist[p].link;//free gibi yeni yer değeri atanır
		}
		if (q == EMPTY) { //front değeri atanır //q null olması gerekir çünkü üstteki while bunu kontrol eder öbür türlü boş kalır q
			*list = r;//dönen r değerinmi listenin başlangıcına göre atar
			linkedlist[r].link = p;
		}
		else { //listenin ortasına atama uapar
			linkedlist[q].link = r;
			linkedlist[r].link = p;
		}
	}
	else printf("\n not enough free space!!");
}
void delete_item(char name[], int* list)
{
	int q, p;
	q = EMPTY;
	p = *list;
	int l;
	while (p != EMPTY && (l = strcmp(linkedlist[p].name, name)) < 0) { //search for the item
		q = p;
		p = linkedlist[p].link;
	}
	if (p == EMPTY || l > 0) //end of the list
		printf("\n %s cannot be found!! ", name);
	else if (q == EMPTY) { //the first item of the list will be deleted.
		*list = linkedlist[p].link;
		return_item(p);
	}
	else { //get the item pointed by ‘p’
		linkedlist[q].link = linkedlist[p].link;
		return_item(p);
	}
}
void print() {
	int sayaç = first;
	printf("tüm dizi:\n");
	for (int i = 0; i < MAX_LIST; i++)
	{
		printf("index	name	link\n");
		printf("%d\t%s\t%d\n", i, linkedlist[i].name, linkedlist[i].link);
	}
}
void print_list(int list_start) {

	printf("\nsadece dolu olan kısım:\n");
	int sayaç = list_start;
	while (sayaç != EMPTY) {
		printf("index\tname\tlink\n");
		printf("%d\t%s\t%d\n", sayaç, linkedlist[sayaç].name, linkedlist[sayaç].link);
		sayaç = linkedlist[sayaç].link;
	}
	printf("free:%d\t", FREE);
	printf("first:%d", first);
}

int main() {
	empty_list_maker();
	char name[100][100] = { "ala","agra","oli","bil","vil" };
	for (int i = 0; i < 5; i++)
	{
		insert_item(name[i],&first);
	}

	printf("1. liste:\n");
	print_list(first);
	
	char name2[100][100] = { "aina","baan","takye"};

	for (int i = 0; i < 3; i++)
	{
		insert_item(name2[i], &first2);//farklı bir first e eklersin
	}
	
	printf("2. liste:\n");
	print_list(first2);
	
	print();
	//printf("\nçıkartılmış yer\n");
	//char name2[100][100] = { "asel" };
	//delete_item(name2[0], &first);
	return 0;
}

//as one list
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
	char name[10];
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

void insert_item(char name[], int* list) {
	int r, q, p;
	if (get_item(&r)) {
		strcpy(linkedlist[r].name, name);
		q = EMPTY;
		p = *list;

		while (p != EMPTY && strcmp(linkedlist[p].name, name) < 0) {
			q = p;
			p = linkedlist[p].link;
		}

		if (q == EMPTY) {
			*list = r;
			linkedlist[r].link = p;
		} else {
			linkedlist[q].link = r;
			linkedlist[r].link = p;
		}
	} else {
		printf("\nNot enough free space!!");
	}
}

void delete_item(char name[], int* list) {
	int q, p;
	q = EMPTY;
	p = *list;
	int l;

	while (p != EMPTY && (l = strcmp(linkedlist[p].name, name)) < 0) {
		q = p;
		p = linkedlist[p].link;
	}

	if (p == EMPTY || l > 0) {
		printf("\n%s cannot be found!!", name);
	} else if (q == EMPTY) {
		*list = linkedlist[p].link;
		return_item(p);
	} else {
		linkedlist[q].link = linkedlist[p].link;
		return_item(p);
	}
}

void print_list(int list_start, const char* list_name) {
	printf("\n%s - Only filled elements:\n", list_name);
	int sayaç = list_start;
	while (sayaç != EMPTY) {
		printf("index\tname\tlink\n");
		printf("%d\t%s\t%d\n", sayaç, linkedlist[sayaç].name, linkedlist[sayaç].link);
		sayaç = linkedlist[sayaç].link;
	}
}

void print() {
	printf("\nFull array:\n");
	for (int i = 0; i < MAX_LIST; i++) {
		printf("index\tname\tlink\n");
		printf("%d\t%s\t%d\n", i, linkedlist[i].name, linkedlist[i].link);
	}
	printf("FREE: %d\n", FREE);
	printf("First: %d\n", first);
	printf("First2: %d\n", first2);
}

int main() {
	empty_list_maker();

	char name[5][10] = { "ala", "agra", "oli", "bil", "vil" };
	for (int i = 0; i < 5; i++) {
		insert_item(name[i], &first);
	}

	print();


	char name2[3][10] = { "aina", "baan", "takye" };
	for (int i = 0; i < 3; i++) {
		insert_item(name2[i], &first);// tek farkı aynı first e eklemen gerekir
	}

	print();

	return 0;
}
