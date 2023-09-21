#include <stdio.h>

// Structure to represent a sparse matrix element
struct Element
 {
    int row, col, value;
};

// Function to read a sparse matrix in 3-tuple format
void read(struct Element mat[], int *m, int *n, int *nz)
{
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", m, n);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", nz);

    printf("Enter the elements (row, column, value):\n");
    for (int i = 0; i < *nz; i++)//read the elements
    {
        scanf("%d %d %d", &mat[i].row, &mat[i].col, &mat[i].value);
    }
}
// Function to perform the transpose of a sparse matrix
void transpose(struct Element mat[], struct Element t[], int m, int n, int nz) {
    // Initialize the transposeMatrix
    for (int i = 0; i < nz; i++) {
        t[i].row = mat[i].col;//row and col are swapped
        t[i].col = mat[i].row;//row and col are swapped
        t[i].value = mat[i].value;//value remains same
    }
}

// Function to display a sparse matrix in 3-tuple format
void display(struct Element matrix[], int nz) {
    printf("Sparse Matrix (row, column, value):\n");
    for (int i = 0; i < nz; i++) {
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);//print the elements
    }
}

int main() {
    struct Element matrix[100], t[100];//declare two sparse matrices
    int m, n, nz;//declare the number of rows, columns and non-zero elements

    read(matrix, &m, &n, &nz);//read the sparse matrix
    printf("\nOriginal Sparse Matrix:\n");//print the original sparse matrix
    display(matrix, nz);//display the original sparse matrix

    transpose(matrix, t, m, n, nz);//transpose the sparse matrix
    printf("\nTransposed Sparse Matrix:\n");
    display(t, nz);//display the transposed sparse matrix

    return 0;
}