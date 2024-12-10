
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;        
    struct node* leftlink;  
    struct node* rightlink; 
};

typedef struct node* node_pointer;

// Yeni bir düğüm oluşturur ve bir polinom terimi olarak ekler
void insert_item(node_pointer* head, int value) {
    node_pointer new_node = (node_pointer)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->leftlink = new_node;   
    new_node->rightlink = new_node;

    if (*head == NULL) {
        *head = new_node;
    }
    else {
        node_pointer last = (*head)->leftlink; 
        last->rightlink = new_node;  
        new_node->leftlink = last;     
        new_node->rightlink = *head;  
        (*head)->leftlink = new_node; 
    }
}


void delete_item(node_pointer* head, int value) {
    node_pointer current = *head;
    if ((*head)->value==value)
    {
        (*head)->leftlink->rightlink = (*head)->rightlink;
        (*head)->rightlink->leftlink = (*head)->leftlink;
        return;
    }
    do
    {
        if (current->value == value)
        {
            break;
        }
        current = current->rightlink;
    } while (current != *head);
    if (current->leftlink!=NULL)
    {
        current->leftlink->rightlink = current->rightlink;
    }
    if (current->rightlink!=NULL)
    {
        current->rightlink->leftlink = current->leftlink;
    }

}
// Listeyi yazdırma fonksiyonu
void print(node_pointer* head) {
    if (*head == NULL) return;

    node_pointer current = *head;
    printf("list: ");
    do {
        printf("%d ->", current->value);
        current = current->rightlink;
    } while (current != *head);
    printf("NULL");
    printf("\n");
}

// Belleği serbest bırakma fonksiyonu
void free_list(node_pointer* head) {
    if (*head == NULL) return;  // Eğer liste boşsa, hiçbir şey yapma
    node_pointer current = *head;
    node_pointer next_node;
    do {
        next_node = current->rightlink;
        free(current);
        current = next_node;
    } while (current != *head);
    *head = NULL;  // Listeyi null yap
}

int main() {
    node_pointer head1 = NULL;

    // Polinom 1: 3x^6 + 15x^4 + 6x^3
    insert_item(&head1, 3);
    insert_item(&head1, 15);
    insert_item(&head1, 6);
    insert_item(&head1, 7);
    insert_item(&head1, 16);
    insert_item(&head1, 31);
    insert_item(&head1, 42);

    print(&head1);

    delete_item(&head1,15);

    print(&head1);
    
    free_list(&head1);

    return 0;
}
