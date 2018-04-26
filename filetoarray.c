#include <stdio.h>
#include <stdlib.h>

#include "inc/fileio.h"

int* filetoarray(char *filename, int l)
{
	int i = 0;
	int *array;
	FILE *f = fopen(filename, "r");
	
	//mem reservation for static definition with non-static var (l)
	array = (int *)malloc((l + 1) * sizeof(int));
	for(i = 0; i < (l + 1); i++)
	{
		fscanf(f, "%d", &array[i]);
	}
	
	fclose(f);
	
	return array;	
}