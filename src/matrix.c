#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

// Basic operations
Matrix *create_matrix(size_t rows, size_t cols) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double *)malloc(rows * cols * sizeof(double));
    return matrix;
}

void free_matrix(Matrix *matrix) {
    free(matrix->data);
    free(matrix);
}

void print_matrix(const Matrix *matrix) {
    for (size_t i = 0; i < matrix->rows; i++) {
        for (size_t j = 0; j < matrix->cols; j++) {
            printf("%f ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

Matrix *matrix_add(const Matrix *a, const Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) return NULL;
    Matrix *result = create_matrix(a->rows, a->cols);
    for (size_t i = 0; i < a->rows * a->cols; i++) {
        result->data[i] = a->data[i] + b->data[i];
    }
    return result;
}

Matrix *matrix_sub(const Matrix *a, const Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) return NULL;
    Matrix *result = create_matrix(a->rows, a->cols);
    for (size_t i = 0; i < a->rows * a->cols; i++) {
        result->data[i] = a->data[i] - b->data[i];
    }
    return result;
}

Matrix *matrix_mul(const Matrix *a, const Matrix *b) {
    if (a->cols != b->rows) return NULL;
    Matrix *result = create_matrix(a->rows, b->cols);
    for (size_t i = 0; i < a->rows; i++) {
        for (size_t j = 0; j < b->cols; j++) {
            result->data[i * b->cols + j] = 0;
            for (size_t k = 0; k < a->cols; k++) {
                result->data[i * b->cols + j] += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
        }
    }
    return result;
}

Matrix *matrix_transpose(const Matrix *matrix) {
    Matrix *result = create_matrix(matrix->cols, matrix->rows);
    for (size_t i = 0; i < matrix->rows; i++) {
        for (size_t j = 0; j < matrix->cols; j++) {
            result->data[j * matrix->rows + i] = matrix->data[i * matrix->cols + j];
        }
    }
    return result;
}

// Determinant (assuming square matrix)
double matrix_determinant(const Matrix *matrix) {
    if (matrix->rows != matrix->cols) return 0; // Not a square matrix
    // Implement determinant calculation (e.g., using LU decomposition)
    return 0; // Placeholder
}

// Identity matrix
Matrix *matrix_identity(size_t size) {
    Matrix *matrix = create_matrix(size, size);
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            matrix->data[i * size + j] = (i == j) ? 1.0 : 0.0;
        }
    }
    return matrix;
}

// Matrix norm
double matrix_norm(const Matrix *matrix) {
    double norm = 0;
    for (size_t i = 0; i < matrix->rows * matrix->cols; i++) {
        norm += matrix->data[i] * matrix->data[i];
    }
    return sqrt(norm);
}

// Eigenvalues (simple example for demonstration)
void matrix_eigenvalues(const Matrix *matrix, double *real, double *imag) {
    // Placeholder for eigenvalue calculation
    for (size_t i = 0; i < matrix->rows; i++) {
        real[i] = 0; // Example real part
        imag[i] = 0; // Example imaginary part
    }
}

// Error handling
const char *matrix_error_message(void) {
    return "No error";
}

int main() {
    // Example usage
    Matrix *a = create_matrix(2, 2);
    Matrix *b = create_matrix(2, 2);

    // Initialize matrices
    a->data[0] = 1; a->data[1] = 2;
    a->data[2] = 3; a->data[3] = 4;

    b->data[0] = 5; b->data[1] = 6;
    b->data[2] = 7; b->data[3] = 8;

    // Matrix addition
    Matrix *result_add = matrix_add(a, b);
    printf("Matrix Addition:\n");
    print_matrix(result_add);

    // Matrix multiplication
    Matrix *result_mul = matrix_mul(a, b);
    printf("Matrix Multiplication:\n");
    print_matrix(result_mul);

    // Matrix transposition
    Matrix *result_transpose = matrix_transpose(a);
    printf("Matrix Transposition:\n");
    print_matrix(result_transpose);

    // Matrix inversion (only if square matrix and invertible)
    Matrix *result_inverse = matrix_inverse(a);
    if (result_inverse) {
        printf("Matrix Inversion:\n");
        print_matrix(result_inverse);
        free_matrix(result_inverse);
    } else {
        printf("Matrix Inversion: Matrix is not invertible\n");
    }

    // Matrix determinant (only if square matrix)
    double det = matrix_determinant(a);
    printf("Matrix Determinant: %f\n", det);

    // Clean up
    free_matrix(a);
    free_matrix(b);
    free_matrix(result_add);
    free_matrix(result_mul);
    free_matrix(result_transpose);

    return 0;
}
