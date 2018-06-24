#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "bstree.h"
#include "minheap.h"
#include "file.h"
#define MAXLINE 1024    /* 行内最大字数 */
int TOPK = 10; /*eTop K items */

void to_lower(char *line);
char *getword(char *str);
void bst_inorder(BSTree_T root, BSTree_T *h, int *index);
int cmp(const void *x, const void *y);

/* lower the case of chars
 * in the line of length n
 */
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

/* get a word from a string of length n */
char *getword(char *s)
{
    int i;
    char *index;    /* Start index of a word */
    static char *next = NULL;  /* Next position of rest string */

    i = 0;
    index = NULL;

    /*
     * Reset s with last next pointer
     */
    if (s == NULL) {
        s = next;
    }
    /*
     * Find out a word, and return start index.
     * Reset next pointer at the same time.
     * If meet the ends of string,
     * reset next into NULL pointer.
     */
    if (s != NULL) {
        while (s[i] != '\0') {  /* Find a word */
            if (isalpha(s[i])) {
                index = &s[i++];
                break;
            }
            ++i;
        }
        while (s[i] != '\0') {  /* Reset next pointer */
            if (!isalpha(s[i])) {
                s[i++] = '\0';
                next = &s[i];
                break;
            }
            ++i;
        }
        if (s[i] == '\0') {     /* At the end of string, */
            next = NULL;        /* reset next with NULL */
        }
    }

    return index;
}


/*
 * Inorder traversal of bstree.
 * Store top k items of count into min heap.
 */
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

int main(int argc, char *argv[])
{
    int opt;    /* Program option */
    char line[MAXLINE];
    char *word;
    FILE *fp;
    BSTree_T root;

    while ((opt = getopt(argc, argv, "n:f:")) != -1) {
        switch (opt) {
        case 'f':
            fp = fopen(optarg, "r");
            break;
        case 'n':
            TOPK = atoi(optarg);
            break;
        case 'w':

        case '?':
            printf("Unknown option: %c\n", optopt);
            break;
        }
    }
    /*
     * Create binary search tree.
     * Get a block of word from the file,
     * and parse the string, then store
     * the words in bstree.
     */
    root = bst_new();
    while (readblock(line, MAXLINE, fp)) {
        to_lower(line);       /* Lower case */
        /*
         * Parse the line, get words
         * and store words into bstree
         */
        word = getword(line);
        while (word != NULL) {
            bst_insert(&root, word);
            word = getword(NULL);
        }
    }
    fclose(fp);

    /*
     * Find out top k of
     * count using min heap
     */
    BSTree_T top[TOPK];
    int index = 0;

    /*
     * Inorder traversal BSTree and find out
     * top k items in the tree and print them out
     */
    bst_inorder(root, top, &index);
    qsort(top, index, sizeof(top[0]), cmp);
    for (int i = 0; i < index; ++i) {
        printf("No.%d:\t%s\tcount = %d\n", i + 1, top[i]->s, top[i]->count);
    }
    bst_free(&root);
    return 0;
}

