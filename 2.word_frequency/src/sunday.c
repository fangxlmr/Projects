#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *sunday (char *s, char *t);

char *sunday (char *s, char *t)
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
                head += t_len - (find - t);
            } else {
                head += t_len + 1;
            }
            i = 0;
        }
    }
    return NULL;
}
