#include "common.h"
#include "bst.h"

int compare(NODE *n, DATA d)
{
    assert(n != NULL);
    return d - n->data;
}

NODE *detach_successor(NODE *node) {
    NODE *child;
    assert(node != NULL);
    /* Go to right child, then as far left as possible */
    child = node->right;
    if (child == NULL) /* no successors */
        return NULL;
    if (child->left == NULL) {
        node->right = child->right;
        return child;
    }
    while (child->left != NULL) {
        node = child;
        child = child->left;
    }
    node->left = child->right;
    return child;
}

void print_tree(NODE *root, int indent) {
    int i;
    if (root == NULL)
        return;
    print_tree(root->left, indent + 1);
    putchar('\n');
    for (i = 0; i < indent; i++)
        putchar('\t');
    printf("%d\n", root->data);
    putchar('\n');
    print_tree(root->right, indent + 1);
    return;
}

/* IGNORE FOR NOW */
void print_pstree(NODE *root) {
    if (root != NULL) {
        fprintf(stderr, "\\pstree{\\TCircle[radius=0.5]{%d}}{\n", root->data);
        print_pstree(root->left);
        print_pstree(root->right);
        fprintf(stderr, "}\n");
    }
    else
        fprintf(stderr, "\\pstree{\\Tn}{} \\pstree{\\Tn}{}");
    return;
}
