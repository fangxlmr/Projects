#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BLOCK 1024

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

int split(char *str, List_T ret);
int isquit(const char *str);
T list_new(int n);
void list_free(T *list);
void list_append(T list, char *str, int val);
char *list_getstr(T list);
void list_tonum(T list);

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

int split(char *str, List_T ret)
{
    const char s[] = " ";
    char *token;
    int count;

    count = 0;
    token = strtok(str, s);
    while (token != NULL) {
        list_append(ret, token, 0);
        count++;
        token = strtok(NULL, s);
    }
    return count;
}

int isquit(const char *str)
{
    return strcmp(str, "quit") == 0
           || strcmp(str, "q") == 0;
}

int main(void)
{
    char buf[BLOCK];
    List_T index;
    int size;

    index = list_new(BLOCK);
    printf("Enter a expression:\n");
    while (fgets(buf, BLOCK, stdin) != NULL) {
        buf[strlen(buf) - 1] = '\0';

        if (isquit(buf)) {
            break;
        }

        size = split(buf, index);
        if (size > 0) {
            for (int i = 0; i < size; ++i) {
//                printf("Done.\n");
//                printf("%s+", list_getstr(index + i));
            }
            printf("\n");
        }
    }
    exit(0);
}