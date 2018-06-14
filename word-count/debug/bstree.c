#include <assert.h>
#include <string.h>
#include "bstree.h"

#define T BSTree_T
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/* 结点的结构 */
typedef struct BSTNode {
    char *x;
    int count;
    struct BSTNode *left, *right;
}*BSTNode;

struct T {
    BSTNode root;
};


/* 新建二叉树根结点并初始化 */
T bst_new (void) {
    T t = (T) malloc(sizeof(struct T));
    t->root = NULL;
    return t;
}


/* 判断二叉树是否为空 */
int bst_empty (T bst) {
    return bst->root == NULL;
}

/* 求二叉树最大深度 */
static int depth (BSTNode root) {
    if (!root)
        return 0;
    return MAX(depth(root->left), depth(root->right)) + 1;
}
int bst_depth (T bst) {
    return depth(bst->root);
}


/* 释放二叉树 */
static void destroy (BSTNode *root) {
    if (!*root) {
        return;
    }
    destroy(&(*root)->left);
    destroy(&(*root)->right);
    free(*root);
    *root = NULL;
}
void bst_free (T *bst) {
    assert(bst && *bst);
    destroy(&(*bst)->root);
    *bst = NULL;
}


static int search (BSTNode root, char *key) {
    if (strcmp(key, root->x) == 0) {
        return 1;
    }
    if (strcmp(key, root->x) < 0) {
        return search(root->left,  key);
    } else {
        return search(root->right, key);
    }
}

/* 查找结点 */
int bst_key_search (T bst, char *key) {
    assert(bst && bst->root);

    return search(bst->root, key);
}


static void insert (BSTNode *root, char *key) {
    if (!*root) {
        int len;
        char *dummy;

        len = strlen(key);
        dummy = (char *) malloc((len + 1) * sizeof(char));
        strncpy(dummy, key, (len + 1) * sizeof(char));
        BSTNode p = (BSTNode) malloc(sizeof(struct BSTNode));
        p->x = dummy;
        p->count = 0;
        p->left = p->right = NULL;
        *root = p;
        return;
    }
    else if (strcmp(key, (*root)->x) == 0) {
        (*root)->count++;  /* 重复值加一 */
        return;
    }
    else if (strcmp(key, (*root)->x) < 0) {
        insert(&(*root)->left, key);
    }
    else {
        insert(&(*root)->right, key);
    }
}

/* 插入结点 */
void bst_key_insert (T bst, char *key) {
    assert(bst);
    insert(&bst->root, key);
}