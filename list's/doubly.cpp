#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LIST 16
#define TRUE 1
#define FALSE 0
#define EMPTY -1
struct item{
	char name[10];
	int next;
	int prev;
};
item linkedlist[MAX_LIST];
int FREE;

void empty_list_maker() {
	for (int i = 0; i < MAX_LIST; i++)
	{
		linkedlist[i].next = i + 1;
	}
	linkedlist[MAX_LIST-1].next = -1;
	linkedlist[0].prev = -1;
	FREE = 0;
}
int  get_item(int* r) {
	*r = FREE;
	FREE = linkedlist[FREE].next;
	return TRUE;
}
void insert(char item[],int *head) {
	int q, r, p;
	if (get_item(&r))
	{
		strcpy(linkedlist[r].name, item);
		//linkedlist[r].link = -1;

		p = *head;
		q = -1;
		while(p!=EMPTY && strcmp(linkedlist[p].name,item)<0)
		{
			q = p;
			p = linkedlist[p].next;
		}
		if (q==-1)
		{
			*head = r;
			linkedlist[r].prev = -1;
			linkedlist[r].next = p;
			if (p != EMPTY) { // Eğer liste boş değilse
				linkedlist[p].prev = r;
			}
		}
		else
		{
			linkedlist[r].prev = q;
			linkedlist[q].next = r;
			linkedlist[r].next = p;
			if (p != EMPTY) { // eğer sona eklenmiyorsa
				linkedlist[p].prev = r;
			}
		}

	}
}
void return_item(int r) {
	linkedlist[r].next = FREE;
	FREE = r;
}
void Delete(char item[], int* head) {
	int q, p;

	p = *head;
	q = -1;
	while (p != EMPTY && strcmp(linkedlist[p].name, item) < 0)
	{
		q = p;
		p = linkedlist[p].next;
	}
	if (q == -1)
	{
		*head = linkedlist[*head].next;
		return_item(p);
	}
	else
	{
		linkedlist[q].next = linkedlist[p].next;
		return_item(p);
	}
}
void print(int* head) {
	int head2 = *head;
	printf("tüm dizi:\n");
	printf("index	name	link     prev\n");
	for (int i = 0; i < MAX_LIST; i++)
	{
		printf("%d\t%s\t%d\t%d\n", i, linkedlist[i].name, linkedlist[i].next,linkedlist[i].prev);
	}
	int sayaç = *head;//sıralı yazdıracak
	printf("index\tname\tlink\n");
	while (sayaç != EMPTY) {
		printf("%d\t%s\t%d\t%d\n", sayaç, linkedlist[sayaç].name, linkedlist[sayaç].next,linkedlist[sayaç].prev);
		sayaç = linkedlist[sayaç].next;
	}
	printf("%d", FREE);
	printf("\n");
}
void print_reverse(int* head) {
	int sayaç = *head;//sıralı yazdıracak
	int last;
	printf("index\tname\tnext\tprev\n");
	while (sayaç != EMPTY) {
		last = sayaç;
		sayaç = linkedlist[sayaç].next;
	}
	while (last != EMPTY)
	{
		printf("%d\t%s\t%d\n", last, linkedlist[last].name, linkedlist[last].next);
		last = linkedlist[last].prev;
	} 
}
int main() {
	int head = -1;
	int head2 = -1;
	empty_list_maker();
	int sayaç = 0;
	char list[MAX_LIST][MAX_LIST] = { "al","ag", "ol","vib","bas","an","al","tak"};
	char list2[MAX_LIST][MAX_LIST] = { "mi","kal", "bel","dai" };
	
	for (int i = 0; i < 8; i++)
	{
		insert(list[i], &head);
	}
	print_reverse(&head);
	print(&head);
	for (int i = 0; i < 4; i++)
	{
		insert(list2[i], &head2);
	}
	//Delete(list[1],&head);
	print(&head2);
}
