#include "word.h"
#define LIMIT 1024

int readblock(char *s, FILE *fp)
{
    return fgets(s, LIMIT, fp);
}


//char *getword(char *s)
//{
//    char delim[] = " ";     /* 空格作为分隔符 */
//    return strtok(s, delim);
//}