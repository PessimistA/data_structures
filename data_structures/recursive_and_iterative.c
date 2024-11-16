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

void sort(int a[],int b,int c){O(n2)
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
//ver2
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

//sorting
#include <stdio.h>

void sorting(int list[],int first,int sayaç,int last);

int main() {
	int list[] = { 19,2,23,111,22 };
	sorting(list,0,1,4);
    printf("en büyük eleman %d ", list[4]);
	return 0;
}
void sorting(int list[], int first, int sayaç, int last) {
    if (first >= last) {
        return;  // Sıralama tamam
    }

    if (sayaç <= last) {
        if (list[first] > list[sayaç]) {
            int temp = list[first];
            list[first] = list[sayaç];
            list[sayaç] = temp;
        }
        sorting(list, first, sayaç + 1, last);  // Bir sonraki elemana geç
    }
    else {
        sorting(list, first + 1, first + 2, last);  // Bir sonraki adım için baştan başla
    }
}

//toplama

#include <stdio.h>

void adding(int list[],int first,int last,int* max );

int main() {
	int list[] = { 19,2,23,111,22 };
	int a = 0;
	int *max= &a;

	adding(list,0,4,&a);
	printf("%d", a);
	return 0;
}
void adding(int list[], int first,  int last,int* max) {
	if (first > last) {
		return;
	}
	else
	{
		int temp = list[first] + *max;
		*max = temp;
		adding(list, first + 1, last, max);
	}
}
//üs alma
#include <stdio.h>

void adding(int,int,int *);

int main() {
	printf("please enter the number");
	int number;
	scanf_s("%d", &number);
	int exponen;
	printf("please enter the exponen");
	scanf_s("%d", &exponen);
	int a = 1;
	int* result = &a;
	adding(number, exponen, &a);
	printf("%d", a);

	return 0;
}
void adding(int number ,int exponen,int *result) {
	if (exponen==0)
	{
		return;
	}
	else
	{
		*result = number * *result;
		adding(number, exponen - 1, result);
	}
}
//aynı sayıların kullanıldığı permütasyon
#include <stdio.h>

void permutasion(char dizi[],int);

int main() {
	char dizi[] = { 'a','b','c' };
	permutasion(dizi, 3);

	return 0;
}
void permutasion(char dizi[], int lenght) {
	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j <lenght;j++) {
			for (int k = 0; k < lenght; k++)
			{
				printf("%c%c%c", dizi[i],dizi[j],dizi[k]);
				printf("\n");
			}
		}
	}
}

//permutasion

#include <stdio.h>

void permutasion(char dizi[],int);

int main() {
    char dizi[] = { 'a','b','c','d'};
    permutasion(dizi, 4);

	return 0;
}
void permutasion(char dizi[], int lenght) {
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght; j++) {
            if (i == j) {
                continue;
            }

            for (int k = 0; k < lenght; k++) {
                if (k == i || k == j) 
                {
                    continue;
                }

                printf("%c%c%c\n", dizi[i], dizi[j], dizi[k]);
            }
        }
    }
}

//binary çevirici
#include <stdio.h>
#include <math.h>

void binary_reverse(int dizi[],int,int,int);

int main() {
    printf("bir sayı giriniz");
    int sayı;   
    int basamak1;
    scanf_s("%d", &sayı);
    double basamak = log2(sayı);
    if (double(basamak)==int(basamak))
    {
        basamak1 = basamak;
    }
    else
    {
        basamak1 = int(basamak) + 1;
    }
    int liste[20];
    binary_reverse(liste,basamak1,0,sayı);
    for (int i = basamak1; i >0; i--)
    {
        printf("%d",liste[i]);
    }

	return 0;
}
void binary_reverse(int dizi[], int basamak,int başlangıç,int number) {
    if (başlangıç > basamak)
    {
        return;
    }
    else
    {
        dizi[başlangıç] = number % 2;
        number = number / 2;
        binary_reverse(dizi, basamak, başlangıç + 1, number);
    }
}

//merge sort
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<math.h>


void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;//sol taraf için
    int n2 = right - mid;//sağ taraf için

    int* L,*R;
    L = (int*)malloc(n1 * sizeof(int));
    R = (int*)malloc(n2 * sizeof(int));

    // Sol ve sağ alt dizileri oluşturma
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];//sol tarafın elemanları eklenir
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];//sağ tarafın elemanları eklenir

    int i = 0, j = 0, k = left;//k ortak dizinin başlangıç noktasıdır

    // L ve R dizilerini sıralı bir şekilde ana diziye birleştirme
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {//soldaki dizi küçükse sağdaki dizi küçükse yapılır
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Kalan elemanları ekleme
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {//binary gibi
        int mid = left + (right - left) / 2;

        // Alt dizileri sıralama
        mergeSort(arr, left, mid);//binary sol tarafın kuralı gibi
        mergeSort(arr, mid + 1, right);//binary sağ tarafın kuralı

        // Alt dizileri birleştirme
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Verilen dizi: ");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("Sıralanmış dizi: ");
    printArray(arr, arr_size);
    return 0;
}
//heap sort
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<math.h>


// Yığın yapısını koruyan heapify fonksiyonu
void heapify(int arr[], int n, int i) {
    int largest = i;          // Kök
    int left = 2 * i + 1;      // Sol çocuk
    int right = 2 * i + 2;     // Sağ çocuk

    // Eğer sol çocuk kökten büyükse
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Eğer sağ çocuk şu ana kadar en büyükten büyükse
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Eğer en büyük, kök değilse yer değiştir
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Alt ağacı da heapify et
        heapify(arr, n, largest);
    }
}

// Heap Sort fonksiyonu
void heapSort(int arr[], int n) {
    // Diziye yığın yapısı oluştur
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Tek tek elemanları yığından çek ve sıralanmış dizinin sonuna koy
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Azalan yığın için kökü yeniden heapify et
        heapify(arr, i, 0);
    }
}

// Diziyi yazdırmak için fonksiyon
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Verilen dizi: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sıralanmış dizi: ");
    printArray(arr, n);
    return 0;
}
