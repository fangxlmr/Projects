#include <stdlib.h>
#include <string.h>
#include "list.h"
#define T List_T

static int count = 0;   /* 数组的下标 */

typedef union Data {
    char *str;
    int val;
}Data;

struct T {
    Data *x;
    int flag;   /* flag = 0, Data为char *；flag = 1, Data类型为int */
};

T list_new(int n)
{
    if (n <= 0) {
        return NULL;
    }
    T list;

    list = (T) malloc(n * sizeof(struct T));
    if (list != NULL) {
        memset(list, 0, n * sizeof(struct T));
    }
    return list;
}

void list_free(T *list)
{
    if (*list) {
        free(*list);
        *list = NULL;
    }
}

void list_append(T list, char *str, int val)
{
    if (list) {
        if (str != NULL) {
            list[count].x->str = str;
        } else {
            list[count].x->val = val;
            list[count].flag = 1;
        }
    }
}


char *list_getstr(T list)
{
    if (list) {
        return list->x->str;
    }
}

void list_tonum(T list)
{
    int i;

    if (list) {
        for (i = 0; i < count; ++i) {
            if (list[i].flag == 0) {
                list[i].x->val = atoi(list[i].x->str);
                list[i].flag = 1;
            }
        }
    }
}