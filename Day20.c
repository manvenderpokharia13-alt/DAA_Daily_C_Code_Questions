#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int last[256];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int n = strlen(str);

    if (n > 0 && str[n - 1] == '\n')
        str[--n] = '\0';

    for (int i = 0; i < 256; i++)
        last[i] = -1;

    int start = 0, maxLength = 0;
    int bestStart = 0;

    for (int i = 0; i < n; i++) {

        if (last[(unsigned char)str[i]] >= start)
            start = last[(unsigned char)str[i]] + 1;

        last[(unsigned char)str[i]] = i;

        if (i - start + 1 > maxLength) {
            maxLength = i - start + 1;
            bestStart = start;
        }
    }

    printf("Longest substring: ");
    for (int i = bestStart; i < bestStart + maxLength; i++)
        printf("%c", str[i]);

    printf("\nLength: %d\n", maxLength);

    return 0;
}
