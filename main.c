#define INTEGERS "integers.txt"
#define WORDS "words.txt"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "inc/fileio.h"
#include "inc/search.h"
#include "inc/sort.h"
#include "inc/rb.h"
#include "inc/trie.h"

int main()
{
	int* arr;
	int i = 0;
	int search = 0;
	char searchword[80];
	int found = 0;
	int lines = 0;
	trienode* trie;

	lines = countlines(INTEGERS);
	
	if (lines > 0)
	{
		arr = filetointarray(INTEGERS, lines);
		mergesort(arr, 0, lines);
	
		for (i = 0; i < lines+1; i++)
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
	
/*
	trie = filetotrie(WORDS);
	
	printf("Trie search for: ");
	
	fgets(searchword, 80, stdin);

	if (triesearch(trie, searchword))
	{
		printf("Word \"%s\" was found in trie", searchword);
	}
	else
	{
		printf("Word \"%s\" was not found in trie", searchword);
	}
	
	printf("Delete a word from the trie\n");
	fgets(searchword, 80, stdin);
	triedelete(trie, searchword, 0, 0);
	
	printf("Trie search for: \n");
	fgets(searchword, 80, stdin);
	if (triesearch(trie, searchword))
	{
		printf("Word \"%s\" was found in trie\n", searchword);
	}
	else
	{
		printf("Word \"%s\" was not found in trie\n", searchword);
	}
*/
	rbtree redblack;
	redblack = rbinit();
	redblack = rbempty(redblack);

/*
	FILE* f = fopen(INTEGERS, "r");
	while (fscanf(f, "%d", &search) != EOF)
	{
		rbinsert(search, redblack);
	}
	
*/

	for (i = 0; i < lines+1; i++)
	{
		rbinsert(arr[i], redblack);
		printf("inserted %d\n", arr[i]);
	}

	printf("inserts are complete\n");
	rbprint(redblack);
		
	
	return 0;
}
