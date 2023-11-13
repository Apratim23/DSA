
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the node
struct node
{
    int data;
    int priority;
    struct node* next;
};

// Define the head of the linked list
struct node* head = NULL;

// Function to insert a new node in the priority queue
void enqueue(int data, int priority) {
    // Create a new node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;

    // If the queue is empty, make the new node the head
    if (head == NULL) {
        head = new_node;
        return;
    }

    // If the new node has higher priority than the head, make it the new head
    if (priority > head->priority)
    {
        new_node->next = head;
        head = new_node;
        return;
    }

    // Traverse the queue to find the correct position to insert the new node
    struct node* temp = head;
    while (temp->next != NULL && temp->next->priority >= priority)
    {
        temp = temp->next;
    }

    // Insert the new node
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to remove the node with the highest priority from the queue
void dequeue()
{
    // If the queue is empty, return
    if (head == NULL) {
        return;
    }

    // Remove the head node
    struct node* temp = head;
    head = head->next;
    free(temp);
}

// Function to traverse the queue and print the data of each node
void traverse() {
    // If the queue is empty, return
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    // Traverse the queue and print the data of each node
    struct node* temp = head;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to display the menu and call the appropriate functions
int main()
{
    int choice, data, priority;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
