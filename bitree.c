typedef struct _BiTree BiTree;
struct _BiTree {
    int val;
    BiTree *left;
    BiTree *right;
};

#define max(x, y) ((x) > (y) ? (x) : (y))
/**
* get_depth     find the max depth of binary tree
*/
int get_depth(BiTree *root)
{
    if (!root) {
        return 0;
    }

     return 1 + max(get_depth(root->left), \
                    get_depth(root->right));
}

#undef max

#define min(x, y) ((x) < (y) ? (x) : (y))
/**
 * get_min_depth    find the min depth of binary tree
 */
int get_min_depth(BiTree *root)
{
    if (!root) {
        return 0;
    } else if (root->left && root->right) {
        return 1 + min(get_min_depth(root->left), \
                       get_min_depth(root->right));
    } else {
        BiTree *tmp;
        tmp = root->left ? root->left : root->right;
        return 1 + get_min_depth(tmp);
    }
}

#undef min

/**
 * get_num      get the total of nodes in bitree
 */
int get_num(BiTree *root)
{
    if (!root) {
        return 0;
    }
    return 1 + get_num(root->left) + get_num(root->right);
}

/**
 * pre_order    preorder traversal of bitree recursively
 */
void pre_order(BiTree *root)
{
    if (!root) {
        return;
    }

    printf("val = %d\n", root->val);
    pre_order(root->left);
    pre_order(root->right);
}

/**
 * pre_order    preorder traversal of bitree non-recursively
 * @note        using stack
 */
void pre_order(BiTree *root)
{
    if (!root) {
        return;
    }

    BiTree *stack[1024];
    int sp = 0;
#define push(p) stack[sp++] = p
#define pop()   stack[--sp]
#define is_empty()  sp == 0
    BiTree *p;
    p = root;
    while (p || !is_empty()) {
        if (p) {
            printf("val = %d\n", p->val);
            push(p);
            p = p->left;
        } else {
            p = pop();
            p = p->right;
        }
    }
#undef is_empty
#undef pop
#undef push
}

/**
 * pre_order    Morris preorder traversal of bitree in place
 */
