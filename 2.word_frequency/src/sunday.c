#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *readline(char *line, int n, FILE *fp);
char *match (char *s, char *t);

char *readline(char *line, int n, FILE *fp)
{
    int offset;
    int c;
    char *backward;

    if (fgets(line, n, fp) == NULL) {
        return NULL;
    } else {
        fseek(fp, -1 * sizeof(char), SEEK_CUR);
        c = fgetc(fp);
        if (c != '\n') {
            backward = line + n - 2;
            while (isalpha(*backward)) {
                --backward;
            }
            *backward = '\0';
            offset = backward - (line + n - 2);
            fseek(fp, offset * sizeof(char), SEEK_CUR);
        }
        return line;
    }

}

char *match (char *s, char *t)
{
    int i, head;
    int s_len, t_len;
    char *find;

    s_len = strlen(s);
    t_len = strlen(t);

    i = 0;
    head = 0;
    while (head + t_len < s_len) {
        if (s[head + i] == t[i]) {
            ++i;
            if (i == t_len) {
                return s + head;
            }
        } else {
            if ((find = strrchr(t, s[head + t_len])) != NULL) {
                //printf("head + t_len - 1 = %d, s_len = %d.\n", head + t_len - 1, s_len);
                head += t_len - (find - t);
            } else {
                head += t_len + 1;
            }
            i = 0;
        }
    }
    return NULL;
}

int main(void)
{
    FILE *fp;
    char s[1024];
    char p[] = "All was well";

    fp = fopen("../res/Harry Potter.txt", "r");
    while(readline(s, 1024, fp) != NULL) {
        if (match(s, p) != NULL) {
            printf("%s", s);
        }
    }
    fclose(fp);
    return 0;
}
