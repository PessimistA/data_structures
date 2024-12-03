#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    int katsayı;
    int exponen;
    struct node* next;
    struct node* prev;
};

int sayaç = 0;

void insert_item(struct node** head, int katsayı, int exponen) {
    struct node* temp = (struct node*)malloc(sizeof(struct node)); // Yeni düğüm için bellek ayır

    temp->exponen = exponen; // Yeni elemanı ekler
    temp->katsayı = katsayı;

    if (*head == NULL) {  // Eğer liste boşsa
        *head = temp;  // Başlangıç elemanını head olarak ayarla
        temp->next = *head;  // Circular bağlantıyı oluştur
        temp->prev = *head;  // Prev işaretçisi de başa gitsin
    }
    else {
        struct node* current = *head;
        while (current->next != *head) {  // Liste sonuna git
            current = current->next;
        }
        current->next = temp;  // Son düğümün next'ini yeni düğüme bağla
        temp->prev = current;  // Yeni düğümün prev işaretçisini eski son düğüme bağla
        temp->next = *head;  // Yeni düğümün next'ini başa bağla
        (*head)->prev = temp;  // Baş düğümün prev işaretçisini yeni düğüme bağla
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
    int katsayı;         // Polinom katsayısı
    int exponen;         // Polinom üssü
    struct node* leftlink;  // Önceki düğüm (prev)
    struct node* rightlink; // Sonraki düğüm (next)
};

typedef struct node* node_pointer;

// Yeni bir düğüm oluşturur ve bir polinom terimi olarak ekler
void insert_item(node_pointer* head, int katsayı, int exponen) {
    node_pointer new_node = (node_pointer)malloc(sizeof(struct node));
    new_node->katsayı = katsayı;
    new_node->exponen = exponen;
    new_node->leftlink = new_node;   // Circular doubly linked list olduğu için kendini işaret eder
    new_node->rightlink = new_node;

    if (*head == NULL) {
        *head = new_node;
    }
    else {
        node_pointer last = (*head)->leftlink; // Listenin sonuna git
        last->rightlink = new_node;    // Son düğümün rightlink'ini yeni düğüm yap
        new_node->leftlink = last;     // Yeni düğümün leftlink'ini son düğüm yap
        new_node->rightlink = *head;   // Yeni düğümün rightlink'ini başa işaret et
        (*head)->leftlink = new_node;  // Baş düğümün leftlink'ini yeni düğüme işaret et
    }
}

// Polinomları toplar ve sonucu head3'te saklar
void addition(node_pointer* head1, node_pointer* head2, node_pointer* head3) {
    node_pointer p1 = *head1;
    node_pointer p2 = *head2;

    // Polinomları toplama işlemi
    do {
        if (p1->exponen == p2->exponen) {
            // Aynı üssü olan terimler, katsayıları toplanır
            insert_item(head3, p1->katsayı + p2->katsayı, p1->exponen);
            p1 = p1->rightlink;
            p2 = p2->rightlink;
        }
        else if (p1->exponen > p2->exponen) {
            // p1'in üssü büyükse, p1'i ekleriz
            insert_item(head3, p1->katsayı, p1->exponen);
            p1 = p1->rightlink;
        }
        else {
            // p2'nin üssü büyükse, p2'yi ekleriz
            insert_item(head3, p2->katsayı, p2->exponen);
            p2 = p2->rightlink;
        }
    } while (p1 != *head1 && p2 != *head2);


    do
    {
        insert_item(head3, p1->katsayı, p1->exponen);
        p1 = p1->rightlink;
    } while (p1 != *head1);
    do
    {
        insert_item(head3, p2->katsayı, p2->exponen);
        p2 = p2->rightlink;
    } while (p2 != *head2);

}

// Listeyi yazdırma fonksiyonu
void print(node_pointer head) {
    if (head == NULL) return;

    node_pointer current = head;
    do {
        printf("%d x^%d ", current->katsayı, current->exponen);
        current = current->rightlink;
    } while (current != head);
    printf("\n");
}

// Belleği serbest bırakma fonksiyonu
void free_list(node_pointer* head) {
    if (*head == NULL) return;  // Eğer liste boşsa, hiçbir şey yapma
    node_pointer current = *head;
    node_pointer next_node;
    do {
        next_node = current->rightlink;
        free(current);
        current = next_node;
    } while (current != *head);
    *head = NULL;  // Listeyi null yap
}

int main() {
    node_pointer head1 = NULL;
    node_pointer head2 = NULL;
    node_pointer head3 = NULL;

    // Polinom 1: 3x^6 + 15x^4 + 6x^3
    insert_item(&head1, 3, 6);
    insert_item(&head1, 15, 4);
    insert_item(&head1, 6, 3);

    // Polinom 2: 7x^3 + 16x^4 + 31x^1 + 42x^0
    insert_item(&head2, 7, 3);
    insert_item(&head2, 16, 4);
    insert_item(&head2, 31, 1);
    insert_item(&head2, 42, 0);

    // Polinomları yazdır
    printf("Polinom 1: ");
    print(head1);
    printf("Polinom 2: ");
    print(head2);

    // Polinomları topla
    addition(&head1, &head2, &head3);

    // Toplanan polinomu yazdır
    printf("Toplanan Polinom: ");
    print(head3);

    // Belleği serbest bırak
    free_list(&head1);
    free_list(&head2);
    free_list(&head3);

    return 0;
}
