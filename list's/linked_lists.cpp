#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LIST 10
#define TRUE 1
#define FALSE 0
#define NULL -1
typedef struct {
	char name[5];
	//other fields
	int link;
}item;
item linkedlist[MAX_LIST];
int free;
int first;

void make_empty_list(void)
{
	int i;
	for (i = 0; i < MAX_LIST - 1; i++)
		linkedlist[i].link = i + 1; //every item points the next
	linkedlist[MAX_LIST - 1].link = NULL; //last item
	free = 0;
	first = NULL;
}
int get_item(int* r)
{
	if (free == NULL) //there is no item to get
		return FALSE;
	else {
		*r = free; //get the item which is pointed by free
		free = linkedlist[free].link; //points next free item
		return TRUE;
	}
}
void return_item(int r)
{
	linkedlist[r].link = free; //return item that is pointed by r
	free = r; //free the item
}
void insert_item(char name[], int* list)
{
	int r, q, p;
	if (get_item(&r)) {
		strcpy(linkedlist[r].name, name);
		q = NULL;
		p = *list;
		while (p != NULL && strcmp(linkedlist[p].name, name) < 0) { //search right position
			q = p;
			p = linkedlist[p].link;
		}
		if (q == NULL) { //new item is inserted to the front of the list.
			*list = r;
			linkedlist[r].link = p;
		}
		else { //new item is inserted in the middle
			linkedlist[q].link = r;
			linkedlist[r].link = p;
		}
	}
	else printf("\n not enough free space!!");
}
void delete_item(char name[], int* list)
{
	int q, p;
	q = NULL;
	p = *list;
	int l;
	while (p != NULL && (l = strcmp(linkedlist[p].name, name)) < 0) { //search for the item
		q = p;
		p = linkedlist[p].link;
	}
	if (p == NULL || l > 0) //end of the list
		printf("\n %s cannot be found!! ", name);
	else if (q == NULL) { //the first item of the list will be deleted.
		*list = linkedlist[p].link;
		return_item(p);
	}
	else { //get the item pointed by ‘p’
		linkedlist[q].link = linkedlist[p].link;
		return_item(p);
	}
}
