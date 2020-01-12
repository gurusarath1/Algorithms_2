#include <stdio.h>
#include <stdlib.h>

typedef float DATA_MATRIX;

DATA_MATRIX** createRowColEliminatedMat(int size; DATA_MATRIX a[size][size], int size, int row, int col);
double Determinant(int size; DATA_MATRIX a[size][size], int size);


int main()
{



	DATA_MATRIX a[10][10];

	int N = 0;
	printf("Enter the size of the matrix N*N ?  ");
	scanf("%d", &N);

	printf("Enter the elements of the matrix - \n");
	for(int i=0; i<N; i++)
	{
		printf("\nEnter the entries of row %d\n", i);
		for(int j=0; j<N; j++)
		{
			scanf("%f", &a[i][j]);
		}
	}

	//DATA_MATRIX b[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	//DATA_MATRIX **x = createRowColEliminatedMat(b, 3, 1, 1);

/*
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
			printf("%f\t", x[i][j]);

		printf("\n");
	}
*/


	printf("\nDet = %lf\n", Determinant(a,N));

	return 0;

}



double Determinant(int size; DATA_MATRIX a[size][size], int size)
{

	//printf("size = %d\n", size);

	if(size == 1)
	{
		printf("Here %lf", a[0][0]);
		return a[0][0];
	}


	int n = size - 1;
	double det = 0;
	DATA_MATRIX **x;

	x = createRowColEliminatedMat(a, size, 0, 2);;

	for(int j=0; j<size; j++)
	{
		x = createRowColEliminatedMat(a, size, 0, j);


	for(int m=0; m<n; m++)
	{
		for(int p=0; p<n; p++)
			printf("%f\t", x[m][p]);

		printf("\n");
	}


		if( j%2 == 0 )
		{
			det += a[0][j] * Determinant(x, n);
		} else {

			det -= a[0][j] * Determinant(x, n);
		}
	}


	return det;
}

DATA_MATRIX** createRowColEliminatedMat(int size; DATA_MATRIX a[size][size], int size, int row, int col)
{

	int n = size - 1;

/*
	DATA_MATRIX **mat = (DATA_MATRIX**) malloc(sizeof( DATA_MATRIX* ) * n); //rows

	for(int i=0; i<n; i++)
	{
		mat[i] = (DATA_MATRIX*) malloc(sizeof(DATA_MATRIX) * n); //cols
	}

*/

	DATA_MATRIX *((*mat)[n]) = (DATA_MATRIX[n][n]) malloc(sizeof( DATA_MATRIX* ) * n)


//	for(int i=0; i<size; i++)
//		for(int j=0; j<size; j++)
//			printf("%f",  a[i][j]    );


	int x = 0;
	int y = 0;
	for(int i=0; i<size; i++)
	{
		if( i == row )
		{
			continue;
		}

		y = 0;
		for(int j=0; j<size; j++)
		{
			if( j == col )
			{
				continue;
			}

			//printf("\n%f\n", a[i][j]  );
			//printf("\nxy = %d - %d\n", x , y);
			//printf("\nij = %d - %d\n", i , j);;
			mat[x][y] = a[i][j];
			//mat[x][y] = 8;
			y += 1;
		}
		x += 1;
	}

	//printf("\nReturn\n");
	return mat;
}
