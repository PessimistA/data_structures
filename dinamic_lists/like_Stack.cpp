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

void insert_at_position(struct node** head, int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->number = item;//elemanı atar temp şu anda bulunduğumuz düğümü gösterir
    temp->next = NULL;
    temp->next = *head;
    *head = temp;
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

    // Eleman ekleme
    insert_at_position(&head,  10);
    insert_at_position(&head,  20); //önce eklenir ama sonra 30 gelince sağa kayar sonra 40 gelince en son sırada olur
    insert_at_position(&head,  30);
    insert_at_position(&head,  70);

    // Listeyi yazdır
    print_list(head);
    Delete(&head);
    print_list(head);
    // Belleği temizle
    free_list(&head);

    return 0;
}
//stack olarak
#include <stdio.h>
#include <stdlib.h>

struct node{
	int item;
	node* next;
};
struct node* top=NULL;

void push(int item) {
	node* temp = (node*)malloc(sizeof(node));
	temp->item = item;	
	temp->next = top;
	top = temp;
}
void pop() {
	if (top==NULL)
	{
		printf("stack is empty\n");
	}
	top = top->next;	
}
void print() {
	node* current = top;
	printf("list: ");
	while (current != NULL) {
		printf("%d -> ", current->item);
		current = current->next;
	}
	printf("NULL\n");
}
void free_list() {
	struct node* temp;
	while (top != NULL) {
		temp = top;
		top = (top)->next;
		free(temp);
	}
}
int main() {
	push(2);
	push(4);
	push(6);
	push(8);
	print();
	pop();
	print();
	free_list();
}


