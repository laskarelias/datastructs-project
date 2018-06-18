#ifndef FILEIO_H_
#define FILEIO_H_

#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

/* Μετράει τις γραμμές του αρχείου, για δέσμευση μνήμης αργότερα */
int countlines (char *filename);

/* Δημιουργεί έναν πίνακα ακεραίων από ένα αρχείο, με μεταβλητή τις γραμμές 
   του */
int* filetointarray(char* filename, int l);

/* Δημιουργεί ένα trie χρησιμοποιώντας ένα αρχείο κειμένου, με τις δοσμένες
   προδιαγραφές */
trienode* filetotrie(char *filename);

#endif