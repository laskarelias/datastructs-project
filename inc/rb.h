#ifndef RB_H_
#define RB_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct rb_node
{
	int d;
	bool red;
	struct rb_node *l;		//left
	struct rb_node *r;		//right
	struct rb_node *p;		//parent
};
typedef struct rb_node rbnode;

void rbswap(rbnode* a, rbnode* b)
{
	if(a->red == true && b->red == false)
	{
		a->red = false;
		b->red = true;
	}
	if(a->red == false && b->red == true)
	{
		a->red = true;
		b->red = false;
	}
}

rbnode* newrbnode(int data)
{
	rbnode* node = NULL;
	node = (rbnode *)malloc(sizeof(rbnode));

	node->d = data;
	node->red = true;
	node->l = node->r = node->p = NULL;

	return node;
}

rbnode* rbsearch(rbnode* root, int data)
{
	if (root == NULL || root->d == data)
		{
			return root;
		}
	if (root->d < data)
	{
		return rbsearch(root->r, data);
	}
	return rbsearch(root->l, data);
}

void rbleft(rbnode* rootptr, rbnode* nodeptr)
{
	rbnode* root = &rootptr;		//pass by reference
	rbnode* node = &nodeptr; 	//pass by reference

	rbnode* temp = node->r;
	node->r = temp->l;

	if (node->r != NULL)
	{
		node->r->p = node;
	}
	temp->p = node->p;

	if (node->p == NULL)
	{
		root = temp;
	}
	else if (node == node->p->l)
	{
		node->p->l = temp;
	}
	else
	{
		node->p->r = temp;
	}

	temp->l = node;
	node->p = temp;
}

void rbright(rbnode* rootptr, rbnode* nodeptr)
{
	rbnode* root = &rootptr;		//pass by reference
	rbnode* node = &nodeptr; 		//pass by reference

	rbnode* temp = node->l;
	node->l = temp->r;

	if (node->l != NULL)
	{
		node->l->p = node;
	}
	temp->p = node->p;

	if (node->p == NULL)
	{
		root = temp;
	}
	else if (node == node->p->l)
	{
		node->p->l = temp;
	}
	else
	{
		node->p->r = temp;
	}

	temp->r = node;
	node->p = temp;
}

void rbfix(rbnode* rootptr, rbnode* nodeptr)
{
	rbnode* root = &rootptr;		//pass by reference
	rbnode* node = &nodeptr; 		//pass by reference

	rbnode* parent = NULL;
	rbnode* grandparent = NULL;

	while ((node != root) && (node->red != false) && (node->p->red == true))
	{
		parent = node->p;
		grandparent = node->p->p;

		if (parent == grandparent->l)
		{
			rbnode* uncle = grandparent->r;

			if (uncle != NULL && uncle->red == true)
			{
				grandparent->red = true;
				parent->red = false;
				uncle->red = false;
				node = grandparent;
			}
			else
			{
				if (node == parent->r)
				{
					rbleft(root, parent);
					node = parent;
					parent = node->p;
				}
				rbright(root, grandparent);
				rbswap(parent, grandparent);
				node = parent;
			}
		}
		else
		{
			rbnode* uncle = grandparent->l;
			if ((uncle != NULL) && uncle->red == true)
			{
				grandparent->red = true;
				parent->red = false;
				uncle->red = false;
				node = grandparent;
			}
			else
			{
				if (node == parent->l)
				{
					rbright(&root, &parent);
					node = parent;
					parent = node->p;
				}
				rbleft(root, grandparent);
				rbswap(parent, grandparent);
				node = parent;	
			}
		}
	}
	root->red = false;
}

rbnode* rbinsert(rbnode* root, rbnode* node)
{
	if (root == NULL)
	{
		return newrbnode(node->d);
	}
	if (node->d < root->d)
	{
		root->l = rbinsert(root->l, node);
		root->l->p = root;
	}
	if (node->d > root->d)
	{
		root->r = rbinsert(root->r, node);
		root->r->p = root;
	}
	return root;
}

void rbinorder(rbnode* root)
{
	if (root == NULL)
	{
		return;
	}
	rbinorder(root->l);
	if (root->red == true)
	{
		printf("%d, red\n", root->d);
	}
	else if (root->red == false)
	{
		printf("%d, black\n", root->d);
	}
	rbinorder(root->r);
}

#endif