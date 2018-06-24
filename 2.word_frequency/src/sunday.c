#include <stdio.h>
#include <string.h>

int sunday (char *s, char *t)
{
    int i;
    int lp;
    char *head;
    char *find;

    i = 0;
    lt = strlen(t);
    head = s;
    while(head != NULL) {
        if(*(head + i) == *(t + i)) {
            ++i;
            if(*(t + i) == '\0') {
                printf("yes.\n");
                return 1;
            }
        } else {
            find = strrchr(t, *(head + lt));
            if(find != NULL){
                head += t + lt - find;
            } else {
                head = head + lt + 1;
            }
            i = 0;
        }
    }
    printf("no.\n");
    return 0;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char s[1024];
    char p[] = "All was well.";

    fp = fopen("./HarryPotter.txt", "r");
    while(fgets(s, 1024, fp) != NULL) {
         if(sunday(s, p))
             printf("find.\n");
        else
            printf("not find.\n");

    }
    return 0;
}
