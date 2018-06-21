#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "bstree.h"
#define MAXLINE 5000    /* 行内最大字数 */
#define TOP 10

BSTree_T ary[TOP];  /* BSTree_T array of size n (n = TOP) */
int min;    /* min of count in BSTree_T array */
int index;  /* index of min */
int empty;  /* empty position */

void to_lower(char *line);
char *getword(char *str);
void gettop(BSTree_T root);

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

/*
 * Get top n of count
 */
/*void gettop(BSTree_T root)
{
    if (!root) {
        return;
    }
    gettop(root->left);

    if (empty < TOP) {
        ary[empty] = root;
        if (root->count < min) {

        }
    }

    gettop(root->right);
}*/

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
        printf("%s\n", line);
        while (word != NULL) {
            bst_insert(&root, word);
            word = getword(NULL);
        }
    }
    fclose(fp);
    bst_inorder(root);
    bst_free(&root);
    return 0;
}
