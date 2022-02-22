#include <stdio.h>

typedef int DATATYPE;

int QuickSort(DATATYPE a[], int low, int high);
int partition(DATATYPE a[], int low, int high);
void swap(DATATYPE* a, DATATYPE* b);
int printArray(DATATYPE a[], int size);

int main()
{

	DATATYPE a[15] = {30,6,7,5,6,6,6,9,10,12,34,86,45,78,89};

	printArray(a,15);

	printf("\n\n");
	QuickSort(a,0,16);

	printArray(a,15);

	return 0;
}


int QuickSort(DATATYPE a[], int low, int high)
{

	if(low >= high) return 0;

	int k = partition(a,low,high);

	QuickSort(a,0,k);
	QuickSort(a,k+1,high);

}

int partition(DATATYPE a[], int low, int high)
{

	DATATYPE pivot = a[low];
	int i = low;
	int j = high;

	while(i < j)
	{
		do
		{
			i++;
		}while(a[i] <= pivot);

		do
		{
			j--;
		}while(a[j] > pivot);

		if(i < j)
		{
			swap(&a[i], &a[j]);
		}
	}

	swap(&a[j],&a[low]);

	return j;
}

void swap(DATATYPE* a, DATATYPE* b)
{
	DATATYPE temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

int printArray(DATATYPE a[], int size)
{

	for(int i=0; i<size; i++)
	{
		printf("%d  ", a[i]);
	}

}
