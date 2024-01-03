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

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to break the linked list into two halves
void breakLinkedList(struct Node* head, struct Node** first, struct Node** second) {
    if (head == NULL || head->next == NULL) {
        *first = head;
        *second = NULL;
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *first = head;
    *second = slow->next;
    slow->next = NULL;
}

// Driver program to test the above functions
int main() {
    struct Node* head = NULL;
    struct Node* firstHalf = NULL;
    struct Node* secondHalf = NULL;

    // Create a linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Original Linked List: ");
    printList(head);

    // Break the linked list into two halves
    breakLinkedList(head, &firstHalf, &secondHalf);

    printf("First Half: ");
    printList(firstHalf);

    printf("Second Half: ");
    printList(secondHalf);

    return 0;
}
