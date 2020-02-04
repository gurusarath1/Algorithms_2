#include <stdio.h>

typedef int DATA;

void insertionSort(DATA *a, int size);
void printArray(DATA* a, int size);

int main()
{

	DATA a[] = {4, 5, 3, 3, 2, 1, 7, 8, 9, 7, 11, 50};
	int size =  sizeof(a)/sizeof(int);

	printf("Before sorting -");
	printArray(a, size);

	insertionSort(a, size);

	printf("After sorting -");
	printArray(a, size);
	return 0;
}

void insertionSort(DATA *a, int size)
{
	if(size == 1)
	{
		return;
	}

	insertionSort(a, size-1);

	DATA Element = a[size - 1];
	int index = size - 2;
	DATA temp;
	while(a[index] > Element && index >= 0)
	{
		temp = a[index];
		a[index] = a[index+1];
		a[index+1] = temp;
		index -= 1;
	}

	return;
}

void printArray(DATA* a, int size)
{
	printf("\n");
	for(int i=0; i<size; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
