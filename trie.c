#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "inc/trie.h"



static int chartoi(char c) //helper function for a = 0, ... z = 25
{
	if ((int)c < 91 && (int)c > 64) // capital to lowercase
	{
		c += 32;
	}
	c -= 97;
	
	return (int)c;
}

trienode* newtrienode(void)
{
	int i = 0;
	trienode* node = NULL;
	node = (trienode *)malloc(sizeof(trienode));
	node->leaf = false;
	for (i = 0; i < 26; i++)
	{
		node->character[i] = NULL;
	}	
	return node;
}

void trieinsert(trienode** root, const char* word)
{
	trienode* c = *root;
	while (*word)
	{
		if (c->character[chartoi(*word)] == NULL)
		{
			c->character[chartoi(*word)] = newtrienode();
		}
		c = c->character[chartoi(*word)]; // next node
		word++; // next character of word	
	}
	c->leaf = true;
}

bool triesearch(trienode* root, const char* word)
{
	if (root == NULL)
	{
		return false;
	}
	
	trienode* c = root;
	while (*word)
	{
		c = c->character[chartoi(*word)];
		if (c == NULL)
		{
			return false;
		}
		word++;
	}
	return c->leaf;
}

static bool child(trienode* node)
{
	int i = 0;
	for (i = 0; i < 26; i++)
	{
		if (node->character[i])
		{
			return true;
		}
	}
	return false;
}

bool triedelete(trienode** root, const char* word)
{
	if (*root == NULL)
	{
		return false;
	}
	
	if (*word)
	{
		if (*root != NULL &&
		   (*root)->character[chartoi(*word)] != NULL &&
		   triedelete(&((*root)->character[chartoi(*word)]), word + 1) &&
		   (*root)->leaf == false)
		{
			if (!child(*root))
			{
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
	if (*word == '\0' && (*root)->leaf)
	{
		if (!child(*root))
		{
			free(*root);
			(*root) = NULL;
			return true;
		}
		else
		{
			(*root)->leaf = false;
			return false;
		}
	}
	return false;
}