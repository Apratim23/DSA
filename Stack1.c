#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5

int stack[max]; // declaring the stack
int top = -1;        // initializing the top of the stack to -1

void push(int element) // function to push an element to the stack
{
    if (top == max - 1) // if the stack is full
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;                // increment the top of the stack
        stack[top] = element; // add the element to the stack
    }
}

void pop() // function to pop an element from the stack
{
    if (top == -1) // if there is no element in the stack
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top]);
        top--; // decrement the top of the stack
    }
}

void display() // function to display the elements of the stack
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int is_empty()
{                  // function to check if the stack is empty
    if (top == -1) // if there is no element in the stack
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full() // function to check if the stack is full
{
    if (top == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void reverse_string(char *str) // function to reverse a string using stack
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        push(str[i]); // push each character of the string to the stack
    }
    printf("Reversed string is: ");
    while (top != -1)
    {
        // pop each character from the stack to get the reversed string
        printf("%c", stack[top]);
        top--;
    }
    printf("\n");
}

int main()
{
    int choice, element; // storing the choice and the element to be pushed
    char str[max];  // declaring a character array to store the input string
    while (1)            // infinite loop
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Check if stack is empty\n");
        printf("5. Check if stack is full\n");
        printf("6. Reverse a string\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // push an element to the stack
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element); // push the element to the stack
            break;
        case 2:    // pop an element from the stack
            pop(); // pop the element from the stack
            break;
        case 3: // display the elements of the stack
            display();
            break;
        case 4: // check if the stack is empty
            if (is_empty())
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        case 5: // check if the stack is full
            if (is_full())
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;
        case 6: // reverse a string
            printf("Enter a string: ");
            scanf("%s", str);
            reverse_string(str);
            break;
        case 7: // exit the program
            exit(0);
        default: // if the user enters an invalid choice
            printf("Invalid choice\n");
        }
    }
    return 0;
}
