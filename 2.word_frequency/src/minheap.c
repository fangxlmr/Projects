#include "minheap.h"
#include "bstree.h"
#define T BSTree_T

static void swap(T *h, int x, int y);  /* Swap nodes */
static int cmp(T *h, int x, int y);  /* Compare h[x] and h[y] */

/* Shift down nodes */
void shiftdown(T *h, int n, int i)
{
    int t, flag;

    flag = 0;

    /* If there is at least one child*/
    while (i * 2 + 1 < n && flag == 0) {
        /* Compare it with left child */
        if (cmp(h, i, i * 2 + 1) > 0) {
            t = i * 2 + 1;
        } else {
            t = i;
        }
        /* Compare it with right child if there is any */
        if (i * 2 + 2 < n && cmp(h, t, i * 2 + 2) > 0) {
            t = i * 2 + 2;
        }

        /* Swap if needed */
        if (t != i) {
            swap(h, t, i);
            i = t;
        } else {
            flag = 1;
        }
    }
}

/* Shift up nodes */
void shiftup(T *h, int n, int i)
{
    int flag;

    flag = 0;
    if (i == 0 || i >= n) {
        return;
    }
    while (i != 0 && flag == 0) {
        /* Compare it with parent nodes */
        if (cmp(h, i, (i - 1) / 2) < 0) {
            swap(h, i, (i - 1) / 2);
        } else {
            flag = 1;
        }

        i = (i - 1) / 2;
    }
}

void swap(T *h, int x, int y)
{
    T temp;

    temp = h[x];
    h[x] = h[y];
    h[y] = temp;
}

int cmp(T *h, int x, int y)
{
    return h[x]->count - h[y]->count;
}