/**
 * @file sort.c
 *
 * @brief implementation of most sort algorithm
 */

#define DEBUG
#ifndef DEBUG
/**
 * quick_sort    core function of quick sort
 */
void quick_sort(int *v, int left, int right)
{
    int i, last;
    void swap(int *v, int x, int y);

    if (left >= right) {    /* do nothing ig array contains*/
        return;             /* fewer than 2 elements */
    }
    swap(v, left, (right + left) / 2);  /* move partition elem */
    last = left;                        /* to v[0] */
    for (i = left + 1; i <= right; ++i) {   /* partition */
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);        /* restore partition elem */

    quick_sort(v, left, last - 1);
    quick_sort(v, last + 1, right);
}

void swap(int *v, int x, int y)
{
    int temp;
    temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}

/**
 * bubble_sort  without optimization
 */
void bubble_sort(int *v, int size)
{
    int i, j;
    int tmp;

    for (i = 0; i < size; ++i) {
        for (j = 0; j < size - i - 1; ++j) {
            if (v[j] > v[j + 1]) {
                tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}

/**
 * bubble_sort  v1.0, using sorted flag
 */
void bubble_sort(int *v, int size)
{
    int i, j;
    int tmp;
    int sorted;   /* a flag that array was sorted or not */

    for (i = 0; i < size; ++i) {
        sorted = 1;
        for (j = 0; j < size - i - 1; ++j) {
            if (v[j] > v[j + 1]) {
                sorted = 0; /* still change, not sorted */
                tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }

        if (sorted) {
            break;
        }
    }
}

/**
 * bubble_sort  v2.0, using sorted flag and last flag
 */
void bubble_sort(int *v, int size)
{
    int i, j, tmp;
    int sorted;   /* a flag that array was sorted or not */
    int border;   /* sorted border of array */
    int last;     /* a flag of last swap position */

    last = 0;
    border = size - 1;
    for (i = 0; i < size; ++i) {
        sorted = 1;
        for (j = 0; j < border; ++j) {
            if (v[j] > v[j + 1]) {
                tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                sorted = 0; /* still change, not sorted */
                last = j;   /* last swap position */
            }
        }

        border = last;  /* update sorted border */
        if (sorted) {
            break;
        }
    }
}

/**
 * cock tail sort with optimization
 */
void cock_tail_sort(int *v, int size)
{
    int i, j, tmp;
    int sorted;
    /* restore the last swap position of odd and even loops*/
    int llast, rlast;
    int lborder, rborder;   /* two border of loops */

    llast = 0;
    rlast = 0;
    lborder = 0;
    rborder = size - 1;
    for (i = 0; i < size / 2 - 1; ++i) {
        sorted = 1;

        /* odd loops, from left to right */
        for (j = i; j < rborder; ++j) {
            if (v[j] > v[j + 1]) {
                tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                sorted = 0;
                rlast = j;
            }
        }
        rborder = rlast;

        /* even loops, from right to left */
        for (j = size - i - 1; j > lborder; --j) {
            if (v[j] < v[j - 1]) {
                tmp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = tmp;
                sorted = 0;
                llast = j;
            }
        }
        lborder = llast;

        if (sorted) {
            break;
        }
    }
}

/**
 * selection_sort
 */
void selection_sort(int *v, int size)
{
    int i, j;
    int tmp, min, index;

    for (i = 0; i < size - 1; ++i) {
        min = v[i];
        index = i;
        for (j = i; j < size; ++j) {
            if (v[j] < min) {
                min = v[j];
                index = j;
            }
        }
        tmp = v[i];
        v[i] = min;
        v[index] = tmp;
    }
}

#endif
/**
 * heap sort using max heap
 */
void swap(int *v, int x, int y);
void shiftdown(int *v, int i, int size);
void heap_sort(int *v, int size)
{
    int i;
    /* heapify from the first non-leaf node */
    for (i = size / 2 - 1; i >= 0; --i) {
        shiftdown(v, i, size);
    }

    for (i = size - 1; i > 0; --i) {
        swap(v, 0, i);
        shiftdown(v, 0, i);
    }
}

void shiftdown(int *v, int i, int size)
{
    int t;
    int left, right;

    t = i;
    left  = 2 * i + 1;
    right = 2 * i + 2;

    while (left < size) {   /* have one child at least */
        if (v[left] > v[i]) {
            t = left;
        }
        if (right < size && v[right] > v[t]) {
            t = right;
        }

        if (t != i) {
            swap(v, i, t);
            /*
             * keep shifting down for left
             * and right children
             */
            i = t;
            left  = 2 * i + 1;
            right = 2 * i + 2;

        } else {    /* finish shift down process */
            break;
        }
    }
}

void swap(int *v, int x, int y)
{
    int temp;
    temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}

#include <stdio.h>
int main(void)
{
    int a[] = {1, 99, 3, 44, 88, 78, 999, 65, 0, -39, -55, -234};
    int len = sizeof(a) / sizeof(a[0]);

    heap_sort(a, len);
    for (int i = 0; i < len; ++i) {
        printf("%d, ", a[i]);
    }

    return 0;
}