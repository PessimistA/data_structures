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

void insert_at_position(struct node** head, struct node** tail, int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->number = item;//elemanı atar temp şu anda bulunduğumuz düğümü gösterir
    temp->next = NULL;

    if (*head == NULL) {
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
void Delete(struct node** head) {
	(*head) = (*head)->next;
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
    insert_at_position(&head, &tail, 10);
    insert_at_position(&head, &tail, 20); //önce eklenir ama sonra 30 gelince sağa kayar sonra 40 gelince en son sırada olur
    insert_at_position(&head, &tail, 30);
    insert_at_position(&head, &tail, 70);

    // Listeyi yazdır
    print_list(head);
    Delete(&head);
    print_list(head);
    // Belleği temizle
    free_list(&head);

    return 0;
}

//queue doğru versiyonu
#include <stdio.h>
#include <stdlib.h>

struct node{
	int item;
	node* next;
};
struct node* rear  = NULL;
struct node* front = NULL;

void enqueue(int item) {
	node* temp = (node*)malloc(sizeof(node));
	temp->item = item;
	temp->next = NULL;
	if (front==NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->next =temp ;
		rear = temp;
	}
}
void pop() {
	if (rear==NULL)
	{
		printf("stack is empty\n");
	}
	front = front->next;	
}
void print() {
	node* current = front;
	printf("list: ");
	while (current != NULL) {
		printf("%d -> ", current->item);
		current = current->next;
	}
	printf("NULL\n");
}
void free_list() {
	struct node* temp;
	while (front != NULL) {
		temp = front;
		front = (front)->next;
		free(temp);
	}
}
int main() {
	enqueue(2);
	enqueue(4);
	enqueue(6);
	enqueue(8);
	print();
	pop();
	print();
	free_list();
}

