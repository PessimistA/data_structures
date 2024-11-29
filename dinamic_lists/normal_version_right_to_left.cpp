#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node* next;
};
#define NUll 0
struct node* current = NULL;

node* insert_at_position(struct node** head, int item);
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

node* insert_at_position(struct node** head, int item) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->number = item;
	temp->next = NULL;
	if (*head==NULL)
	{
		*head = temp;
		return *head;
	}
	else{
		struct node* current = *head;
		while (current->next != NULL) {//sonraki elemanı null olunca duracaksın yanı kendisi son eleman
			current = current->next;
		}
		current->next = temp;
		return *head;

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
    // Eleman ekleme
    head=insert_at_position(&head,10);
    head=insert_at_position(&head, 21); 
    head=insert_at_position(&head, 32); 
    head=insert_at_position(&head, 73); 
    head=insert_at_position(&head, 84);
    print_list(head);

    free_list(&head);

    return 0;
}

//ver2

#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node* next;
};
#define NUll 0
struct node* current = NULL;

void insert_at_position(struct node** head, int item);
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

void insert_at_position(struct node** head, int item) {
	struct node* temp = (node*)malloc(sizeof(node*));
	temp->number = item;
	temp->next = NULL;
	if (*head==NULL)
	{
		*head = temp;
	}
	else{
		struct node* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;

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
    // Eleman ekleme
    insert_at_position(&head,10);
    insert_at_position(&head, 21); //önce eklenir ama sonra 30 gelince sağa kayar sonra 40 gelince en son sırada olur
    insert_at_position(&head, 32); 
    insert_at_position(&head, 73); 
    insert_at_position(&head, 84);
    print_list(head);

    free_list(&head);

    return 0;
}
