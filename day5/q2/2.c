#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void solve(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int v = a[i];
        int d = INT_MAX;
        int res = -1;

        for (int j = i + 1; j < n; j++) {
            if (a[j] > v) {
                if (j - i < d) {
                    d = j - i;
                    res = a[j];
                }
            }
        }
        
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > v) {
                if (i - j <= d) {
                    d = i - j;
                    res = a[j];
                }
            }
        }
        printf("%d ", res);
    }
}

int main(int c, char *v[]) {
    if (c < 2) {
        printf("Usage: %s <num1> <num2> ...\n", v[0]);
        return 1;
    }

    int n = c - 1;
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) return 1;

    for (int i = 0; i < n; i++) {
        a[i] = atoi(v[i + 1]);
    }

    solve(a, n);

    free(a);
    return 0;
}