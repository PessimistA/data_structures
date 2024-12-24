#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100
int array[MAX] = {};
void percolateDown(int hole);
int the_size = 0;
void insert(int x) {
	int hole;

	hole = ++the_size;
	for ( ; x <array[hole/2] ;hole/=2)
	{
		array[hole] = array[hole / 2];
	}
	array[hole] = x;
}
int DeleteMin() {//other
    if (the_size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int minElement = array[1];
    int lastElement = array[the_size--];

    int hole = 1;
    int child;

    while (hole * 2 <= the_size) {
        child = hole * 2;
        if (child != the_size && array[child + 1] < array[child]) {
            child++;
        }

        if (array[child] < lastElement) {
            array[hole] = array[child];
        }
        else {
            break;
        }
        hole = child;
    }

    array[hole] = lastElement;
    return minElement;
}
int isEmpty()
{
    return the_size > 0 ? 0: 1;
}

void deleteMin()
{
    if (isEmpty())
        return;

    array[1] = array[the_size--];
    percolateDown(1);
}

void percolateDown(int hole)
{
    int child;
    int tmp = array[hole];
    for (; hole * 2 <= the_size; hole = child)
    {
        child = hole * 2;
        if (child != the_size && array[child + 1] < array[child])
            child++;
        if (array[child] < tmp)
            array[hole] = array[child];
        else
            break;

    }
    array[hole] = tmp;
} 
void printHeap() {
    printf("Heap: ");
    for (int i = 1; i <= the_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(5);
    insert(20);
    insert(1);
    insert(15);

    printHeap();

    deleteMin();
    printHeap();

    deleteMin();
    printHeap();

    return 0;
}
