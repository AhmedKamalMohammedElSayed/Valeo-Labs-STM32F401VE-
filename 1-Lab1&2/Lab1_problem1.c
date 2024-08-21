#include <stdio.h>

int main()
{
    float u, a, t, v, s;

    printf("Enter the initial velocity (u): ");
    scanf("%f", &u);

    printf("Enter the acceleration (a): ");
    scanf("%f", &a);

    printf("Enter the time elapsed (t): ");
    scanf("%f", &t);

    v = u + (a * t);

    s = (u * t) + (0.5 * a * t * t);

    printf("Final velocity (v): %f\n", v);
    printf("Distance traveled (s): %f\n", s);

    return 0;
}
