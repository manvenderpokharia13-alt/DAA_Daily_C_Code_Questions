#include <stdio.h>

// Normal recursive approach
int climbRecursive(int n) {
    if (n <= 2)
        return n;

    return climbRecursive(n - 1) + climbRecursive(n - 2);
}

// Optimal Dynamic Programming approach
int climbDP(int n) {
    if (n <= 2)
        return n;

    int a = 1, b = 2, c;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;

    printf("Enter number of stairs: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Enter a positive number.\n");
        return 0;
    }

    printf("Ways using Recursion: %d\n", climbRecursive(n));
    printf("Ways using Dynamic Programming: %d\n", climbDP(n));

    return 0;
}
