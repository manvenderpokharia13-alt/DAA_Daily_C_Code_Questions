#include <stdio.h>

int main() {
    int arr[] = {1, 1, 2, 3, 3, 3, 4};
    int n = 7, k = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[k - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }

    printf("Unique elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nK = %d", k);

    return 0;
}
