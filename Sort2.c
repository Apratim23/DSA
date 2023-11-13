
#include <stdio.h>

void selectionSort(int arr[], int n, int order) {
    int i, j, min_idx, max_idx, temp;
    
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        if (order == 1) { // ascending order
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        } else { // descending order
            temp = arr[i];
            arr[i] = arr[max_idx];
            arr[max_idx] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // sort in ascending order
    selectionSort(arr, n, 1);
    printf("Array sorted in ascending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // sort in descending order
    selectionSort(arr, n, 0);
    printf("Array sorted in descending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
