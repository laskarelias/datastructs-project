#define FILENAME "integers.txt"

#include <stdio.h>
#include <stdlib.h>

#include "inc/fileio.h"
#include "inc/search.h"
#include "inc/sort.h"

int main()
{
	int *arr;
	int i = 0;
	int search = 0;
	int found = 0;
	
	int lines = countlines(FILENAME);
	
	if (lines > 0)
	{
		arr = filetoarray(FILENAME, lines);
	
		mergesort(arr, 0, lines);
	
		for (i = 0; i < (lines + 1); i++)
		{
			printf("Sorted array has: %d\n", arr[i]);
		}
	}

	printf("Linear Search for: ");
	scanf("%d", &search);
	
	found = linearsearch(arr, lines, search);
	
	printf("Found %d with Linear Search at location %d\n", search, found);
	
	printf("Binary Search for: ");
	scanf("%d", &search);
	
	found = binarysearch(arr, 0, lines, search);
	
	printf("Found %d with Binary Search at location %d\n", search, found);
	
	printf("Interpolation Search for: ");
	scanf("%d", &search);
	
	found = interpolationsearch(arr, lines, search);
	
	printf("Found %d with Interpolation Search at location %d\n", search, found);

	return 0;
}