#include "header.h"

int main() {
    char input[SIZE], encoded[SIZE], decoded[SIZE];
    char mostCh = '\0';
    int maxCt = 0;

    printf("Input string: ");
    if (fgets(input, SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // remove newline if exists
    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) == 0) {
        printf("Empty input.\n");
        return 0;
    }

    // Encoding
    encode(input, encoded, &mostCh, &maxCt);
    printf("Encoded: %s\n", encoded);
    printf("Max repeated char: %c (count: %d)\n", mostCh, maxCt);

    // Decoding
    decode(encoded, decoded);
    printf("Decoded: %s\n", decoded);

    return 0;
}
