#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

void percolateDown(int hole,int array[]);
void percolateUp(int hole, int array[]);

int the_size = 5;
void build_heap_down(int the_size,int array[]) {
    int i;
    for ( i =the_size/2; i>0; i--)//son elemandan başladığından burasu daha doğrusu sonuncunun parent kısmından başladığından dolayı
    {
        percolateDown(i,array);
    }
}
void percolateDown(int hole,int array[])//O(n) karmaşıklığı
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
void linear_search(int item,int array[], int size, int* sayaç) {
	for (int i = 1; i <= size; i++)
	{
		if (array[i]==item)
		{
			return;
		}
		(*sayaç)++;
	}
}

void printHeap(int array[],int the_size) {
    printf("Heap: ");
    for (int i = 1; i <= the_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int recursiveSearchHeap(int array[], int index, int the_size, int value) {//bu aynı zamanda mim ve max heap arama şeklidir
    if (index > the_size) {
        return -1; 
    }

    if (array[index] == value) {
        return index; 
    }

    int leftChild = recursiveSearchHeap(array, index * 2, the_size, value);
    if (leftChild != -1) {
        return leftChild; 
    }
    int rightChild = recursiveSearchHeap(array, index * 2+1, the_size, value);
    if (rightChild!=-1)
    {
        return rightChild;
    }
}

int main() {
    int array_down[MAX] = { 0,10,5,20,1,15 };
    int size_down = 5;
    build_heap_down(size_down, array_down);
    printf("down ile yapılan\n");
    printHeap(array_down,size_down);
    printf("\n");
	int sayaç = 1;
	linear_search(5, array_down, size_down, &sayaç);
	printf("%d. sırada\n", sayaç);
    int index= recursiveSearchHeap(array_down, 1, size_down, 5);
    printf("%d. sırada\n", index);
    return 0;
}
