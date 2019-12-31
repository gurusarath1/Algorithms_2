#include <stdio.h>

int GaussianElimination(double a[][10], int r, int c, int printSteps);
int swapRows(double a[][10], int row1, int row2, int numCols);
int replaceRow(double a[][10], int rowToReplace, int rowX, double k, int numCols);
int printMatrix(double a[][10], int numRow, int numCol);


int main()
{


	double augMat[10][10];
	int r,c;

	printf("Number of Rows in the augmented matrix ? ");
	scanf("%d", &r);
	printf("Number of Cols in the augmented matrix ? ");
	scanf("%d", &c);

	printf("Enter the elements of the augmented matrix \n");

	for(int i=0; i<r; i++)
	{
		printf("Enter elements of row %d \n", i+1);
		for(int j=0; j<c; j++)
			scanf("%lf", &augMat[i][j]);
	}

	GaussianElimination(augMat, r, c, 1);
	printMatrix(augMat, r, c);

	return 0;
}

int GaussianElimination(double augMat[][10], int r, int c, int printSteps)
{

	int fixedCol, tempRow;
	double k;
	int swapRequiredFlag = 0, skipFlag = 0;

	for(int rowX=0; rowX<r; rowX++)
	{

		if(printSteps)
		{
			printMatrix(augMat, r, c);
		}

		fixedCol = rowX;

		skipFlag = 0;
		swapRequiredFlag = 0;
		tempRow = rowX;
		while(augMat[tempRow][fixedCol] == 0)
		{
			swapRequiredFlag = 1;
			tempRow++;

			if(tempRow >= r)
			{
				skipFlag = 1;
			}
		}

		if(skipFlag) continue;

		if(swapRequiredFlag)
		{
			swapRows(augMat, tempRow, rowX, c);
			if(printSteps)
			{
				printf("\nRows %d and %d were swapped.", rowX+1, tempRow+1);
			}
		}

		for(int rowY = rowX+1; rowY<r; rowY++)
		{

			k = -(augMat[rowY][fixedCol] / augMat[rowX][fixedCol]);
			replaceRow(augMat, rowY, rowX, k, c);
			if(printSteps)
			{
				printf("\nR%d <- %lf*R%d + R%d.", rowY+1, k, rowX+1, rowY+1);
			}
		}

	}

	return 0;
}


int swapRows(double a[][10], int row1, int row2, int numCols)
{
	double temp;

	for(int i=0; i<numCols; i++)
	{
		temp = a[row1][i];
		a[row1][i] = a[row2][i];
		a[row2][i] = temp;
	}

	return 0;
}

int replaceRow(double a[][10], int rowToReplace, int rowX, double k, int numCols)
{
	for(int i=0; i<numCols; i++)
	{
		a[rowToReplace][i] += k * a[rowX][i];
	}

	return 0;
}

int printMatrix(double a[][10], int numRow, int numCol)
{
	printf("\n");

	for(int i=0; i<numRow; i++)
	{
		for(int j=0; j<numCol; j++)
		{
			printf("%lf\t", a[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	return 0;
}
