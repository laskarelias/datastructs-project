#include <stdio.h>
#include <stdlib.h>

#include "inc/redblack.h"

int rbsearch(Node* root, int s)
{
	
	if (*root == NULL)
	{
		return -1;
	}

	Node nextNode = *root;

	while (nextNode != NULL)
	{
		if(nextNode->data == s)
		{
			return 0;
		}	

		nextNode = nextNode->data < s ? nextNode->right : nextNode->left;
	}

	return -1;
	
}	

void rbinsert(Node* root, int s)
{
	if (*root == NULL)
	{
		Node n = malloc(sizeof(Node));
		n->data = s;
		*root = n;
		return;
	}
	
		Node nextNode = *root;
	while (1)
	{
		Node temp = nextNode->data < s ? nextNode->right : nextNode->left;
		if(temp == NULL){
			break;
		}
		nextNode = temp;
	}

	Node n = malloc(sizeof(Node));
	n->data = s;
	n->color = RED;
	n->parent = nextNode;

	if(s > nextNode->data){
		nextNode->right = n;
	}else{
		nextNode->left = n;
	}

	insertfix(n);

	while(1){
		Node par = n->parent;
		if(par == NULL){
			break;
		}
		n = par;
	}

	*root = n;
}

void insertfix(Node n){
	if(n->parent == NULL){
		n->color = BLACK;
	}else if(n->parent->color == BLACK){
		return;
	}else if(uncle(n) != null && uncle(n)->color == RED){
		n->parent->color = BLACK;
		uncle(n)->color = BLACK;
		grandparent(n)->color = RED;
		insertfix(grandparent(n));
	}else{
		Node p = n->parent;
		Node g = grandparent(n);
		
		if(g->left != NULL && n == g->left->right){
			leftrotate(p);
			n = n->left;
		}else if(g->right != NULL && n == g->right->left){
			rightrotate(p);
			n = n->right;
		}


		
		p = n->parent;
		g = grandparent(n);

		if(n == p->left){
			rightrotate(g);
		}else{
			leftrotate(g);
		}

		p->color = BLACK;
		g->color = RED;
	}
}

void rightrotate(Node n){
	Node nnew = n->left;
	if(nnew == NULL){
		return;
	}

	n->right = nnew.left;
	nnew->left = n;
	nnew->parent = n->parent;
	n->parent = nnew;
}

void leftrotate(Node n){
	Node nnew = n->right;
	if(nnew == NULL){
		return;
	}

	n->right = nnew->left;
	nnew->left = n;
	nnew->parent = n->parent;
	n->parent = nnew;
}

Node grandparent(Node n){
	return n->parent == NULL ? NULL : (n->parent->parent == NULL ? NULL : n->parent->parent);
}

Node uncle(Node n){
	Node grandpa = grandparent(n);
	if(grandpa == NULL){
		return NULL;
	}
	return sibling(n->parent);
}

Node sibling(Node n){
	Node p = n->parent;
	if(p == NULL){
		return NULL;
	}

	if(n == p->left){
		return p->right;
	}
	
	return p->left;
}
