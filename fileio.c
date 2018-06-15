#include <stdio.h>
#include <stdlib.h>

#include "inc/fileio.h"
#include "inc/trie.h"

int countlines (char *filename)
{
	char c = 0;
	int l = 1; // if \n not found, means 1 line
	
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

int* filetointarray(char* filename, int l) //l = lines of file
{
	int i = 0;
	int* array;
	FILE* f = fopen(filename, "r");
	
	//mem reservation for static definition with non-static var (l)
	array = (int *)malloc((l) * sizeof(int));
	for(i = 0; i < l; i++)
	{
		fscanf(f, "%d", &array[i]);
	}
	
	fclose(f);
	
	return array;	
}

trienode* filetotrie(char* filename) //l = lines of file
{
	FILE* f = fopen(filename, "r");
	char word[80];
	trienode* root = newtrienode();
	
	while (fscanf(f, "%79s", &word) == 1)
	{
		printf("%s", word);
		trieinsert(&root, word);
	}
	fclose(f);
	return root;
}
