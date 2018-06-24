#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bstree.h"
#define T BSTree_T

/* create a new bstree node */
T bst_new(void)
{
    T root;
    char *t;

    root = (T) malloc(sizeof(struct T));
    if (root) {
        t = (char *) malloc(10 * sizeof(char));
        strncpy(t, "BSTree_T", strlen("BSTree_T"));
        root->s = t;
        root->count = 1;
        root->left  = NULL;
        root->right = NULL;
    }
    return root;
}

/* insert a key string into rootree */
void bst_insert(T *root, const char *str)
{
    int len;
    char *t;
    T node;

    if (!*root) {
        /*
         * create a new BSTree node
         * at the end of the tree
         */
        len = strlen(str);
        t = (char *) malloc(len * sizeof(char));
        strncpy(t, str, len);
        node = (T) malloc(sizeof(struct T));

        node->s = t;
        node->count = 1;
        node->left  = NULL;
        node->right = NULL;
        *root = node;
    }

    /*
     * search the key string in bstree
     * if exists matching node, then count++
     * otherwise create a new bstree node
     */
    if (strcmp(str, (*root)->s) == 0) {
        (*root)->count++;
    } else if (strcmp(str, (*root)->s) < 0) {
        bst_insert(&(*root)->left, str);
    } else {
        bst_insert(&(*root)->right, str);
    }
}

/* free bstree */
void bst_free(T *root)
{
    if (!*root) {
        return;
    }
    bst_free(&(*root)->left);
    bst_free(&(*root)->right);

    /* free bstree node */
    char *t;

    t = (*root)->s;
    free(t);
    free(*root);
    *root = NULL;
}