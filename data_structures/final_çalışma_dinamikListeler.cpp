#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
	int number;
	node* next;
};
void insert_item_to_left(node** head,int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	temp->next = *head;//geriye sarıyormuş gibi düşün sola doğru eklenir ama sola eklediğinin nexti sağı gösterir
	*head = temp;//yeni head değerini atama
}
void insert_item_to_right(node** head, int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	temp->next = NULL;//geriye sarıyormuş gibi düşün sola doğru eklenir ama sola eklediğinin nexti sağı gösterir
	if (*head==NULL)
	{
		*head = temp;
	}
	else
	{
		node* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
		current = temp;
	}
}
void insert_item_sorted(node** head, int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	temp->next = NULL;//geriye sarıyormuş gibi düşün sola doğru eklenir ama sola eklediğinin nexti sağı gösterir
	if (*head == NULL || (*head)->number >= item)//küçük istiyorsun bu büyük alttaki küçük işareti olacak
	{
		temp->next = *head;
		*head = temp;
	}
	else
	{
		node* current = *head;
		while (current->next != NULL && current->next->number < item) {
			current = current->next;
		}
		current->next = temp;
		current = temp;
	}
}
void insert_wanted_location(node** head, int item,int location) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	temp->next = NULL;//geriye sarıyormuş gibi düşün sola doğru eklenir ama sola eklediğinin nexti sağı gösterir
	if (location == 1)
	{
		temp->next = *head;
		*head = temp;
	}
	else
	{
		node* current = *head;
		for (int i = 1; i <= location - 2; i++) {
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
		current = temp;
	}
}
void delete_wanted_location(node** head,int location) {
	if (location == 1)
	{
		*head = (*head)->next;
	}
	else
	{
		node* current = *head;
		for (int i = 1; i <= location - 2; i++) {
			current = current->next;
		}
		current->next = current->next->next;
		
	}
}
void delete_wanted_item(node** head, int item) {
	node* current = *head;
	while (current->next != NULL) {
		if (current->next->number ==item)
		{
			current->next = current->next->next;
			return;
		}
		current=current->next;
	}
}
void delete_sorted(node** head, int count) {//sırasız dizide en büyük n elemanı siler
	for (int i = 0; i < count; i++)
	{
		node* max_node = *head; // max_node başlangıçta listenin ilk elemanını işaret ediyor
		node* current = *head;
		node* pre = NULL;
		while (current->next != NULL) {

			if (max_node->number < current->next->number) {

				pre = current;
				max_node = current->next; // max_node en büyük elemanı işaret eder
			}
			current = current->next;
		}
		pre->next = max_node->next;
	}
}
struct node* reverse_recursive(struct node* head) {
	// Eğer liste boşsa veya sadece bir eleman varsa, ters çevirmeye gerek yok
	if (head == NULL || head->next == NULL) {
		return head;
	}

	// Kalan listeyi ters çevir
	struct node* new_head = reverse_recursive(head->next);

	// Mevcut düğümü ters çevir
	head->next->next = head;//ters çevirme işlemini burası yapar head değerinin yönünü değiştire değiştire en son head değerini elde ederiz
	head->next = NULL;

	return new_head; // Yeni baş düğümü döndür
}
struct node* reverse_iterative(struct node* head) {

	struct node* prev = NULL; // Bir önceki düğüm
	struct node* current = head; // Şu anki düğüm
	struct node* next = NULL; // Sonraki düğüm

	while (current != NULL) {
		next = current->next;    // Sonraki düğümü sakla
		current->next = prev;    // Mevcut düğümün yönünü değiştir
		prev = current;          // Bir sonraki iterasyonda prev, current olur
		current = next;          // current bir sonraki düğüme geçer
	}

	return prev; // Yeni baş düğümü döndür
}
void print(node* head) {
	node* head1 = head;
	printf("list: ");
	while (head1 != NULL) {
		printf("%d \t", head1->number);
		head1 = head1->next;
	}
	printf("\n");
}

