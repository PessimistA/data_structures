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

void insert_at_position(struct node** head,struct node** tail, int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->number = item;//elemanı atar temp şu anda bulunduğumuz düğümü gösterir
    temp->next = NULL;

    if ( *head == NULL) {
        temp->next = *head;//başlangıçta ise head güncellemesi yapar
        *head = temp;//*head çünkü mainden gönderilir
        *tail = temp;
    }
    else
    {
        (*tail)->next = temp;
        *tail = temp;//yeni olana eskisinin next adresi verilir 
    }
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
    struct node* tail = NULL;
    // Eleman ekleme
    insert_at_position(&head,&tail,10);
    insert_at_position(&head,&tail, 20); //önce eklenir ama sonra 30 gelince sağa kayar sonra 40 gelince en son sırada olur
    insert_at_position(&head,&tail, 30); 
    insert_at_position(&head,&tail, 70); 

    // Listeyi yazdır
    print_list(head);

    struct node* head2 = NULL;
    struct node* tail2 = NULL;
    insert_at_position(&head2, &tail2, 80);
    insert_at_position(&head2, &tail2, 90); //önce eklenir ama sonra 30 gelince sağa kayar sonra 40 gelince en son sırada olur
    insert_at_position(&head2, &tail2, 70);
    insert_at_position(&head2, &tail2, 60);
    //
    print_list(head2);
    // Belleği temizle
    free_list(&head);
    free_list(&head2);

    return 0;
}
