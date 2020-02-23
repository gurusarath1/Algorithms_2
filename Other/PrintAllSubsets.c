#include <stdio.h>
#include <stdlib.h>
#define NOT_INCLUDED -999

typedef int DATA_SUBSET;
int printAllSubsets(DATA_SUBSET set[], int size);
void printAllSubsets_recc(DATA_SUBSET set[], DATA_SUBSET CurrentSet[], int size, int location, int include);
void copySet(DATA_SUBSET from[], DATA_SUBSET to[], int size);
void printSet(DATA_SUBSET a[], int size);

int main()
{

	DATA_SUBSET x[] = {0,1,2,3}; 
	printAllSubsets(x, sizeof(x) / sizeof(DATA_SUBSET));

	return 0;
}

int printAllSubsets(DATA_SUBSET set[], int size)
{

	DATA_SUBSET* a1 = (DATA_SUBSET*)malloc(sizeof(DATA_SUBSET) * size);
	printAllSubsets_recc(set, a1, size, 0, 1);
	DATA_SUBSET* a2 = (DATA_SUBSET*)malloc(sizeof(DATA_SUBSET) * size);
	printAllSubsets_recc(set, a2, size, 0, 0);
	return 0;

}

void printAllSubsets_recc(DATA_SUBSET set[], DATA_SUBSET CurrentSet[],int size, int location, int include)
{	

	//printf("loc= %d  ", location);
	if(location == size-1)
	{

		DATA_SUBSET* a1 = (DATA_SUBSET*)malloc(sizeof(DATA_SUBSET) * size);
		copySet(CurrentSet, a1, size);
		if(include) a1[location] = set[location]; else a1[location] = NOT_INCLUDED;

		printSet(a1,size);
		return;
	}

	DATA_SUBSET* a1 = (DATA_SUBSET*)malloc(sizeof(DATA_SUBSET) * size);
	copySet(CurrentSet, a1, size);
	if(include) a1[location] = set[location]; else a1[location] = NOT_INCLUDED;

	printAllSubsets_recc(set, a1, size, location+1, 1);


	DATA_SUBSET* a2 = (DATA_SUBSET*)malloc(sizeof(DATA_SUBSET) * size);
	copySet(CurrentSet, a2, size);
	if(include) a2[location] = set[location]; else a2[location] = NOT_INCLUDED;
	
	printAllSubsets_recc(set, a2, size, location+1, 0);

}

void printSet(DATA_SUBSET a[], int size)
{
	printf("{ ");
	for(int i=0; i<size; i++)
	{
		if(a[i] != NOT_INCLUDED)
			printf("%d ", a[i]);
	}
	printf("}\n");
}

void copySet(DATA_SUBSET from[], DATA_SUBSET to[], int size)
{
	for(int i=0; i<size; i++)
	{
		to[i] = from[i];
	}
}


/*
OUTPUT ----------------

{ 0 1 2 3 }
{ 0 1 2 }
{ 0 1 3 }
{ 0 1 }
{ 0 2 3 }
{ 0 2 }
{ 0 3 }
{ 0 }
{ 1 2 3 }
{ 1 2 }
{ 1 3 }
{ 1 }
{ 2 3 }
{ 2 }
{ 3 }
{ }

*/