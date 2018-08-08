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
     * You can check it out in the website:
     * https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
     */

}