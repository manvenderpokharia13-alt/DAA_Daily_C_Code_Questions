#include <stdio.h>
#include <limits.h>

// Optimized Approach: Single Traversal
int thirdMax(int arr[], int n) {

    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    for (int i = 0; i < n; i++) {

        if (arr[i] == first ||
            arr[i] == second ||
            arr[i] == third)
            continue;

        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        }

        else if (arr[i] > second) {
            third = second;
            second = arr[i];
        }

        else if (arr[i] > third) {
            third = arr[i];
        }
    }

    if (third == LLONG_MIN)
        return first;

    return third;
}

int main() {

    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 0;
    }

    int arr[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Third maximum number: %d\n",
           thirdMax(arr, n));

    return 0;
}
