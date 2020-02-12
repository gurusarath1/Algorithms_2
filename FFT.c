#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358

typedef struct ComplexNumber {

	double magnitude;
	double angle;

} ComplexNumber;


typedef struct ComplexNumber2 {

	double real;
	double img;

} ComplexNumber2;


ComplexNumber RectToPolar(ComplexNumber2 x);
ComplexNumber2 PolarToRect(ComplexNumber x);
ComplexNumber* FFT(double coeffs[], int size);
void printPolar(ComplexNumber x, int newlineFlag);
void printRect(ComplexNumber2 x, int newlineFlag);
void printArray(double* x, int size);

int main()
{

	double a[] = {1,2,-3,4,5,-6,7,8,9,-10,-11,-12,13,14,15,-16};
	int size = sizeof(a) / sizeof(double);

	
	ComplexNumber *Y = FFT(a, size);

	printf("\n-----\n");
	for(int i=0; i<size; i++)
	{
		//printPolar(Y[i], 1);
		printRect(PolarToRect(Y[i]), 1);
	}
	

	/*
	ComplexNumber2 c = {1,1};
	ComplexNumber c2 = {25,PI / 4};
	printPolar(RectToPolar(c), 1);
	printRect(PolarToRect(c2), 1);
	*/
	return 0;
}


ComplexNumber* FFT(double coeffs[], int size)
{

	if(size == 1)
	{
		//printf("\n%lf\n", coeffs[0]);
		ComplexNumber *Y = (ComplexNumber*) malloc(sizeof(ComplexNumber) * size);
		Y[0].magnitude = coeffs[0];
		Y[0].angle = 0;
		return Y;
	}

	int size_half = size / 2;

	double *A_even = (double*) malloc(sizeof(double) * size_half);
	double *A_odd = (double*) malloc(sizeof(double) * size_half);

	for(int i=0, e=0, o=0; i<size; i++)
	{
		if(i%2 == 0)
		{
			A_even[e++] = coeffs[i];
		} else {

			A_odd[o++] = coeffs[i];
		}
	}

	ComplexNumber *E, *D;

	E = FFT(A_even, size_half);
	D = FFT(A_odd, size_half);
	

	ComplexNumber wk;
	ComplexNumber wk_x_dk;
	ComplexNumber2 wk_x_dk_2, ek_2; 
	ComplexNumber2 ek_plus_wk_x_dk_2, ek_minus_wk_x_dk_2;

	int n = size, n_half = size/2;
	ComplexNumber *Y = (ComplexNumber*) malloc(sizeof(ComplexNumber) * size);
	
	//printf("\n------------------\n");
	//printArray(coeffs, size);
	for(int k=0; k<size_half; k++)
	{

		wk.magnitude = 1;
		wk.angle = (-2 * PI * k) / n;

		wk_x_dk.magnitude = wk.magnitude * D[k].magnitude; 
		wk_x_dk.angle = wk.angle + D[k].angle;
		wk_x_dk_2 = PolarToRect(wk_x_dk);
		ek_2 = PolarToRect(E[k]);

		ek_plus_wk_x_dk_2.real = ek_2.real + wk_x_dk_2.real;
		ek_plus_wk_x_dk_2.img = ek_2.img + wk_x_dk_2.img;

		ek_minus_wk_x_dk_2.real = ek_2.real - wk_x_dk_2.real;
		ek_minus_wk_x_dk_2.img = ek_2.img - wk_x_dk_2.img;


		Y[k] = 	RectToPolar(ek_plus_wk_x_dk_2);
		//printPolar(Y[k], 1);
		Y[k + n_half] = RectToPolar(ek_minus_wk_x_dk_2);
		//printPolar(Y[k + n_half], 1);
	}

	//printf("\n------------------\n");
	return Y;
}


ComplexNumber2 PolarToRect(ComplexNumber x)
{
	ComplexNumber2 C;	


	//printf("%lf %lf\n", cos(x.angle), sin(x.angle));
	C.real = x.magnitude * cos(x.angle);
	C.img = x.magnitude * sin(x.angle);

	return C;
}


ComplexNumber RectToPolar(ComplexNumber2 x)
{

	ComplexNumber C;

	C.magnitude = pow( pow(x.real,2) + pow(x.img,2) , 0.5 ); 

	//if(x.real != 0)
		C.angle = atan2(x.img , x.real);
	//else
		//C.angle = 0;
	//C.angle = atan(x.img / x.real);

	return C;
}


void printPolar(ComplexNumber x, int newlineFlag)
{
	if(x.angle >= 0)
	{
		printf("%lf * exp(%lfj)", x.magnitude, x.angle);	
	} else {
		printf("%lf * exp(%lfj)", x.magnitude, x.angle);	
	}

	if(newlineFlag)
	{
		printf("\n");
	}
	
}

void printRect(ComplexNumber2 x, int newlineFlag)
{

	if(x.img >= 0)
	{
		printf("%lf + %lfj", x.real, x.img);	
	} else {
		printf("%lf  %lfj", x.real, x.img);	
	}
	
	if(newlineFlag)
	{
		printf("\n");
	}
}


void printArray(double* x, int size)
{
	printf("[ ");
	for(int i=0; i<size; i++)
		printf("%lf    ", x[i]);
	printf(" ]\n");
}
