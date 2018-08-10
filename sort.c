/**
 * @file sort.c
 *
 * @brief implementation of most sort algorithm
 */

/**
 * qsort    core function of quick sort
 */
void qsort(int *v, int left, int right)
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

    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(int *v, int x, int y)
{
    int temp;
    temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}

#define DEBUG
#ifndef DEBUG
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

#endif
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


#include <stdio.h>
int main(void)
{
    int a[] = {1, 99, 3, 44, 88, 78, 999, 65, 0, -39, -55, -234};
    int len = sizeof(a) / sizeof(a[0]);

    cock_tail_sort(a, len);
    for (int i = 0; i < len; ++i) {
        printf("%d, ", a[i]);
    }

    return 0;
}