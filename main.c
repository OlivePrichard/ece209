#include <stdio.h>
#include <string.h>

int fact(int n);

int main(void) {
    int userNum;
    const int maxDigits = 9;      // will allow up to 9 digits in the input value
    int digits[maxDigits];  // array of digits, initialized to zero

    printf("Enter a decimal integer (>= 1): ");
    fflush(stdout);
    scanf("%d", &userNum);  // input assumed to meet the spec

    int num = userNum;
    int numDigits = 0;
    for (; userNum; numDigits++) {
        digits[numDigits] = userNum % 10;
        userNum /= 10;
    }
    if (numDigits == 0) {
        numDigits = 1;
        digits[0] = 0;
    }
    printf("Digits: ");
    for (int i = numDigits - 1; i >= 0; i--) {
        printf("%d", digits[i]);
        if (i > 0) printf(",");
    }
    printf("\n");
    fflush(stdout);

    for (int i = numDigits - 1; i >= 0; i--) {
        printf("%d! = %d\n", digits[i], fact(digits[i]));
    }
    fflush(stdout);

    int sum = 0;
    for (int i = 0; i < numDigits; i++)
        sum += fact(digits[i]);
    printf("Sum = %d\n", sum);
    char res[5] = "";
    if (sum != num) strcpy(res, " not");
    printf("%d is%s a strong number.\n", num, res);

    return 0;
}

int fact(const int n) {
    int acc = 1;
    for (int i = 2; i <= n; i++) acc *= i;
    return acc;
}