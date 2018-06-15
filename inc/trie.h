#ifndef TRIE_H_
#define TRIE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct trie_node
{
	struct trie_node* character[26];
	bool leaf; // if end of word
};
typedef struct trie_node trienode;

//static int chartoi(char c);
trienode* newtrienode(void);
void trieinsert(trienode** root, const char* word);
bool triesearch(trienode* root, const char* word);
//static bool child(trienode* node);
bool triedelete(trienode** root, const char* word);

#endif
