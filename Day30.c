#include <stdio.h>

// Normal Approach: Brute Force
int bruteForce(int arr[], int n) {
    for (int i = 1; i <= n + 1; i++) {
        int found = 0;

        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = 1;
                break;
            }
        }

        if (!found)
            return i;
    }

    return n + 1;
}

// Optimized Approach: Cyclic Sort
int optimizedApproach(int arr[], int n) {

    for (int i = 0; i < n; i++) {

        while (arr[i] >= 1 && arr[i] <= n &&
               arr[arr[i] - 1] != arr[i]) {

            int temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }

    return n + 1;
}

int main() {

    int arr1[] = {3, 4, -1, 1};
    int arr2[] = {3, 4, -1, 1};

    int n = 4;

    printf("Original Array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);

    printf("\nFirst Missing Positive (Brute Force): %d",
           bruteForce(arr1, n));

    printf("\nFirst Missing Positive (Optimized): %d\n",
           optimizedApproach(arr2, n));

    return 0;
}
