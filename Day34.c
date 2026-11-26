#include <stdio.h>

// Normal Approach: Linear Search
int linearSqrt(int n) {
    int i = 0;

    while ((long long)i * i <= n) {
        i++;
    }

    return i - 1;
}

// Optimized Approach: Binary Search
int binarySqrt(int n) {
    int low = 0;
    int high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Square root of negative number is not supported.\n");
        return 0;
    }

    printf("Square root using Linear Search: %d\n",
           linearSqrt(n));

    printf("Square root using Binary Search: %d\n",
           binarySqrt(n));

    return 0;
}
