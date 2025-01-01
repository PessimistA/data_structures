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
