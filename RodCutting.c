#include <stdio.h>

float cutRod(float priceList[], int rodLength);
float max(float a, float b);

int main()
{

	float p[] = {0, 2, 1, 3, 4}; // always start the array with 0
	int length = 4;

	printf("\nROD Cost (length = %d) = %f\n", length, cutRod(p,length));

	return 0;

}

float cutRod(float priceList[], int rodLength)
{
	if(rodLength == 0)
	{
		return 0;
	}

	float cost = -999999;
	for(int i=1; i<=rodLength; i++)
	{
		cost = max(cost, priceList[i] + cutRod(priceList, rodLength-i));
	}

	return cost;
}

float max(float a, float b)
{

	if(a >= b)
	{
		return a;
	} else {

		return b;
	}

}
