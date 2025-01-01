void levelOrderWithHeap(Node* root) {//level order mesela
    if (root == NULL) {
        return;
    }

    // Queue oluştur
    Node* queue[100];  // Bu basit bir array ile yapılabilir, daha büyük ağaçlar için dinamik yapı kullanılabilir
    int front = 0, rear = 0;

    // Root'u kuyruğa ekle
    queue[rear++] = root;

    while (front < rear) {
        // Kuyruğun ilk elemanını al
        Node* current = queue[front++];

        // Node'u yazdır
        printf("%d ", current->data);

        // Çocukları kuyruğa ekle
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

// inorder mesela
void inorder_iterative(Node* root) {
    Node* stack[100]; // Stack boyutunu ağacın derinliğine göre ayarlayabilirsiniz.
    int top = -1; // Stack'in başlangıç durumu.
    Node* current = root;

    while (current != NULL || top != -1) {
        // Sol alt ağaca git
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        // Stack'ten bir düğüm al ve işleyin
        current = stack[top--];
        printf("%d ", current->data);

        // Sağ alt ağaca geç
        current = current->right;
    }
}
void preorder_iterative(Node* root) {
    Node* stack[100]; // Stack boyutunu ağacın derinliğine göre ayarlayabilirsiniz.
    int top = -1; // Stack'in başlangıç durumu.

    // Stack'e kök düğümünü ekleyin
    stack[++top] = root;

    while (top != -1) {
        // Stack'ten bir düğüm alın
        Node* current = stack[top--];

        // Mevcut düğümün değerini yazdırın
        printf("%d ", current->data);

        // Sağ alt ağacı önce ekleyin (çünkü stack LIFO yapısına sahiptir)
        if (current->right != NULL) {
            stack[++top] = current->right;
        }

        // Sol alt ağacı ekleyin
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

//mirror almak reverse almak yani
void mirror(Node* root) {
    if (root == NULL) {
        return;
    }

    // Stack kullanarak iteratif mirror işlemi
    Node* stack[100]; // Stack boyutunu ağacın derinliğine göre ayarlayabilirsiniz.
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        Node* current = stack[top--];

        // Sol ve sağ çocukları takas et
        Node* temp = current->left;
        current->left = current->right;
        current->right = temp;

        // Sağ çocuğu önce ekleyin (çünkü stack LIFO yapısına sahiptir)
        if (current->left != NULL) {
            stack[++top] = current->left;
        }

        // Sol çocuğu ekleyin
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
    }
}

//linkedlist için dinamik doubly
struct node* recursive(node* current) {
	if (current == NULL || current->next == NULL) {
		return current; // Base case
	}

	// Recursive çağrı
	struct node* new_head = recursive(current->next);

	// Bağlantıları ters çevir
	current->next->next = current;
	current->prev = current->next;
	current->next = NULL;

	return new_head;
}
struct node* iterative(node** head) {
	node* current = *head;
	node* temp = NULL;
	while (current != NULL) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		*head = current;
		current = current->prev;
	}
	return *head;
}
//dinamik single reverse
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

//statik doubly
void reverse_iterative(int* head) {
	int current = *head;
	int temp = EMPTY;

	while (current != EMPTY) {
		temp = linkedlist[current].next;
		linkedlist[current].next = linkedlist[current].prev;
		linkedlist[current].prev = temp;
		*head = current;//hayati önem taşır koymazsan olmaz yeni head değerini böyle alırsın
		current = temp;
	}
	
}
void reverse_recursive(int current,int*head) {
	if (current == EMPTY) {
		return;
	}

	// 'next' ve 'prev' bağlantılarını değiştir
	int temp = linkedlist[current].next;
	linkedlist[current].next = linkedlist[current].prev;
	linkedlist[current].prev = temp;
	*head = current;

	reverse_recursive(temp, head);

}
//statik single
void reverseRecursive(int current, int prev) {//prev==0 current==head
    if (current == EMPTY) {
        head = prev;  // Başlangıçta head'i en son eleman yap
        return;
    }

    int next = linkedList[current].link;  // Bir sonraki elemanı kaydet
    linkedList[current].link = prev;      // Mevcut elemanın linkini tersine çevir
    reverseRecursive(next, current);      // Özyineleme ile devam et
}
void reverseIterative() {
    int prev = EMPTY;
    int current = head;
    int next;

    while (current != EMPTY) {
        next = linkedList[current].link;  // Bir sonraki elemanı kaydet
        linkedList[current].link = prev;  // Mevcut elemanın linkini tersine çevir
        prev = current;                   // Prev'i güncelle
        current = next;                   // Current'ı güncelle
    }
    head = prev;  // Son eleman, baş eleman olarak atanır
}
