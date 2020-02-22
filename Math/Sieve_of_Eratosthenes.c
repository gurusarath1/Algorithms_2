#include <stdio.h>
#include <math.h>

int main()
{

	int primesArray[10000];
	double lastNum = 9999;

	for(int i=0; i<lastNum+1; i++)
	{
		primesArray[i] = 1;
	}

	primesArray[0] = 0;
	primesArray[1] = 0;

	int limit = ceil(sqrt(lastNum));

	int numberOfPrimeNumbers = 0;
	for(int i = 2; i <= limit; i++)
	{
		if(primesArray[i] == 1)
		{
			for(int j = i+i; j <= lastNum; j = j+i)
			{
				primesArray[j] = 0;
			}
		}
	}

	for(int i=0 ; i<lastNum; i++)
	{
		if(primesArray[i] == 1)
			printf("\n%d", i);
	}

	printf("\n\n");

	return 0;
}
