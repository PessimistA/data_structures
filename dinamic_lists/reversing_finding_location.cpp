#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node* next;
};
#define NUll 0

int queue[100];
int rear=-1;
int front=-1;
int stack[100];
int top=-1;

void enqueue(int item) {
    queue[++rear] = item;
}
int dequeue() {
    return queue[front++];
}
void push(int item) {
    stack[++top] = item;
}
int pop() {
    return stack[top--];
}
void atama(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        enqueue(current->number);
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
void print() {
    printf("queue:");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t",queue[i]);
    }
    printf("\n");
}
void print_stack() {
    printf("stack:");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}
void reverse() {
    int rear1 = rear;
    int front1 = front;
    while (!(front1>rear1)) {
        int temp = queue[rear1];
        queue[rear1] = queue[front1];
        queue[front1] = temp;
        front1++;
        rear1--;
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
struct node* reverse_recursive(struct node* head) {
    // Eğer liste boşsa veya sadece bir eleman varsa, ters çevirmeye gerek yok
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Kalan listeyi ters çevir
    struct node* new_head = reverse_recursive(head->next);

    // Mevcut düğümü ters çevir
    head->next->next = head;//ters çevirme işlemini burası yapar head değerinin yönünü değiştire değiştire en son head değerini elde ederiz
    head->next = NULL;

    return new_head; // Yeni baş düğümü döndür
}
struct node* reverse_iterative(struct node* head) {

    struct node* prev = NULL; // Bir önceki düğüm
    struct node* current = head; // Şu anki düğüm
    struct node* next = NULL; // Sonraki düğüm

    while (current != NULL) {
        next = current->next;    // Sonraki düğümü sakla
        current->next = prev;    // Mevcut düğümün yönünü değiştir
        prev = current;          // Bir sonraki iterasyonda prev, current olur
        current = next;          // current bir sonraki düğüme geçer
    }

    return prev; // Yeni baş düğümü döndür
}
int find_location(int number,struct node* head) {
    struct node* current = head; // Şu anki düğüm
    int location = 0;
    while (current != NULL) {
        if (number==current->number)
        {
            return location;
            break;
        }
        location++;
        current = current->next;
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
    atama(head);
    // Listeyi yazdır
    print_list(head);//List: 10  20  30  70  NULL
    print_stack();//stack:10        20      30      70
    print();//queue:0 10      20      30      70
    reverse();
    print();//queue:70        30      20      10      0
    for (int i = front; i <= rear; i++)
    {
        insert_at_position(&head, &tail, dequeue());//List: 10  20  30  70  70  30  20  10  0  NULL basar
    }
    print_list(head);
    struct node* head2 = NULL;
    struct node* tail2 = NULL;
    int k = top;
    for (int i = 0; i <= k; i++)
    {
        insert_at_position(&head2, &tail2, pop());//List: 70  30  20  10  NULL
    }
    print_list(head2);
    struct node* tail3= reverse_recursive(head2);//10  20  30  70  NULL
    print_list(tail3);
    struct node* head3 =reverse_iterative(tail3);//List: 70  30  20  10  NULL
    print_list(head3);
    int location = find_location(20, head2);
    printf("%d is the location", location);
    // Belleği temizle
    free_list(&head);
    free_list(&head2);

    return 0;
}
