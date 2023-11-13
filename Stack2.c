#include <stdio.h>//for printf(), scanf(), gets(), strcat()
#include <stdlib.h>//for malloc()

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;//store the element in the data field of the node
    temp->next = top;//link the node to the top
    top = temp;//link the top to the node
}

void pop()
{
    struct Node* temp;
    if (top == NULL)//if the stack is empty
    return;
    temp = top;//link temp to top
    top = top->next;//link top to the next node
    free(temp);//free the memory allocated to temp
}

int isEmpty()
{
    return top == NULL;//return 1
}

void display()
{
    struct Node* temp;//temp = NULL
    if (top == NULL)//if the stack is empty
    return;
    temp = top;
    while (temp != NULL)//traverse till the end of the stack
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, x;//for storing the choice and the element to be pushed
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &x);
                push(x);//push the element to the stack
                break;
            case 2:
                pop();//pop the element from the stack
                break;
            case 3:
                display();//display the elements of the stack
                break;
            case 4:
                exit(0);//exit the program
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
