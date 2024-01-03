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

// Function to detect a cycle in a linked list using Floyd's Cycle Detection Algorithm
int detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If there is a cycle, the pointers will meet at some point
        if (slow == fast) {
            return 1; // Cycle detected
        }
    }

    return 0; // No cycle detected
}

// Driver program to test the above functions
int main() {
    struct Node* head = NULL;

    // Create a linked list with a cycle
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // Create a cycle in the linked list
    head->next->next->next->next->next = head->next;

    // Check whether the linked list has a cycle
    if (detectCycle(head))
        printf("Linked list has a cycle.\n");
    else
        printf("Linked list does not have a cycle.\n");

    return 0;
}
