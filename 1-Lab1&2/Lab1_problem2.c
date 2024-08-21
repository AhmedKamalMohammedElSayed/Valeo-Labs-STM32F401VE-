#include <stdio.h>

int main() {
    int num1, num2, num3;
    
    printf("Enter three different integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int sum = num1 + num2 + num3;
    printf("Sum is : %d\n", sum);

    
    float average = (float)sum / 3;
    printf("Average is : %.2f\n", average);

    int product = num1 * num2 * num3;
    printf("Product is : %d\n", product);

    int smallest = num1 < num2 ? (num1 < num3 ? num1 : num3) : (num2 < num3 ? num2 : num3);
    printf("Smallest is : %d\n", smallest);

    int largest = num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3);
    printf("Largest is : %d\n", largest);

    return 0;
}
