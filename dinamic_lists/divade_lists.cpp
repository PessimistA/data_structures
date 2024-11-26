//özel kurallı çift ve tek diye ikiye bölme işlemi burada yapılır
#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node* next;
};
#define NUll 0
void insert_at_position(struct node** head, struct node** tail, int item);
void free_list(struct node** head);

void print_list(struct node* head) {
    struct node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d  ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}
void adding_newlists(struct node* head) {
    struct node* current = head;
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* tail1 = NULL;
    struct node* tail2 = NULL;

    while (current != NULL) {
        if (current->number%2==0)
        {
            insert_at_position(&head1, &tail1,current->number);
        }
        if (current->number % 2 == 1)
        {
            insert_at_position(&head2, &tail2, current->number);
        }
        current = current->next;
    }
    printf("çift list:\n");
    print_list(head1);
    printf("tek list:\n");
    print_list(head2);
    free_list(&head1);
    free_list(&head2);
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
    insert_at_position(&head,&tail, 21); //önce eklenir ama sonra 30 gelince sağa kayar sonra 40 gelince en son sırada olur
    insert_at_position(&head,&tail, 32); 
    insert_at_position(&head,&tail, 73); 
    insert_at_position(&head, &tail, 84);
    print_list(head);

    adding_newlists(head);
    free_list(&head);

    return 0;
}

//ikiye bölme ilk yol(burada iki farklı yeni liste hazırlanıp onlara eklenir)
#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node* next;
};
#define NUll 0
void insert_at_position(struct node** head, struct node** tail, int item);
void free_list(struct node** head);

void print_list(struct node* head) {
    struct node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d  ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}
void adding_newlists(struct node* head, struct node** tail,int middle) {
    struct node* current = head;
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* tail1 = NULL;
    struct node* tail2 = NULL;
    int sayaç = 0;

    while (current != NULL) {
        if (sayaç<=middle)
        {
            insert_at_position(&head1, &tail1,current->number);
        }
        else
        {
            insert_at_position(&head2, &tail2, current->number);
        }
        sayaç++;
        current = current->next;
    }
    printf("çift list:\n");
    print_list(head1);
    printf("tek list:\n");
    print_list(head2);
    free_list(&head1);
    free_list(&head2);
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
    insert_at_position(&head,&tail, 21); //önce eklenir ama sonra 30 gelince sağa kayar sonra 40 gelince en son sırada olur
    insert_at_position(&head,&tail, 32); 
    insert_at_position(&head,&tail, 73); 
    insert_at_position(&head, &tail, 84);
    print_list(head);
    struct node* current = head;
    int eleman_sayısı = 0;
    while (current != NULL) {
        eleman_sayısı++;
        current = current->next;
    }
    printf("eleman sayısı:%d\n", eleman_sayısı);
    int ortadaki_sayı = 0;
    if (eleman_sayısı % 2 == 0)
    {
        ortadaki_sayı = eleman_sayısı / 2;
    }
    else
    {
        ortadaki_sayı = (eleman_sayısı / 2);
    }
    adding_newlists(head,&tail,ortadaki_sayı);
    free_list(&head);

    return 0;
}

