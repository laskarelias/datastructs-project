#ifndef FILEIO_H_
#define FILEIO_H_

#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

int countlines (char *filename);
int* filetointarray(char* filename, int l);
trienode* filetotrie(char *filename);

#endif