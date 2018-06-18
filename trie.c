#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "inc/trie.h"


/* Βοηθητική συνάρτηση, μετατρέπει τα κεφαλαία σε μικρά και τους χαρακτήρες σε
   θέσεις πίνακα (από 0 εώς 25) */
static int chartoi(char c)
{
	if ((int)c < 91 && (int)c > 64) /* Κεφαλαία σε μικρά */
	{
		c += 32;
	}
	c -= 97; /* Χαρακτήρας σε θέση πίνακα */
	
	return (int)c;
}

/* Αρχικοποίηση κόμβου trie */
trienode* newtrienode(void)
{
	int i = 0; /* Βοηθητικός μετρητής */
	trienode* node = NULL; /* Δημιουργία κόμβου */
	node = (trienode *)malloc(sizeof(trienode)); /* Δέσμευση μνήμης */
	node->leaf = false;
	/* Αρχικοποίηση πίνακα κόμβου */
	for (i = 0; i < 26; i++)
	{
		node->character[i] = NULL;
	}	
	return node;
}

/* Προσπελαύνει ένα ένα τα επίπεδα του trie και προσθέτει τα γράμματα */
void trieinsert(trienode** root, const char* word)
{
	trienode* c = *root;
	while (*word) /* Σειριακή προσπέλαση λέξης */
	{
		/* Δημιουργία κόμβου που λείπει */
		if (c->character[chartoi(*word)] == NULL)
		{
			c->character[chartoi(*word)] = newtrienode();
		}
		c = c->character[chartoi(*word)]; /* Θέση επόμενου κόμβου */
		word++; /* Επόμενος χαρακτήρας */
	}
	c->leaf = true; /* Τέλος λέξης */
}

/* Προσπελαύνει με την σειρά το δέντρο και ελέγχει αν υπάρχει ο χαρακτήρας */
bool triesearch(trienode* root, const char* word)
{
	if (root == NULL) /* Έλεγχος κενού δέντρου */
	{
		return false;
	}
	
	trienode* c = root;
	while (*word) /* Σειριακή προσπέλαση λέξης */
	{
		c = c->character[chartoi(*word)];
		if (c == NULL) /* Αν ο κόμβος δεν υπάρχει */
		{
			return false;
		}
		word++; /* Επόμενος χαρακτήρας */
	}
	return c->leaf; /* Επιστρέφει False όταν δεν αναζητείται ολόκληρη λέξη */
}

/* Βοηθητική συνάρτηση, ανιχνεύει αν ο κόμβος έχει παιδιά */
static bool child(trienode* node)
{
	int i = 0; /* Βοηθητικός μετρητής */
	for (i = 0; i < 26; i++) /* Προσπελαύνει σειριακά τον πίνακα του κόμβου */
	{
		if (node->character[i]) /* Αν υπάρχει έστω ένα παιδί */
		{
			return true;
		}
	}
	return false;
}

/* Διαγράφει μια λέξη από την δομή, προσπελαύνοντας ανάποδα το trie μέσω
   αναδρομής, σβήνοντας τους κόμβους που δεν έχουν παιδιά και ξεμαρκάροντας ως
   φύλλα τους κόμβους που έχουν παιδιά */
bool triedelete(trienode** root, const char* word)
{
	if (*root == NULL) /* Έλεγχος κενού δέντρου */
	{
		return false;
	}
	
	if (*word)
	{
		/* Έλεγχοι για αναδρομή */
		if (*root != NULL &&
		   (*root)->character[chartoi(*word)] != NULL &&
		   triedelete(&((*root)->character[chartoi(*word)]), word + 1) &&
		   (*root)->leaf == false)
		{
			if (!child(*root)) /* Αν ο κόμβος δεν έχει παιδιά, διαγράφεται */
			{
				/* Απελευθέρωση μνήμης */
				free(*root);
				(*root) = NULL;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	if (*word == '\0' && (*root)->leaf) /* Αν τελειώνει εδώ η λέξη */
	{
		if (!child(*root)) /* Αν ο κόμβος δεν έχει παιδιά, διαγράφεται */
		{
			/* Απελευθέρωση μνήμης */
			free(*root);
			(*root) = NULL;
			return true;
		}
		else
		{
			/* Ξεμαρκάρισμα ως φύλλο, άρα η λέξη δεν υπάρχει */
			(*root)->leaf = false;
			return false;
		}
	}
	return false;
}