#define INTEGERS "integers.txt"
#define WORDS "words.txt"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "inc/bench.h"
#include "inc/fileio.h"
#include "inc/search.h"
#include "inc/sort.h"
#include "inc/rb.h"
#include "inc/trie.h"

int main()
{

	int lines = 0; /* Πλήθος ακεραίων */
	int* arr; /* Πίνακας ακεραίων */
	int search = 0; /* Αναζήτηση στους ακεραίους */
	int found = 0; /* Αποτέλεσμα αναζήτησης */
	rbtree redblack; /* Κεφαλίδα red-black */
	position rbfound; /* Αποτέλεσμα αναζήτησης red-black */
	trienode* trie; /* Ρίζα trie */
	char searchword[80]; /* Αναζήτηση στο trie */
	
	int i = 0; /* Βοηθητικός μετρητής */
	int x = 0; /* Βοηθητική μεταβλητή */
	char c; /* Επιλογή χρήστη */
	int exit = 0; /* Έξοδος από το πρόγραμμα */
	
	lines = countlines(INTEGERS); 
	arr = filetointarray(INTEGERS, lines); /* Δημιουργία πίνακα από το αρχείο */
	mergesort(arr, 0, lines); /* Κλήση merge sort στον πίνακα */
	
	/* Προετοιμασία red-black tree */
	redblack = rbinit();
	redblack = rbempty(redblack);
	for (i = 0; i < lines+1; i++)
	{
		redblack = rbinsert(arr[i], redblack); /* Εισαγωγή στοιχείων */
	}

	trie = filetotrie(WORDS); /* Προετοιμασία trie */
	
	/* Κυρίως πρόγραμμα */
	printf("Press q to quit anytime\n");
	while (!exit)
	{
		printf("Select an option:\n");
		printf("(L)inear search\n(B)inary search\n(I)nterpolation search\n(R)ed-black search\n(T)rie search\nTrie (d)elete\nBench(m)ark\n(Q)uit\n");
		scanf("%c", &c);
		
		switch(c)
		{
			case 'q':
				exit = 1;
				break;
			case 'l':
				printf("Linear Search for: ");
				scanf("%d", &search);
				if ((char)search == 'q')
				{
					exit = 1;
				}	
				found = linearsearch(arr, lines + 1, search);
				printf("Found %d with Linear Search at location %d\n", search, found);
				break;
			case 'b':
				printf("Binary Search for: ");
				scanf("%d", &search);
				if ((char)search == 'q')
				{
					exit = 1;
				}
				found = binarysearch(arr, 0, lines + 1, search);
				printf("Found %d with Binary Search at location %d\n", search, found);
				break;
			case 'i':
				printf("Interpolation Search for: ");
				scanf("%d", &search);
				if ((char)search == 'q')
				{
					exit = 1;
				}
				found = interpolationsearch(arr, lines + 1, search);
				printf("Found %d with Interpolation Search at location %d\n", search, found);
				break;
			case 'r':
				printf("Red-Black Search for: ");
				scanf("%d", &search);
				if ((char)search == 'q')
				{
					exit = 1;
				}
				rbfound = rbsearch(search, redblack);
				if ((rbfound = rbsearch(search, redblack)) != NULL)
				{
					printf("Found %d with Red-Black Search\n", search);
				}
				else
				{
					printf("%d not found in Red-Black tree\n", search);
				}
			case 't':
				printf("Trie search for: ");	
				scanf("%79s", searchword);
				if (searchword[0] == 'q' && searchword[1] == NULL)
				{
					exit = 1;
				}
				if (triesearch(trie, searchword))
				{
					printf("Word \"%s\" was found in trie\n", searchword);
				}
				else
				{
					printf("Word \"%s\" was not found in trie\n", searchword);
				}
				break;
			case 'd':
				printf("Delete a word from the trie\n");
				scanf("%79s", searchword);
				if (searchword[0] == 'q' && searchword[1] == NULL)
				{
					exit = 1;
				}
				triedelete(&trie, searchword);
				break;
			case 'm':
				printf("Enter number of random searches:\n");
				scanf("%d", &x);
				if ((char)x == 'q')
				{
					exit = 1;
				}
				bench(x, arr, lines);
				benchrb(x, redblack, arr[lines]);
				break;
		}
	}
	printf("Laskarelias Vaios, 10544322, laskarelias@ceid.upatras.gr\n");

	return 0;
}
