#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node* next;
};

void print_list(struct node* head) {
    struct node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d  ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}

void insert_at_position(struct node** head, int item, int position) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->number = item;//elemanı atar temp şu anda bulunduğumuz düğümü gösterir
    temp->next = NULL;

    if (position == 0 || *head == NULL) {
        temp->next = *head;//başlangıçta ise head güncellemesi yapar
        *head = temp;//*head çünkü mainden gönderilir
        return;
    }

    struct node* current = *head;//başlangıç noktası yeni bir düğüme verilir
    int index = 0;

    while (current != NULL && index < position - 1) {
        current = current->next;//burada istediğimiz yerden bir önceki elemanın next elemanı bulunur
        index++;
    }

    if (current == NULL) {
        printf("Position out of bounds. Adding at the end.\n");
        return;
    }
    temp->next = current->next;//yeni olana eskisinin next adresi verilir 
    current->next = temp;//eski olanınn yeni eklediğimize gitmesi sağlanır
}

void free_list(struct node** head) {
    struct node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct node* head = NULL;

    // Eleman ekleme
    insert_at_position(&head, 10, 0); 
    insert_at_position(&head, 20, 1); //önce eklenir ama sonra 30 gelince sağa kayar sonra 40 gelince en son sırada olur
    insert_at_position(&head, 30, 1); 
    insert_at_position(&head, 40, 2); 

    // Listeyi yazdır
    print_list(head);

    // Belleği temizle
    free_list(&head);

    return 0;
}
