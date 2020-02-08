#include <stdio.h>


typedef struct coin {

	int numberOfCoins; // Minimum number of coins to give for a particular j (change) 
	int used_flag; // Flag to indicate if a particular i (denomination) was used for a specific j (change) 

} Coin;


int coinChange_DP(int change, int* denominations, int numberOfDenominations);

int main()
{

	//int denominations[] = {1,2,5,6}; //the first denomination must be 1
	int denominations[] = {1,6,10}; //the first denomination must be 1
	int change = 12;

	int minNumberOfCoinsNeeded = coinChange_DP(change, denominations, sizeof(denominations) / sizeof(int));

	printf("\nMinimum number of coins to give: %d\n", minNumberOfCoinsNeeded);

	return 0;
}


int coinChange_DP(int change, int* denominations, int numberOfDenominations)
{

	Coin table[numberOfDenominations][change+1];

	/*
	j = running current change (column index) (1 to change to give )
	i = index of denomination (row index)
	*/

	//initialize row 1 of the table (for 1$ denomination)
	for(int j=0; j<change+1; j++)
	{
		table[0][j].numberOfCoins = j;
		
		if (j == 0)
			table[0][j].used_flag = 0;
		else
			table[0][j].used_flag = 1;
	}

	for(int i=1; i<numberOfDenominations; i++)
	{
		for(int j=0; j<change+1; j++)
		{

			if (j == 0) // For Zero change
			{
				//No need to give any coin
				table[i][j].numberOfCoins = 0;
				table[i][j].used_flag = 0;

			} else {

				if(j < denominations[i]) // If change is less than the current denomination
				{
					//You can't give any coin of this denomination
					//Hence give coins of lower denomination (prev row)
					table[i][j].numberOfCoins = table[i-1][j].numberOfCoins;
					table[i][j].used_flag = 0;

				} else { // If change is greater than or equal to the current denomination

					//Check for optimal option
					if(	(table[i-1][j].numberOfCoins) < (1 + table[i][j - denominations[i]].numberOfCoins ) )
					{
						//Optimal option is not to give this denomination
						table[i][j].numberOfCoins = table[i-1][j].numberOfCoins;
						table[i][j].used_flag = 0;

					} else {

						//Optimal option is to give this denomination
						table[i][j].numberOfCoins = 1 + table[i][j - denominations[i]].numberOfCoins;
						table[i][j].used_flag = 1;

					}

				}

			}

		}

	}



	//Loop below generates the values of coins to give (using the used_flag variable)
	printf("Coins to Give: ");
	int i = numberOfDenominations-1;
	int j = change;
	while(j != 0)
	{

		if(!table[i][j].used_flag)
		{
			i--;

		} else {

			printf("%d  ", denominations[i]);
			j = j - denominations[i];
		}

	}
	printf("\n");


	// Print Table
	for(int i=0; i<numberOfDenominations; i++)
	{
		for(int j=0; j<change+1; j++)
		{

			if(j == 0)
			{
				printf("%d:  ", denominations[i]);
			}

			printf("{%d , %d}   ", table[i][j].numberOfCoins, table[i][j].used_flag);
		}
		printf("\n");
	}

	return table[numberOfDenominations-1][change].numberOfCoins;
}