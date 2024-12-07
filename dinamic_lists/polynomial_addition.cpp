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

//teacher version

#include <stdio.h>
#include <stdlib.h>

typedef struct poly_node* poly_pointer;

typedef struct poly_node {
    int coef;          // Katsayı
    int expon;         // Üs
    poly_pointer link; // Sonraki düğümün adresi
} poly_node;

// Bellek kontrol makrosu
#define IS_FULL(ptr) (!(ptr))

// Üs karşılaştırma fonksiyonu
int COMPARE(int a, int b) {
    if (a < b) return -1;
    if (a == b) return 0;
    return 1;
}

// Yeni düğüm ekleme fonksiyonu
void attach(int coefficient, int exponent, poly_pointer* rear) {
    poly_pointer temp = (poly_pointer)malloc(sizeof(poly_node));
    if (IS_FULL(temp)) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    temp->coef = coefficient;
    temp->expon = exponent;
    temp->link = NULL;
    (*rear)->link = temp;
    *rear = temp;
}

// Polinom yazdırma fonksiyonu
void print_poly(poly_pointer p) {
    while (p != NULL) {
        printf("%dx^%d", p->coef, p->expon);
        p = p->link;
        if (p != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Polinom toplama fonksiyonu
poly_pointer add_poly(poly_pointer a, poly_pointer b) {
    poly_pointer front, rear, temp;
    int sum;

    rear = (poly_pointer)malloc(sizeof(poly_node));
    if (IS_FULL(rear)) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    front = rear;

    while (a && b) {
        switch (COMPARE(a->expon, b->expon)) {
            case -1:  // a'nın üssü küçük
                attach(b->coef, b->expon, &rear);
                b = b->link;
                break;
            case 0:  // Üsler eşit
                sum = a->coef + b->coef;
                if (sum) attach(sum, a->expon, &rear);
                a = a->link;
                b = b->link;
                break;
            case 1:  // a'nın üssü büyük
                attach(a->coef, a->expon, &rear);
                a = a->link;
                break;
        }
    }

    // Geri kalan elemanları ekle
    while (a) {
        attach(a->coef, a->expon, &rear);
        a = a->link;
    }
    while (b) {
        attach(b->coef, b->expon, &rear);
        b = b->link;
    }

    rear->link = NULL;

    temp = front;
    front = front->link;
    free(temp);

    return front;
}

// Belleği serbest bırakma fonksiyonu
void free_poly(poly_pointer p) {
    poly_pointer temp;
    while (p != NULL) {
        temp = p;
        p = p->link;
        free(temp);
    }
}

int main() {
    // İlk polinom: 3x^3 + 2x^2 + 1
    poly_pointer a = (poly_pointer)malloc(sizeof(poly_node));
    a->coef = 3;
    a->expon = 3;
    a->link = NULL;
    poly_pointer temp_a = a;
    attach(2, 2, &temp_a);
    attach(1, 0, &temp_a);

    // İkinci polinom: 4x^3 + 3x + 5
    poly_pointer b = (poly_pointer)malloc(sizeof(poly_node));
    b->coef = 4;
    b->expon = 3;
    b->link = NULL;
    poly_pointer temp_b = b;
    attach(3, 1, &temp_b);
    attach(5, 0, &temp_b);

    printf("Polinom 1: ");
    print_poly(a);

    printf("Polinom 2: ");
    print_poly(b);

    // Polinomları topla
    poly_pointer result = add_poly(a, b);
    printf("Toplam: ");
    print_poly(result);

    // Belleği serbest bırak
    free_poly(a);
    free_poly(b);
    free_poly(result);

    return 0;
}

//multiple top version
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;         
	int exponen;         
	struct node* next;   
} node;

typedef struct node* pointer_front; 


pointer_front top[10] = { NULL }; 

// Listeye düğüm ekleme (sondan ekleme)
void insert(pointer_front* head, int value, int exponen) {
	pointer_front temp = (node*)malloc(sizeof(node)); 
	temp->value = value;
	temp->exponen = exponen;
	temp->next = NULL;

	if (*head == NULL) {
		*head = temp;
	}
	else { 
		pointer_front current = *head;
		while (current->next != NULL) { 
			current = current->next;
		}
		current->next = temp; 
	}
}
int compare(int exponen1,int exponen2) {
	if (exponen1>exponen2)
	{
		return 1;
	}
	else if (exponen1==exponen2)
	{
		return 0;
	}
	else if (exponen1 < exponen2)
	{
		return -1;
	}
}
void addition(pointer_front* head1, pointer_front* head2,pointer_front* head3) {
	pointer_front temp1 = *head1;
	pointer_front temp2 = *head2;

	while (temp1 != NULL && temp2 != NULL) {
		switch (compare(temp1->exponen, temp2->exponen)) {
		case 1: 
			insert(head3, temp1->value, temp1->exponen);
			temp1 = temp1->next;
			break;
		case -1: 
			insert(head3, temp2->value, temp2->exponen);
			temp2 = temp2->next;
			break;
		case 0: 
			insert(head3, temp1->value + temp2->value, temp1->exponen);
			temp1 = temp1->next;
			temp2 = temp2->next;
			break;
		}
	}
	while (temp1 != NULL) {
		insert(head3, temp1->value, temp1->exponen);
		temp1 = temp1->next;
	}

	while (temp2 != NULL) {
		insert(head3, temp2->value, temp2->exponen);
		temp2 = temp2->next;
	}
}
void print(pointer_front* head) {
	pointer_front current = *head;
	printf("list: ");
	while (current != NULL) {
		printf("%d-%d -> ", current->value,current->exponen);
		current = current->next;
	}
	printf("NULL\n");
}

int main() {

	insert(&top[0], 2, 6);
	insert(&top[0], 2, 5);
	insert(&top[0], 2, 4);
	insert(&top[0], 2, 3);

	insert(&top[1], 2, 6);
	insert(&top[1], 2, 4);
	insert(&top[1], 2, 3);
	insert(&top[1], 2, 1);

	printf("first one ");
	print(&top[0]);

	printf("Second one: ");
	print(&top[1]);

	// Polinomları topla
	addition(&top[0], &top[1], &top[2]);
	printf("last one ");
	print(&top[2]);
	return 0;
}
