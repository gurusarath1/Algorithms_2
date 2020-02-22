#include <stdio.h>

float cutRod(float priceList[], int rodLength);
float max(float a, float b);

int memo[100];

int main()
{

	float p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20}; // always start the array with 0
	int length = 8;

	printf("\nROD Cost (length = %d) = %f\n", length, cutRod(p,length));

	return 0;

}

float cutRod(float priceList[], int rodLength)
{
	memo[0] = 0;

	for(int i=1; i<=rodLength; i++)
	{

		float cost = -999999;
		for(int j=1; j<=i; j++)
		{
			cost = max(cost, priceList[j] + memo[i-j]);
		}

		memo[i] = cost;
	}

	return memo[rodLength];
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
