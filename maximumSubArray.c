#include <stdio.h>

typedef int DATATYPE;

typedef struct package {

	int low;
	int high;
	DATATYPE sum;
}package;

package maxSubArray(DATATYPE* a, int low, int high);
package maxSplitSubArray(DATATYPE* a, int low, int mid, int high);

int main()
{

	DATATYPE a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	DATATYPE b[] = {5,6,7,8,9,1,2,3};

	package x = maxSubArray(a,0,15);
	printf("\nLow Index = %d\nHigh Index = %d\nSum =  %d\n", x.low, x.high, x.sum);



	x = maxSubArray(b,0,7);
	printf("\nLow Index = %d\nHigh Index = %d\nSum =  %d\n", x.low, x.high, x.sum);


	return 0;
}

package maxSubArray(DATATYPE* a, int low, int high)
{

	if (low == high)
	{
		package p;
		p.low = low;
		p.high = low;
		p.sum = a[low];
		return p;
	}

	int mid = (low + high) / 2;

	package leftPack = maxSubArray(a, low, mid);
	package rightPack = maxSubArray(a, mid+1, high);
	package splitPack = maxSplitSubArray(a, low, mid, high);

	package maxArrayPack;

	if (leftPack.sum > rightPack.sum && leftPack.sum > splitPack.sum)
	{
		maxArrayPack = leftPack;
	} else if (rightPack.sum > leftPack.sum && rightPack.sum > splitPack.sum)
	{
		maxArrayPack = rightPack;
	} else {

		maxArrayPack = splitPack;
	}

	return maxArrayPack;

}

package maxSplitSubArray(DATATYPE* a, int low, int mid, int high)
{

	package splitPack;

	DATATYPE leftSum = -999999;
	DATATYPE sum = 0;
	int MaxLeftIndex;
	for (int i=mid; i>= low; i--)
	{
		sum += a[i];

		if (sum > leftSum)
		{
			leftSum = sum;
			MaxLeftIndex = i;
		}
	}


	DATATYPE rightSum = -99999;
	sum = 0;
	int MaxRightIndex;
	for (int i = mid+1; i <= high; i++)
	{
		sum += a[i];

		if(sum > rightSum)
		{
			rightSum = sum;
			MaxRightIndex = i;
		}
	}


	splitPack.low = MaxLeftIndex;
	splitPack.high = MaxRightIndex;
	splitPack.sum = leftSum + rightSum;

	return splitPack;
}

