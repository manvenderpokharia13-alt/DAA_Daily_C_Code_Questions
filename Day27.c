#include <stdio.h>

int main() {
    int rows, cols;
    int parking[50][50];
    int found = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0 || rows > 50 || cols > 50) {
        printf("Invalid parking layout size.\n");
        return 0;
    }

    printf("Enter parking layout (0 = Empty, 1 = Occupied):\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &parking[i][j]);
        }
    }

    // Find first available parking space
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (parking[i][j] == 0) {
                parking[i][j] = 1;

                printf("\nCar parked successfully!\n");
                printf("Parking position: Row %d, Column %d\n",
                       i + 1, j + 1);

                found = 1;
                break;
            }
        }

        if (found)
            break;
    }

    if (!found) {
        printf("\nParking lot is full!\n");
    }

    // Display updated parking layout
    printf("\nUpdated Parking Layout:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", parking[i][j]);
        }
        printf("\n");
    }

    return 0;
}
