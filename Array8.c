#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
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

    printf("Node appended successfully.\n");
}

// Function to search for an element in the list
int searchElement(struct Node* head, int target) {
    int position = 1;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Element not found
}

// Function to sort the list in ascending order using bubble sort
void sortList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // List is already sorted or empty
    }

    int swapped;
    struct Node* current;
    struct Node* last = NULL;

    do {
        swapped = 0;
        current = *head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                // Swap data of adjacent nodes
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    printf("List sorted in ascending order.\n");
}

// Function to reverse the list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    printf("List reversed.\n");
}

// Function to traverse and print the linked list
void traverseList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, target, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Append a node\n");
        printf("2. Search for an element\n");
        printf("3. Sort the list (ascending order)\n");
        printf("4. Reverse the list\n");
        printf("5. Traverse the linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                appendNode(&head, data);
                break;

            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &target);
                position = searchElement(head, target);
                if (position != -1) {
                    printf("Element found at position %d.\n", position);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;

            case 3:
                sortList(&head);
                break;

            case 4:
                reverseList(&head);
                break;

            case 5:
                traverseList(head);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
