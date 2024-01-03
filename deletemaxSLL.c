#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the linked list
void insertNode(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete the node with the maximum value in the linked list
void deleteMaxNode(struct Node **head) {
    if (*head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;
    struct Node *maxNode = *head;
    int maxVal = (*head)->data;

    while (current->next != NULL) {
        if (current->next->data > maxVal) {
            maxVal = current->next->data;
            maxNode = current->next;
            prev = current;
        }
        current = current->next;
    }

    if (maxNode == *head) {
        *head = maxNode->next;
    } else {
        prev->next = maxNode->next;
    }

    free(maxNode);
    printf("Deleted the node with the maximum value (%d).\n", maxVal);
}

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    // Insert nodes into the linked list
    insertNode(&head, 5);
    insertNode(&head, 8);
    insertNode(&head, 12);
    insertNode(&head, 3);
    insertNode(&head, 10);

    printf("Original linked list: ");
    printList(head);

    // Delete the node with the maximum value
    deleteMaxNode(&head);

    printf("Linked list after deleting the maximum node: ");
    printList(head);

    return 0;
}
