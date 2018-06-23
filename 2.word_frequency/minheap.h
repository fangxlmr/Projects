#ifndef MINHEAP_H
#define MINHEAP_H

#include "bstree.h"
#define T BSTree_T

extern void shiftdown(T *h, int n, int i);  /* Shift nodes down */

extern void shiftup(T *h, int n, int i);  /* Shift nodes up */

#undef T
#endif /* MINHEAP_H */
