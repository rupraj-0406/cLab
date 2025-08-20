/*
 * float.c - illustrate various counterintuitive results obtained
 * using floating point arithmetic
 */

#include "common.h"
#include <float.h>

int
main(int ac, char **av)
{
    int i;
    float f, saved_f;
    double f1 = 0.1;

    /* f1 appears to be 1.1, but is not */
    for (i=0; i < 10; i++, f1 += 0.1);
    printf("f1: %f\n1.1: %f\n", f1, 1.1);
    if (f1 == 1.1) printf("f1 == 1.1\n");
    else printf("%.20f\n", fabs(f1-1.1));

    /* Adding 1 to a large floating point number has no effect */
    printf("%e %e\n", FLT_MIN, FLT_MAX);
    saved_f = f = FLT_MAX/1e20; /* AT WHAT VALUE DOES THIS START HAPPENING? */
    for (i = 0; i < 10'000'000; i++) {
        f += 1.0;
        if (saved_f == f) {
            printf("At f=%20f (%e), adding 1 has no effect\n", f, f);
            break;
        }
        else saved_f = f;
    }
    
    return 0;
}
