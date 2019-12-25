#include <stdio.h>
#define emptyVal -9999999

long long int NthFibNum(int num);

long long int memo[1000];

int main()
{

	for(int i =0; i<1000; i++)
	{
		memo[i] = emptyVal;
	}

	int num = 43;
	printf("\n%dth Fib Num = %lld\n", num, NthFibNum(num));

	return 0;
}

long long int NthFibNum(int num)
{
	if(num == 1)
	{
		return 0;
	}

	if(num == 2)
	{
		return 1;
	}

	if(memo[num] != emptyVal)
	{
		return memo[num];
	}

	long long int soln = NthFibNum(num-1) + NthFibNum(num-2);

	memo[num] = soln;

	return soln;
}
