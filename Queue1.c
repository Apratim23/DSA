#include <stdio.h>  //for printf(), scanf()
#include <stdlib.h> //for exit()

#define max 10

int queue[max];
int front = -1, rear = -1; // Initially, queue is empty

void enqueue(int data)
{
    if (rear == max - 1) // Queue is full
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) // Queue is empty
    {
        front = 0; // Set front to 0
    }
    rear++;             // Increment rear
    queue[rear] = data; // Insert data at rear
    printf("%d enqueued to queue\n", data);
}

void dequeue()
{
    if (front == -1) // Queue is empty
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front]);
    front++;          // Increment front
    if (front > rear) // If front is greater than rear, queue is empty
    {
        front = rear = -1; // Reset front and rear
    }
}

void traverse()
{
    if (front == -1) // Queue is empty
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int is_empty()
{
    if (front == -1) // Queue is empty
    {
        return 1;
    }
    return 0;
}

int is_full()
{
    if (rear == max - 1) // Queue is full
    {
        return 1;
    }
    return 0;
}

int main()
{
    int choice, data; // data is the value to be inserted in the queue
    while (1)
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
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traverse();
            break;
        case 4:
            if (is_empty())
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 5:
            if (is_full())
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Queue is not full\n");
            }
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
