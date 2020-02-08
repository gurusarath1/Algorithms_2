#include <stdio.h>

int gcd(int a, int b);

int main()
{

	printf("\nGCD(4,6) = %d", gcd(4,6));
	printf("\nGCD(3,0) = %d", gcd(3,0));
	printf("\nGCD(111,37) = %d", gcd(111,37));
	printf("\nGCD(1245,165) = %d", gcd(1245,165));
	printf("\nGCD(0,0) = %d", gcd(0,0));
}

int gcd(int a, int b)
{

	/*
	gcd(0,0) = 0
	gcd(a,a) = a
	gcd(a,0) = a
	gcd(a,b) = gcd(a, b - a) if b > a
	gcd(a,b) = gcd(a - b, b) if a > b
	*/

	while(a != 0 && b != 0)
	{
		if(a > b)
		{
			a = a - b;
		} else {
			b = b - a;
		}
	}

	if(a == 0) return b;
	else return a;
}