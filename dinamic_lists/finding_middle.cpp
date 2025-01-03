#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node* next;
};
#define NUll 0


int stack[100];
int top=-1;


void push(int item) {
    stack[++top] = item;
}
int pop() {
    return stack[top--];
}
void atama(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        push(current->number);
        current = current->next;
    }
}
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

void print_stack() {
    printf("stack:");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}
void combine(struct node** head2, struct node** tail1,struct node** tail2) {
    (*tail1)->next = *head2;
    *tail1 = *tail2;
}
int find_middle(int middle,struct node* head) {
    struct node* current = head;
    int sayaç = 0;
    while (current!=NULL) {
        if (sayaç== middle)
        {
            return current->number;
        }
        sayaç++;
        current = current->next;
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
    insert_at_position(&head, &tail, 80);
    atama(head);
    // Listeyi yazdır
    print_list(head);//List: 10  20  30  70  NULL
    struct node* current = head;
    int eleman_sayısı = 0;
    while (current!=NULL) {
        eleman_sayısı++;
        current = current->next;
    }
    printf("eleman sayısı:%d\n", eleman_sayısı);
    int ortadaki_sayı = 0;
    if (eleman_sayısı%2==0)
    {
        ortadaki_sayı = eleman_sayısı / 2;
    }
    else
    {
        ortadaki_sayı = (eleman_sayısı / 2) ;
    }
    int eleman = find_middle(ortadaki_sayı, head);
    printf("eleman:%d", eleman);
    // Belleği temizle
    free_list(&head);

    return 0;
}
