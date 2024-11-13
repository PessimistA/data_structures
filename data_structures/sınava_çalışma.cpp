//iterative fibonacci
int array[100] = { 2,4,6,7,8 };

int main() {
	int fibonacci[100];
	int first=0,second=1;
	

	for (int i = 0; i < 10; i++)
	{
		if (first==0&&second==1)
		{
			fibonacci[0] = first;
			fibonacci[1] = second;
			i = 2;
		}

			int geç = first + second;
			first = second;
			second = geç;
			fibonacci[i] = geç;
		
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", fibonacci[i]);
	}	
	return 0;
}

//iterative binary
int array[100] = { 2,4,6,7,8 };
int main() {
	int len = 0;
	for (int i = 0; i < 100; i++)
	{
		if (array[i]!=0)
		{
			len++;
		}
	}
	int search = 4;
	int sol = 0, sağ = len;
	while (sol <= sağ) {
		int middle = (sol + sağ) / 2;
		if (search < array[middle]) {
			sağ = middle - 1;
		}
		else if (search > array[middle]) {
			sol = middle + 1;
		}
		else if (search == array[middle])
		{
			printf("%d", middle);
			break;
		}		
	}	
	return 0;
}
