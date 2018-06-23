#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "bstree.h"
#include "minheap.h"
#define MAXLINE 5000    /* 行内最大字数 */
int TOPK = 10; /* Top K items */

void to_lower(char *line);
char *getword(char *str);
void bst_inorder(BSTree_T root, BSTree_T *h, int *index);
int cmp(const void *x, const void *y);

/* lower the case of chars in the line */
void to_lower(char *s)
{
    int i;
    
    if (!s) {
        return;
    }
    i = 0;
    while (s[i] != '\0') {
        if (isupper(s[i]) != 0) {
            s[i] = tolower(s[i]);
        }
        ++i;
    }
}

/* get a word from a string */
char *getword(char *s)
{
    int i;
    char *index;    /* start index of a word */
    static char *next = NULL;  /* next position of rest string */

    i = 0;
    index = NULL;

    if (s == NULL) {
        s = next;
    }
    while (s != NULL && s[i] != '\0') {
        if (isalpha(s[i])) {
            index = &s[i++];
            break;
        }
        ++i;
    }
    while (s != NULL && s[i] != '\0') {
        if (!isalpha(s[i])) {
            s[i++] = '\0';
            next = &s[i];
            break;
        }
        ++i;
    }
    return index;
}


/* Inorder traversal of bstree */
void bst_inorder(BSTree_T root, BSTree_T *h, int *index)
{
    if (!root) {
        return;
    }
    bst_inorder(root->left, h, index);

    if (*index < TOPK) {
        h[(*index)++] = root;
        shiftup(h, *index, *index - 1);
    } else {
        if (root->count > h[0]->count) {
            h[0] = root;
            shiftdown(h, *index, 0);
        }
    }

    bst_inorder(root->right, h, index);
}

/* Compare function for qsort */
int cmp(const void *x, const void *y)
{
    BSTree_T *a, *b;
    a = (BSTree_T *)x;
    b = (BSTree_T *)y;
    return (*b)->count - (*a)->count;
}

int main(void)
{
    char line[MAXLINE];
    char *word;
    FILE *fp;
    BSTree_T root;

    root = bst_new();
    fp = fopen("./Harry Potter.txt", "r");
    while (fgets(line, MAXLINE, fp)) {
        to_lower(line);
        word = getword(line);
        while (word != NULL) {
            bst_insert(&root, word);
            word = getword(NULL);
        }
    }
    fclose(fp);

    /* Min heap sort, find out top k of count */
    BSTree_T top[TOPK];
    int index = 0;

    bst_inorder(root, top, &index);
    qsort(top, index, sizeof(top[0]), cmp);
    for (int i = 0; i < TOPK; ++i) {
        printf("No.%d:\t%s\tcount = %d\n", i + 1, top[i]->s, top[i]->count);
    }
    printf("Done.\n");
    bst_free(&root);
    return 0;
}
