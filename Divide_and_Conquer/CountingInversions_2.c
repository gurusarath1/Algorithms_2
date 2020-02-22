#include <stdio.h>
#include <stdlib.h>


typedef int DATATYPE;
DATATYPE* mergeSort(DATATYPE* a, int low, int high);
DATATYPE* merge(DATATYPE* ary1, DATATYPE* ary2, int size_1, int size_2);
void printArray(DATATYPE* a, int size);


int inversions = 0;

int main()
{
	DATATYPE a[] = {7,6,5,4,3,2,1};//{9,6,8,4};

	printArray(a,7);

	DATATYPE* p = mergeSort(a,0,6);

	printArray(p,7);

	printf("\nNumber of inversions = %d\n", inversions);

	return 0;
}


DATATYPE* mergeSort(DATATYPE* a, int low, int high)
{
	if (low == high)
	{

		DATATYPE* p = (DATATYPE*) malloc(sizeof(DATATYPE));
		*p = a[low];
		return p;
	}


	int mid = (low + high) / 2;


	DATATYPE* ary1 = mergeSort(a, low, mid);
	DATATYPE* ary2 = mergeSort(a, mid+1, high);

	int size_1 = (mid - low) + 1;
	int size_2 = (high - (mid+1)) + 1;

	DATATYPE* aryMerged = merge(ary1, ary2, size_1, size_2);

	return aryMerged;
}

DATATYPE* merge(DATATYPE* ary1, DATATYPE* ary2, int size_1, int size_2)
{

	int i = 0, j = 0, k = 0;

	DATATYPE* retArray = (DATATYPE*) malloc(sizeof(DATATYPE) * (size_1 + size_2));

	while(i < size_1 && j < size_2)
	{

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

			inversions += (size_1 - i);
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
