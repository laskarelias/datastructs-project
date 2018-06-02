#ifndef TRIE_H_
#define TRIE_H_

#include <stdbool.h>

struct trie_node
{
	struct trie_node *nextnode[26];
	bool end;
};

typedef struct trie_node trienode;

int chartoi(char c) //helper function for a = 0, ... z = 26
{
	// capital to lowercase
	if (c < 91 && c > 64)
	{
		c += 32;
	}
	c -= 97;
	
	return c;
}

trienode* newtrienode(void);
void insert(trienode *root, const char *word);
void delete(trienode *root, const char *word);

#endif
