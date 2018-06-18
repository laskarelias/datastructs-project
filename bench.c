#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "inc/search.h"
#include "inc/rb.h"

/* Συνάρτηση αξιολόγησης ταχύτητας, όπου:
   x = Επαναλήψεις
   arr = Πίνακας για αναζήτηση
   lines = μέγεθος του πίνακα */
void bench(int x, int* arr, int lines)
{
	clock_t start, end;
	double total, t, worse = 0.0;
	int search;
	int i;
	int max = arr[lines];
	
	srand(time(0));

	for (i = 0; i < x; i++)
	{
		search = rand() % (max + 1);
		start = clock();
		linearsearch(arr, lines + 1, search);			
		end = clock();
		t = (double)(end - start) / CLOCKS_PER_SEC;
		total += t;
		if (t > worse)
		{
			worse = t;
		}
	}
	printf("Average time for 1 Linear search = %f sec.\n", (total / x));
	printf("Total time for %d Linear searches = %f sec.\n", x, total);
	printf("Worst time for 1 Linear search = %f sec.\n", worse);
	
	total = worse =  t = 0.0;
	
	for (i = 0; i < x; i++)
	{
		search = rand() % (max + 1);
		start = clock();
		binarysearch(arr, 0, lines + 1, search);		
		end = clock();
		t = (double)(end - start) / CLOCKS_PER_SEC;
		total += t;
		if (t > worse)
		{
			worse = t;
		}
	}
	printf("Average time for 1 Binary search = %f sec.\n", (total / x));
	printf("Total time for %d Binary searches = %f sec.\n", x, total);
	printf("Worst time for 1 Binary search = %f sec.\n", worse);

	total = worse =  t = 0.0;

	for (i = 0; i < x; i++)
	{
		search = (rand() % (max +1)) + 1;
		start = clock();
		interpolationsearch(arr, lines + 1, search);
		end = clock();
		t = (double)(end - start) / CLOCKS_PER_SEC;
		total += t;
		if (t > worse)
		{
			worse = t;
		}
	}
	printf("Average time for 1 Interpolation search = %f sec.\n", (total / x));
	printf("Total time for %d Interpolation searches = %f sec.\n", x, total);
	printf("Worst time for 1 Interpolation search = %f sec.\n", worse);
}

/* Συνάρτηση αξιολόγησης ταχύτητας, όπου:
   x = Επαναλήψεις
   rb = Red-Black για αναζήτηση
   max = Μέγιστη τιμή τυχαίου αριθμού */
void benchrb(int x, rbtree rb, int max)
{
	clock_t start, end;
	double total, t, worse = 0.0;
	int search;
	int i;
	
	for (i = 0; i < x; i++)
	{
		search = (rand() % (max + 1)) + 1;
		start = clock();
		rbsearch(search, rb);
		end = clock();
		t = (double)(end - start) / CLOCKS_PER_SEC;
		total += t;
		if (t > worse)
		{
			worse = t;
		}
	}
	printf("Average time for 1 Red-Black search = %f sec.\n", (total / x));
	printf("Total time for %d Red-Black searches = %f sec.\n", x, total);
	printf("Worst time for 1 Red-Black search = %f sec.\n", worse);
}

