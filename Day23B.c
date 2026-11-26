#include <stdio.h>

int main() {
    int arr[] = {3, 1, 2, 4};
    int n = 4;

    int left = 0, right = n - 1;

    while (left < right) {

        if (arr[left] % 2 == 0) {
            left++;
        }
        else if (arr[right] % 2 != 0) {
            right--;
        }
        else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }

    printf("Array after rearrangement: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
