#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

// Function to reverse k nodes in a linked list
struct Node* reverseKNodes(struct Node* head, int k) {
    struct Node *current = head, *next = NULL, *prev = NULL;
    int count = 0;

    // Count the number of nodes in the current k nodes segment
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // If there are more nodes, recursively reverse the next k nodes
    if (next != NULL)
        head->next = reverseKNodes(next, k);

    return prev;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver program to test the above functions
int main() {
    struct Node* head = NULL;

    // Create a linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);
    append(&head, 7);
    append(&head, 8);

    int k = 3; // Set the value of k

    printf("Original Linked List: ");
    printList(head);

    // Reverse k nodes
    head = reverseKNodes(head, k);

    printf("Reversed Linked List in groups of %d: ", k);
    printList(head);

    return 0;
}
