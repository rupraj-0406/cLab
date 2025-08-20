#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 128


void multiple_input_loops_getchar()
{
    int c = 0;

    do
        printf("1st round: %d\n", c);
    while (EOF != (c = getchar()));

    do
        printf("2nd round: %d\n", c);
    while (EOF != (c = getchar()));
}

void multiple_input_loops_scanf()
{
    char c = 0;

    do
        printf("1st round: %d\n", c);
    while (EOF != scanf("%c", &c));

    do
        printf("2nd round: %d\n", c);
    while (EOF != scanf("%c", &c));
}

int main(int ac, char *av[])
{
#if OPTION==1
    char buffer1[BUF_LEN], buffer2[BUF_LEN];
    int c;

    /* Reading comma separated values: try on test-input.txt */
    while (1) {
        scanf("%[^,],%[^,],", buffer1, buffer2);
        printf("%s\n", buffer1);
        printf("%s\n", buffer2);
        if (EOF == (c = getchar())) exit(0);
        printf("%c %d\n", c, c);
    }
#elif OPTION==2
    int c, d;

    /* Read an arbitrary number of integers */
    c = 0;
    while (1 == scanf("%d", &d)) {
        c++;
        printf("Read %d-th integer %d\n", c, d);
    }
#else
    /* Cannot resume input once EOF is found */
    multiple_input_loops_scanf();
    multiple_input_loops_getchar();
    exit(0);
#endif
    return 0;
}
