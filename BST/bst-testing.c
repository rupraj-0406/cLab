#include "common.h"
#include "bst.h"


void inorder(NODE *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
    return;
}

int main(int ac, char *av[])
{
    int *data, num, i, j;
    NODE *root = NULL;

    if (ac != 2)
        ERR_MESG("Usage: bst <number>");
    num = atoi(av[1]);

    if (NULL == (data = Malloc(num, int)))
        ERR_MESG("bst: out of memory");
    srand((int) time(NULL));
    for (i = 0; i < num; i++) {
        data[i] = rand() % 100000;
        root = insert(root, data[i]);
        fprintf(stderr, "After inserting %d\n", data[i]);
        print_pstree(root);
        fprintf(stderr, "\n\n");
    }
    inorder(root);
    printf("\n\n");

    for (i = 0; i < num; i++) {
        j = rand() % num;
        if (data[j] != -1) {
            root = delete(root, data[j]);
            fprintf(stderr, "After deleting %d:\n", data[j]);
            print_pstree(root);
            fprintf(stderr, "\n\n");
            data[j] = -1;
        }
    }

    return 0;
}
