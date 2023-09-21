#include <stdio.h>
#include <math.h>

#define N 5

// Function to print a matrix
void print_matrix(double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Perform Gaussian elimination with partial pivoting
void gaussian_elimination(double matrix[N][2*N]) {
    for (int i = 0; i < N; i++) {
        // Pivoting
        int max_row = i;
        for (int j = i + 1; j < N; j++) {
            if (fabs(matrix[j][i]) > fabs(matrix[max_row][i])) {
                max_row = j;
            }
        }
        // Swap rows
        for (int j = 0; j < 2*N; j++) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[max_row][j];
            matrix[max_row][j] = temp;
        }
        // Elimination
        for (int j = i + 1; j < N; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < 2*N; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

// Perform back substitution to get the inverse
void back_substitution(double matrix[N][2*N]) {
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < 2*N; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

int main() {
    double matrix[N][N] = {
        {2, 1, 3, 2, 1},
        {1, 2, 1, 1, 3},
        {3, 1, 3, 2, 2},
        {2, 1, 2, 1, 2},
        {1, 3, 2, 2, 2}
    };

    double augmented_matrix[N][2*N];

    // Augment the matrix with an identity matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            augmented_matrix[i][j] = matrix[i][j];
            augmented_matrix[i][j+N] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Apply Gaussian elimination
    gaussian_elimination(augmented_matrix);

    // Apply back substitution
    back_substitution(augmented_matrix);

    // Normalize the rows of the inverse matrix
    for (int i = 0; i < N; i++) {
        double divisor = augmented_matrix[i][i];
        for (int j = 0; j < N*2; j++) {
            augmented_matrix[i][j] /= divisor;
        }
    }

    // Extract the inverse matrix
    double inverse_matrix[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inverse_matrix[i][j] = augmented_matrix[i][j+N];
        }
    }

    printf("Original Matrix:\n");
    print_matrix(matrix);
    printf("Inverse Matrix:\n");
    print_matrix(inverse_matrix);

    return 0;
}