int main() {
	node* head = NULL;
	node* head1 = NULL;
	node* head3 = NULL;
	node* head4 = NULL;
	insert_item_to_left(&head,6);
	insert_item_to_left(&head,7);
	insert_item_to_left(&head, 8);
	insert_item_to_left(&head, 9);
	insert_item_to_left(&head, 1);
	insert_item_to_left(&head, 10);

	insert_item_to_right(&head1, 6);
	insert_item_to_right(&head1, 7);
	insert_item_to_right(&head1, 8);
	insert_item_to_right(&head1, 9);
	insert_item_to_right(&head1, 1);
	insert_item_to_right(&head1, 10);

	insert_wanted_location(&head3, 10, 1); // 1. sıraya ekle
	insert_wanted_location(&head3, 20, 2); // 2. sıraya ekle
	insert_wanted_location(&head3, 15, 2); // 2. sıraya ekle
	insert_wanted_location(&head3, 5, 1);  // 1. sıraya ekle
	
	insert_item_sorted(&head4, 2);
	insert_item_sorted(&head4, 1);
	insert_item_sorted(&head4, 4);
	insert_item_sorted(&head4, 7);
	print(head);
	print(head1);
	print(head3);
	print(head4);
	delete_sorted(&head1, 2);
	print(head1);
	//printf("reverse\n");
	//node* head5 = reverse_iterative(head4);
	//node* head6 = reverse_recursive(head3);
	//print(head5);
	//print(head6);
	//delete_wanted_location(&head3, 4);
	//delete_wanted_item(&head3, 10);
	//print(head3);

	return 0;
}

//stack ve queue
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
	int number;
	node* next;
};
void push(node** head,int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	temp->next = *head;//geriye sarıyormuş gibi düşün sola doğru eklenir ama sola eklediğinin nexti sağı gösterir
	*head = temp;//yeni head değerini atama
}
void pop(node** head) {
	*head = (*head)->next;
} 
void enqueue(node** head, int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp şu anki düğümüm
	temp->number = item;
	if (*head==NULL)
	{
		temp->next = *head;
		*head = temp;
	}
	else
	{
		node* current = *head;
		while (current->next!=NULL) {
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
	}
}
void dequeue(node** head) {
	node* current = *head;
	while (current->next->next != NULL) {
		current = current->next;
	}
	current->next= NULL;
}

void print(node* head) {
	node* head1 = head;
	printf("list-stack: ");
	while (head1 != NULL) {
		printf("%d  \t", head1->number);
		head1 = head1->next;
	}
	printf("\n");
}

int main() {
	node* head = NULL;
	node* head2 = NULL;
	push(&head,6);
	push(&head,7);
	push(&head, 8);
	push(&head, 9);
	push(&head, 1);
	push(&head, 10);
	print(head);
	pop(&head);
	pop(&head);
	pop(&head);
	print(head);

	enqueue(&head2, 1);
	enqueue(&head2, 2);
	enqueue(&head2, 3);
	enqueue(&head2, 4);
	enqueue(&head2, 5);
	enqueue(&head2, 6);
	print(head2);
	dequeue(&head2);
	dequeue(&head2);
	dequeue(&head2);
	print(head2);

	return 0;
}

//doubly
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node {
	int value;
	node* next;
	node* prev;
};


void insert_from_left(node** head, int value) {
	node* temp = (node*)malloc(sizeof(node));
	temp->value = value;
	if (*head != NULL)
	{
		(*head)->prev = temp;
	}
	temp->next=* head;
	*head = temp;
	temp->prev = NULL;

}
void insert_from_right(node** head, int value) {
	node* temp = (node*)malloc(sizeof(node));
	temp->value = value;
	temp->next = NULL;
	if (*head==NULL)
	{
		*head = temp;
		temp->prev = NULL;
	}
	else
	{
		node* current = *head;
		while (current->next!=NULL) {
			current=current->next;
		}
		current->next = temp;
		temp->prev = current;
	}
}
void insert_nLocation_(node** head, int value, int location) {
	node* temp = (node*)malloc(sizeof(node));
	node* current = *head;
	temp->value = value;
	if (location==1)
	{
		temp->next = *head;//eski head değeri 2. sıraya gelsin diye
		*head = temp;
		(*head)->prev = NULL;
	}
	else
	{
		for (int i = 1; i <= location-2; i++)
		{
			current = current->next;
		}
		temp->next = current->next;
		if (current->next != NULL)
			current->next->prev = temp;
		current->next = temp;
		temp->prev = current;
	}


}
struct node* recursive(node* current) {
	if (current == NULL || current->next == NULL) {
		return current; // Base case
	}

	// Recursive çağrı
	struct node* new_head = recursive(current->next);

	// Bağlantıları ters çevir
	current->next->next = current;
	current->prev = current->next;
	current->next = NULL;

	return new_head;
}
struct node* iterative(node** head) {
	node* current = *head;
	node* temp = NULL;
	while (current != NULL) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp != NULL)
	{
		*head = temp->prev;
	}
	return *head;
}
void delete_from_beginning(node** head) {
	*head = (*head)->next;
	(*head)->prev = NULL;
	
}
void delete_from_last(node** head) {
	node* current = *head;
	while (current->next->next != NULL) {
		current = current->next;
	}
	current->next = NULL;

}
void delete_nLocation(node** head, int location) {
	node* current = *head;
	if (location == 1)
	{
		(*head)->next->prev = NULL;
		*head = (*head)->next;
		return;
	}
	for (int i = 1; i <= location-2; i++)
	{
		current = current->next;
	}
	current->next->next->prev = current;
	current->next = current->next->next;
}

