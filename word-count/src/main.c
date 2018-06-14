#include <stdio.h>
#include <string.h>
#include "word.h"
#include "bstree.h"
#define MAX 1024    /* 行内最大字数 */

int sort(char *key1, char *key2);
int main(void)
{
    FILE *fp;
    char line[MAX];
    char s[] =  "the"; /* 待匹配字符串 */
    char *word;     /* 每个单词 */
    BSTree_T tree;
    char delim[] = " ";

    fp = fopen("./src/HarryPotter.txt", "r");
    tree = bst_new();

    while(readblock(line, fp) > 0) {
        word = strtok(line, delim);
        if (word != NULL) {
            bst_key_insert(tree, word);
        }
        while((word = strtok(NULL, delim)) != NULL) {
            bst_key_insert(tree, word);
        }
    }
    fclose(fp);
    printf("\n\n");
    printf("Done.\n");
    return 0;
}