//two different lists
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LIST 10
#define TRUE 1
#define FALSE 0
#define EMPTY -1

typedef struct {
	int number;
	int link;
} item;

item linkedlist[MAX_LIST];
int FREE;
int first;
int first2;

void empty_list_maker() {
	for (int i = 0; i < MAX_LIST; i++) {
		linkedlist[i].link = i + 1;
	}
	linkedlist[MAX_LIST - 1].link = EMPTY;
	FREE = 0;
	first = EMPTY;
	first2 = EMPTY;
}

int get_item(int* r) {
	if (FREE == EMPTY) {
		return FALSE;
	} else {
		*r = FREE;
		FREE = linkedlist[FREE].link;
		return TRUE;
	}
}

void return_item(int r) {
	linkedlist[r].link = FREE;
	FREE = r;
}

void insert_item(int numbers[], int* list,int len) {
	int r, q, p;
	for (int i = 0; i < len; i++) {
		if (get_item(&r)) {
			linkedlist[r].number = numbers[i];  // Yeni öğeyi ekliyoruz
			q = EMPTY;
			p = *list;

			// Doğru konumu bulmak için mevcut listeyi tarıyoruz
			while (p != EMPTY && linkedlist[p].number < numbers[i]) {
				q = p;
				p = linkedlist[p].link;
			}

			if (q == EMPTY) {
	
				*list = r;
				linkedlist[r].link = p;
			}
			else {
				linkedlist[q].link = r;
				linkedlist[r].link = p;
			}
		}
		else {
			printf("\nYeterli boş alan yok!!");
		}
	}
}

void delete_item(int numbers[], int* list) {
	int q, p;
	q = EMPTY;
	p = *list;
	int l;

	while (p != EMPTY ) {
		q = p;
		p = linkedlist[p].link;
	}

	if (p == EMPTY ) {
		printf("\n%s cannot be found!!", numbers);
	} else if (q == EMPTY) {
		*list = linkedlist[p].link;
		return_item(p);
	} else {
		linkedlist[q].link = linkedlist[p].link;
		return_item(p);
	}
}

void print() {
	printf("\nFull array:\n");
	for (int i = 0; i < MAX_LIST; i++)
	{
		printf("index\tname\tlink\n");
		printf("%d\t%d\t%d\n", i, linkedlist[i].number, linkedlist[i].link);
	}
	printf("\n first not Full array:\n");
	int sayaç = first;
	while (sayaç != EMPTY) {
		printf("index\tname\tlink\n");
		printf("%d\t%d\t%d\n", sayaç, linkedlist[sayaç].number, linkedlist[sayaç].link);
		sayaç = linkedlist[sayaç].link;
	}
	printf("\n second not Full array:\n");
	int sayaç1 = first2;
	while (sayaç1 != EMPTY) {
		printf("index\tname\tlink\n");
		printf("%d\t%d\t%d\n", sayaç1, linkedlist[sayaç1].number, linkedlist[sayaç1].link);
		sayaç1 = linkedlist[sayaç1].link;
	}
	printf("FREE: %d\n", FREE);
	printf("First: %d\n", first);
	printf("First2: %d\n", first2);
}

int main() {
	empty_list_maker();

	int numbers[5] = {9,2,1,4,3};
	int len = sizeof(numbers) / sizeof(numbers[0]);
	insert_item(numbers, &first,len);
	print();
	int numbers2[4] = { 3,0,7,8 };
	int len1 = sizeof(numbers2) / sizeof(numbers[0]);
	insert_item(numbers2, &first2, len1);
	print();

	return 0;
}
//as one array
#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LIST 10
#define TRUE 1
#define FALSE 0
#define EMPTY -1

typedef struct {
	int number;
	int link;
} item;

item linkedlist[MAX_LIST];
int FREE;
int first;
int first2;

void empty_list_maker() {
	for (int i = 0; i < MAX_LIST; i++) {
		linkedlist[i].link = i + 1;
	}
	linkedlist[MAX_LIST - 1].link = EMPTY;
	FREE = 0;
	first = EMPTY;
	first2 = EMPTY;
}

int get_item(int* r) {
	if (FREE == EMPTY) {
		return FALSE;
	} else {
		*r = FREE;
		FREE = linkedlist[FREE].link;
		return TRUE;
	}
}

void return_item(int r) {
	linkedlist[r].link = FREE;
	FREE = r;
}

void insert_item(int numbers[], int* list,int len) {
	int r, q, p;
	for (int i = 0; i < len; i++) {
		if (get_item(&r)) {
			linkedlist[r].number = numbers[i];  // Yeni öğeyi ekliyoruz
			q = EMPTY;
			p = *list;

			// Doğru konumu bulmak için mevcut listeyi tarıyoruz
			while (p != EMPTY && linkedlist[p].number < numbers[i]) {
				q = p;
				p = linkedlist[p].link;
			}

			if (q == EMPTY) {
	
				*list = r;
				linkedlist[r].link = p;
			}
			else {
				linkedlist[q].link = r;
				linkedlist[r].link = p;
			}
		}
		else {
			printf("\nYeterli boş alan yok!!");
		}
	}
}

