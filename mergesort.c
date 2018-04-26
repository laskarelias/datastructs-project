#include "inc/sort.h"

int* merge(int *array, int left, int mid, int right)
{
	int i, j, k = 0;
	int x = mid - left + 1;
	int y = right - mid;
	
	int L[x], R[y];
	
	//copy data to arrays L and R
	for (i = 0; i < x; i++)
	{
		L[i] = array[left + i];
	}
	for (j = 0; j < y; j++)
	{
		R[j] = array[mid + j + 1];
	}
	
	//merging
	i = 0;
	j = 0;
	k = left;
	
	while (i < x && j < y)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		
		k++;
	}
	
	while (i < x)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	
	while (j < y)
	{
		array[k] = R[j];
		j++;
		k++;
	}
	
	return array;
}

void mergesort(int *array, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergesort(array, left, mid);
		mergesort(array, mid + 1, right);
		
		merge(array, left, mid, right);
	}
}

