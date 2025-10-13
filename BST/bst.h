/* TRADITIONAL IMPLEMENTATION */

#ifndef BST_H
#define BST_H

typedef int DATA; // OR: typedef void * DATA;

typedef struct node {
    DATA data;
    struct node *left, *right;
} NODE;

/* Main operations: see bst.c for what each function returns */
extern NODE *insert(NODE *root, DATA d);
extern NODE *search(NODE *root, DATA d);
extern NODE *delete(NODE *root, DATA d);

/* Auxiliary operations (defined in bst-utils.c) */
extern int compare(NODE *n, DATA d);
extern NODE *detach_successor(NODE *node);

extern void print_tree(NODE *root, int indent);
extern void print_pstree(NODE *root); /* Ignore for now */

#endif /* BST_H */
