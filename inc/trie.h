#ifndef TRIE_H_
#define TRIE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct trie_node
{
	struct trie_node* character[26]; /* Πίνακας επόμενου χαρακτήρα */
	bool leaf; /* Αν τελειώνει εδώ η λέξη */
};
typedef struct trie_node trienode;

/* Βοηθητική συνάρτηση, μετατρέπει τα κεφαλαία σε μικρά και τους χαρακτήρες σε
   θέσεις πίνακα (από 0 εώς 25) */
//static int chartoi(char c);

/* Αρχικοποίηση κόμβου trie */
trienode* newtrienode(void);

/* Προσπελαύνει ένα ένα τα επίπεδα του trie και προσθέτει τα γράμματα */
void trieinsert(trienode** root, const char* word);

/* Προσπελαύνει με την σειρά το δέντρο και ελέγχει αν υπάρχει ο χαρακτήρας */
bool triesearch(trienode* root, const char* word);

/* Βοηθητική συνάρτηση, ανιχνεύει αν ο κόμβος έχει παιδιά */
//static bool child(trienode* node);

/* Διαγράφει μια λέξη από την δομή, προσπελαύνοντας ανάποδα το trie μέσω
   αναδρομής, σβήνοντας τους κόμβους που δεν έχουν παιδιά και ξεμαρκάροντας ως
   φύλλα τους κόμβους που έχουν παιδιά */
bool triedelete(trienode** root, const char* word);

#endif
