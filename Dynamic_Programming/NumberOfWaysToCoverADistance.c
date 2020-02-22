#include <stdio.h>
#include <stdlib.h>

int CoverDistance(int Distance, int Steps[], int sizeOfArray, int smallestStep);

int main()
{


	int Distance = 5;
	int steps[] = {1,2,3,4};

	printf("\n%d\n", CoverDistance(Distance, steps, sizeof(steps)/sizeof(int), steps[0])  );

	return 0;
}

int CoverDistance(int Distance, int Steps[], int sizeOfArray, int smallestStep)
{
	int result;

	if(Distance == 0)
	{
		return 1;
	}

	if(Distance < smallestStep)
	{
		return 0;
	}

	int total = 0;
	for(int i=0; i < sizeOfArray; i++)
	{
		result = CoverDistance(Distance - Steps[i], Steps, sizeOfArray, smallestStep);

		total += result;
	}

	return total;

}