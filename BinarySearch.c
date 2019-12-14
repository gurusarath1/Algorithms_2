#include <stdio.h>

enum location{
	any,
	first,
	last
};

int BinarySearch(int a[], int searchElement, int low, int high, enum location l);

int main()
{

	int a[] = {1,3,5,5,5,5,5,8,9,10,16,19,19,23,45,69,77,100};

	printf("Any = %d", BinarySearch(a,199,0,18, any));
	printf("First = %d", BinarySearch(a,199,0,18, first));
	printf("Last = %d", BinarySearch(a,199,0,18, last));

	return 0;
}

int BinarySearch(int a[], int searchElement, int low, int high, enum location l)
{
	int mid = (low + high)/2;
	int current_found_loc = -1;
	while(low <= high)
	{
		if(a[mid] == searchElement)
		{
			if (l == any)
			{
				return mid;
			} else if (l == first)
			{
				current_found_loc = mid;
				high = mid - 1;
			}else if (l == last)
			{
				current_found_loc = mid;
				low = mid + 1;
			}

		} else if (a[mid] > searchElement)
		{
			high = mid - 1;
		} else if (a[mid] < searchElement)
		{
			low = mid + 1;
		}

		mid = (low + high)/2;
	}

	return current_found_loc;

}
