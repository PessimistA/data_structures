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
void percolateUp(int hole,int array[]) {
    int tmp = array[hole];
    for (; hole > 1 && tmp < array[hole / 2]; hole /= 2) {
        array[hole] = array[hole / 2];
    }
    array[hole] = tmp; 
}

void build_heap_up(int the_size,int array[]) {
    for (int i = 1; i <=the_size; i++) { // baştan yani roottan başlarsın bu yüzden 1 den başla
        percolateUp(i,array);
    }
}
void printHeap(int array[],int the_size) {
    printf("Heap: ");
    for (int i = 1; i <= the_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array_down[MAX] = { 0,10,5,20,1,15 };
    int size_down = 5;
    int array_up[MAX] = { 0,10,5,20,1,15 };//{ 0,92,47,21,17,12 ,25,63,61,20,55,37,45,64,83,73};
    int size_up = 5;
    build_heap_down(size_down, array_down);
    build_heap_up(size_up, array_up);
    printf("down ile yapılan\n");
    printHeap(array_down,size_down);
    printf("\n");
    printf("up ile yapılan\n");
    printHeap(array_up, size_up);

    return 0;
}
