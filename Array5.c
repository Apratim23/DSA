#include <stdio.h>

struct Element {
    int row, col, value;
};

void read(struct Element mat[], int *num)//read the sparse matrix
 {
    printf("Enter the number of non-zero elements: ");
    scanf("%d", num);//read the number of non-zero elements

    printf("Enter the elements (row, column, value):\n");
    for (int i = 0; i < *num; i++)//read the elements
    {
        scanf("%d %d %d", &mat[i].row, &mat[i].col, &mat[i].value);
    }
}

int main() {
    struct Element m1[100], m2[100], result[200];//declare two sparse matrices and a resultant sparse matrix
    int num1, num2, r = 0;

    printf("Enter the first matrix:\n");
    read(m1, &num1);

    printf("Enter the second matrix:\n");
    read(m2, &num2);

    for (int i = 0, j = 0; i < num1 || j < num2;)//add the two matrices 
    {
        if (i < num1 && (j >= num2 || (m1[i].row < m2[j].row) || (m1[i].row == m2[j].row && m1[i].col < m2[j].col)))//if the row and column of the first matrix is less than that of the second matrix
         {
            result[r++] = m1[i++];//add the element of the first matrix to the resultant matrix
        } else if (j < num2 && (i >= num1 || (m2[j].row < m1[i].row) || (m2[j].row == m1[i].row && m2[j].col < m1[i].col)))//if the row and column of the second matrix is less than that of the first matrix 
        {
            result[r++] = m2[j++];//add the element of the second matrix to the resultant matrix
        } else {
          result[r].row = m1[i].row;//if the row and column of the first matrix is equal to that of the second matrix
            result[r].col = m1[i].col;//add the sum of the values of the two matrices to the resultant matrix
            result[r].value = m1[i].value + m2[j].value;//increment the row, column and resultant matrix indices
            r++, i++, j++;//increment the row, column and resultant matrix indices
        }
    }

    printf("Resultant Sparse Matrix (Sum of two matrices):\n");
    for (int i = 0; i < r; i++) {
        printf("%d %d %d\n", result[i].row, result[i].col, result[i].value);//print the resultant sparse matrix
    }

    return 0;
}
