#ifndef RB_H_
#define RB_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Ορισμός τύπου χρώματος κόμβου */
typedef enum color_type
{
	red, black /* Κόκκινο = 0, Μαύρο = 1 */
}
colortype;

struct rb_node;
typedef struct rb_node rbnode;
typedef rbnode* position;
typedef rbnode* rbtree;

struct rb_node
{
	int d;         /* δεδομένα */
	rbtree l;      /* δείκτης στο αριστερό παιδί του κόμβου */
	rbtree r;      /* δείκτης στο δεξί παιδί του κόμβου */
	colortype c;   /* χρώμα (“red” ή “black”) */
};

rbtree rbinit(void); /* Δέσμευση μνήμης για το δέντρο */
//static rbtree rbnull(rbtree root); /* Αρχικοποίηση κόμβων */
rbtree rbempty(rbtree root); 
//static position rbleft(position b);
//static position rbright(position a);
//static position rbrotate(int data, position p);
//static void rbfix(int data, rbtree root);
rbtree rbinsert(int data, rbtree root);
//static void rbprint2(rbtree root);
void rbprint(rbtree root);

#endif