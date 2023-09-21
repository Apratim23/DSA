#include <stdio.h>
// Function to insert an element at a specific position in the array
void insert(int arr[], int *size, int element, int pos) {
    if (pos < 0 || pos > *size) {
        printf("Invalid position for insertion.\n");
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];//storing the value of the previous element in the next element
    }
    arr[pos] = element;//inserting the element at the given position
    (*size)++;//increasing the size of the array
    printf("Element inserted.\n");
}
// Function to delete an element from a specific position in the array
void delete(int arr[], int *size, int position) {
    if (position < 0 || position >= *size)//checking if the position is valid 
    {
        printf("Invalid position for deletion.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];//storing the value of the next element in the previous element
    }
    (*size)--;//decreasing the size of the array
    printf("Element deleted.\n");
}
// Function for linear search in the array
int linear(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element)//checking if the element is present in the array
         {
            return i; // Return the index where the element is found
        }
    }
    return -1; // Return -1 if element is not found
}
// Function to traverse and print the array
void traverse(int arr[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter size n: ");//
    scanf("%d", &n);
    int arr[100];
    int size = n;//initializing the size of the array
    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int c;
    do
    {
        printf("\n***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &c);
        switch (c) {
            case 1:     // Insert
                {
                    int element, position;
                    printf("Element to insert: ");
                    scanf("%d", &element);
                    printf("Enter Position: ");
                    scanf("%d", &position);
                    insert(arr, &size, element, position);
                }
                break;
            case 2:     // Delete
                {
                    int position;
                    printf("Enter Position: ");
                    scanf("%d", &position);
                    delete(arr, &size, position);
                }
                break;
            case 3:     // Linear Search
                {
                    int element;
                    printf("Element to search: ");
                    scanf("%d", &element);
                    int index = linear(arr, size, element);
                    if (index != -1) {
                        printf("Element found at index %d\n", index);
                    } else {
                        printf("Element not found\n");
                    }
                }
                break;
            case 4:     // Traverse
                traverse(arr, size);
                break;
            case 5:     // Exit
                printf("Exiting program.\n");
                break;
            default:        // Invalid option
                printf("Invalid option! Please select a valid option.\n");
        }
    } while (c != 5);//looping until the user exits

    return 0;
}
