#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#define BLOCK 1024

int split(char *str, List_T ret);
int isquit(const char *str);

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