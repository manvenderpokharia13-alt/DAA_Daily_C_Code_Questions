#include <stdio.h>
#include <string.h>

// Normal Approach: Brute Force
void bruteForce(char s[], char p[]) {
    int n = strlen(s);
    int m = strlen(p);

    int found = 0;

    printf("Brute Force Indices: ");

    if (m > n) {
        printf("None\n");
        return;
    }

    for (int i = 0; i <= n - m; i++) {
        int count[26] = {0};
        int match[26] = {0};

        for (int j = 0; j < m; j++) {
            count[s[i + j] - 'a']++;
            match[p[j] - 'a']++;
        }

        int flag = 1;

        for (int j = 0; j < 26; j++) {
            if (count[j] != match[j]) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("None");

    printf("\n");
}

// Optimized Approach: Sliding Window
void optimizedApproach(char s[], char p[]) {
    int n = strlen(s);
    int m = strlen(p);

    int count[26] = {0};
    int match[26] = {0};

    int found = 0;

    printf("Optimized Indices: ");

    if (m > n) {
        printf("None\n");
        return;
    }

    // Count characters in pattern
    for (int i = 0; i < m; i++) {
        match[p[i] - 'a']++;
        count[s[i] - 'a']++;
    }

    // Check first window
    for (int i = 0; i < 26; i++) {
        if (count[i] != match[i])
            break;

        if (i == 25) {
            printf("0 ");
            found = 1;
        }
    }

    // Slide window
    for (int i = m; i < n; i++) {

        count[s[i - m] - 'a']--;
        count[s[i] - 'a']++;

        int flag = 1;

        for (int j = 0; j < 26; j++) {
            if (count[j] != match[j]) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            printf("%d ", i - m + 1);
            found = 1;
        }
    }

    if (!found)
        printf("None");

    printf("\n");
}

int main() {
    char s[1000], p[1000];

    printf("Enter main string: ");
    scanf("%999s", s);

    printf("Enter pattern string: ");
    scanf("%999s", p);

    bruteForce(s, p);

    optimizedApproach(s, p);

    return 0;
}
