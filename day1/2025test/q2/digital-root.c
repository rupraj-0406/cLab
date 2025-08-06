#include "common.h"

int main(int ac, char *av[])
{
    unsigned int root = 0, sum;
    int c;

    while (EOF != (c = getchar()) && isdigit(c))
        root += c - '0';
    while (root > 9) {
        sum = 0;
        while (root > 0) {
            sum += root % 10;
            root = root / 10;
        }
        root = sum;
    }
    printf("%d\n", root);
    return 0;
}
