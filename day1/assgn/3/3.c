#include <stdio.h>

char *ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
char *teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                  "sixteen", "seventeen", "eighteen", "nineteen" };
char *tens[] = { "", "", "twenty", "thirty", "forty", "fifty",
                  "sixty", "seventy", "eighty", "ninety" };

void two_digit(int n) {
    if (n == 0) return;
    if (n < 10)
        printf("%s ", ones[n]);
    else if (n < 20)
        printf("%s ", teens[n - 10]);
    else {
        printf("%s ", tens[n / 10]);
        if (n % 10 != 0)
            printf("%s ", ones[n % 10]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("zero\n");
        return 0;
    }

    int lakh = n / 100000;
    int thousand = (n / 1000) % 100;
    int hundred = (n / 100) % 10;
    int last_two = n % 100;

    if (lakh > 0) {
        two_digit(lakh);
        printf("lakh ");
    }

    if (thousand > 0) {
        two_digit(thousand);
        printf("thousand ");
    }

    if (hundred > 0) {
        printf("%s hundred ", ones[hundred]);
    }

    if (last_two > 0) {
        two_digit(last_two);
    }

    printf("\n");
    return 0;
}