void print(node** head) {
	node* current1 = *head;
	printf("list: ");
	while (current1 != NULL) {//next kullandığından bu kısım tam basilmaz
		printf("%d -> ", current1->value);
		current1 = current1->next;
	}
	printf("NULL\n");
	//printf("\n");
	//node* current = *head;
	//while (current->next != NULL) {
	//	current = current->next;
	//}
	//printf("list reverse: ");
	//while (current!=NULL) {
	//	printf("%d -> ", current->value);
	//	current = current->prev;
	//}
	//printf("NULL\n");
}

int main() {
	node* head = NULL;
	insert_from_left(&head, 2);
	insert_from_left(&head, 4);
	insert_from_left(&head, 5);
	insert_from_left(&head, 6);
	delete_from_beginning(&head);
	print(&head);

	node* head2 = NULL;
	insert_from_right(&head2, 2);
	insert_from_right(&head2, 3);
	insert_from_right(&head2, 7);
	insert_from_right(&head2, 8);
	//delete_from_last(&head2);
	print(&head2);
	//head2 = iterative(&head2);
	////head2 = recursive(head2);
	//print(&head2);

	printf("ucuncu\n");
	node* head3 = NULL;
	insert_nLocation_(&head3, 1, 1);
	insert_nLocation_(&head3, 2, 2);
	insert_nLocation_(&head3, 3, 3);
	insert_nLocation_(&head3, 4, 2);
	print(&head3);
	delete_nLocation(&head3, 2);
	print(&head3);

	return 0;
}


//multiple stack new 

#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
	int number;
	node* next;
};

typedef struct {
	int value;
};
typedef struct stack* stack_pointer;
typedef struct stack {
	int item;
	stack* next;
};
stack_pointer top[10];

void push(stack_pointer* top, int item) {
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->item = item;
	temp->next = *top;
	*top = temp;
}
void pop(stack_pointer* top) {
	if (*top == NULL)
	{
		printf("stack is empty\n");
	}
	*top = (*top)->next;
}
void şekilliprint() {
	for (int i = 0; i < 10; i++)
	{
		stack* current = top[i];
		printf("list: ");
		while (current != NULL) {
			printf("%d -> ", current->item);
			current = current->next;
		}
		printf("NULL\n");
	}
}
void print(stack_pointer* top) {
	stack* current = *top;
	printf("list: ");
	while (current != NULL) {
		printf("%d -> ", current->item);
		current = current->next;
	}
	printf("NULL\n");
}
int main() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int sayı = rand() % 9 + 1;
			push(&top[i], sayı);
		}
	}
	şekilliprint();
	return 0;
}


//polinom için olan düzeltilmiş kod
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanýyorsanýz bu satýr gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct node {
    int katsayı;      // Polinom katsayısı
    int exponen;      // Polinom üssü
    struct node* next; // Bir sonraki düğüme işaretçi
};

