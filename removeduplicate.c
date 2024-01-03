#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
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
        newNode->prev = temp;
    }
}

// Function to remove duplicates from a doubly linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        struct Node* temp = current->next;
        while (temp != NULL) {
            if (current->data == temp->data) {
                // Duplicate found, remove temp
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
                if (temp->prev != NULL) {
                    temp->prev->next = temp->next;
                }
                free(temp);
            }
            temp = temp->next;
        }
        current = current->next;
    }
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the doubly linked list
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

    // Insert elements into the doubly linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 3);

    printf("Original Doubly Linked List:\n");
    printList(head);

    // Remove duplicates
    removeDuplicates(head);

    printf("\nDoubly Linked List after removing duplicates:\n");
    printList(head);

    // Free allocated memory
    freeList(head);

    return 0;
}
