//sabit arrayda head atama işlemi
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define EMPTY -1

// İç listelerde kullanılacak düğüm yapısı
struct inner_node {
    int data;
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

// İç listeye eleman ekler
void insert_inner(struct inner_node** head, int value) {
    struct inner_node* temp = (struct inner_node*)malloc(sizeof(struct inner_node));
    temp->data = value;
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

// Ana listeyi ve iç listeleri yazdırır
void print_master_list(int head) {
    int count = 0;
    int list_number = 1;
    while (head != EMPTY) {
        printf("List %d: ", list_number++);
        struct inner_node* current_inner = linkedlist[head].inner_head;
        while (current_inner != NULL) {
            printf("%d -> ", current_inner->data);
            current_inner = current_inner->next;
        }
        printf("NULL\n");
        printf("index:%d head:%d next:%d\n",count,linkedlist[head].inner_head->data, linkedlist[head].link);
        head = linkedlist[head].link;
        count++;
    }
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

int main() {
    int master_head = EMPTY;
    empty_list_maker();

    // İç listelerden biri
    struct inner_node* inner_list1 = NULL;
    insert_inner(&inner_list1, 1);
    insert_inner(&inner_list1, 2);
    insert_inner(&inner_list1, 3);

    // İç listelerden diğeri
    struct inner_node* inner_list2 = NULL;
    insert_inner(&inner_list2, 10);
    insert_inner(&inner_list2, 20);

    // Ana listeye iç listelerin head pointer'larını ekle
    insert_master(&master_head, inner_list1);
    insert_master(&master_head, inner_list2);

    // Sonuçları yazdır
    print_master_list(master_head);

    // Belleği serbest bırak
    free_inner_list(inner_list1);
    free_inner_list(inner_list2);

    return 0;
}
//ikisi de dinamic olan sistem

#include <stdio.h>
#include <stdlib.h>

// İç listelerde kullanılacak düğüm yapısı
struct inner_node {
    int data;
    struct inner_node* next;
};

// Ana listede kullanılacak düğüm yapısı
struct master_node {
    struct inner_node* inner_head; // İç listenin başını tutan pointer
    struct master_node* next;
};

// İç listeye eleman ekleyen fonksiyon
void insert_inner(struct inner_node** head, int value) {
    struct inner_node* temp = (struct inner_node*)malloc(sizeof(struct inner_node));
    temp->data = value;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        struct inner_node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

// Ana listeye, iç listenin head pointer'ını ekleyen fonksiyon
void insert_master(struct master_node** master_head, struct inner_node* inner_head) {
    struct master_node* temp = (struct master_node*)malloc(sizeof(struct master_node));
    temp->inner_head = inner_head;
    temp->next = NULL;

    if (*master_head == NULL) {
        *master_head = temp;
    } else {
        struct master_node* current = *master_head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

// Ana listeyi ve iç listeleri yazdıran fonksiyon
void print_master_list(struct master_node* master_head) {
    struct master_node* current_master = master_head;

    int list_number = 1;
    while (current_master != NULL) {
        printf("List %d: ", list_number++);
        struct inner_node* current_inner = current_master->inner_head;

        while (current_inner != NULL) {
            printf("%d -> ", current_inner->data);
            current_inner = current_inner->next;
        }
        printf("NULL\n");
        current_master = current_master->next;
    }
}

int main() {
    struct master_node* master_head = NULL;

    // İç listelerden biri
    struct inner_node* inner_list1 = NULL;
    insert_inner(&inner_list1, 1);
    insert_inner(&inner_list1, 2);
    insert_inner(&inner_list1, 3);

    // İç listelerden diğeri
    struct inner_node* inner_list2 = NULL;
    insert_inner(&inner_list2, 10);
    insert_inner(&inner_list2, 20);

    // Ana listeye iç listelerin head pointer'larını ekle
    insert_master(&master_head, inner_list1);
    insert_master(&master_head, inner_list2);

    // Sonuçları yazdır
    print_master_list(master_head);

    return 0;
}
