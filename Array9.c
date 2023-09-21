#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list representing a term in a polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to insert a term into a polynomial linked list
void insertTerm(struct Node** head, int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to add two polynomial equations represented as linked lists
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        struct Node* newTerm = (struct Node*)malloc(sizeof(struct Node));
        newTerm->next = NULL;

        if (poly1 == NULL || (poly2 != NULL && poly1->exponent < poly2->exponent)) {
            newTerm->coefficient = poly2->coefficient;
            newTerm->exponent = poly2->exponent;
            poly2 = poly2->next;
        } else if (poly2 == NULL || (poly1 != NULL && poly1->exponent > poly2->exponent)) {
            newTerm->coefficient = poly1->coefficient;
            newTerm->exponent = poly1->exponent;
            poly1 = poly1->next;
        } else {
            newTerm->coefficient = poly1->coefficient + poly2->coefficient;
            newTerm->exponent = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (result == NULL) {
            result = newTerm;
        } else {
            struct Node* current = result;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newTerm;
        }
    }
    return result;
}

// Function to display a polynomial equation
void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }

    while (poly != NULL) {
        printf("%d", poly->coefficient);
        if (poly->exponent != 0) {
            printf("x^%d", poly->exponent);
        }
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Insert terms into the first polynomial
    insertTerm(&poly1, 3, 2); // 3x^2
    insertTerm(&poly1, 4, 1); // 4x

    // Insert terms into the second polynomial
    insertTerm(&poly2, 2, 2); // 2x^2
    insertTerm(&poly2, 1, 0); // 1

    // Display the first polynomial
    printf("First Polynomial: ");
    displayPolynomial(poly1);

    // Display the second polynomial
    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    // Display the result polynomial
    printf("Result Polynomial: ");
    displayPolynomial(result);

    // Free memory
    while (poly1 != NULL) {
        struct Node* temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }

    while (poly2 != NULL) {
        struct Node* temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }

    while (result != NULL) {
        struct Node* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