// Circular linked list'e yeni eleman ekler
void insert_item(struct node** head, int katsayı, int exponen) {
    struct node* temp = (struct node*)malloc(sizeof(struct node)); // Yeni bir düğüm oluştur
    temp->katsayı = katsayı;
    temp->exponen = exponen;
    temp->next = NULL;
    if (*head == NULL) {
        *head = temp; // Eğer liste boşsa, head'i bu eleman yap
        temp->next = *head;
    }
    else {
        struct node* current = *head;
        while (current->next != *head) { // Döngüde dolaş
            current = current->next;
        }
        current->next = temp; // Son elemanın next'ini yeni eleman yap
        current = temp;
        temp->next = *head;
    }
}
void delete_item(struct node** head, int katsayi, int exponen) {
    if (*head == NULL) {
        printf("Liste boş, silinecek eleman yok.\n");
        return;
    }

    struct node* current = *head;
    struct node* prev = NULL;

    do {
        if (current->katsayı == katsayi && current->exponen == exponen) {
            if (current == *head) { // Eğer silinecek eleman head ise
                struct node* temp = current;
                // Son elemanın next'ini güncelle
                struct node* tail = *head;
                while (tail->next != *head) {
                    tail = tail->next;
                }
                *head = current->next;
                tail->next = *head;
            }
            else { // Head değilse
                prev->next = current->next;
                free(current);
            }
            return; // Silme işlemi tamamlanınca çık
        }
        prev = current;
        current = current->next;
    } while (current != *head);
}
int compare(int exp1, int exp2) {
    if (exp1 > exp2)
    {
        return 1;
    }
    else if (exp2 > exp1)
    {
        return -1;
    }
    else if (exp1 == exp2)
    {
        return 0;
    }
}
// İki polinomu toplar ve sonucu head3'te saklar
void addition(struct node** head1, struct node** head2, struct node** head3) {
    struct node* p1 = *head1;
    struct node* p2 = *head2;

    // Polinomları toplarken aynı üsleri kontrol ederiz
    do {
        switch (compare(p1->exponen, p2->exponen)) {
        case 0:
            // Aynı üssü olan terimler, katsayıları toplanır
            insert_item(head3, p1->katsayı + p2->katsayı, p1->exponen);
            p1 = p1->next;
            p2 = p2->next;
            break;
        case 1:
            // p1'in üssü büyükse, p1'i ekleriz
            insert_item(head3, p1->katsayı, p1->exponen);
            p1 = p1->next;
            break;
        case -1:
            // p2'nin üssü büyükse, p2'yi ekleriz
            insert_item(head3, p2->katsayı, p2->exponen);
            p2 = p2->next;
            break;
        }
    } while (p1 != *head1 && p2 != *head2); // Her iki polinomda da eleman olduğu sürece devam et

    for (; p1 != *head1; p1 = p1->next) {
        insert_item(head3, p1->katsayı, p1->exponen);
    }

    for (; p2 != *head2; p2 = p2->next) {
        insert_item(head3, p2->katsayı, p2->exponen);
    }
}

// Circular linked list'teki tüm elemanları yazdırır
void print(struct node* head) {
    if (head == NULL) {
        printf("Liste boş\n");
        return;
    }

    struct node* current = head;
    do {
        printf("%dx^%d ", current->katsayı, current->exponen);
        current = current->next;
    } while (current != head); // Liste başına dönene kadar yazdır
    printf("\n");
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* result = NULL;

    // Polinom 1: 6x^3 + 15x^4 + 30x^5 + 40x^6
    insert_item(&poly1, 6, 3);
    insert_item(&poly1, 15, 4);
    insert_item(&poly1, 30, 5);
    insert_item(&poly1, 40, 6);

    // Polinom 2: 7x^3 + 16x^4 + 31x^1 + 42x^0
    insert_item(&poly2, 7, 3);
    insert_item(&poly2, 16, 4);
    insert_item(&poly2, 31, 1);
    insert_item(&poly2, 42, 0);

    //delete_item(&poly2, 42, 0);
    // Polinomları ekleyelim
    printf("Polinom 1: ");
    print(poly1);

    printf("Polinom 2: ");
    print(poly2);

    // Polinomları topla
    addition(&poly1, &poly2, &result);
    printf("hele");
    // Sonucu yazdıralım
    printf("Toplanan Polinom: ");
    print(result);

    return 0;
}
