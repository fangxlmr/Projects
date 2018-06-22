#ifndef BSTREE_H
#define BSTREE_H
#define T BSTree_T
struct T {
    char *s;
    unsigned int count;
    struct T *left, *right;
};
typedef struct T *T;

extern T bst_new(void);

extern void bst_insert(T *bst, const char *s);

extern void bst_free(T *bst);

#undef T
#endif /* BSTREE_H */
