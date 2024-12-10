#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {

    int number;
    node* next;
    node* prev;
};
node* head = NULL;
node* tail = NULL;
node* temp;
int sayaç = 0;
void insert_item(int item) {
    struct node* temp = (node*)malloc(sizeof(node));//temp tüm iki kutucuğu ifade eder

    temp->number = item;//yeni elemanı ekler
    temp->next = NULL;//bu yeni eklenmiş elemanın next null yapar yeni eleman eklenene kadar

    if (head == NULL)
    {
        head = temp;//başlangıç durumudur head e ekleme bir kez yapılır
        temp->prev = NULL;
    }
    else
    {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;
        current = temp;
    }

}
void item_count(node* head) {
    node* current = head;
    while (current != NULL) {
        current = current->next;
        sayaç++;
    }
}
node* get_node(node* head1, int middle) {
    for (int i = 0; i <middle-1 ; i++)
    {
        head1 = head1->next;
    }
    return head1;
}
int binary_search(node* head, int item, int sol, int sağ) {
    if (sol>sağ)
    {
        return -1;
    }

    int middle = (sağ + sol) / 2;

    node* middle_node = get_node(head, middle);

    if (middle_node->number==item)
    {
        return middle;
    }
    else if (item > middle_node->number) {
        return binary_search(head, item, middle + 1, sağ);
    }
    else if (item < middle_node->number)
    {
        return binary_search(head, item,sol ,middle - 1);
    }
}
int binary_search_iterative(node* head, int item, int sol, int sağ) {
    node* current = head;
    while (current != NULL) {
        if (sol > sağ)
        {
            return -1;
        }

        int middle = (sağ + sol) / 2;

        node* middle_node = get_node(head, middle);

        if (middle_node->number == item)
        {
            return middle;
        }
        else if (item > middle_node->number) {
            sol = middle + 1;
        }
        else if (item < middle_node->number)
        {
            sağ = middle - 1;
        }
    }
}
void free_list() {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void print(node* head) {

    struct node* head2 = head;//bu ilk elemanı gösterir atama yapınca head 1 de orayı gösteriyor o elemanın  nexti sonuçta sonraki elemanı gösterir 
    printf("düz list: ");
    while (head2 != NULL) {
        printf("%d ",head2->number);
        head2 = head2->next;
    }
}

int main() {
    insert_item(6);
    insert_item(15);
    insert_item(30);
    insert_item(40);
    insert_item(50);
    insert_item(70);
    insert_item(80);
    item_count(head);
    printf("%d sayac\n", sayaç);
    int konum = binary_search(head, 50, 0, sayaç);
    int konum2 = binary_search_iterative(head, 70, 0, sayaç);
    printf("konum1=%d\n", konum);
    printf("konum2=%d\n", konum2);
    print(head);
    free_list();
    return 0;
}
