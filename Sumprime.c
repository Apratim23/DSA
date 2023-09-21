#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Not prime
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }

    return 1; // Prime
}

// Function to calculate the sum of prime elements in an array
int sumOfPrimes(int *arr, int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        if (isPrime(arr[i])) {
            sum += arr[i];
        }
    }

    return sum;
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Error
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int result = sumOfPrimes(arr, n);
    printf("Sum = %d\n", result);

    // Deallocate the memory
    free(arr);

    return 0;
}
