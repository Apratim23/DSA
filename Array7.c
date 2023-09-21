#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at a specific position
void insert(struct Node **head, int position, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed.);
        return;
    }
    newNode->data = data;

    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node *prev = *head;
        for (int i = 1; i < position - 1 && prev != NULL; i++)
        {
            prev = prev->next;//
        }

        if (prev == NULL)
        {
            printf("Invalid position for insertion.\n");
            free(newNode);
            return;
        }

        newNode->next = prev->next;
        prev->next = newNode;//
    }

    printf("Node inserted successfully.\n");
}

// Function to delete a node from a specific position
void delete(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (position == 1)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else
    {
        struct Node *prev = *head;
        for (int i = 1; i < position - 1 && prev->next != NULL; i++)
        {
            prev = prev->next;
        }

        if (prev->next == NULL)
        {
            printf("Invalid position for deletion.\n");
            return;
        }

        struct Node *temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }

    printf("Node deleted successfully.\n");
}

// Function to count the number of nodes in the linked list
int count(struct Node *head)
{
    int count = 0;
    struct Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Function to traverse and print the linked list
void traverse(struct Node *head)
{
    struct Node *current = head;
    printf("Linked List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, position, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert a node at a specific position\n");
        printf("2. Delete a node from a specific position\n");
        printf("3. Count nodes\n");
        printf("4. Traverse the linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            printf("Enter the data: ");
            scanf("%d", &data);
            insert(&head, position, data);
            break;

        case 2:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            delete(&head, position);
            break;

        case 3:
            printf("Number of nodes: %d\n", count(head));
            break;

        case 4:
            traverse(head);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
