#include "common.h"
#include "bst-alt.h"

void inorder(TREE *tree, int root) {
    if (root == -1)
        return;
    inorder(tree->nodelist[root].left);
    printf("%d ", tree->nodelist[root].data);
    inorder(tree->nodelist[root].right);
    return;
}


int main(int ac, char *av[])
{
    int *data, num, i, j;
    NODE *nodeptr;
    TREE tree;

    if (ac != 2)
        ERR_MESG("Usage: bst <number>");
    num = atoi(av[1]); // max. number of nodes

    /* Initialise tree: should move this to a separate init_tree function */
    tree.num_nodes = 0;
    tree.max_nodes = N;
    tree.root = -1;
    tree.free_list = 0;
    /* TODO: set up free_list properly */
    if (NULL == (tree.nodelist = Malloc(num, NODE)) ||
        NULL == (data = Malloc(num, int)))
        ERR_MESG("bst: out of memory");

    /* Insert nodes */
    // srandom((int) time(NULL)); // Commented for reproducibility
    for (i = 0; i < num; i++) {
        data[i] = random() % 1000;
        tree.root = insert(&tree, tree.root, data[i]);
        fprintf(stderr, "After inserting %d\n", data[i]);
        print_pstree(&tree, tree.root);
        fprintf(stderr, "\n\n");
    }
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n\n");

    /* Dump the tree as a table: should move this to print_tree_as_table() */
    printf("%u\n", tree.num_nodes);
    for (i = 0, nodeptr = tree.nodelist; i < tree.num_nodes; i++, nodeptr++)
        printf("%d %d %d\n", nodeptr->data,
#ifdef LINENUM
               (nodeptr->left > 0) ? nodeptr->left + 2 : nodeptr->left,
               (nodeptr->right > 0) ? nodeptr->right + 2 : nodeptr->right
#else
               nodeptr->left, nodeptr->right
#endif
            );

    /* Delete nodes */
    for (i = 0; i < num; i++) {
        j = rand() % num;
        if (data[j] != -1) {
            tree.root = delete(&tree, tree.root, data[j]);
            fprintf(stderr, "After deleting %d:\n", data[j]);
            print_pstree(&tree, tree.root);
            fprintf(stderr, "\n\n");
            data[j] = -1;
        }
    }

    return 0;
}
