#include "inc/search.h"

/* Συνάρτηση interpolation search με είσοδο:
   δείκτη σε πίνακα ακεραίων
   μέγεθος πίνακα
   στοιχείο προς αναζήτηση */
int interpolationsearch(int *array, int l, int s)
{
	int left = 0;
	int right = l;
	/* Συνθήκη επανάληψης, έλεγχος ότι το στοιχείο βρίσκεται μέσα στον πίνακα */
	while ((left <= right) && (s >= array[left]) && (s <= array[right])) 
	{
        /* Ορισμός θέσης αναζήτησης */
		int i = left + (((double)(right - left) / 
		               (array[right] - array[left]))*(s - array[left])); 
		if (array[i] == s) /* Συνθήκη εύρεσης στοιχείου */
		{
			return i; /* Επιστροφή της θέσης του στοιχείου */
		}
		/* Αλλαγή ορίων αναζήτησης στον πίνακα */
		if (array[i] < s) /* Το στοιχείο βρίσκεται στην δεξιά μεριά */
		{
			left = i + 1;
		}
		else /* Το στοιχείο βρίσκεται στην αριστερή μεριά */
		{
			right = i - 1;
		}
	}
	return -1; /* Επιστροφή -1, το στοιχείο δεν βρέθηκε */
}
