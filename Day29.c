#include <stdio.h>
#include <string.h>

// Check palindrome
int isPalindrome(char str[], int left, int right) {
    while (left < right) {
        if (str[left] != str[right])
            return 0;

        left++;
        right--;
    }

    return 1;
}

// Normal approach: Brute Force
void bruteForce(char str[]) {
    int n = strlen(str);
    int maxLength = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            if (isPalindrome(str, i, j)) {
                if (j - i + 1 > maxLength) {
                    maxLength = j - i + 1;
                    start = i;
                }
            }
        }
    }

    printf("Brute Force: ");
    for (int i = start; i < start + maxLength; i++)
        printf("%c", str[i]);

    printf("\nLength: %d\n", maxLength);
}

// Optimal approach: Expand Around Center
void expandCenter(char str[], int n,
                  int left, int right,
                  int *start, int *maxLength) {

    while (left >= 0 && right < n &&
           str[left] == str[right]) {

        if (right - left + 1 > *maxLength) {
            *start = left;
            *maxLength = right - left + 1;
        }

        left--;
        right++;
    }
}

void optimalApproach(char str[]) {
    int n = strlen(str);
    int start = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {

        // Odd length palindrome
        expandCenter(str, n, i, i,
                     &start, &maxLength);

        // Even length palindrome
        expandCenter(str, n, i, i + 1,
                     &start, &maxLength);
    }

    printf("Optimal Approach: ");

    for (int i = start; i < start + maxLength; i++)
        printf("%c", str[i]);

    printf("\nLength: %d\n", maxLength);
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    bruteForce(str);
    optimalApproach(str);

    return 0;
}
