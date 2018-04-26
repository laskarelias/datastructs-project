#ifndef REDBLACK_H_
#define REDBLACK_H_

#define BLACK 0
#define RED 1

struct rbnode
{
	int data;
	rbnode* left, right, parent;
	int color = BLACK;
};

typedef struct rbnode * Node;

int rbsearch(Node* root, int s); 
void rbinsert(Node* root, int s);

#endif