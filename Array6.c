#include <stdio.h>
#include <math.h>

// Function to read a polynomial equation
void read(int poly[], int *degree)//read the polynomial equation
{
    printf("Enter the degree of the polynomial: ");
    scanf("%d", degree);//read the degree of the polynomial equation

    printf("Enter the coefficients from highest degree to lowest degree:\n");
    for (int i = *degree; i >= 0; i--)//read the coefficients
    {
        scanf("%d", &poly[i]);//read the coefficients
    }
}

// Function to add two polynomial equations
void add(int poly1[], int poly2[], int result[], int d1, int d2) {
    int maxDegree = (d1 > d2) ? d1 : d2;//find the maximum degree

    for (int i = 0; i <= maxDegree; i++)//add the coefficients
    {
        result[i] = poly1[i] + poly2[i];//add the coefficients
    }
}

// Function to display a polynomial equation
void display(int poly[], int degree)
{
    for (int i = degree; i >= 0; i--)
    {
        if (i == degree)//if the degree is equal to the maximum degree
        {
            printf("%dx^%d ", poly[i], i);
        }
         else if (i == 0)//if the degree is equal to 0
         {
            printf("+ %d", poly[i]);
        } else//if the degree is not equal to 0 or the maximum degree
        {
            printf("+ %dx^%d ", poly[i], i);
        }
    }
    printf("\n");
}

int main()//main function
{
    int poly1[100], poly2[100], result[100];
    int degree1, degree2;

    printf("Enter the first polynomial equation:\n");
    read(poly1, &degree1);//read the first polynomial equation

    printf("\nEnter the second polynomial equation:\n");
    read(poly2, &degree2);//read the second polynomial equation

    // Display the entered polynomials
    printf("\nPolynomial 1: ");
    display(poly1, degree1);//display the first polynomial equation
    printf("Polynomial 2: ");
    display(poly2, degree2);//display the second polynomial equation

    // Add the polynomials and display the result
    add(poly1, poly2, result, degree1, degree2);//add the two polynomials
    printf("\nResultant Polynomial (Sum of two polynomials): ");
    display(result, (degree1 > degree2) ? degree1 : degree2);//display the resultant polynomial equation

    return 0;
}
