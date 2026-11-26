#include <stdio.h>

void bucketSort(int arr[], int n) {
    int bucket[10][100];
    int count[10] = {0};

    // Initialize buckets
    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;

        if (index > 9)
            index = 9;

        bucket[index][count[index]++] = arr[i];
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < count[i]; j++) {
            int key = bucket[i][j];
            int k = j - 1;

            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }

            bucket[i][k + 1] = key;
        }
    }

    // Merge buckets into original array
    int index = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

int main() {
    int arr[] = {42, 23, 4, 16, 8, 15, 9, 31};
    int n = 8;

    printf("Original Array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted Array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
