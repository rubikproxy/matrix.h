#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

typedef struct {
    size_t rows;
    size_t cols;
    double *data;
} Matrix;

// Basic operations
Matrix *create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix *matrix);
void print_matrix(const Matrix *matrix);
Matrix *matrix_add(const Matrix *a, const Matrix *b);
Matrix *matrix_sub(const Matrix *a, const Matrix *b);
Matrix *matrix_mul(const Matrix *a, const Matrix *b);
Matrix *matrix_transpose(const Matrix *matrix);
Matrix *matrix_inverse(const Matrix *matrix);
double matrix_determinant(const Matrix *matrix);

// Advanced operations
Matrix *matrix_multiply(const Matrix *a, const Matrix *b);
Matrix *matrix_identity(size_t size);
double matrix_norm(const Matrix *matrix);
void matrix_eigenvalues(const Matrix *matrix, double *real, double *imag);

// Error handling
const char *matrix_error_message(void);

#endif // MATRIX_H
