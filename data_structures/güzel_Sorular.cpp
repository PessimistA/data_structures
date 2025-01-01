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

//soru heap'in en küçük n tane elemanını silen fonksiyonlar

void deleteMin(int n)
{
    if (isEmpty())
        return;
    for (int i = 0; i < n; i++)
    {
        array[1] = array[the_size--];
        //percolateDown(1);//burada gönderilen değer en sondaki değer yani oldukça büyük unutma
        recursive_percolateDown(1, array[1]);
    }
}

void percolateDown(int hole)
{
    int child;
    int tmp = array[hole];
    for (; hole <= the_size / 2; hole = child)
    {
        child = hole * 2;
        if (child != the_size && array[child + 1] < array[child])//sağ çocuk küçükse 
            child++;//sağ çocuğa geçiyoruz // bu koşul sağlanmazsa sol çocukta kalırız
        if (array[child] < tmp)//üstte hangi tarafta olduğumuzu bulduk şimdi 
            array[hole] = array[child];//küçükse hole yani boşluğa atarız ve atanılan yer boşalır bu yüzden hole=child deriz
        else
            break;

    }
    array[hole] = tmp;//en son boşluk dizideki en son değer yani tmp ye attığımız ve hiç değişmeyen değer atanır hole artık uygun yer haline gelmiştir
}
