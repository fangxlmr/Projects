#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "bstree.h"
#include "minheap.h"
#define MAXLINE 1024    /* Maxsize of a block */
int TOPK = 10; /*eTop K items */

char *get_block(char *buf, int n, FILE *fp);
void to_lower(char *line);
char *get_word(char *str);
void bst_inorder(BSTree_T root, BSTree_T *h, int *index);
char *sunday(char *s, char *t);
int cmp(const void *x, const void *y);

char *get_block(char *buf, int n, FILE *fp)
{
    int offset;
    int c;
    char *back;

    if (fgets(buf, n, fp) == NULL) {
        return NULL;
    } else {
        /*
         * 通过fp的上一个字符是否为'\n'判断，文件内一行的大小是否
         * 超过了n - 1， buf不够存储一行内容。此时，将buf字符串
         * 的长度缩短至buf内最后一个非字母字符处，计算出缩短的
         * 长度，并将文件指针fp也回溯相应的长度。
         */
        fseek(fp, -1 * sizeof(char), SEEK_CUR);
        c = fgetc(fp);
        if (c != '\n') {
            back = buf + n - 2;
            while (isalpha(*back)) {
                --back;
            }
            *back = '\0';
            offset = back - (buf + n - 2);
            fseek(fp, offset * sizeof(char), SEEK_CUR);
        }
        return buf;
    }
}

/* lower the case of chars
 * in the line of length n
 */
void to_lower(char *s)
{
    int i;
    
    if (!s) {
        return;
    }
    i = 0;
    while (s[i] != '\0') {
        if (isupper(s[i]) != 0) {
            s[i] = tolower(s[i]);
        }
        ++i;
    }
}

/*
 * 用sunday算法匹配字符串
 * s为目标字符串，t为模式串
 */
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

/* get a word from a string of length n */
char *get_word(char *s)
{
    int i;
    char *index;    /* Start index of a word */
    static char *next = NULL;  /* Next position of rest string */

    i = 0;
    index = NULL;

    /*
     * Reset s with last next pointer
     */
    if (s == NULL) {
        s = next;
    }
    /*
     * Find out a word, and return start index.
     * Reset next pointer at the same time.
     * If meet the ends of string,
     * reset next into NULL pointer.
     */
    if (s != NULL) {
        while (s[i] != '\0') {  /* Find a word */
            if (isalpha(s[i])) {
                index = &s[i++];
                break;
            }
            ++i;
        }
        while (s[i] != '\0') {  /* Reset next pointer */
            if (!isalpha(s[i])) {
                s[i++] = '\0';
                next = &s[i];
                break;
            }
            ++i;
        }
        if (s[i] == '\0') {     /* At the end of string, */
            next = NULL;        /* reset next with NULL */
        }
    }

    return index;
}


/*
 * Inorder traversal of bstree.
 * Store top k items of count into min heap.
 */
void bst_inorder(BSTree_T root, BSTree_T *h, int *index)
{
    if (!root) {
        return;
    }
    bst_inorder(root->left, h, index);

    if (*index < TOPK) {
        h[(*index)++] = root;
        shiftup(h, *index, *index - 1);
    } else {
        if (root->count > h[0]->count) {
            h[0] = root;
            shiftdown(h, *index, 0);
        }
    }

    bst_inorder(root->right, h, index);
}

/* Compare function for qsort */
int cmp(const void *x, const void *y)
{
    BSTree_T *a, *b;
    a = (BSTree_T *)x;
    b = (BSTree_T *)y;
    return (*b)->count - (*a)->count;
}

int main(int argc, char *argv[])
{
    int opt;    /* 程序命令选项 */
    char line[MAXLINE];
    char *word;
    int SINGLE;
    char *pattern;
    FILE *fp;
    BSTree_T root;      /* 二叉树根结点 */

    /*
     * fp默认设置为stdin.
     */
    fp = stdin;
    /*
     * 默认关闭单个单词的字符统计。
     * 当SINGLE = 1时，只统计文件内指定单词的出现次数
     */
    SINGLE = 0;

    while ((opt = getopt(argc, argv, "n:f:w:")) != -1) {
        switch (opt) {
        case 'f':
            fp = fopen(optarg, "r");
            break;
        case 'n':
            TOPK = atoi(optarg);
            break;
        case 'w':
            SINGLE = 1;
            pattern = optarg;
            break;
        case '?':
            printf("Unknown option: %c\n", optopt);
            break;
        }
    }


    if (SINGLE == 1) {
        unsigned int count;

        count = 0;

        while (get_block(line, MAXLINE, fp)) {
            to_lower(line);       /* 所有字母小写  */
            /*
             * 解析获取到的字符串
             */
            word = get_word(line);
            while (word != NULL) {
                /*
                 * 使用sunday算法查找
                 * TODO 1. 这里其实并不完善，sunday算法只能查找到
                 * 匹配的字符串，但是没有办法区分单词。比如：查找
                 * 单词the出现的次数，这会把包含the的单词也包含进去
                 * （比如them, then, their）。
                 * TODO 2. 这里的sunday算法查找到匹配的单词就返回
                 * 但是没有返回包含该模式子串的个数。
                 */
                if (sunday(line, pattern) != NULL) {
                    ++count;
                }
                word = get_word(NULL);
            }
        }
        printf("%s\tcount = %d", pattern, count);
        fclose(fp);
        return 0;
    }
    /*
     * 新建二叉树
     */
    root = bst_new();
    while (get_block(line, MAXLINE, fp)) {
        to_lower(line);       /* 所有字母小写  */
        /*
         * 解析获取到的字符串，并存储进二叉树内
         */
        word = get_word(line);
        while (word != NULL) {
            bst_insert(&root, word);
            word = get_word(NULL);
        }
    }
    fclose(fp);

    /*
     * Find out top k of
     * count using min heap
     */
    BSTree_T top[TOPK];
    int index = 0;
    /*
     * Inorder traversal BSTree and find out
     * top k items in the tree and print them out
     */
    bst_inorder(root, top, &index);
    qsort(top, index, sizeof(top[0]), cmp);
    for (int i = 0; i < index; ++i) {
        printf("No.%d:\t%s\tcount = %d\n", i + 1, top[i]->s, top[i]->count);
    }
    bst_free(&root);
    return 0;
}
