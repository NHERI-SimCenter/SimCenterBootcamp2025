#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 100;  // Matrix size
    const char* filename = "matrix.bin";

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Allocate memory for n x n matrix
    double* matrix = malloc(n * n * sizeof(double));
    if (matrix == NULL) {
        perror("malloc failed");
        return 1;
    }

    // Fill matrix with random doubles in [0.0, 1.0)
    for (int i = 0; i < n; i++) {         // row
        for (int j = 0; j < n; j++) {     // column
            matrix[i * n + j] = rand() / (double)RAND_MAX;
        }
    }

    // Open file for binary writing
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen failed");
        free(matrix);
        return 1;
    }

    // Write matrix size
    fwrite(&n, sizeof(int), 1, fp);

    // Write matrix in column-major order
    for (int j = 0; j < n; j++) {         // column
        for (int i = 0; i < n; i++) {     // row
            double value = matrix[i * n + j];
            fwrite(&value, sizeof(double), 1, fp);
        }
    }

    fclose(fp);
    free(matrix);

    printf("Random matrix saved to %s in column-major order.\n", filename);
    return 0;
}
