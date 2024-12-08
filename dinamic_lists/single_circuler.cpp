#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    int katsayı;
    int exponen;
    struct node* next;
};

int sayaç = 0;

void insert_item(struct node** head, int katsayı, int exponen) {
    struct node* temp = (struct node*)malloc(sizeof(struct node)); // Yeni düğüm için bellek ayır

    temp->exponen = exponen; // Yeni elemanı ekler
    temp->katsayı = katsayı;

    if (*head == NULL) {  // Eğer liste boşsa
        *head = temp;  // Başlangıç elemanını head olarak ayarla
        temp->next = *head;  // Circular bağlantıyı oluştur
    }
    else {
        struct node* current = *head;
        while (current->next != *head) {  // Liste sonuna git
            current = current->next;
        }
        current->next = temp;  // Son düğümün next'ini yeni düğüme bağla
        temp->next = *head;  // Yeni düğümün next'ini başa bağla

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

void addition(struct node** head, struct node** head2, struct node** head3) {
    struct node* head1 = *head;
    struct node* head4 = *head2;
    do {
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
    } while (head1 != *head && head4 != *head2);
    

    // head1 veya head4'ün bitmemiş kısmını ekleyelim
    while (head1 != *head) {
        insert_item(head3, head1->katsayı, head1->exponen);
        head1 = head1->next;
    }

    while (head4 != *head2) {
        insert_item(head3, head4->katsayı, head4->exponen);
        head4 = head4->next;
    }
}

void free_list(struct node** head) {
    struct node* temp;
    if (*head == NULL) return;  // Eğer liste boşsa, hiçbir şey yapma

    temp = *head;
    do {
        struct node* next = temp->next;
        free(temp);  // Geçici düğümü serbest bırak
        temp = next;
    } while (temp != *head);  // Başka bir düğüme gidene kadar devam et

    *head = NULL;  // Listeyi null yap
}

void print(struct node** head) {
    if (*head == NULL) {
        printf("Liste boş\n");
        return;
    }

    struct node* current = *head;
    printf("\ndüz list: ");

    do {
        printf("%d-%d\t", current->katsayı, current->exponen);
        current = current->next;
    } while (current != *head);  // Başta olduğumuzda dur
}

int main() {
    struct node* head = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;

    insert_item(&head, 6, 3);
    insert_item(&head, 15, 4);
    insert_item(&head, 30, 5);
    insert_item(&head, 40, 6);
    printf("\nlist 1\n");
    print(&head);

    insert_item(&head2, 7, 3);
    insert_item(&head2, 16, 4);
    insert_item(&head2, 31, 1);
    insert_item(&head2, 42, 0);
    printf("\nlist 2\n");
    print(&head2);

    addition(&head, &head2, &head3);
    printf("\ntoplanmış liste\n");
    print(&head3);

    free_list(&head);
    free_list(&head2);
    free_list(&head3);

    return 0;
}
//ver 2
#include <stdio.h>
#include <stdlib.h>

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
    temp->next = *head;

    if (*head == NULL) {
        *head = temp; // Eğer liste boşsa, head'i bu eleman yap
    } else {
        struct node* current = *head;
        // Liste sonuna kadar git
        while (current->next != *head) {
            current = current->next;
        }
        current->next = temp; // Son elemanın next'ini yeni eleman yap
    }
}

// İki polinomu toplar ve sonucu head3'te saklar
void addition(struct node** head1, struct node** head2, struct node** head3) {
    struct node* p1 = *head1;
    struct node* p2 = *head2;

    // Polinomları toplarken aynı üsleri kontrol ederiz
    do {
        switch (p1->exponen - p2->exponen) {
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
    } while (p1 != *head && p2 != *head); // Her iki polinomda da eleman olduğu sürece devam et

    // Kalan elemanları ekleyelim
    while (p1 != *head) {
        insert_item(head3, p1->katsayı, p1->exponen);
        p1 = p1->next;
    }
    while (p2 != *head) {
        insert_item(head3, p2->katsayı, p2->exponen);
        p2 = p2->next;
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

    // Polinomları ekleyelim
    printf("Polinom 1: ");
    print(poly1);

    printf("Polinom 2: ");
    print(poly2);

    // Polinomları topla
    addition(&poly1, &poly2, &result);

    // Sonucu yazdıralım
    printf("Toplanan Polinom: ");
    print(result);

    return 0;
}
//deleting ve insert yapar

#include <stdio.h>
#include <stdlib.h>

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
    if (exp1>exp2)
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
        switch (compare(p1->exponen,p2->exponen)) {
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

    do {
        insert_item(head3, p1->katsayı, p1->exponen);
        p1 = p1->next;
    } while (p1 != *head1);
    
    do{
        insert_item(head3, p2->katsayı, p2->exponen);
        p2 = p2->next;
    } while (p2 != *head2);
    
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

    delete_item(&poly2,7,3);
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
