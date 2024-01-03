#include <stdio.h>
#include <stdlib.h>

// Define a basic structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find the smallest data in a circular linked list
int findSmallestData(struct Node* head) {
    if (head == NULL) {
        printf("The circular linked list is empty.\n");
        return -1; // Assuming -1 as a sentinel value for an empty list
    }

    struct Node* current = head;
    int smallest = head->data;

    do {
        if (current->data < smallest) {
            smallest = current->data;
        }
        current = current->next;
    } while (current != head);

    return smallest;
}

int main() {
    // Sample circular linked list creation
    struct Node* head = createNode(10);
    head->next = createNode(5);
    head->next->next = createNode(8);
    head->next->next->next = createNode(3);
    head->next->next->next->next = head; // Make it circular

    // Find the smallest data in the circular linked list
    int smallestData = findSmallestData(head);

    // Display the result
    if (smallestData != -1) {
        printf("The smallest data in the circular linked list is: %d\n", smallestData);
    }

    return 0;
}
