#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS 

#define MAX_LIST 10
#define TRUE 1
#define FALSE 0
#define EMPTY -1
typedef struct {
	int number;
	//other fields
	int link;
}item;
item linkedlist[MAX_LIST];
int FREE;
int first;
int first2;

void empty_list_maker() {
	for (size_t i = 0; i < MAX_LIST; i++)
	{
		linkedlist[i].link = i + 1;
	}
	linkedlist[MAX_LIST - 1].link = -1;
	FREE = 0;
	first = -1;
}
int get_item(int* r) {
	*r = FREE;
	FREE = linkedlist[FREE].link;
	return 1;
}

void instert(int item, int* first) {
	int q, r, p;
	if (get_item(&r))
	{
		linkedlist[r].number = item;
		p = *first;
		q = -1;
		while (p != -1 && linkedlist[p].number < item) {
			q = p;
			p = linkedlist[p].link;
		}
		if (q == -1)
		{
			linkedlist[r].link = p;
			*first = r;
		}
		else
		{
			linkedlist[q].link = r;//q önceki eleman r þimdiki eleman
			linkedlist[r].link = p;//p sonraki eleman
		}
	}
}
void deletemin(int* first) {
	int temp = *first;
	*first = linkedlist[*first].link;
	linkedlist[temp].link = FREE;
	FREE = temp;
}
void print() {
	int sayaç = first;
	printf("tüm dizi:\n");
	printf("index	name	link\n");
	for (int i = 0; i < MAX_LIST; i++)
	{
		printf("%d\t%d\t%d\n", i, linkedlist[i].number, linkedlist[i].link);
	}
}
void print_list(int list_start) {

	printf("\nsadece dolu olan kýsým:\n");
	printf("index\tname\tlink\n");
	int sayaç = list_start;
	while (sayaç != EMPTY) {
		printf("%d\t%d\t%d\n", sayaç, linkedlist[sayaç].number, linkedlist[sayaç].link);
		sayaç = linkedlist[sayaç].link;
	}
	printf("free:%d\t", FREE);
	printf("first:%d", first);
}

int main() {
	empty_list_maker();
	instert(3, &first);
	instert(34, &first);
	instert(1, &first);
	instert(32, &first);
	instert(13, &first);
	instert(35, &first);
	print();
	print_list(first);
	deletemin(&first);
	print();
	print_list(first);
}