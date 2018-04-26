#include "inc/search.h"

int linearsearch(int *array, int l, int s)
{
	int i = 0;

	for (i = 0; i < (l + 1); i++)
	{
		if (array[i] == s)
		{
			return i;
		}
	}
	
	return -1;	
}