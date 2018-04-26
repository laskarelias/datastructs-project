#include "inc/search.h"

int binarysearch(int *array, int left, int right, int s)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;
		
		if (array[mid] == s)
		{
			return mid;
		}
		
		if (array[mid] > s)
		{
			return binarysearch(array, left, mid - 1, s);
		}
		
		if (array[mid] < s)
		{
			return binarysearch(array, mid + 1, right, s);
		}
	}
	
	return -1;
}