#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10
#define EMPTY -1

// Düğüm yapısı
struct temp {
    int number; // Veriyi saklar
    int link;   // Bir sonraki düğümün indeksini saklar
};
struct temp* linkedlist;
int Free = 0;
int first = EMPTY;

// Diziyi başlat
void initialize_array() {
    int n;
    printf("n değeri giriniz");
    scanf_s("%d", &n);
    linkedlist = (temp*)malloc(n * sizeof(temp));
    for (int i = 0; i < MAX; i++) {
        linkedlist[i].link = i + 1; // Her düğüm bir sonrakini işaret eder
    }
    linkedlist[MAX - 1].link = EMPTY; // Son düğümün bağlantısı yok
    Free = 0;
    first = EMPTY;
}

// Yeni düğüm için yer ayır
int allocate_node() {
    if (Free == EMPTY) {
        printf("Liste dolu!\n");
        return EMPTY;
    }
    int r = Free;
    Free = linkedlist[Free].link;
    return r;
}

// Düğümü serbest bırak
void free_node(int index) {
    linkedlist[index].link = Free;
    Free = index;
}

// Düğümleri listeye ekle (sıralı ekleme)
void insert_item(int number) {
    int r = allocate_node();
    if (r == EMPTY) {
        return;
    }
    linkedlist[r].number = number;

    int prev = EMPTY;
    int current = first;

    // Doğru pozisyonu bul
    while (current != EMPTY && linkedlist[current].number < number) {
        prev = current;
        current = linkedlist[current].link;
    }

    if (prev == EMPTY) { // Listenin başına ekleme
        linkedlist[r].link = first;
        first = r;
    }
    else { // Araya veya sona ekleme
        linkedlist[r].link = current;
        linkedlist[prev].link = r;
    }
}

// Belirli bir değeri listeden sil
void delete_item(int number) {
    int prev = EMPTY;
    int current = first;

    while (current != EMPTY && linkedlist[current].number < number) {
        prev = current;
        current = linkedlist[current].link;
    }

    if (current == EMPTY) {
        printf("%d listede bulunamadı!\n", number);
        return;
    }

    if (prev == EMPTY) { // Baş düğümü silme
        first = linkedlist[current].link;
    }
    else { // Aradan veya sondan silme
        linkedlist[prev].link = linkedlist[current].link;
    }

    free_node(current);
}

// Listeyi yazdır
void print_list() {
    printf("Liste: ");
    int current = first;
    while (current != EMPTY) {
        printf("%d -> ", linkedlist[current].number);
        current = linkedlist[current].link;
    }
    printf("NULL\n");
}

// Diziyi yazdır (tüm düğümleri gösterir)
void print_array() {
    printf("Dizi durumu:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d\t%d\t%d\n", i, linkedlist[i].number, linkedlist[i].link);
    }
}

int main() {
    initialize_array();

    insert_item(10);
    insert_item(20);
    insert_item(15);

    printf("Liste durumu:\n");
    //print_list();
    print_array();
    delete_item(20);
    //printf("20 silindikten sonra liste durumu:\n");
    //print_list();

    print_array();
    free(linkedlist);
    return 0;
}