void pre_order(BiTree *root)
{
    BiTree *cur, *prev;
    cur = root;
    prev = NULL;
    while (cur) {
        if (!cur->left) {
            printf("val = %d\n", cur->val);
            cur = cur->right;
        } else {
            /* find predecessor */
            prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }

            /* visit root node before left node */
            if (prev->right == NULL) {
                printf("val = %d\n", cur->val);
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
}

/**
 * in_order     inorder traversal of bitree recursively
 */
void in_order(BiTree *root)
{
    if (!root) {
        return;
    }

    in_order(root->left);
    printf("val = %d\n", root->val);
    in_order(root->right);
}

/**
 * in_order     inorder traversal of bitree non-recursively
 * @note        using stack
 */
void in_order(BiTree *root)
{
    if (!root) {
        return;
    }

    BiTree *stack[1024];
    int sp = 0;
#define push(p) stack[sp++] = p
#define pop()   stack[--sp]
#define is_empty()  sp == 0
    BiTree *p;
    p = root;
    while (p || !is_empty()) {
        if (p) {
            push(p);
            p = p->left;
        } else {
            p = pop();
            printf("val = %d\n", p->val);
            p = p->right;
        }
    }
#undef is_empty
#undef pop
#undef push
}

/**
 * in_order    Morris inorder traversal of bitree in place
 */
void in_order(BiTree *root)
{
    BiTree *cur, *prev;
    cur = root;
    prev = NULL;

    while (cur) {
        if (!cur->left) {
            printf("val = %d\n", cur->val);
            cur = cur->right;
        } else {
            /* find predecessor */
            prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }

            /* visit left node before root node */
            if (prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else {
                printf("val = %d\n", cur->val);
                cur = cur->right;
            }
        }
    }
}


/**
 * post_order  postorder traversal of bitree recursively
 */
void post_order(BiTree *root)
{
    if (!root) {
        return;;
    }

    post_order(root->left);
    post_order(root->right);
    printf("val = %d\n", root->val);
}

/**
 * post_order  postorder traversal of bitree non-recursively
 * @note       using queue
 */
void post_order(BiTree *root)
{
    if (!root) {
        return;
    }

    BiTree *p;
    p = root;
    while (p || is_empty) { /* is_empty works for queue */
        if (p) {
            printf("val = %d\n", p->val);
            if (p->left) {
                enqueue(p->left);
            }
            if (p->right) {
                enqueue(p->right);
            }
        } else {
            p = dequeue();
        }
    }
}

/**
 * post_order  Morris postorder traversal of bitree in place
 */
void post_order(BiTree *root)
{
    /*
     * TODO there is a Morris postorder traversal of bitree,
     * TODO but it's a bit complicated.
     * You can check it out by following link:
     * https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
     */
}

/**
 * convert      convert bitree to doubly linked list in place
 *
 * @param root  root of bitree
 * @param head  secondly pointer of doubly linked list
 * @note        it can be done recursively, but I use Morris algorithm here.
 *
 * //TODO to be tested
 */
typedef BiTree Node;
void convert(BiTree *root, Node **head)
{
    if (!root) {
        return;
    }

    /*
     * initialize previous visited node as NULL.
     * it is static so that it will be accessible
     * in all recursive calls.
     */
    static BiTree *prev = NULL;

    /* recursively convert left subtree */
    convert(root->left, head);

    /* convert this node */
    if (prev == NULL) {
        *head = root;
    } else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    /* finally convert right subtree */
    convert(root->right, head);
}

/**
 * get_num_k_level  get total of nodes in k level of bitree
 */
int get_num_k_level(BiTree *root, int k)
{
    int left, right;

    if (!root || k < 1) {
        return 0;

    } else if (k == 1) {
        return 1;

    } else {
        left  = get_num_k_level(root->left,  k - 1);
        right = get_num_k_level(root->right, k - 1);
        return left + right;
    }
}

/**
 * get_num_leaves   get total of leaves in bitree
 */
int get_num_leaves(BiTree *root)
{
    if (!root) {
        return 0;

    } else if (!root->left && !root->right) {
        return 1;

    } else {
        return get_num_k_level(root->left) + \
               get_num_k_level(root->right);
    }
}

/**
 * is_same      check r1 and r2 is the same
 */
int is_same(BiTree *r1, BiTree *r2)
{
    if (!r1 && !r2) {
        return 1;
    } else if (!r1 || !r2) {
        return 0;
    } else {
        int x1, x2;
        x1 = is_same(r1->left)  && is_same(r2->left);
        x2 = is_same(r1->right) && is_same(r2->right);
        return x1 && x2;
    }
}

/**
 * is_symmetric    check bitree is symmetry recursively
 */
int is_symmetric(BiTree *root) {
    int helper(BiTree *r1, BiTree *r2);

    return helper(root, root);
}

int helper(BiTree *r1, BiTree *r2) {
    if (!r1 && !r2) {
        return 1;
    }
    if (!r1 || !r2) {
        return 0;
    }
    return r1->val == r2->val && \
           helper(r1->left, r2->right) && \
           helper(r1->right, r2->left);
}

/**
 * is_symmetric    check bitree is symmetry using queue
 */
int is_symmetric(BiTree *root) {
    if (!root) {
        return 1;
    }

    BiTree *p, *q;
    enqueue(root);
    enqueue(root);
    while (!is_empty()) {
        p = dequeue();
        q = dequeue();

        if (p && q && p->val == q->val) {
            /* enqueue reversely */
            enqueue(p->left);
            enqueue(q->right);
            enqueue(p->right);
            enqueue(q->left);

        } else if (!p && !q) {
            continue;
            
        } else {
            return 0;
        }
    }
    return 1;
}
