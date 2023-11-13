
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;// Data to be stored
    struct Node* next;// Pointer to the next node
};

struct Node* front = NULL;// Global variable - Pointer to front node
struct Node* rear = NULL;// Global variable - Pointer to rear node

void Enqueue(int x)// Inserting an element in the queue
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;// Initially, new node is pointing to NULL
    if(front == NULL && rear == NULL)// If queue is empty
    {
        front = rear = temp;// Both front and rear will point to new node
        return;
    }
    rear->next = temp;// Inserting new node at the end of the queue
    rear = temp;// Making rear point to new node
}

void Dequeue()
{
    struct Node* temp = front;
    if(front == NULL)// If queue is empty
    {
        printf("Queue is Empty\n");
        return;
    }
    if(front == rear)// If there is only one node in the queue
    {
        front = rear = NULL;// Reset front and rear
    }
    else
    {
        front = front->next;// Increment front
    }
    free(temp);// Delete the previous front node
}

int IsEmpty()
{
    if(front == NULL)// If queue is empty
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Traverse()
{
    struct Node* temp = front;
    while(temp != NULL)// Looping through the queue
    {
        printf("%d ",temp->data);
        temp = temp->next;// Increment temp
    }
    printf("\n");
}

int main()
{
    int choice, x;
    while(1)// Infinite loop
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&x);
                Enqueue(x);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                if(IsEmpty())
                {
                    printf("Queue is Empty\n");
                }
                else
                {
                    printf("Queue is not Empty\n");
                }
                break;
            case 4:
                Traverse();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
