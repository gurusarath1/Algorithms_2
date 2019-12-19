#include <stdio.h>

int LCS(char a[], char b[], int index1, int index2);
int max(int x, int y);

int main()
{

	char a[] = "qwertyy";
	char b[] = "wrtxq";

	printf("\nLCS = %d\n", LCS(a,b,0,0));

	return 0;
}

int LCS(char a[], char b[], int index1, int index2)
{

	if(a[index1] == '\0' || b[index2] == '\0')
	{
		return 0;
	}
	else if (a[index1] == b[index2])
	{
		return 1 + LCS(a,b,index1+1,index2+1);
	}
	else
	{
		return max(LCS(a,b,index1+1, index2) , LCS(a,b,index1,index2+1));
	}

}

int max(int x, int y)
{

	if (x >= y)
	{
		return x;
	} else {

		return y;
	}

}
