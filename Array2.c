#include <stdio.h>
// Function to input a square matrix of given size
void input(int s, int matrix[s][s])
 {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            scanf("%d", &matrix[i][j]); // Input each element
        }
    }
}
// Function to count the number of nonzero elements in the matrix
int count(int size, int matrix[size][size]) {
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 0)      // If element is nonzero
            {
                count++;
            }
        }
    }
    return count;
}
#include <stdio.h>
int display1(int n, int matrix[n][n])
{
    // Print the upper triangular matrix
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)// If element is in upper triangle excluding main diagonal
            {
                printf("%d\t", matrix[i][j]);
            } else
            {
                printf(" \t"); // Print a space to maintain the matrix structure
            }
        }
        printf("\n");
    }
    return 0;
}
// Function to display elements just above and below the main diagonal
void display2(int size, int matrix[size][size])
{
    printf("Elements just above and below the main diagonal:\n");
    for (int i = 0; i < size; i++)
     {
        for (int j = 0; j < size; j++)
         {
            if (j == i-1 || j == i + 1)     // If element is just above or below main diagonal
             {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  "); // Print two spaces for formatting
            }
        }
        printf("\n");
    }
}
int main()
 {
    int size;
    printf("Enter size of the square matrix: ");
    scanf("%d", &size);
    int matrix[size][size];
    input(size, matrix);// Input matrix
    printf("\nMatrix:\n");
    for (int i = 0; i < size; i++)
     {
        for (int j = 0; j < size; j++)
         {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    int nonzeroCount = count(size, matrix);     // Count nonzero elements
    printf("\nNonzero elements: %d\n", nonzeroCount);       // Display count
    display1(size, matrix);     // Display upper triangular matrix
    display2(size, matrix);     // Display elements above and below main diagonal
    return 0;
}