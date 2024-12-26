#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LIST 20
#define TRUE 1
#define FALSE 0
#define EMPTY -1
typedef struct list1 {
	int item;
	//other fields
	int link;
	int prev;
};
int Free;
void make_list(struct list1 linkedlist[],int* head) {
	for (int i = 0; i < MAX_LIST; i++)
	{
		linkedlist[i].link = i + 1;
		linkedlist[i].item = 0;
	}
	linkedlist[MAX_LIST - 1].link = EMPTY;
	*head = EMPTY;
	Free = 0;
}

void insert(struct list1 linkedlist[], int* head,int item) {
	int q, r, p;
	r = Free;
	Free = linkedlist[Free].link;
	linkedlist[r].item = item;
	linkedlist[r].link = EMPTY;
	linkedlist[r].prev = EMPTY;
	q = EMPTY;
	p = *head;
	while (p!=EMPTY&& linkedlist[p].item>item) {//büyüktür işareti ile büyükten küçüğe sıralarsın olur
		q = p;
		p = linkedlist[p].link;
	}
	if (q==EMPTY)
	{
		*head = r;
		linkedlist[r].prev = -1;
		linkedlist[r].link = p;

		linkedlist[p].prev = r;
	}
	else
	{
		linkedlist[q].link = r;
		linkedlist[r].prev = q;
		linkedlist[p].prev = r;
		linkedlist[r].link = p;
	}
}
void insert_wanted_location(struct list1 linkedlist[], int* head, int item,int location) {
	int q, r, p;
	r = Free;
	Free = linkedlist[Free].link;
	linkedlist[r].item = item;
	linkedlist[r].link = EMPTY;
	linkedlist[r].prev = EMPTY;
	q = EMPTY;
	p = *head;
	if (location==0)
	{
		linkedlist[r].link = *head;//eski head bir sonraki eleman olur
		*head = r;//yeni head değeri eklenir
		linkedlist[r].prev = EMPTY;
	}
	else
	{
		
		for (int i = 0; i < location-2; i++)//p önceki eleman eklenilecek yerin bir öncesi
		{
			p = linkedlist[p].link;
		}
		linkedlist[r].link = linkedlist[p].link;
		linkedlist[r].prev = p;
		if (linkedlist[r].link != EMPTY) { // Check if we are not inserting at the end
			linkedlist[linkedlist[r].link].prev = r;
		}
		linkedlist[p].link = r;

	}
}
void reverse_iterative() {

}
void reverse_recursive() {

}
void return_item(struct list1 linkedlist[], int* head,int p) {
	linkedlist[p].link = Free;
	Free = p;
}
void delete_item(struct list1 linkedlist[], int* head,int item) {
	int q, p;
	q = EMPTY;
	p = *head;
	while (p!= EMPTY&& linkedlist[p].item>item) {//döngü kırıldığında yani eşit olduğunda ben p ile o andaki elemandayım bu yüzden p kullan
		q = p;//q bir önceki elemanda kalır döngü kırıldığında
		p = linkedlist[p].link;
	}
	if (q==EMPTY)
	{
		*head = linkedlist[p].link;// p kullan çünkü şu anda buradasın
		return_item(linkedlist,head,p);
	}
	else
	{
		linkedlist[q].link = linkedlist[p].link;
		return_item(linkedlist, head, p);
	}
}
int locate(struct list1 linkedlist[], int* head, int item) {
	int position = 1;
	int q, p;
	q = EMPTY;
	p = *head;
	while (p != EMPTY && linkedlist[p].item > item) {//döngü kırıldığında yani eşit olduğunda ben p ile o andaki elemandayım bu yüzden p kullan
		q = p;//q bir önceki elemanda kalır döngü kırıldığında
		p = linkedlist[p].link;
		position++;
	}
	return position;
}
void print(struct list1 linkedlist[], int* head) {
	int current = *head;
	int last;
	while (current!= EMPTY){
		last = current;
		printf("%d %d %d %d", current, linkedlist[current].item, linkedlist[current].link,linkedlist[current].prev);
		current = linkedlist[current].link;
		printf("\n");
	}printf("\n");
	printf("print reverse\n");
	while (last != EMPTY) {
		printf("%d %d %d %d", last, linkedlist[last].item, linkedlist[last].link, linkedlist[last].prev);
		last = linkedlist[last].prev;
		printf("\n");
	}printf("\n");
}
void print_normal(struct list1 linkedlist[], int* head) {
	printf("long one\n");
	for (int i = 0; i < MAX_LIST; i++)
	{
		printf("%d %d %d", i, linkedlist[i].item, linkedlist[i].link);
		printf("\n");
	}
	printf("\n");
}
int main() {
	struct list1 linkedlist[MAX_LIST];
	int head = 0;//aynı head ile ikinci diziyi eklersen ilk diziye ekler ve kuralı korur
	int head2 = 0;//yeni bir head değeri ve o diziye ait bir başka -1 değeri ortaya çıkar
	make_list(linkedlist,&head);
	insert(linkedlist, &head, 4);
	insert(linkedlist, &head, 1);
	insert(linkedlist, &head, 2);
	insert(linkedlist, &head, 9);
	insert(linkedlist, &head, 5);
	insert(linkedlist, &head, 6);
	insert(linkedlist, &head, 3);

	print(linkedlist, &head);
	print_normal(linkedlist, &head);

	//delete_item(linkedlist, &head, 4);
	//delete_item(linkedlist, &head, 9);
	//delete_item(linkedlist, &head, 1);

	print(linkedlist, &head);
	printf("position index= %d\n",locate(linkedlist,&head,9));

	//insert_wanted_location(linkedlist, &head, 7, 3);
	//insert_wanted_location(linkedlist, &head, 8, 3);
	print(linkedlist, &head);
	return 0;
}
