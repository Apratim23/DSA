#include <stdio.h>
// Function to represent a sparse matrix in 3-tuple format
void sparse(int matrix[][100], int rows, int cols) {
    int sp[100][3]; // 3-tuple format array
    int k = 0; // Counter for non-zero elements in 3-tuple format
    // Store the size of the sparse matrix
    sp[k][0] = rows;// Store the size of the sparse matrix
    sp[k][1] = cols;// Store the size of the sparse matrix
    // Iterate through the matrix and add non-zero elements to the 3-tuple
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                k++;// Increment the counter
                sp[k][0] = i;// Store the row index
                sp[k][1] = j;// Store the column index
                sp[k][2] = matrix[i][j];// Store the value
            }
        }
    }
    // Print the sparse matrix in 3-tuple format
    printf("Sparse matrix in 3-tuple format:\n");
    printf("%d %d %d\n", rows, cols, k);
    for (int i = 0; i <= k; i++)
    {
        printf("%d %d %d\n", sp[i][0], sp[i][1], sp[i][2]);
    }
}
int main() {
    int rows, cols;
    int matrix[100][100];
    // Input: Size of the sparse matrix
    printf("Enter size of the sparse matrix (rows columns): ");
    scanf("%d %d", &rows, &cols);
    printf("Enter elements of sparse matrix:\n");
    // Input: Elements of the sparse matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Call the function to convert and display the sparse matrix in 3-tuple format
    sparse(matrix, rows, cols);
    return 0;
}
