```c
#include <stdio.h>

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Method 1: Using Sorting
int kthLargestSorting(int arr[], int n, int k) {
    sortArray(arr, n);
    return arr[n - k];
}

// Method 2: Without Sorting (Repeated Maximum)
int kthLargestWithoutSorting(int arr[], int n, int k) {
    int max, index;

    for (int i = 0; i < k; i++) {
        max = arr[0];
        index = 0;

        for (int j = 1; j < n; j++) {
            if (arr[j] > max) {
                max = arr[j];
                index = j;
            }
        }

        arr[index] = -999999;
    }

    return max;
}

// Method 3: Optimal Approach (Quickselect)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k)
            return arr[pivotIndex];

        if (pivotIndex > k)
            return quickSelect(arr, low, pivotIndex - 1, k);

        return quickSelect(arr, pivotIndex + 1, high, k);
    }

    return -1;
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = 6, k = 2;

    int a[6] = {3, 2, 1, 5, 6, 4};
    int b[6] = {3, 2, 1, 5, 6, 4};
    int c[6] = {3, 2, 1, 5, 6, 4};

    if (k < 1 || k > n) {
        printf("Invalid value of k\n");
        return 0;
    }

    printf("Kth largest using sorting: %d\n",
           kthLargestSorting(a, n, k));

    printf("Kth largest without sorting: %d\n",
           kthLargestWithoutSorting(b, n, k));

    printf("Kth largest using Quickselect: %d\n",
           quickSelect(c, 0, n - 1, n - k));

    return 0;
}
```
