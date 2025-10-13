#include "bst-alt.h"

int get_new_node(TREE *tree) {
    int newnode, i;
    NODE *tmp;
    if (tree->free_list == -1) {
        assert(tree->num_nodes == tree->max_nodes);
        tree->max_nodes *= 2;
        if (NULL == (tmp = Realloc(tree->nodelist, tree->max_nodes, NODE)))
            return -1;
        tree->nodelist = tmp;
        tree->free_list = tree->num_nodes;
        for (i = tree->num_nodes+1; i < tree->max_nodes; i++)
            tree->nodelist[i-1].left = i;
        tree->nodelist[i-1].left = -1;
    }
    newnode = tree->free_list;
    tree->free_list = tree->nodelist[tree->free_list].left;
    return newnode;
}

void free_up_node(TREE *tree, int index) {
    tree->nodelist[index].left = tree->free_list;
    /* tree->nodelist[index].right = tree->nodelist[index].parent = -1; */
    /* tree->nodelist[index].height = 0; */
    tree->free_list = index;
    return;
}

int detach_successor(TREE *tree, int node) {
    int child;
    assert(node != -1);
    /* Go to right child, then as far left as possible */
    child = tree->nodelist[node].right;
    if (child == -1) /* no successors */
        return -1;
    if (tree->nodelist[child].left == -1) {
        tree->nodelist[node].right = tree->nodelist[child].right;
        return child;
    }
    while (tree->nodelist[child].left != -1) {
        node = child;
        child = tree->nodelist[child].left;
    }
    tree->nodelist[node].left = tree->nodelist[child].right;
    return child;
}

void print_tree(TREE *tree, int root) {
    /* TODO */
    return;
}

void print_pstree(TREE *tree, int root) {
    if (root != -1) {
        fprintf(stderr, "\\pstree{\\TCircle[radius=0.5]{%d}}{\n", tree->nodelist[root].data);
        print_pstree(tree, tree->nodelist[root].left);
        print_pstree(tree, tree->nodelist[root].right);
        fprintf(stderr, "}\n");
    }
    else
        fprintf(stderr, "\\pstree{\\Tn}{} \\pstree{\\Tn}{}");

    return;
}
