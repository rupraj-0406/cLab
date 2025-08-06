#include "common.h"

#define MAX_DAYS 100

int main(int ac, char *av[])
{
    int temperatures[MAX_DAYS], N, i;
    int warming, start, max_warming, max_warming_start,
        jump, max_jump, max_jump_day;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", temperatures + i);

    max_warming_start = start = 0;
    max_warming = 0; warming = 1;
    max_jump_day = max_jump = -1;
    for (i = 1; i < N; i++) {
        jump = temperatures[i] - temperatures[i-1];
        if (abs(jump) > max_jump) {
            max_jump = abs(jump);
            max_jump_day = i;
        }
        if (jump >= 0)
            warming++;
        else {
            if (warming > max_warming) {
                max_warming = warming;
                max_warming_start = start;
            }
            start = i;
            warming = 1;
        }
    }
    if (warming > max_warming) {
        max_warming = warming;
        max_warming_start = start;
    }

    printf("%d %d\n%d\n", max_warming_start + 1, max_warming,
           max_jump_day + 1);

    return 0;
}
