#ifndef BULLET_BSTREE_H
#define BULLET_BSTREE_H

#include <stdlib.h>
#include <stdio.h>
#define T BSTree_T

typedef struct T *T;

/* 新建二叉树根结点并初始化 */
extern T bst_new (void);

/* 判断二叉树是否为空 */
extern int bst_empty (T bst);

/* 求二叉树最大深度 */
extern int bt_depth (T bst);

/* 释放二叉树 */
extern void bst_free (T *bst);

/* 查找结点 */
extern int bst_key_search (T bst, char *key);

/* 插入结点 */
extern void bst_key_insert (T bst, char *key);

#undef T
#endif /* BULLET_BSTREE_H */