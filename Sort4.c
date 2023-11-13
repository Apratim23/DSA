
#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;//size of left array
    int n2 = r - m;//size of right array

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];//copy left array
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];//copy right array

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)//merge left and right array
    {
        if (L[i] <= R[j])//if left array element is less than right array element
        {
            arr[k] = L[i];//copy left array element
            i++;
        }
        else
        {
            arr[k] = R[j];//copy right array element
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];//copy remaining left array element
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];//copy remaining right array element
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)//if left index is less than right index
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array is \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
