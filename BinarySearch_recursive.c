#include <stdio.h>

int BinarySearch(int a[], int searchElement, int low, int high);

int main()
{

	int a[] = {2,4,6,7,8,9,10,14,18,26,78,90,100};

	printf("%d",BinarySearch(a,90,0,13));


	return 0;
}


int BinarySearch(int a[], int searchElement, int low, int high)
{

	if(low == high)
	{
		if(searchElement == a[low])
		{
			return low;
		} else {
			return -1;
		}
	} else {

		int mid = (low + high)/2;

		if(searchElement == a[mid])
		{
			return mid;
		} else if (a[mid] < searchElement)
		{
			BinarySearch(a,searchElement, mid+1, high);
		} else {
			BinarySearch(a,searchElement, low, high-1);
		}
	}
}
