//selection sort
/*
 Dizinin ilk elemanını, dizideki en küçük (veya en büyük, sıralama türüne bağlı olarak) elemanla değiştir. İkinci elemanı, dizinin ikinci elemanından başlayarak son elemana kadar olan alt dizideki en küçük (veya en büyük) elemanla değiştir. Bu işlemi dizinin son elemanına kadar tekrarlayın
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void sort(int [],int);


int main(){
    int list[101];
    int i,n;
    printf("please enter array size");
    scanf("%d",&n);

    for ( i = 0; i < n; i++)
    {
        list[i] = rand() %10;
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",list[i]);
    }

    sort(list,n);
    printf(" ");
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",list[i]);
    }
    
    
    return 0;
}
//iterative
void sort(int a[],int b){O(n2)
    for (int i = 0; i < b-1; i++)
    {
        for (int j = i+1 ; j < b; j++)//bulunduğu yerin üstlerinde aramalı
        {
            if (a[i]>a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
//recursive
void sort(int a[],int b,int c){
    if (b>=c)
    {
        return ;
    }
    else{
        int k = minindex(a,b,c-1);
        if (k != b)
        {
            int temp = a[k];
            a[k] = a[b];
            a[b] = temp;
        }
        
        sort(a,b+1,c);
    }  
}
int minindex(int list[],int a,int b){
    if (a==b)
    {
        return a;
    }
    else{
        int k = minindex(list,a+1,b);
        return (list[a]<list[b])? a :k;
    }
    
}

//insertion sort

#include <stdio.h>

void insertion_sort(int list[], int right);
void recursive(int list[], int left, int right);
int main()
{
	int list[5] = { 13,89,34,24,556 };

	insertion_sort(list,5);
	recursive(list, 1, 4);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", list[i]);
	}
	return 1;
}
void insertion_sort(int list[], int right) {
	for (int i = 1; i < right; i++)
	{
		for (int  j=i-1 ; j > 0; j--)
		{
			if (list[j-1]>list[j])
			{
				int temp = list[j - 1];
				list[j-1] = list[j];
				list[j] = temp;
			}
		}
	}
	for (int i = 0; i < right; i++)
	{
		printf("%d\n", list[i]);
	}
}

void recursive(int list[], int left, int right) {
	if (left > right ) {
		return;
	}
		if (left>0 && list[left - 1] < list[left])
		{
			int temp = list[left - 1];
			list[left - 1] = list[left];
			list[left] = temp;
			recursive(list, left -1, right);
		}
		else
		{
			recursive(list, left + 1, right);
		}
}

//buble sort

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void sort(int [],int,int);
int minindex(int list[],int a,int b);

int main(){
    int list[101];
    int i,n;
    printf("please enter array size");
    scanf("%d",&n);

    for ( i = 0; i < n; i++)
    {
        list[i] = rand() %10;
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",list[i]);
    }

    sort(list,0,n-1);
    printf(" \n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",list[i]);
    }
    
    
    return 0;
}
//iterative
void sort(int a[],int b,int c){
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j <c; j++)
        {
            if (a[i]>a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            
        }
        
    }
    
}
//recursive
void sort(int a[],int b,int c){
    if (b==c)
    {
        return ;
    }
    else{
        if(b<c)
        {   
            if (a[b]>a[b+1])
            {
                int temp = a[b+1];
                a[b+1] = a[b];
                a[b] = temp;
            }
            sort(a,b+1,c);
        }
    }    
    sort(a,b,c-1); 
}

//binary search

#include <stdio.h>
#include <math.h>

void binary_search(int dizi[],int,int*);

int main() {
    printf("bir sayı giriniz");
    int sayı,a=0;
    int* ptr ;
    ptr = &a;
    scanf_s("%d", &sayı);
    int dizi[] = {1,2,3,4,5,6,7,8,9,10};
    binary_search(dizi, sayı,ptr);
    printf("%d", a);
	return 0;
}
void binary_search(int dizi[], int istenilen,int * ptr) {
    int sol = 0, sağ = 9,middle=0;
    while (sol <= sağ) {
        middle = sol + ((sağ - sol) / 2);
        if (istenilen > dizi[middle])
        {
            sol = middle + 1;
        }
        else if (istenilen < dizi[middle]) {
            sağ = middle - 1;
        }
        else
        {
            *ptr = middle;
            break;
        }
    }
}
//recursive
int binary_search(int list[], int searchnum, int left, int right) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		switch (compare(list[middle], searchnum))
		{
		case -1: return binary_search(list, searchnum, middle+1, right);
			
		case 0:
			return middle;
			
		case 1:return binary_search(list, searchnum, left, middle -1);

		}
	}
	return -1;
}
int compare(int a, int b) {
	if (a>b)
	{
		return 1;
	}
	if (a==b)
	{
		return 0;
	}
	if (b>a)
	{
		return -1;
	}
}
