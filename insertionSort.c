#include<stdio.h>

typedef int DATATYPE;
void insertionSort(DATATYPE a[], int size);
void printArray(DATATYPE a[], int size);

int main()
{

	DATATYPE a[] = {3,4,5,6,1,2,2,3,34,65,12,98,45,90};

	int size = sizeof(a) / sizeof(DATATYPE);

	printf("Size of the array = %d\n", size);

	printArray(a,size);

	insertionSort(a,size);

	printArray(a,size);

	return 0;
}

void insertionSort(DATATYPE a[], int size)
{

	DATATYPE temp;
	int j;

	for(int i=1; i<size; i++)
	{
		if(a[i] < a[i-1])
		{
			j = i;
			while(a[j] < a[j-1] && j >= 1)
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				j--;
			}
		}
	}

}

void printArray(DATATYPE a[], int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%d  ", a[i]);
	}

	printf("\n\n");
}
