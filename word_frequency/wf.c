#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "bstree.h"
#define MAXLINE 5000    /* 行内最大字数 */

char *getword(char *str);

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

int main(void)
{
    char line[MAXLINE];
    char *word;
    FILE *fp;
    BSTree_T root;

    root = bst_new();
    fp = fopen("./Knowledge and Virtue.txt", "r");
    while (fgets(line, MAXLINE, fp)) {
        word = getword(line);
        while (word != NULL) {
//            printf("%s\n", word);
            bst_insert(&root, word);
            word = getword(NULL);
        }
    }
    fclose(fp);
    bst_inorder(root);
    bst_free(&root);
    return 0;
}
