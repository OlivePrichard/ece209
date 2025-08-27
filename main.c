#include <stdio.h>

int main(void) {
    printf("Enter a number: ");
    fflush(stdout);
    unsigned int num;
    scanf("%u", &num);
    printf("Enter a digit: ");
    fflush(stdout);
    unsigned int digit;
    scanf("%u", &digit);
    unsigned int count = 0;
    for (unsigned n = num; n; n /= 10) {
        if (n % 10 == digit)
            count++;
    }
    if (num == 0 && digit == 0) count = 1;
    printf("The digit %u appears %u times in %u.\n", digit, count, num);
    return 0;
}