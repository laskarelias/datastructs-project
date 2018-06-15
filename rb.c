#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "inc/rb.h"

static position nullnode = NULL;

rbtree rbinit(void)
{
	rbtree root;
	if (nullnode == NULL)
	{
		nullnode = malloc(sizeof(rbnode));
	}
	nullnode->l = nullnode->r = nullnode;
	nullnode->c = black;
	nullnode->d = -1;
	
	root = malloc(sizeof(rbnode));
	root->l = root->r = nullnode;
	root->c = black;
	root->d = -1;
	return root;
}

static rbtree rbnull(rbtree root)
{
	if (root != nullnode)
	{
		rbnull(root->l);
		rbnull(root->r);
		free(root);
	}
	return nullnode;
}

rbtree rbempty(rbtree root)
{
	root->r = rbnull(root->r);
	return root;
}

static position rbleft(position b) //left rotate (b with its left child)
{
	position a;
	a = b->l;
	b->l = a->r;
	a->r = b;
	return a;	
}

static position rbright(position a) //right rotate (a with its right child)
{
	position b;
	b = a->r;
	a->r = b->l;
	b->l = a;
	return b;
}

static position rbrotate(int data, position p) //rotate node with its parent as parameter
{
	if (data < p->d)
	{
		return p->l = data < p->l->d ?
			rbleft(p->l) : rbright(p->l);
	}
	else
	{
		return p->r = data < p->r->d ?
				rbleft(p->r) : rbright(p->r);
	}
}

static position x, p, gp, ggp;

static void rbfix(int data, rbtree root)
{
	x->c = red;		//c flip;
	x->l->c = black;
	x->r->c = black;
	
	if (p->c == red)
	{
		gp->c = red;
		if ((data < gp->d) != (data < p->d))
		{
			p = rbrotate(data, gp);
		}
		x = rbrotate(data, ggp);
		x->c = black;
	}
	root->r->c = black;	
}

rbtree rbinsert(int data, rbtree root)
{
	x = p = gp = root;
	nullnode->d = data;
	while (x->d != data)
	{
		ggp = gp;
		gp = p;
		p = x;
		if (data < x->d)
		{
			x = x->l;
		}
		else
		{
			x = x->r;
		}
		if ((x->l->c == red) && (x->r->c == red))
		{
			rbfix(data, root);
		}
	}
	
	if (x != nullnode)
	{
		return nullnode;
	}
	x = malloc(sizeof(rbnode));
	x->d = data;
	x->l = x->r = nullnode;
	
	if (data < p->d)
	{
		p->l = x;
	}
	else
	{
		p->r = x;
	}
	rbfix(data, root);
	
	return root;
}

static void rbprint2(rbtree root)
{
	if (root != nullnode)
	{
		rbprint2(root->l);
		printf("%d %d\n", root->d, root->c);
		rbprint2(root->r);
	}
}

void rbprint(rbtree root) // prints inorder
{
	rbprint2(root->r); // avoids printing -1
}