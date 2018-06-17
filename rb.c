#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "inc/rb.h"

static position nullnode = NULL; /* Αρχικοποίηση κενού κόμβου */

/* Δέσμευση μνήμης για τον πρώτο κόμβο (ρίζα) του δέντρου και για τον κενό κόμβο
   (φύλλο) */
rbtree rbinit(void)
{
	rbtree root;
	if (nullnode == NULL) /* Δέσμευση μνήμης για τον κενό κόμβο (φύλλο) */
	{
		nullnode = malloc(sizeof(rbnode));
	}
	nullnode->l = nullnode->r = nullnode; /* Δείκτες σε κενό κόμβο */
	nullnode->c = black; /* Εφαρμογή κανόνα: μαύρα φύλλα */
	nullnode->d = -1; /* Κανένα δεδομένο */
	
	/* Κεφαλίδα δέντρου (Θα έχει δεξί παιδί την ρίζα) */
	root = malloc(sizeof(rbnode)); /* Δέσμευση μνήμης για κεφαλίδα δέντρου */
	root->l = root->r = nullnode; /* Κανένα παιδί ακόμα */
	root->c = black;
	root->d = -1; /* Κανένα δεδομένο ακόμα */
	return root;
}

/* Βοηθητική συνάρτηση για αποδέσμευση μνήμης */
static rbtree rbnull(rbtree root)
{
	if (root != nullnode)
	{
		rbnull(root->l);
		rbnull(root->r);
		free(root);
	}
	return nullnode; /* Στο τέλος ο δοσμένος κόμβος είναι κενός, χωρίς παιδιά */
}

/* Αρχικοποίηση δέντρου, κλήση μετά την rbinit */
rbtree rbempty(rbtree root)
{
	/* Το δέντρο θα είναι δεξί παιδί του κόμβου κεφαλίδας */
	root->r = rbnull(root->r);
	return root;
}

/* Αριστερή περιστροφή του β (Αλλαγή του β με το αριστερό του παιδί) */
static position rbleft(position b)
{
	position a;
	a = b->l;
	b->l = a->r;
	a->r = b;
	return a; /* Επιστροφή αλλαγμένου κόμβου β */
}

/* Δεξιά περιστροφή του α (αλλαγή του α με το δεξί του παιδί) */
static position rbright(position a)
{
	position b;
	b = a->r;
	a->r = b->l;
	b->l = a;
	return b; /* Επιστροφή αλλαγμένου κόμβου α */
}

/* Περιστροφή κόμβου, δίνεται το δεδομένο του και ο πατέρας του ως παράμετροι */
static position rbrotate(int data, position p)
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

/* Στατικές δηλώσεις κόμβων όπου
   x = Βοηθητικός κόμβος
   p = Πατέρας κόμβου
   gp = "Παππούς" κόμβου
   ggp = "Προπαππούς" κόμβου */
static position x, p, gp, ggp;

/* Διόρθωση του red-black μετά την εισαγωγή κόμβου,
   με παράμετρους τα δεδομένα του εισαχθέντος κόμβου και την κεφαλίδα του 
   δέντρου */
static void rbfix(int data, rbtree root)
{
	x->c = red;	/* Χρωματισμός του δοσμένου κόμβου με κόκκινο */
	/* Εφαρμογή κανόνα: τα παιδιά κόκκινου κόμβου είναι μαύρα */
	x->l->c = black;
	x->r->c = black;
	
	if (p->c == red) /* Αν είναι δύο συνεχόμενοι κόκκινοι κόμβοι, περιστροφή */
	{
		gp->c = red;
		if ((data < gp->d) != (data < p->d))
		{
			p = rbrotate(data, gp); /* Διπλή περιστροφή */
		}
		x = rbrotate(data, ggp);
		x->c = black;
	}
	root->r->c = black;	/* Εφαρμογή κανόνα: μαύρη ρίζα */
}

/* Εισαγωγή νέου κόμβου στο δέντρο, με παραμέτρους τα νέα δεδομένα και την
   κεφαλίδα του δέντρου */
rbtree rbinsert(int data, rbtree root)
{
	x = p = gp = root;
	nullnode->d = data;
	while (x->d != data) /* Πηγαίνει χαμηλότερα στο δέντρο */
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
		/* Εφαρμογή κανόνα: όχι δύο συνεχόμενοι κόκκινοι κόμβοι */
		if ((x->l->c == red) && (x->r->c == red))
		{
			rbfix(data, root);
		}
	}
	
	if (x != nullnode)
	{
		return nullnode; /* Επέστρεψε κενό κόμβο, το x υπάρχει ήδη */
	}
	x = malloc(sizeof(rbnode)); /* Δημιουργία κόμβου */
	x->d = data; /* Αποθήκευση δεδομένων στον κόμβο */
	x->l = x->r = nullnode; /* Θέση κενών φύλλων ως παιδιών του νέου κόμβου */
	/* Σύνδεση κόμβου με τον πατέρα του (συνεπώς με το δέντρο) */
	if (data < p->d)
	{
		p->l = x;
	}
	else
	{
		p->r = x;
	}
	rbfix(data, root); /* Βάψιμο κόμβου με κόκκινο, έλεγχος δέντρου */
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

void rbprint(rbtree root) /* In-order εκτύπωση του δέντρου */
{
	rbprint2(root->r); /* Αποφυγή εκτύπωσης -1 (κανένα δεδομένο) */
}