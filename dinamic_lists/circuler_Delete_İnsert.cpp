
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
//Recursive version
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
void insert_recursive(node_pointer* head,node_pointer current,int value) {
    if (*head==NULL)
    {
        node_pointer new_node = (node_pointer)malloc(sizeof(struct node));
        new_node->value = value;
        new_node->rightlink = new_node;
        new_node->leftlink = new_node;
        *head = new_node;
        return;
    }
    if((current)->rightlink==*head)
    {
        node_pointer new_node = (node_pointer)malloc(sizeof(struct node));
        new_node->value = value;
        new_node->rightlink = new_node;
        new_node->leftlink = new_node;

        new_node->rightlink = *head;
        new_node->leftlink = current;
        (*head)->leftlink = new_node;
        current->rightlink = new_node;  
        return;
    }
    insert_recursive(head, (current)->rightlink, value);
}
void delete_recursive(node_pointer *head, node_pointer current, int value) {
    if ((*head)->value==value)
    {
        (*head)->leftlink->rightlink = (*head)->rightlink;
        (*head)->rightlink->leftlink = (*head)->leftlink;
        *head =(*head)->rightlink;
        return;
    }
    if(current->value==value)
    {
        current->leftlink->rightlink = current->rightlink;
        current->rightlink->leftlink = current->leftlink;
        return;
    }
    delete_recursive(head,current->rightlink,value);

}
void Max_value(node_pointer* head, node_pointer current, int maxValue) {
    if (current->value > maxValue)
    {
        maxValue = current->value;
    }
    if (current->rightlink == *head)
    {
        printf("%d en buyuk değerdir\n",maxValue);
        return;
    }
    Max_value(head, current->rightlink, maxValue);

}
void reverse_recursive(node_pointer* head, node_pointer current) {
    if (current->rightlink == *head) {
        *head = current; 
        return;
    }

    reverse_recursive(head, current->rightlink);

    node_pointer next_node = current->rightlink;
    current->rightlink = current->leftlink; 
    current->leftlink = next_node;        

    if (next_node == *head) {
        (*head)->rightlink = current;
        current->leftlink = *head;     
    }
}
void sort_recursive(node_pointer head) {
    if (head == NULL || head->rightlink == head) return;

    node_pointer current = head, next_node = NULL;
    int temp;

    do {
        next_node = current->rightlink;
        while (next_node != head) {
            if (current->value > next_node->value) {
                temp = current->value;
                current->value= next_node->value;
                next_node->value = temp;
            }
            next_node = next_node->rightlink;
        }
        current = current->rightlink;
    } while (current->rightlink != head);
}

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
    //normal işlemler
    // Polinom 1: 3x^6 + 15x^4 + 6x^3
    //insert_item(&head1, 3);
    //insert_item(&head1, 15);
    //insert_item(&head1, 6);
    //insert_item(&head1, 7);
    //insert_item(&head1, 16);
    //insert_item(&head1, 31);
    //insert_item(&head1, 42);
    //print(&head1);
    //delete_item(&head1,15);
    //print(&head1);
    //free_list(&head1);



    insert_recursive(&head1,head1, 1);
    insert_recursive(&head1, head1, 22);
    insert_recursive(&head1, head1, 13);
    insert_recursive(&head1, head1, 43);
    insert_recursive(&head1, head1, 15);
    insert_recursive(&head1, head1, 6);

    print(&head1);
    delete_recursive(&head1,head1, 1);
    print(&head1);
    Max_value(&head1, head1, head1->value);

    //reverse_recursive(&head1, head1);
    sort_recursive(head1);
    print(&head1);
    return 0;
}
