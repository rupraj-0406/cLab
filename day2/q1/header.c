#include "header.h"

// RLE encode function
void encode(const char *in, char *out, char *maxCh, int *maxCt) {
    int i = 0, k = 0, cnt, best = 0;
    char curr;

    while (in[i]) {
        curr = in[i];
        cnt = 1;

        while (in[i + 1] && in[i + 1] == curr) {
            cnt++;
            i++;
        }

        out[k++] = curr;

        if (cnt > 1) {
            k += sprintf(out + k, "%d", cnt);
        }

        if (cnt > best) {
            best = cnt;
            *maxCh = curr;
        }

        i++;
    }

    out[k] = '\0';
    *maxCt = best;
}

// RLE decode function
void decode(const char *in, char *out) {
    int i = 0, k = 0;
    while (in[i]) {
        char ch = in[i++];

        int cnt = 0;
        while (isdigit(in[i])) {
            cnt = cnt * 10 + (in[i++] - '0');
        }

        if (cnt == 0) cnt = 1;

        for (int j = 0; j < cnt && k < SIZE - 1; j++) {
            out[k++] = ch;
        }
    }

    out[k] = '\0';
}
