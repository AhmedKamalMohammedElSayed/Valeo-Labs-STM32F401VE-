#include <stdio.h>

int main() {
    double x, result = 1.0;
    int n, i, j;

    printf("Enter the exponent (x): ");
    scanf("%lf", &x);

    printf("Enter the number of iterations (n): ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        double term = 1.0;
        for (j = 1; j <= i; ++j) {
            term *= x / j;
        }
        result += term;
    }
    printf("Exponential result e^%.2f using %d iterations: %.6f\n", x, n, result);

    return 0;
}
