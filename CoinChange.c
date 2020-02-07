#include <stdio.h>


typedef struct coin {

	int numberOfCoins;
	int used_flag;

} Coin;


int coinChange_DP(int change, int* denominations, int numberOfDenominations);

int main()
{

	//int denominations[] = {1,2,5,6}; //the first denomination must be 1
	int denominations[] = {1,6,10};
	int change = 12;

	int minNumberOfCoinsNeeded = coinChange(change, denominations, sizeof(denominations) / sizeof(int));

	printf("\n%d\n", minNumberOfCoinsNeeded);

	return 0;
}


int coinChange_DP(int change, int* denominations, int numberOfDenominations)
{

	Coin table[numberOfDenominations][change+1];

	/*

	j = running current change (column index) (1 to change to give )
	i = index of denomination (row index)

	*/

	for(int j=0; j<change+1; j++)
	{
		table[0][j].numberOfCoins = j;
		table[0][j].used_flag = 1;
	}

	for(int i=1; i<numberOfDenominations; i++)
	{
		for(int j=0; j<change+1; j++)
		{

			if (j == 0)
			{

				table[i][j].numberOfCoins = 0;
				table[i][j].used_flag = 0;

			} else {

				if(j < denominations[i])
				{

					table[i][j].numberOfCoins = table[i-1][j].numberOfCoins;
					table[i][j].used_flag = 0;

				} else {

					if(	(table[i-1][j].numberOfCoins) < (1 + table[i][j - denominations[i]].numberOfCoins ) )
					{

						table[i][j].numberOfCoins = table[i-1][j].numberOfCoins;
						table[i][j].used_flag = 0;

					} else {

						table[i][j].numberOfCoins = 1 + table[i][j - denominations[i]].numberOfCoins;
						table[i][j].used_flag = 1;

					}

				}

			}

		}

	}

	for(int i=0; i<numberOfDenominations; i++)
	{
		for(int j=0; j<change+1; j++)
		{
			printf("{%d , %d}   ", table[i][j].numberOfCoins, table[i][j].used_flag);
		}
		printf("\n");
	}


	return table[numberOfDenominations-1][change].numberOfCoins;
}