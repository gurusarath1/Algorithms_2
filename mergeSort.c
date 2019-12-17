#include <stdio.h>
#include <stdlib.h>


typedef int DATATYPE;
DATATYPE* mergeSort(DATATYPE* a, int low, int high);
DATATYPE* merge(DATATYPE* ary1, DATATYPE* ary2, int size_1, int size_2);
void printArray(DATATYPE* a, int size);

int main()
{
	DATATYPE a[] = {1,2,4,5,3,8,5,6,7,8,10,34,56,78,89,56,1,1,2,56,88,23,25,89,56};

	printArray(a, 25);

	DATATYPE* p = mergeSort(a,0,24);

	printArray(p,25);

	return 0;
}


DATATYPE* mergeSort(DATATYPE* a, int low, int high)
{

	if (low == high)
	{
		//printf("\nTermination = %d %d - %d\n", low, high, a[0]);
		DATATYPE* p = (DATATYPE*) malloc(sizeof(DATATYPE));
		*p = a[low];
		return p;
	}


	int mid = (low + high) / 2;


	DATATYPE* ary1 = mergeSort(a, low, mid);
	DATATYPE* ary2 = mergeSort(a, mid+1, high);

	int size_1 = (mid - low) + 1;
	int size_2 = (high - (mid+1)) + 1;

	//printf("\nL H = %d %d\n", low, high);
	//printf("\nS1 S2 = %d %d\n", size_1, size_2);

	DATATYPE* aryMerged = merge(ary1, ary2, size_1, size_2);

	return aryMerged;

}

DATATYPE* merge(DATATYPE* ary1, DATATYPE* ary2, int size_1, int size_2)
{

	int i = 0, j = 0, k = 0;

	//printArray(ary1, size_1);
	//printArray(ary2, size_2);

	DATATYPE* retArray = (DATATYPE*) malloc(sizeof(DATATYPE) * (size_1 + size_2));

	while(i < size_1 && j < size_2)
	{
		//printf("\n%d %d %d %d",i,j,ary1[i],ary2[j]);

		if(ary1[i] < ary2[j])
		{
			retArray[k] = ary1[i];
			i++;
			k++;
			continue;
		}

		if(ary1[i] > ary2[j])
		{
			retArray[k] = ary2[j];
			j++;
			k++;
			continue;
		}

		if(ary1[i] == ary2[j])
		{
			retArray[k++] = ary1[i];
			retArray[k] = ary2[j];
			k++;
			i++;
			j++;
			continue;
		}
	}


	while(i < size_1)
	{
		retArray[k] = ary1[i];
		i++;
		k++;
	}


	while(j < size_2)
	{
		retArray[k] = ary2[j];
		j++;
		k++;
	}

	//printArray(retArray, size_1 + size_2);

	return retArray;

}

void printArray(DATATYPE* a, int size)
{

	printf("\n");

	for(int i=0; i<size; i++)
	{
		printf(" %d ", a[i]);
	}

	printf("\n");

}
