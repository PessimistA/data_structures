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

void sort(int a[],int b){
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

//unfinished try for this
//selection sort recursive

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void sort(int [],int,int);


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

    sort(list,0,n);
    printf(" ");
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",list[i]);
    }
    
    
    return 0;
}

void sort(int a[],int b,int c){
    if (b>=c)
    {
        return ;
    }
    else{
        int d = b+1;
        if (d>=c)
        {
            if (a[b]>a[d])
            {
                int temp = a[b];
                a[b] = a[d];
                a[d] =temp;
            }
            d++;   
        }
        sort(a,b+1,c);
    }  
}
//teacher version

//selection sort recursive

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

    sort(list,0,n);
    printf(" ");
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",list[i]);
    }
    
    
    return 0;
}

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

//buble sort

//buble sort recursive

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

//buble sort iterative

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


// binary search
#include <stdio.h>

int binary_search(int list[], int searchnum, int left, int right);
int compare(int a, int b);

int main()
{
	int list[5] = { 1,2,3,4,5 };
	printf("please enter a number to search");
	int a;
	scanf_s("%d", &a);
	int sonuç = binary_search(list,a,0,4);
	printf("%d", sonuç);

	return 0;
}
int binary_search(int list[], int searchnum, int left, int right) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		switch (compare(list[middle], searchnum))
		{
		case -1: left = middle + 1;
			break;
		case 0:
			return middle;
			
		case 1: right = middle - 1;
			break;
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

//recursive olarak binary search

#include <stdio.h>

int binary_search(int list[], int searchnum, int left, int right);
int compare(int a, int b);

int main()
{
	int list[5] = { 1,2,3,4,5 };
	printf("please enter a number to search");
	int a;
	scanf_s("%d", &a);
	int sonuç = binary_search(list,a,0,4);
	printf("%d", sonuç);

	return 0;
}
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

//linear search
#include <stdio.h>

int linear_search(int list[], int searchnum, int left, int right);

int main()
{
	int list[5] = { 1,2,3,4,5 };
	printf("please enter a number to search\n");
	int a;
	scanf_s("%d", &a);
	int sonuç = linear_search(list,a,0,4);
	printf("%d", sonuç);

	return 0;
}
int linear_search(int list[], int searchnum, int left, int right) {
	for (int i = 0; i < right; i++)
	{
		if(list[i] == searchnum) {
			return i;
		}
	}
	return -1;

}
//linear search recursive

#include <stdio.h>

int linear_search(int list[], int searchnum, int left, int right);

int main()
{
	int list[5] = { 1,2,3,4,5 };
	printf("please enter a number to search\n");
	int a;
	scanf_s("%d", &a);
	int sonuç = linear_search(list,a,0,4);
	printf("%d", sonuç);

	return 0;
}
int linear_search(int list[], int searchnum, int left, int right) {
	if (right<=left)
	{
		return -1;
	}
	else
	{
		if (list[right]==searchnum)
		{
			return right;
		}
		return linear_search(list, searchnum, left, right - 1);
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

//factorial
#include <stdio.h>
void iterative_factorial(int number);

int recursive_factorial(int number);

int main() {
	int number;

	printf("pleasse enter  a number \n");
	scanf_s("%d", &number);
	iterative_factorial(number);
	printf("bundan sonrası recursive\n");
	for (int i = 0; i <= number; i++)
	{
		printf("%d. adım == %d\n",i,recursive_factorial(i));
	}

	return 0;
}
void iterative_factorial(int number) {
	int start = 1;
	int list[100];
	for (int i = 1; i <= number; i++)
	{
		list[i] = i;
	}
	for (int i = 1; i <= number; i++)
	{
		start = start * i;
		printf("%d. adım => %d \n", i, start);

	}
}

int recursive_factorial(int number) {
	if (number <=0)
	{
		return 1;
	}
	else
	{
		return number * recursive_factorial(number - 1);
	}
}

//fibonacci
#include <stdio.h>
void iterative_fibonacci(int number);

int recursive_fibonacci(int number);

int main() {
	int number;

	printf("pleasse enter  a number \n");
	scanf_s("%d", &number);
	iterative_fibonacci(number);
	printf("bundan sonrası recursive\n");
	for (int i = 0; i <= number; i++)
	{
		printf("%d. adım == %d\n",i,recursive_fibonacci(i));
	}

	return 0;
}
void iterative_fibonacci(int number) {
	int temp = 0, a = 0, b = 1;
	if (number>=0)
	{
		printf("%d\n", a);
	}
	if (number >= 1)
	{
		printf("%d\n", b);

	}
	for (int i = 2; i <= number ; i++)
	{
		temp = a + b;
		a = b;
		b = temp;
		printf("%d\n", temp);

	}
}

int recursive_fibonacci(int number) {
	if (number ==0)
	{
		return 0;
	}
	if (number == 1)
	{
		return 1;
	}
	else
	{
		return recursive_fibonacci(number-1)+recursive_fibonacci(number-2);
	}
}
