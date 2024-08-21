#include<stdio.h>

void printFibonacci(int n);

int main(){
    int n;
    scanf("%d",&n);
    printFibonacci(n);
    return 0;
}

void printFibonacci(int n) {
    int first = 0, second = 1, next;
    printf("Fibonacci Series up to %d terms:\n" ,n);

    for (int i = 0; i < n; ++i) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf(" %d",next);
    }
        printf("\n");
}