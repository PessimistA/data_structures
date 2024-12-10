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

node* temp;
int sayaç = 0;
void insert_item(node** head,node** tail,int item) {
    struct node* temp = (node*)malloc(sizeof(node));//temp tüm iki kutucuğu ifade eder

    temp->number = item;//yeni elemanı ekler
    temp->next = NULL;//bu yeni eklenmiş elemanın next null yapar yeni eleman eklenene kadar

    if (*head == NULL)
    {
        *head = temp;//başlangıç durumudur head e ekleme bir kez yapılır
        *tail = temp;
        temp->prev = NULL;
    }
    else{
        temp->prev = *tail;
        (*tail)->next = temp;
        *tail = temp;
    }

}
void item_count(node* head) {
    node* current = head;
    while (current != NULL) {
        current = current->next;
        sayaç++;
    }
}
void buble_sort(node* head) {
    node* current = head;
    while (current!=NULL) {
        node* current2 = current;
        while (current2 != NULL) {
            if (current->number < current2->number)
            {
                int temp = current->number;
                current->number = current2->number;
                current2->number = temp;
            }
            current2 = current2->next;
        }
        current = current->next;
    }
}
void buble_sort_recursive(node* current,node* head,node* tail) {
    if (current==NULL|| tail==NULL|| current==tail)
    {
        return;
    }
    else
    {
        if (current->next != tail->next)
        {
            if (current->number < current->next->number)
            {
                int temp = current->number;
                current->number = current->next->number;
                current->next->number = temp;
            }
            buble_sort_recursive(current->next,head, tail);
        }

    }
    buble_sort_recursive(head, head, current);
}
void free_list(node* head, node* tail) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void print(node** head) {

    struct node* head2 = *head;//bu ilk elemanı gösterir atama yapınca head 1 de orayı gösteriyor o elemanın  nexti sonuçta sonraki elemanı gösterir 
    printf("düz list: ");
    while (head2 != NULL) {
        printf("%d ",head2->number);
        head2 = head2->next;
    }
}

int main() {
    node* head = NULL;
    node* tail = NULL;
    insert_item(&head,&tail,63);
    insert_item(&head, &tail, 3);
    insert_item(&head, &tail, 64);
    insert_item(&head, &tail, 60);
    insert_item(&head, &tail, 9);
    insert_item(&head, &tail, 6);
    item_count(head);
    buble_sort_recursive(head, head, tail);
    //buble_sort(head);
    print(&head);
    free_list(head,tail);
    return 0;
}
