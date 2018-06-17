#ifndef SEARCH_H_
#define SEARCH_H_

/* Συνάρτηση δυαδικής αναζήτησης, με είσοδο:
   δείκτη σε πίνακα ακεραίων
   αριστερό άκρο πίνακα (για αναδρομή)
   δεξί άκρο πίνακα (για αναδρομή)
   στοιχείο προς αναζήτηση */
int binarysearch(int *array, int left, int right, int s);

/* Συνάρτηση interpolation search με είσοδο:
   δείκτη σε πίνακα ακεραίων
   μέγεθος πίνακα
   στοιχείο προς αναζήτηση */
int interpolationsearch(int *array, int l, int s);

/* Συνάρτηση γραμμικής αναζήτησης, με είσοδο:
   δείκτη σε πίνακα ακεραίων
   μέγεθος πίνακα
   στοιχείο προς αναζήτηση */
int linearsearch(int *array, int l, int s);

#endif