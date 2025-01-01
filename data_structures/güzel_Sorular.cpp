//Soru: İki farklı priority queue'yi, tek bir priority queue olarak birleştiren bir algoritma yazın.
void mergeHeaps(int heap1[], int size1, int heap2[], int size2) {
    for (int i = 0; i < size2; i++) {
        heap1[size1 + i] = heap2[i];
    }
    int newSize = size1 + size2;
    for (int i = newSize / 2 - 1; i >= 0; i--) {
        heapifyDown(heap1, newSize, i);
    }
}
