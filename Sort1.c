
#include <stdio.h>
void insertionSortAsc(int arr[], int n)//function to sort the array in ascending order
{
    int i, t, j;//declaring variables
    for (i = 1; i < n; i++)
    {
        t = arr[i];//assigning the value of the array to the variable t
        j = i - 1;//assigning the value of the array to the variable j
        while (j >= 0 && arr[j] > t)//while loop to check if the value of j is greater than or equal to 0 and the value of the array is greater than the value of t
        {
            arr[j + 1] = arr[j];//assigning the value of the array to the value of the array plus 1
            j = j - 1;//assigning the value of j to the value of j minus 1
        }
        arr[j + 1] = t;//assigning the value of the array to the value of t plus 1
    }
}
void insertionSortDesc(int arr[], int n)
{
    int i, t, j;
    for (i = 1; i < n; i++)
    {
        t = arr[i];//assigning the value of the array to the variable t
        j = i - 1;

        while (j >= 0 && arr[j] < t)//while loop to check if the value of j is greater than or equal to 0 and the value of the array is less than the value of t
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = t;
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Original array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    insertionSortAsc(arr, n);
    printf("\nArray sorted in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    insertionSortDesc(arr, n);
    printf("\nArray sorted in descending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
