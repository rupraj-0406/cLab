#include "common.h"
#include "heap.h"

static int compare_int(void *array, int i1, int i2)
{
    int n1 = *((int *) array + i1);
    int n2 = *((int *) array + i2);
    return n1 - n2;
}


int main(int ac, char *av[])
{
    int i, x, *array;
    HEAP h;

    initHeap(&h, sizeof(int), compare_int);

    if (NULL == (array = Malloc(ac, int)))
        ERR_MESG("heap: out of memory");

    for (i = 1; i < ac; i++) {
        x = atoi(av[i]);
        insert(&h, (void *) &x);
        array[i] = x;
#if 0
        for (j = 1; j <= h.num_used; j++)
            printf("%d ", * (((int *) h.array) + j));
        putchar('\n');
#endif
    }

    assert(h.num_used + 1 == ac);
    
    for (i = 1; i < ac; i++) {
        deleteMax(&h, (void *) &x);
        printf("%d ", x);
    }
    putchar('\n');

    heapsort((void *) array, ac-1, sizeof(int), compare_int);

    free(array);

    return 0;
}
