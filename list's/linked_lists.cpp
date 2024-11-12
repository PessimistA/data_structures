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
	//other fields
	int link;
}item;
item linkedlist[MAX_LIST];
int FREE;
int first;

void empty_list_maker() {
	for (int i = 0; i < MAX_LIST; i++)
	{
		linkedlist[i].link = i + 1;//link değerlerini 1 fazla olarak atama yap
	}
	linkedlist[MAX_LIST - 1].link = EMPTY;//son eleman linki -1 olmlaı null da -1 durumda
	FREE = 0;//bu indextir yani bellekteki yeri
	first = EMPTY;//başlangıça eleman yokken first ile son eleman aynıdır ve ikisi de -1 dedir
}
int get_item(int* r) {
	if (FREE == EMPTY)//dizi için düşün 0 ın altında olursa eleman yoktur boş 
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
void insert_item(const char name[], int* list)//liste bağlı listenin başını point eden bir pointer
{
	int r, q, p;
	if (get_item(&r)) {//yeni free değeri ve hala free olan kutunun indexi r olarak verilir
		strcpy(linkedlist[r].name, name);
		q = EMPTY;
		p = *list;//listenin başlangıç noktasu yani FİRST
		while (p != EMPTY && strcmp(linkedlist[p].name, name) < 0) { //compare yapılır a dan z ye olacak şekilde//büyükyüt olursa z den a ya sıralar
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
	printf("tüm dizi:\n");
	printf("index	name	link\n");
	for (int i = 0; i < MAX_LIST; i++)
	{
		printf("%d\t%s\t%d\n", i, linkedlist[i].name, linkedlist[i].link);
	}
	printf("\nsadece dolu olan kısım:\n");
	int sayaç = first;//sıralı yazdıracak
	printf("index\tname\tlink\n");
	while (sayaç != EMPTY) {
		printf("%d\t%s\t%d\n", sayaç, linkedlist[sayaç].name, linkedlist[sayaç].link);
		sayaç = linkedlist[sayaç].link;
	}
	printf("free:%d", FREE);
	printf("first:%d", first);
}

int main() {
	empty_list_maker();
	char name[100][100] ={"apple", "orange", "banana", "grape", "kiwi"};
	for (int i = 0; i < 5; i++)
	{
		insert_item(name[i], &first);
	}
	print();
	delete_item(name[0], &first);
	insert_item("heyla", &first);
	print();
	return 0;
}

//locate fonksiyonu eklenmiş hali
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
	//other fields
	int link;
}item;
item linkedlist[MAX_LIST];
int FREE;
int first;

void empty_list_maker() {
	for (int i = 0; i < MAX_LIST; i++)
	{
		linkedlist[i].link = i + 1;//link değerlerini 1 fazla olarak atama yap
	}
	linkedlist[MAX_LIST - 1].link = EMPTY;//son eleman linki -1 olmlaı null da -1 durumda
	FREE = 0;//bu indextir yani bellekteki yeri
	first = EMPTY;//başlangıça eleman yokken first ile son eleman aynıdır ve ikisi de -1 dedir
}
int get_item(int* r) {
	if (FREE == EMPTY)//dizi için düşün 0 ın altında olursa eleman yoktur boş 
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
void insert_item(const char name[], int* list)//liste bağlı listenin başını point eden bir pointer
{
	int r, q, p;
	if (get_item(&r)) {//yeni free değeri ve hala free olan kutunun indexi r olarak verilir
		strcpy(linkedlist[r].name, name);
		q = EMPTY;
		p = *list;//listenin başlangıç noktasu yani FİRST
		while (p != EMPTY && strcmp(linkedlist[p].name, name) < 0) { //compare yapılır a dan z ye olacak şekilde//büyükyüt olursa z den a ya sıralar
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
	printf("tüm dizi:\n");
	printf("index	name	link\n");
	for (int i = 0; i < MAX_LIST; i++)
	{
		printf("%d\t%s\t%d\n", i, linkedlist[i].name, linkedlist[i].link);
	}
	printf("\nsadece dolu olan kısım:\n");
	int sayaç = first;//sıralı yazdıracak
	printf("index\tname\tlink\n");
	while (sayaç != EMPTY) {
		printf("%d\t%s\t%d\n", sayaç, linkedlist[sayaç].name, linkedlist[sayaç].link);
		sayaç = linkedlist[sayaç].link;
	}
	printf("free:%d", FREE);
	printf("first:%d", first);
}
void locate(char searcname[]) {
	int sayaç = first;//sıralı yazdıracak
	while (sayaç != EMPTY) {
		if (strcmp(linkedlist[sayaç].name ,searcname)==0)
		{
			printf("\nyandaki yerlerde bulunur %d\t%s\t%d\n", sayaç, linkedlist[sayaç].name, linkedlist[sayaç].link);
			break;
		}
		sayaç = linkedlist[sayaç].link;
	}
}
int main() {
	empty_list_maker();
	char name[100][100] ={"apple", "orange", "banana", "grape", "kiwi"};
	for (int i = 0; i < 5; i++)
	{
		insert_item(name[i], &first);
	}
	print();
	insert_item("heyla", &first);
	print();
	char kelime[10] = "apple";
	locate(kelime);
	return 0;
}
