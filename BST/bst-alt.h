/* "ALTERNATE" FORTRAN-STYLE IMPLEMENTATION */
#ifndef BST_ALT_H
#define BST_ALT_H

typedef int DATA;

typedef struct node {
    DATA data;
    int left, right;
} NODE;

typedef struct {
    unsigned int num_nodes, max_nodes;
    int root, free_list;
    NODE *nodelist;
} TREE;

/* Main operations: see bst-alt.c for what each function returns */
extern int insert(TREE *, int root, DATA d);
extern int search(TREE *, int root, DATA d);
extern int delete(TREE *, int root, DATA d);

/* Auxiliary operations (defined in bst-alt-utils.c) */
extern int get_new_node(TREE *);
extern void free_up_node(TREE *, int node);
extern int detach_successor(TREE *, int node);

extern void print_tree(TREE*, int root);
extern void print_pstree(TREE*, int root);

#endif /* BST_ALT_H */
