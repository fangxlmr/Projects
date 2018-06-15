#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BLOCK 1024


int split(char *str, char *ret[]);
int isquit(const char *str);

int main(void)
{
    char buf[BLOCK];
    char *index[BLOCK];
    int size;

    printf("Enter a expression:\n");
    while (fgets(buf, BLOCK, stdin) != NULL) {
        buf[strlen(buf) - 1] = '\0';

        if (isquit(buf)) {
            break;
        }

        size = split(buf, index);
        if (size > 0) {
            for (int i = 0; i < size; ++i) {
                printf("%s+", index[i]);
            }
            printf("\n");
        }
    }
    exit(0);
}


int split(char *str, char *ret[])
{
    const char s[] = " ";
    char *token;
    int count;

    count = 0;
    token = strtok(str, s);
    while (token != NULL) {
        ret[count++] = token;
        token = strtok(NULL, s);
    }
    return count;
}



int isquit(const char *str)
{
    return strcmp(str, "quit") == 0
           || strcmp(str, "q") == 0;
}