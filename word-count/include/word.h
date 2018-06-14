#ifndef _WORD_H
#define _WORD_H

#include <stdio.h>
#include <string.h>

/*
 * 读取字符块：1024 Kb
 * 返回实际读取到的个数
 */
int readblock(char *s, FILE *fp);

char *getword(char *s);

#endif /* _WORD_H */