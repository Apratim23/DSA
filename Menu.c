#include <stdio.h>

struct Complex {
    float real;//storing the real part of the number
    float i;//storing the imaginary part of the number
};

// Function to add two complex numbers (call by value)
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.i = num1.i + num2.i;
    return result;
}

// Function to multiply two complex numbers (call by address)
void multiplyComplex(struct Complex num1, struct Complex num2, struct Complex *result) {
    result->real = (num1.real * num2.real) - (num1.i * num2.i);
    result->i = (num1.real * num2.i) + (num1.i * num2.real);
}

int main() {
    struct Complex num1, num2, result;
    int choice;

    printf("Enter complex number 1: ");
    scanf("%f %f", &num1.real, &num1.i);

    printf("Enter complex number 2: ");
    scanf("%f %f", &num2.real, &num2.i);

    do {
        printf("\nMENU\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = addComplex(num1, num2);
                printf("Sum = %.2f + %.2fi\n", result.real, result.i);
                break;
            case 2:
                multiplyComplex(num1, num2, &result);
                printf("Product = %.2f + %.2fi\n", result.real, result.i);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
