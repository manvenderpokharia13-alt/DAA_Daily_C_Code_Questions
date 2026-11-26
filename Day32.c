#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a > *(int *)b) -
           (*(int *)a < *(int *)b);
}

// Normal Approach: Brute Force
void bruteForce(int arr[], int n) {
    int found = 0;

    qsort(arr, n, sizeof(int), compare);

    printf("\nBrute Force Triplets:\n");

    for (int i = 0; i < n - 2; i++) {

        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int j = i + 1; j < n - 1; j++) {

            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            for (int k = j + 1; k < n; k++) {

                if (k > j + 1 && arr[k] == arr[k - 1])
                    continue;

                if (arr[i] + arr[j] + arr[k] == 0) {
                    printf("%d %d %d\n",
                           arr[i], arr[j], arr[k]);
                    found = 1;
                }
            }
        }
    }

    if (!found)
        printf("No triplets found.\n");
}

// Optimized Approach: Two Pointers
void optimizedApproach(int arr[], int n) {
    int found = 0;

    qsort(arr, n, sizeof(int), compare);

    printf("\nOptimized Triplets:\n");

    for (int i = 0; i < n - 2; i++) {

        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0) {
                printf("%d %d %d\n",
                       arr[i], arr[left], arr[right]);

                found = 1;

                left++;
                right--;

                while (left < right &&
                       arr[left] == arr[left - 1])
                    left++;

                while (left < right &&
                       arr[right] == arr[right + 1])
                    right--;
            }

            else if (sum < 0) {
                left++;
            }

            else {
                right--;
            }
        }
    }

    if (!found)
        printf("No triplets found.\n");
}

int main() {
    int arr1[1000], arr2[1000];
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 3 || n > 1000) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }

    bruteForce(arr1, n);

    optimizedApproach(arr2, n);

    return 0;
}
