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