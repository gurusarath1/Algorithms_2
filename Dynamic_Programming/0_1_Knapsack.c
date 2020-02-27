#include <stdio.h>

int max(int a, int b);
int Zero_1_Knapsack(int* values, int* weights, int limit, int size);
int Zero_1_Knapsack_support(int* values, int* weights, int limit, int size, int currentWeight, int currentvalue, int itemIndex);

int main()
{

	int values[] = {10,40,30,50};
	int weights[] = {5,4,6,3};
	int limit = 10;

	printf("%d\n", Zero_1_Knapsack(values, weights, limit, sizeof(values) / sizeof(int)) );
	return 0;
}

int Zero_1_Knapsack(int* values, int* weights, int limit, int size)
{
	if(limit < weights[0])
	{
		return Zero_1_Knapsack_support(values, weights, limit, size, 0, 0, 1);
	}

	return max(
		Zero_1_Knapsack_support(values, weights, limit, size, weights[0], values[0], 1) ,
		Zero_1_Knapsack_support(values, weights, limit, size, 0, 0, 1)
		 );
}

int Zero_1_Knapsack_support(int* values, int* weights, int limit, int size, int currentWeight, int currentvalue, int itemIndex)
{

	if(itemIndex >= size)
		return currentvalue;
		//return currentWeight // To maximize weight

	if(limit < currentWeight + weights[itemIndex])
	{

		return Zero_1_Knapsack_support(values, weights, limit, size, currentWeight, currentvalue, itemIndex + 1);

	} else {

		return max(
					Zero_1_Knapsack_support(values, weights, limit, size, currentWeight + weights[itemIndex], currentvalue + values[itemIndex], itemIndex + 1) , 
					Zero_1_Knapsack_support(values, weights, limit, size, currentWeight, currentvalue, itemIndex + 1)
				);

	}

}


int max(int a, int b)
{
	if(a > b)
	{
		return a;

	} else {

		return b;
	}
}

/*

OUTPUT ----------------------

90


*/