void delete_item(int numbers[], int* list) {
	int q, p;
	q = EMPTY;
	p = *list;
	int l;

	while (p != EMPTY ) {
		q = p;
		p = linkedlist[p].link;
	}

	if (p == EMPTY ) {
		printf("\n%s cannot be found!!", numbers);
	} else if (q == EMPTY) {
		*list = linkedlist[p].link;
		return_item(p);
	} else {
		linkedlist[q].link = linkedlist[p].link;
		return_item(p);
	}
}

void print() {
	printf("\nFull array:\n");
	for (int i = 0; i < MAX_LIST; i++)
	{
		printf("index\tname\tlink\n");
		printf("%d\t%d\t%d\n", i, linkedlist[i].number, linkedlist[i].link);
	}
	printf("\n first not Full array:\n");
	int sayaç = first;
	while (sayaç != EMPTY) {
		printf("index\tname\tlink\n");
		printf("%d\t%d\t%d\n", sayaç, linkedlist[sayaç].number, linkedlist[sayaç].link);
		sayaç = linkedlist[sayaç].link;
	}
	printf("FREE: %d\n", FREE);
	printf("First: %d\n", first);
	//printf("First2: %d\n", first2);
}

int main() {
	empty_list_maker();

	int numbers[5] = {9,2,1,4,3};
	int len = sizeof(numbers) / sizeof(numbers[0]);
	insert_item(numbers, &first,len);
	print();
	int numbers2[4] = { 3,0,7,8 };
	int len1 = sizeof(numbers2) / sizeof(numbers[0]);
	insert_item(numbers2, &first, len1);
	print();

	return 0;
}

//iki liste eklemek ve çıkarma işlemleri

#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 10
#define EMPTY -1
#define True 1
#define False 0


struct temp {
    int number;
    int link;
};
temp linkedlist[MAX];
int Free;
int first;
int first2;

void arraymake() {
    for (int i = 0; i < MAX; i++)
    {
        linkedlist[i].link = i + 1;
    }
    linkedlist[MAX - 1].link = EMPTY;
    Free = 0;
    first2 = EMPTY;
    first = EMPTY;
}
int get_item(int* r) {
    if (Free==MAX)
    {
        printf("array doludur\n");
        return False;
    }
    else
    {
        *r = Free;
        Free = linkedlist[Free].link;
        return True;
    }
}
int compare(int a, int b) {
    if (a<b)//küçük olursa küçükten büyüğe sıralar
    {
        return True;
    }
    else
    {
        return False;
    }
}
void insert_item(int number,int* list) {
    int r, q, p;
    if (get_item(&r)) {
        linkedlist[r].number = number;
        q = EMPTY;
        p = *list;
        while (p != EMPTY && compare(linkedlist[p].number,number)>0) {
            q = p;
            p = linkedlist[p].link;
        }
        if (q==EMPTY)
        {
            *list = r;//first değerine atama yapılır
            linkedlist[r].link = p;
        }
        else
        {
            linkedlist[q].link = r;
            linkedlist[r].link = p;
        }

    }
    else
    {
        printf("array dolu\n");
    }
}
void return_item(int r) {
    linkedlist[r].link = Free;
    Free = r;
}
void delete_item(int number, int* list) {
    int p, q;
    q = EMPTY;
    p = *list;
    int i = 0;
    while (p!=EMPTY&&(i=compare(linkedlist[p].number,number))>0) {
        q = p;
        p = linkedlist[p].link;
    }
    if (p==EMPTY&&i<0)
    {
        printf("bulunamadı\n");
    }
    else if (q==EMPTY)
    {
        *list = linkedlist[p].link;
        return_item(p);
    }
    else
    {
        linkedlist[q].link = linkedlist[p].link;
        return_item(p);
    }
}
void print() {
    int sayaç = first;
    int sayaç2 = first2; printf("all list:\n");
    printf("index\tnumber\tlink\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t%d\t%d\n", i, linkedlist[i].number, linkedlist[i].link);
    }
    printf("first:%d\n", first);
    printf("free:%d\n", Free);
    printf("sorted list:\n");
    while (sayaç != EMPTY) {
        printf("%d\t%d\t%d\n", sayaç, linkedlist[sayaç].number, linkedlist[sayaç].link);
        sayaç = linkedlist[sayaç].link;
    }
    if (sayaç2!=EMPTY)
    {
        printf("array2\n");
        while (sayaç2 != EMPTY) {
            printf("%d\t%d\t%d\n", sayaç2, linkedlist[sayaç2].number, linkedlist[sayaç2].link);
            sayaç2 = linkedlist[sayaç2].link;
        }
        printf("first2:%d", first2);
    }
}

int main() {
    int list1[MAX] = { 2,88,3,1,4 };    int list2[MAX] = {0,7,8,9,5};
    int sayaç = 0;
    arraymake();
    for (int i = 0; i < MAX; i++)
    {
        if (list1[i] != 0) {
            sayaç++;
        }
    }
    for (int i = 0; i < sayaç; i++)
    {
        insert_item(list1[i], &first);
    }
    printf("\nilki için\n");
    print();
    for (int i = 0; i < 5; i++)
    {
        insert_item(list2[i], &first2);
    }
    printf("\nikinci için\n");
    print();

    delete_item(list2[1], &first2);
    printf("\nucuncu icin\n");
    print();
    return 0;
}
