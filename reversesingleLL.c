#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to reverse a linked list in groups of k
struct Node* reverseInGroups(struct Node* head, int k) {
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int count = 0;

    // Count the number of nodes in the current group
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }

    // Reverse the current group of k nodes
    if (count == k) {
        current = head;
        count = 0;
        while (current != NULL && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        // Recursively reverse the rest of the list
        if (next != NULL) {
            head->next = reverseInGroups(next, k);
        }

        return prev; // new head of the reversed group
    } else {
        return head; // if the remaining group has less than k elements
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    for (int i = 1; i <= 10; i++) {
        insertAtEnd(&head, i);
    }

    printf("Original Linked List:\n");
    printList(head);

    // Reverse the linked list in groups of k (e.g., k = 3)
    int k = 3;
    head = reverseInGroups(head, k);

    printf("\nLinked List after reversing in groups of %d:\n", k);
    printList(head);

    // Free allocated memory
    freeList(head);

    return 0;
}
