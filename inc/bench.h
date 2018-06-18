#ifndef BENCH_H_
#define BENCH_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "search.h"
#include "rb.h"

/* Συνάρτηση αξιολόγησης ταχύτητας, όπου:
   x = Επαναλήψεις
   arr = Πίνακας για αναζήτηση
   lines = μέγεθος του πίνακα */
void bench(int x, int* arr, int lines);

/* Συνάρτηση αξιολόγησης ταχύτητας, όπου:
   x = Επαναλήψεις
   rb = Red-Black για αναζήτηση
   max = Μέγιστη τιμή τυχαίου αριθμού */
void benchrb(int x, rbtree rb, int max);

#endif