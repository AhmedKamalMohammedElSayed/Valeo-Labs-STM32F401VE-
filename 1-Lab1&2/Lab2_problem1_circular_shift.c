#include <stdio.h>

unsigned char rotateRight(unsigned char x, int n) {
    return (x >> n) | (x << (8 - n));
}

unsigned char rotateLeft(unsigned char x, int n) {
    return (x << n) | (x >> (8 - n));
}

int main() {
    unsigned char x;
    int n;
    char option;

    printf("Enter an 8-bit number (0-255): ");
    scanf("%hhu", &x);

    printf("Enter number of rotate cycles: ");
    scanf("%d", &n);

    printf("Enter rotate option (R for right, L for left): ");
    scanf(" %c", &option);

    if (option == 'R' || option == 'r') {
        x = rotateRight(x, n);
        printf("Rotate Right: %hhu\n", x);
    } else if (option == 'L' || option == 'l') {
        x = rotateLeft(x, n);
        printf("Rotate Left: %hhu\n", x);
    } else {
        printf("Invalid rotate option. Please enter R for right or L for left.\n");
        return 1;
    }

    return 0;
}
