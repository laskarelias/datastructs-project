#include "inc/search.h"

int interpolationsearch(int *array, int l, int s)
{
	int left = 0;
	int right = l;

	while ((left <= right) && (s >= array[left]) && (s <= array[right]))
	{
		int i = left + (((double)(right - left) / (array[right] - array[left]))*(s - array[left]));

		if (array[i] == s)
		{
			return i;
		}

		if (array[i] < s)
		{
			left = i + 1;
		}
		else
		{
			right = i - 1;
		}

	}

	return -1;
}
