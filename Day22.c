#include <stdio.h>

void normalApproach(int arr[], int n) {
    int temp[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[j++] = arr[i];
        }
    }

    while (j < n) {
        temp[j++] = 0;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

void optimalApproach(int arr[], int n) {
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {0, 1, 0, 3, 12};
    int arr2[] = {0, 1, 0, 3, 12};

    int n = 5;

    printf("Original Array: ");
    display(arr1, n);

    normalApproach(arr1, n);
    printf("Normal Approach: ");
    display(arr1, n);

    optimalApproach(arr2, n);
    printf("Optimal Approach: ");
    display(arr2, n);

    return 0;
}
