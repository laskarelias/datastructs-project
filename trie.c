#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "inc/fileio.h"
#include "inc/trie.h"

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

trienode* newtrienode(void)
{
	trienode *node = NULL;
	node = (trienode *)malloc(sizeof(trienode));
	
	if (node)
	{
		int i;
		node->end = false;
		
		for (i = 0; i < 26; i++)
		{
			node->nextnode[i] = NULL;
		}
		
		return node;
	}
}

void insert(trienode *root, const char *word)
{
	int level;
	int length = strlen(word);
	int i;
	trienode *c = root;
	
	for (level = 0; level < length; level++)
	{
		i = chartoi(word[level]);
		if (!c->nextnode[i])
		{
			c->nextnode[i] = newtrienode;
		}
		c = c->nextnode[i];
	}
}

bool triesearch(trienode *root, const char *word)
{
	int level;
	int length = strlen(key);
	int i;
	trienode *c = root;
	
	for (level = 0; level < length; level++)
	{
		i = chartoi(word[level]);
		if (!c->nextnode[i])
		{
			return false;
		}
		
		c = c->nextnode[i];
	}	
	return (c != NULL && c->end);
}

