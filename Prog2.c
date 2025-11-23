#include <stdio.h>

int main() {
    int a[10][10], b[10][10], sum[10][10], sub[10][10], mul[10][10], transpose[10][10];
    int i, j, k, r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);
    if (r1 == r2 && c1 == c2) {

        for (i = 0; i < r1; i++)
            for (j = 0; j < c1; j++)
                sum[i][j] = a[i][j] + b[i][j];

        for (i = 0; i < r1; i++)
            for (j = 0; j < c1; j++)
                sub[i][j] = a[i][j] - b[i][j];
    }

    if (c1 == r2) {
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c2; j++) {
                mul[i][j] = 0;
                for (k = 0; k < c1; k++)
                    mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (i = 0; i < c1; i++)
        for (j = 0; j < r1; j++)
            transpose[i][j] = a[j][i];

    printf("\nMatrix A:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }

    if (r1 == r2 && c1 == c2) {
        printf("\nSum of Matrices:\n");
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++)
                printf("%d ", sum[i][j]);
            printf("\n");
        }

        printf("\nSubtraction of Matrices (A - B):\n");
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++)
                printf("%d ", sub[i][j]);
            printf("\n");
        }
    } else {
        printf("\nSum and Subtraction NOT possible (Dimension mismatch)\n");
    }

    if (c1 == r2) {
        printf("\nProduct of Matrices:\n");
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c2; j++)
                printf("%d ", mul[i][j]);
            printf("\n");
        }
    } else {
        printf("\nMultiplication NOT possible (c1 != r2)\n");
    }

    printf("\nTranspose of Matrix A:\n");
    for (i = 0; i < c1; i++) {
        for (j = 0; j < r1; j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }

    return 0;
}
