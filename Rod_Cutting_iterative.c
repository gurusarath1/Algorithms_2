#include <stdio.h>

int cutRod(int L, int prices[]);
int optimalRevenue[15];


int main()
{
	int L = 10;
	int prices[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; // First element should be 0 (Rod of length 0)

	printf("\n\nBest price possible: %d", cutRod(L,prices));

	return 0;
}


int cutRod(int L, int prices[])
{
	int max, printTableFlag = 1;

	for(int i=1; i<=L; i++) // Start from rod of length 1 to L
	{
		max = prices[i]; // Price for No cuts 
		for(int j=0; j <= (i/2); j++) //Division
		{
			if(max < optimalRevenue[j] + optimalRevenue[i - j])
			{
				max = optimalRevenue[j] + optimalRevenue[i - j]; 
			}
		}

		optimalRevenue[i] = max;
	}

	
	if(printTableFlag)
	{
		printf("\nOptimal Revenue Table ----------\n");
		for(int i=0; i<=L; i++)
		{
			printf("%d : %d\n", i, optimalRevenue[i]);
		}
		printf("----------\n");
	}
	

	return optimalRevenue[L];
}

/*
OUTPUT ------------------------

Optimal Revenue Table ----------
0 : 0
1 : 1
2 : 5
3 : 8
4 : 10
5 : 13
6 : 17
7 : 18
8 : 22
9 : 25
10 : 30
----------


Best price possible: 30


*/