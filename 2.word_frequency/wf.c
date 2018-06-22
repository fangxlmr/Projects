#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "bstree.h"
#define MAXLINE 5000    /* 行内最大字数 */
#define K 10

void to_lower(char *line);
char *getword(char *str);
/* Min heap */
void shiftdown(BSTree_T *h, int n, int i);  /* Shift nodes down */
void   shiftup(BSTree_T *h, int n, int i);  /* Shift nodes up */
void      swap(BSTree_T *h, int x, int y);  /* Swap nodes */
int        cmp(BSTree_T *h, int x, int y);  /* Compare h[x] and h[y] */
void bst_inorder(BSTree_T root, BSTree_T *h, int *index);

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

/* Shift down nodes */
void shiftdown(BSTree_T *h, int n, int i)
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
        if (i * 2 + 2 < n && cmp(h, t, i * 2 + 2)) {
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
void shiftup(BSTree_T *h, int n, int i)
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

void swap(BSTree_T *h, int x, int y)
{
    BSTree_T temp;

    temp = h[x];
    h[x] = h[y];
    h[y] = temp;
}

int cmp(BSTree_T *h, int x, int y)
{
    return h[x]->count - h[y]->count;
}

/* Inorder traversal of bstree */
void bst_inorder(BSTree_T root, BSTree_T *h, int *index)
{
    if (!root) {
        return;
    }
    bst_inorder(root->left, h, index);

    if (*index < K) {
        h[(*index)++] = root;
        shiftup(h, *index, *index - 1);
    } else {
        h[0] = root;
        shiftdown(h, *index, 0);
    }

    bst_inorder(root->right, h, index);
}

int main(void)
{
    char line[MAXLINE];
    char *word;
    FILE *fp;
    BSTree_T root;

    root = bst_new();
    fp = fopen("./Knowledge and Virtue.txt", "r");
    while (fgets(line, MAXLINE, fp)) {
        to_lower(line);
        word = getword(line);
        while (word != NULL) {
            bst_insert(&root, word);
            word = getword(NULL);
        }
    }
    fclose(fp);

    /* Min heap sort, find out top k count */
    BSTree_T top[K];
    int index = 0;

    bst_inorder(root, top, &index);
    for (int i = 0; i < K; ++i) {
        printf("%s, count = %d\n", top[i]->s, top[i]->count);
    }
    bst_free(&root);
    return 0;
}


