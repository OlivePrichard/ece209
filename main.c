/* Olive Prichard - 22 Sep 2025
 *
 * This program calculates a fractional
 * approximation of the given number with
 * a given limit on the size of the denominator.
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    // read inputs
    double target;
    int maxDen;
    printf("Enter floating point value between 0 and 1: ");
    fflush(stdout);
    scanf("%lf", &target);
    printf("Enter maximum denominator: ");
    fflush(stdout);
    scanf("%d", &maxDen);
    printf("\n");

    // initial values
    int a = 0, b = 1;
    int c = 1, d = 1;
    double mediant = 0.0;
    while (b + d <= maxDen) {
        printf("%d/%d     %d/%d     %d/%d\n", a, b, c, d, a+c, b+d);
        mediant = (double) (a + c) / (b + d); // calculate next mediant
        if (mediant <= target) { // go up
            a += c;
            b += d;
            // stop iterating if fraction found
            if (fabs(mediant - target) < 1e-9) break;
        }
        else { // go down
            c += a;
            d += b;
        }
    }
    // print out last mediant if needed
    if (b <= maxDen && d <= maxDen && fabs(mediant - target) >= 1e-9)
        printf("%d/%d     %d/%d     %d/%d\n", a, b, c, d, a+c, b+d);
    const double firstDiff = target - (double) a / b;
    const double secondDiff = (double) c / d - target;
    // find the closest of the possible fractions
    if (secondDiff < firstDiff || secondDiff == firstDiff && d < b) {
        a = c;
        b = d;
    }

    // print out results
    printf("Closest fraction is %d/%d\n", a, b);
    printf("Fraction value is %lf\n", (double) a / b);
    printf("Error = %e\n", fabs(target - (double) a / b));
    fflush(stdout);

    return 0;
}