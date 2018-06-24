#include "file.h"

char *readblock(char *s, int n, FILE *fp)
{
    int offset;
    int c;
    char *backward;

    if (fgets(s, n, fp) == NULL) {
        return NULL;
    } else {
        fseek(fp, -1 * sizeof(char), SEEK_CUR);
        c = fgetc(fp);
        if (c != '\n') {
            backward = s + n - 2;
            while (isalpha(*backward)) {
                --backward;
            }
            *backward = '\0';
            offset = backward - (s + n - 2);
            fseek(fp, offset * sizeof(char), SEEK_CUR);
        }
        return s;
    }
}
