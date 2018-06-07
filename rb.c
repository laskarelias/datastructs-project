#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "inc/rb.h"

void rbswap(rbnode* a, rbnode* b)
{
	rbnode* temp = a;
	a = b;
	b = temp;
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

void rbleft(rbnode* root, rbnode* node)
{
	printf("doing rbleft\n");
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

void rbright(rbnode* root, rbnode* node)
{
	printf("doing rbright\n");
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

void rbfix(rbnode* root, rbnode* node)
{
	printf("doing rbfix\n");
	rbnode* parent = NULL;
	rbnode* grandparent = NULL;

	while ((node != root) && (node->red) && (node->p->red))
	{
		parent = node->p;
		grandparent = node->p->p;
		if (parent == grandparent->l)
		{
			printf("inside\n");
			rbnode* uncle = grandparent->r;

			if (uncle != NULL && uncle->red == true)
			{
				grandparent->red = true;
				parent->red = false;
				uncle->red = false;
				node = grandparent;
				printf("case a done\n");
			}
			else
			{
				if (node == parent->r)
				{
					printf("case b\n");
					rbleft(root, parent);
					node = parent;
					parent = node->p;
					printf("case b done\n");
				}
				printf("case c\n");
				rbright(root, grandparent);
				rbswap(parent, grandparent);
				node = parent;
				printf("case c done\n");
			}
		}
		else
		{
			printf("inside2222\n");
			rbnode* uncle = grandparent->l;
			if ((uncle != NULL) && uncle->red == true)
			{
				grandparent->red = true;
				parent->red = false;
				uncle->red = false;
				node = grandparent;
				printf("case d done\n");
			}
			else
			{
				if (node == parent->l)
				{
					printf("case e\n");
					rbright(root, parent);
					node = parent;
					parent = node->p;
					printf("case e done\n");
				}
				printf("case f\n");
				rbleft(root, grandparent);
				rbswap(parent, grandparent);
				node = parent;
				printf("case f done\n");
			}
		}
	}
	printf("uh\n");
	root->red = false;
}

rbnode* rbinsert(rbnode* root, rbnode* node)
{
	if (root == NULL)
	{
		return node;
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

void rbinsertfix(rbnode* root, int data)
{
	rbnode* node = newrbnode(data);
	node = rbinsert(root, node);
	rbfix(root, node);
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

rbnode* rbinit(int d)
{
	rbnode* root = newrbnode(d);
	root->red = false;
	return root;
}

void black(rbnode* node)
{
	node->red = false;
}