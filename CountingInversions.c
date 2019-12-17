#include <stdio.h>

enum printFlag {yes, no};

int countInversions(int a[], int size, enum printFlag printInversionsFlag);

int main()
{

	int a[6] = {1,3,5,2,4,6};

	printf("\nNumber of Inversions = %d ", countInversions(a,6,yes));

	return 0;
}

int countInversions(int a[], int size, enum printFlag printInversionsFlag)
{
	int inversions = 0;
	for (int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if(a[j] < a[i]) 
			{
				inversions++;
				if(printInversionsFlag == yes)
				{
					printf("\n( %d , %d )", a[i],a[j]);
				}

			}
		}
	}

	return inversions;
}
