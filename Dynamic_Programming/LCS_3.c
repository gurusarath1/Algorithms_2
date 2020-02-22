#include <stdio.h>

int LCS_bottomUp(char a[], char b[], int size1, int size2);

int main()
{

	char str2[] = "BDCABA";
	char str1[] = "ABCBDAB";

	printf("\nLength of longest common subsequence = %d\n", LCS_bottomUp(str1, str2, sizeof(str1)/sizeof(char) - 1, sizeof(str2)/sizeof(char) - 1));


	return 0;
}


int LCS_bottomUp(char a[], char b[], int size1, int size2)
{
	int optimalSolution[size1+1][size2+1];
	char reConstructionMatrix[size1+1][size2+1];

	for(int i=0; i < size2+1; i++)
		optimalSolution[0][i] = 0;

	for(int i=0; i < size1+1; i++)
		optimalSolution[i][0] = 0;


	for(int i=1; i < size1+1; i++)
	{
		for(int j=1; j < size2+1; j++)
		{
			if(a[i-1] == b[j-1])
			{

				optimalSolution[i][j] = optimalSolution[i-1][j-1] + 1;
				reConstructionMatrix[i][j] = '\\'; //Diagonal

			} else if (optimalSolution[i-1][j] >= optimalSolution[i][j-1]) {

				optimalSolution[i][j] = optimalSolution[i-1][j];
				reConstructionMatrix[i][j] = '^'; //Up
			
			} else {
			
				optimalSolution[i][j] = optimalSolution[i][j-1];
				reConstructionMatrix[i][j] = '<'; //Left
			
			}
		}
	}


	//// Print the matrix

	if(1)
	{
		for(int i=0; i<size1+1; i++)
		{
			for(int j=0; j<size2+1; j++)
			{
				if(i != 0 && j != 0)
				{
					printf("%d %c\t", optimalSolution[i][j], reConstructionMatrix[i][j]);
				}
				else
				{
					if(i == 0 && j ==0)
						printf(" \t");
					if(i == 0 && j > 0)
						printf("%c\t", b[j-1]);
					if(j == 0 && i > 0)
						printf("%c\t", a[i-1]);
				}
			}
			printf("\n");
		}
	}


	/// Reconstructing LCS  --------------------------------

	int i = size1;
	int j = size2;
	int k = optimalSolution[size1][size2];
	char LCS[ optimalSolution[size1][size2] + 1];

	LCS[k] = '\0'; // Order will be reversed, so go from last index

	while(i != 0 && j != 0)
	{
		if(reConstructionMatrix[i][j] == '\\')
		{
			i = i - 1;
			j = j - 1;
			LCS[k--] = a[i];
		}

		if(reConstructionMatrix[i][j] == '^')
		{
			i = i - 1;
		}

		if(reConstructionMatrix[i][j] == '<')
		{
			j = j - 1;
		}
	}

	printf("LCS = %s",LCS);

	return optimalSolution[size1][size2];
}

/*

OUTPUT -----------------

        B       D       C       A       B       A
A       0 ^     0 ^     0 ^     1 \     1 <     1 \
B       1 \     1 <     1 <     1 ^     2 \     2 <
C       1 ^     1 ^     2 \     2 <     2 ^     2 ^
B       1 \     1 ^     2 ^     2 ^     3 \     3 <
D       1 ^     2 \     2 ^     2 ^     3 ^     3 ^
A       1 ^     2 ^     2 ^     3 \     3 ^     4 \
B       1 \     2 ^     2 ^     3 ^     4 \     4 ^
LCS = BCBA
Length of longest common subsequence = 4



*/