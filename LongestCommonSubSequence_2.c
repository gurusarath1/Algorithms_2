#include <stdio.h>

int LCS(char a[], char b[], int index1, int index2);
int max(int x, int y);

typedef struct memoRecord {

	int index1;
	int index2;
	int soln;

}memoRecord;

memoRecord memo[1000];
int CurrentStore = 0;

int main()
{

	char a[] = "qwertyymmmmmmmcmmmmmmmmmmmmm";
	char b[] = "wrtxqmmccccccccccccccccccccccccccccccc";

	printf("\nLCS = %d\n", LCS(a,b,0,0));

	return 0;
}

int LCS(char a[], char b[], int index1, int index2)
{


	for(int i=0; i<CurrentStore; i++)
	{
		if(memo[i].index1 == index1 && memo[i].index2 == index2)
		{
			printf("\nMemo hit !! (%d , %d , %d)", memo[i].index1, memo[i].index2, memo[i].soln);
			return memo[i].soln;
		}
	}


	if(a[index1] == '\0' || b[index2] == '\0')
	{
		int soln = 0;
		memoRecord temp;
		temp.index1 = index1;
		temp.index2 = index2;
		temp.soln = soln;

		memo[CurrentStore++] = temp;
		return soln;
	}
	else if (a[index1] == b[index2])
	{
		int soln =  1 + LCS(a,b,index1+1,index2+1);
		memoRecord temp;
		temp.index1 = index1;
		temp.index2 = index2;
		temp.soln = soln;

		memo[CurrentStore++] = temp;
		return soln;
	}
	else
	{
		int soln = max(LCS(a,b,index1+1, index2) , LCS(a,b,index1,index2+1));
		memoRecord temp;
		temp.index1 = index1;
		temp.index2 = index2;
		temp.soln = soln;

		memo[CurrentStore++] = temp;
		return soln;
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
