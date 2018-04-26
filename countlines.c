#include <stdio.h>
#include <stdlib.h>

#include "inc/fileio.h"

int countlines (char *filename)
{
	char c = 0;
	int l = 0;
	
	FILE *f = fopen(filename, "r");
	if (f == NULL)
	{
		printf("Error in opening file \"%s\"\n", filename);
		return -1;
	}
	for (c = fgetc(f); c != EOF; c = fgetc(f))
	{
		if (c == '\n')
		{
			l++;
		}
	}
	printf("Read %d lines\n", l);
	
	fclose(f);
	
	return l;
}