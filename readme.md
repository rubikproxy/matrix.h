```markdown
# Matrix Library

`matrix.h` is a C library for advanced matrix calculations. It provides various functions to perform operations such as matrix addition, subtraction, multiplication, transposition, inversion, and more. This library is suitable for numerical computing and scientific applications.

## Features

- Matrix Creation and Deallocation
- Basic Operations: Addition, Subtraction, Multiplication
- Advanced Operations: Transposition, Inversion, Determinant Calculation
- Matrix Norm Calculation
- Eigenvalue Computation (Placeholder)
- Identity Matrix Creation

## Installation

### Linux

1. **Clone the Repository**

   ```sh
   git clone https://github.com/rubikproxy/matrix.h
   cd matrix.h
   ```

2. **Build and Install the Library**

   Run the following script to build and install the library:

   ```sh
   chmod +x install_matrix_lib.sh
   ./install_matrix_lib.sh
   ```

   This script will:
   - Clean up previous builds
   - Compile the source code
   - Create a static library
   - Install the library and header files
   - Update the library cache

3. **Verify the Installation**

   Ensure that the library files are installed:

   ```sh
   ls /usr/local/lib/libmatrix.a
   ls /usr/local/include/matrix.h
   ```

### macOS

1. **Clone the Repository**

   ```sh
   git clone https://github.com/rubikproxy/matrix.h
   cd matrix.h
   ```

2. **Build the Library**

   ```sh
   make
   ```

3. **Install the Library**

   ```sh
   sudo cp libmatrix.a /usr/local/lib/
   sudo cp include/matrix.h /usr/local/include/
   sudo ranlib /usr/local/lib/libmatrix.a
   ```

4. **Verify the Installation**

   Check if the library files are correctly installed:

   ```sh
   ls /usr/local/lib/libmatrix.a
   ls /usr/local/include/matrix.h
   ```

### Windows

1. **Clone the Repository**

   ```sh
   git clone https://github.com/rubikproxy/matrix.h
   cd matrix.h
   ```

2. **Build the Library**

   Use the MinGW or MSVC compiler to build the library:

   ```sh
   gcc -Iinclude -Wall -Wextra -c src/matrix.c -o src/matrix.o
   ar rcs libmatrix.a src/matrix.o
   ```

3. **Install the Library**

   Copy the files to appropriate directories. You can manually set up directories such as `C:\Program Files\MatrixLib`:

   ```sh
   mkdir "C:\Program Files\MatrixLib"
   copy libmatrix.a "C:\Program Files\MatrixLib"
   copy include\matrix.h "C:\Program Files\MatrixLib"
   ```

4. **Set Environment Variables**

   Add the library path to your environment variables:

   ```sh
   setx LIBRARY_PATH "C:\Program Files\MatrixLib"
   ```

5. **Verify the Installation**

   Check if the files are in the installed directory:

   ```sh
   dir "C:\Program Files\MatrixLib"
   ```

## Usage

### Example Code

Here’s an example demonstrating how to use the library:

1. **Create a Source File**

   Create a file named `main.c` with the following content:

   ```c
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
   ```

2. **Compile the Example**

   - **Linux/macOS**:

     ```sh
     gcc main.c -L/usr/local/lib -lmatrix -o main -lm
     ```

   - **Windows**:

     ```sh
     gcc main.c -o main -L"C:\Program Files\MatrixLib" -lmatrix
     ```

3. **Run the Example**

   - **Linux/macOS**:

     ```sh
     ./main
     ```

   - **Windows**:

     ```sh
     main.exe
     ```

### Example Output

The output of the example program might look like this:

```
Matrix Addition:
6.000000 8.000000 
10.000000 12.000000 
Matrix Multiplication:
19.000000 22.000000 
43.000000 50.000000 
```

## Function Documentation

### `Matrix *create_matrix(size_t rows, size_t cols)`

Allocates memory for a matrix with the specified number of rows and columns.

### `void free_matrix(Matrix *matrix)`

Frees the memory allocated for the matrix.

### `void print_matrix(const Matrix *matrix)`

Prints the matrix to the standard output.

### `Matrix *matrix_add(const Matrix *a, const Matrix *b)`

Adds two matrices. The matrices must have the same dimensions.

### `Matrix *matrix_sub(const Matrix *a, const Matrix *b)`

Subtracts matrix `b` from matrix `a`. The matrices must have the same dimensions.

### `Matrix *matrix_mul(const Matrix *a, const Matrix *b)`

Multiplies two matrices. The number of columns in matrix `a` must equal the number of rows in matrix `b`.

### `Matrix *matrix_transpose(const Matrix *matrix)`

Transposes the matrix.

### `double matrix_determinant(const Matrix *matrix)`

Calculates the determinant of a square matrix.

### `Matrix *matrix_identity(size_t size)`

Creates an identity matrix of the given size.

### `double matrix_norm(const Matrix *matrix)`

Calculates the Frobenius norm of the matrix.

### `void matrix_eigenvalues(const Matrix *matrix, double *real, double *imag)`

Computes the eigenvalues of a square matrix. The real and imaginary parts are stored in the provided arrays.

## License

This library is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
```

### Changes Made
1. **Added Compilation Command**: Included the `gcc` command with `-L/usr/local/lib` and `-lmatrix` for Linux/macOS compilation.
2. **Updated Instructions**: Provided instructions for compiling and running the example code.

Feel free to adjust any details based on your specific setup or requirements!