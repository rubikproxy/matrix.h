#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix *a = create_matrix(2, 2);
    Matrix *b = create_matrix(2, 2);
    
    // Initialize matrices
    a->data[0] = 1.0; a->data[1] = 2.0; a->data[2] = 3.0; a->data[3] = 4.0;
    b->data[0] = 5.0; b->data[1] = 6.0; b->data[2] = 7.0; b->data[3] = 8.0;
    
    Matrix *c = matrix_add(a, b);
    print_matrix(c);
    
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);
    
    return 0;
}
