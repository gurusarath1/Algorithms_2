#include <stdio.h>

long long int findOptimalMultiply(int M_sizes[], int numElements);

int main()
{

	int a[] = {30,35,15,5,10,20,25};
	int b[] = {5,10,3,12,5,50,6};

	printf("\nMin Multiplications needed = %lld\n\n\n", findOptimalMultiply(a, sizeof(a)/sizeof(int)));
	printf("\nMin Multiplications needed = %lld\n", findOptimalMultiply(b, sizeof(b)/sizeof(int)));

	return 0;
}


long long int findOptimalMultiply(int M_sizes[], int numElements)
{

	long long int optimalMultiplyTable[numElements][numElements];
	int numMats = numElements - 1;

	for(int i=0; i<numElements; i++)
		for(int j=0; j<numElements; j++)
			optimalMultiplyTable[i][j] = 0;


	//  A[i .. k .. j]
	// left = A[i, j-k]
	// right = A[j-k+1, j]
	long long int min, left, right, combine, val;

	for(int m=1; m <= numMats; m++ )
	for(int i = 1, j = m+1; i<=numMats && j <= numMats; i++, j++)
	{
		//printf("(%d %d)---------------\n", i, j);
		
		min = 9999999;
		for(int k=1; k <= m; k++)
		{
			left = optimalMultiplyTable[i][j-k];
			//printf("%d: (%d %d) %lld\n", k, i, j-k, left);
			
			right = optimalMultiplyTable[j-k+1][j];
			//printf("%d: (%d %d) %lld\n", k, j-k+1, j, right);
			
			combine =   M_sizes[i-1] * M_sizes[j-k+1-1] * M_sizes[j+1-1]; // -1 offset because array index starts from 0
			//printf("%d: (%d %d %d) %lld\n", k, i, j-k+1, j+1, combine);

			val = left + right + combine;

			if(min > val)
			{
				min = val;
			}
		}	

		optimalMultiplyTable[i][j] = min;	
	}

	int printMat = 1;

	if(printMat)
	for(int i=1; i<numElements; i++)
	{
		for(int j=1; j<numElements; j++)
		{
			printf("%d\t", optimalMultiplyTable[i][j]);
		}
		printf("\n");
	}

	return optimalMultiplyTable[1][numMats];
}

/*
OUTPUT ----------------

0       15750   7875    9375    11875   15125
0       0       2625    4375    7125    10500
0       0       0       750     2500    5375
0       0       0       0       1000    3500
0       0       0       0       0       5000
0       0       0       0       0       0

Min Multiplications needed = 15125





0       150     330     405     1655    2010
0       0       360     330     2430    1950
0       0       0       180     930     1770
0       0       0       0       3000    1860
0       0       0       0       0       1500
0       0       0       0       0       0

Min Multiplications needed = 2010

*/

