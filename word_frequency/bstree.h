#ifndef BSTREE_H
#define BSTREE_H
#define T BSTree_T

typedef struct T *T;

extern T bst_new(void);

extern void bst_insert(T *bst, const char *s);

extern void bst_free(T *bst);

extern void bst_inorder(T bst);

#undef T
#endif /* BSTREE_H */
