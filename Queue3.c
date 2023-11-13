
#include <stdio.h>// Pre-Process directive to include standard input output header file
#define max 5

int queue[max];// Array implementation of queue
int front = -1, rear = -1;// Initially, queue is empty

void enqueue(int value)
{
    if ((front == 0 && rear == max - 1) || (rear == front - 1))// Queue is full
    {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1)// Queue is empty
    {
        front = rear = 0;// Set front and rear to 0
        queue[rear] = value;// Insert value at rear
    }
    else if (rear == max - 1 && front != 0)// Rear is at last position of queue
    {
        rear = 0;// Set rear to 0
        queue[rear] = value;// Insert value at rear
    }
    else
    {
        rear++;// Increment rear
        queue[rear] = value;// Insert value at rear
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)// Queue is empty
    {
        printf("Queue is empty\n");
    } else if (front == rear)// Queue has only one element
    {
        printf("Deleted element: %d\n", queue[front]);
        front = rear = -1;// Reset front and rear
    }
    else if (front == max - 1)// Front is at last position of queue
    {
        printf("Deleted element: %d\n", queue[front]);
        front = 0;// Set front to 0
    } else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;// Increment front
    }
}

void traverse()
{
    if (front == -1 && rear == -1)// Queue is empty
    {
        printf("Queue is empty\n");
    } else
    {
        printf("Queue elements: ");
        int i;
        if (front <= rear)// Front is less than or equal to rear
        {
            for (i = front; i <= rear; i++)// Looping through the queue
            {
                printf("%d ", queue[i]);
            }
        } else
        {
            for (i = front; i < max; i++)
            {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++)// Looping through the queue
            {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

int is_empty()
{
    if (front == -1 && rear == -1)// Queue is empty
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full()
{
    if ((front == 0 && rear == max - 1) || (rear == front - 1))// Queue is full
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int choice, value;// Variable declaration
    while (1)// Infinite loop
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);// Enqueue value to queue
                break;
            case 2:
                dequeue();// Dequeue element from queue
                break;
            case 3:
                traverse();// Traverse queue
                break;
            case 4:
                if (is_empty())// Check queue is empty
                {
                    printf("Queue is empty\n");
                }
                 else
                  {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                if (is_full())// Check queue is full
                 {
                    printf("Queue is full\n");
                }
                 else
                 {
                    printf("Queue is not full\n");
                }
                break;
            case 6:
                printf("Exiting from program\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
