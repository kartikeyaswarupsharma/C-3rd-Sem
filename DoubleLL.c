#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create and return a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to print the number of nodes and data in the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    int count = 0;

    printf("Data in the doubly linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        count++;
        current = current->next;
    }
    printf("\nNumber of nodes in the doubly linked list: %d\n", count);
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the doubly linked list
    insertEnd(&head, 5);
    insertEnd(&head, 8);
    insertEnd(&head, 12);
    insertEnd(&head, 3);
    insertEnd(&head, 10);

    // Print the doubly linked list
    printList(head);

    return 0;
}
