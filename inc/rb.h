#ifndef RB_H_
#define RB_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum color_type
{
	red, black
}
colortype;

struct rb_node;
typedef struct rb_node rbnode;
typedef rbnode* position;
typedef rbnode* rbtree;

struct rb_node
{
	int d;         //data
	rbtree l;      //left
	rbtree r;      //right
	colortype c;   //color
};

rbtree rbinit(void);
//static rbtree rbnull(rbtree root);
rbtree rbempty(rbtree root);
//static position rbleft(position b);
//static position rbright(position a);
//static position rbrotate(int data, position p);
//static void rbfix(int data, rbtree root);
rbtree rbinsert(int data, rbtree root);
//static void rbprint2(rbtree root);
void rbprint(rbtree root);

#endif