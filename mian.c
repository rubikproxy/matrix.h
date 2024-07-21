#include <stdio.h>
#include <matrix.h>

int main() {
    // Create matrices
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

    // Clean up
    free_matrix(a);
    free_matrix(b);
    free_matrix(result_add);
    free_matrix(result_mul);

    return 0;
}
