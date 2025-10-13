#include "common.h"
#include "bst-alt.h"

int insert(TREE *tree, int root, DATA d) {
    int next;

    if (root == -1) {
        if (-1 == (next = get_new_node(tree)))
            ERR_MESG("insert: out of memory");
        tree->nodelist[next].data = d;
        tree->nodelist[next].left = tree->nodelist[next].right = -1;
        return next;
    }

    if (d < tree->nodelist[root].data)
        tree->nodelist[root].left = insert(tree, tree->nodelist[root].left, d);
    else if (d > tree->nodelist[root].data)
        tree->nodelist[root].right = insert(tree, &tree->nodelist[root].right, d);
    return root;
}

int search(TREE *tree, int root, DATA d) {
    if (root == -1) return -1;
    if (d < tree->nodelist[root].data) 
        return search(tree, tree->nodelist[root].left, d);
    if (d > tree->nodelist[root].data)
        return search(tree, tree->nodelist[root].right, d);
    return root;
}

int delete(TREE *tree, int root, DATA d) {
    if (root == -1) return -1;

    if (d < tree->nodelist[root].data)
        tree->nodelist[root].left = delete(tree, tree->nodelist[root].left, d);
    else if (d > tree->nodelist[root].data)
        tree->nodelist[root].right = delete(tree, &tree->nodelist[root].right, d);
    else {
        /* TODO: complete this part */
    }

    return root;
}
