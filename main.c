#include <stdio.h>
#include <math.h>

int main(void) {
    double target;
    int maxDen;
    printf("Enter floating point value between 0 and 1: ");
    fflush(stdout);
    scanf("%lf", &target);
    printf("Enter maximum denominator: ");
    fflush(stdout);
    scanf("%d", &maxDen);
    printf("\n");

    int a = 0, b = 1;
    int c = 1, d = 1;
    while (b + c <= maxDen) {
        const double mediant = (double)(a + c) / (b + d);
        if (mediant <= target) {
            a += c;
            b += d;
            if (mediant == target) break;
        }
        else {
            c += a;
            d += b;
        }
    }
    const double firstDiff = target - (double)a / b;
    const double secondDiff = (double)c / b - target;
    if (secondDiff < firstDiff || secondDiff == firstDiff && d < b) {
        a = c;
        b = d;
    }

    printf("Closest fraction is %d/%d\n", a, b);
    printf("Fraction value is %lf\n", (double)a / b);
    printf("Error = %e\n", fabs(target - (double)a / b));
    fflush(stdout);

    return 0;
}