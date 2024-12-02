#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
	int katsayı;
	int exponen;
	node* next;
	node* prev;
};
int sayaç = 0;
void insert_item(node** head,int katsayı,int exponen) {
	struct node* temp = (node*)malloc(sizeof(node));//temp tüm iki kutucuğu ifade eder

	temp->exponen = exponen;//yeni elemanı ekler
	temp->katsayı = katsayı;
	temp->next = NULL;
	if (*head==NULL)
	{
		*head = temp;
	}
	else
	{
		struct node* current = *head;
		while (current->next!=NULL) {
			current = current->next;
		}
		current->next = temp;
		current = temp;
	}
	sayaç++;
}
int compare(int exponen, int exponen2) {
	if (exponen > exponen2)
	{
		return 1;
	}
	if (exponen == exponen2)
	{
		return 0;
	}
	if (exponen < exponen2)
	{
		return -1;
	}
}

void addition(node** head, node** head2,node** head3) {
	struct node* head1 = *head;
	struct node* head4 = *head2;
	while (head1 != NULL && head4 != NULL) {
		switch (compare(head1->exponen, head4->exponen)) {
		case 1:  // head1'in üssü büyük
			insert_item(head3, head1->katsayı, head1->exponen);
			head1 = head1->next;
			break;

		case -1: // head2'nin üssü büyük
			insert_item(head3, head4->katsayı, head4->exponen);
			head4 = head4->next;
			break;

		case 0:  // Üsler eşit
			insert_item(head3, head1->katsayı + head4->katsayı, head1->exponen);
			head1 = head1->next;
			head4 = head4->next;
			break;
		}
	}
	while (head1 != NULL) {
		insert_item(head3, head1->katsayı, head1->exponen);
		head1 = head1->next;
	}

	while (head4 != NULL) {
		insert_item(head3, head4->katsayı, head4->exponen);
		head4 = head4->next;
	}
}

void free_list(node** head) {
	struct node* temp;
	while (*head != NULL) {
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
void print(node** head) {

	struct node* head3 = *head;//bu ilk elemanı gösterir atama yapınca head 1 de orayı gösteriyor o elemanın  nexti sonuçta sonraki elemanı gösterir 
	printf("\ndüz list: ");
	while (head3 != NULL) {
		printf("%d-%d\t", head3->katsayı, head3->exponen);
		head3 = head3->next;
	}
}

int main() {
	node* head = NULL;
	node* head2 = NULL;
	node* head3 = NULL;
	insert_item(&head,6,3);
	insert_item(&head,15,4);
	insert_item(&head,30,5);
	insert_item(&head,40,6);
	printf("\nlist 1\n");
	print(&head);
	insert_item(&head2, 7, 3);
	insert_item(&head2, 16, 4);
	insert_item(&head2, 31, 1);
	insert_item(&head2, 42, 0);
	printf("\nlist 2");
	print(&head2);
	addition(&head, &head2, &head3);
	printf("\ntoplanmış liste\n");
	print(&head3);
	free_list(&head);
	free_list(&head2);
	free_list(&head3);
	
	return 0;
}
//ver2
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define EMPTY -1

// İç listelerde kullanılacak düğüm yapısı
struct inner_node {
    int exponen;
    int katsayı;
    struct inner_node* next;
};

// Ana listede kullanılacak düğüm yapısı
struct master_node {
    struct inner_node* inner_head; // İç listenin başını tutan pointer
    int link;
};

int FREE = -1;
int first = EMPTY;
struct master_node linkedlist[MAX];

// Listeyi boş hale getirir
void empty_list_maker() {
    for (int i = 0; i < MAX; i++) {
        linkedlist[i].link = i + 1;
    }
    linkedlist[MAX - 1].link = EMPTY;
    FREE = 0;
    first = EMPTY;
}


// Ana listeye, iç listenin head pointer'ını ekler
void insert_master(int* head, struct inner_node* inner_head) {
    int r = FREE;
    if (r == EMPTY) {
        printf("Boş yer kalmadı!\n");
        return;
    }
    FREE = linkedlist[r].link;
    linkedlist[r].inner_head = inner_head;
    linkedlist[r].link = EMPTY;

    if (*head == EMPTY) {
        *head = r;
    }
    else {
        int p = *head;
        while (linkedlist[p].link != EMPTY) {
            p = linkedlist[p].link;
        }
        linkedlist[p].link = r;
    }
}

void insert_inner(inner_node** head, int katsayı, int exponen) {
    struct inner_node* temp = (struct inner_node*)malloc(sizeof(struct inner_node));
    temp->exponen = exponen;
    temp->katsayı = katsayı;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    }
    else {
        struct inner_node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}
int compare(int exponen1, int exponen2) {
    if (exponen1 > exponen2) return 1;
    if (exponen1 < exponen2) return -1;
    return 0;
}

// İç listeyi serbest bırakır
void free_inner_list(struct inner_node* head) {
    struct inner_node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void addition(int head) {


    struct inner_node* current1 = linkedlist[head].inner_head;
    struct inner_node* current2 = linkedlist[linkedlist[head].link].inner_head;
    struct inner_node* result = NULL;

    while (current1 != NULL && current2 != NULL) {
        switch (compare(current1->exponen, current2->exponen)) {
        case 1:
            insert_inner(&result, current1->katsayı, current1->exponen);
            current1 = current1->next;
            break;
        case -1:
            insert_inner(&result, current2->katsayı, current2->exponen);
            current2 = current2->next;
            break;
        case 0:
            insert_inner(&result, current1->katsayı + current2->katsayı, current1->exponen);
            current1 = current1->next;
            current2 = current2->next;
            break;
        }
    }

    // Kalan elemanları ekle
    while (current1 != NULL) {
        insert_inner(&result, current1->katsayı, current1->exponen);
        current1 = current1->next;
    }
    while (current2 != NULL) {
        insert_inner(&result, current2->katsayı, current2->exponen);
        current2 = current2->next;
    }

    printf("Toplama Sonucu:\n");
    struct inner_node* temp = result;
    while (temp != NULL) {
        printf("%dx^%d -> ", temp->katsayı, temp->exponen);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int master_head = EMPTY;
    empty_list_maker();

    // İç listelerden biri
    struct inner_node* inner_list1 = NULL;
    insert_inner(&inner_list1, 1,2);
    insert_inner(&inner_list1, 2,3);
    insert_inner(&inner_list1, 3,4);

    // İç listelerden diğeri
    struct inner_node* inner_list2 = NULL;
    insert_inner(&inner_list2, 10,2);
    insert_inner(&inner_list2, 20,5);

    // Ana listeye iç listelerin head pointer'larını ekle
    insert_master(&master_head, inner_list1);
    insert_master(&master_head, inner_list2);

    addition(master_head);

    // Belleği serbest bırak
    free_inner_list(inner_list1);
    free_inner_list(inner_list2);

    return 0;
}
