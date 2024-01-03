#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to find the length of a linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the intersection point of two linked lists
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int length1 = getLength(head1);
    int length2 = getLength(head2);

    // Find the absolute difference in lengths
    int lengthDiff = abs(length1 - length2);

    // Move the pointer of the longer linked list by the difference in lengths
    if (length1 > length2) {
        while (lengthDiff--) {
            head1 = head1->next;
        }
    } else {
        while (lengthDiff--) {
            head2 = head2->next;
        }
    }

    // Traverse both linked lists until the intersection point is found
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1; // Intersection point found
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; // No intersection point found
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create linked list 1: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);
    head1->next->next->next->next->next = createNode(6);
    head1->next->next->next->next->next->next = createNode(7);

    // Create linked list 2: 10 -> 9 -> 8 -> 5 -> 6 -> 7
    struct Node* head2 = createNode(10);
    head2->next = createNode(9);
    head2->next->next = createNode(8);
    head2->next->next->next = head1->next->next->next->next; // Set intersection point

    printf("Linked List 1: ");
    printList(head1);

    printf("Linked List 2: ");
    printList(head2);

    struct Node* intersectionPoint = findIntersection(head1, head2);

    if (intersectionPoint != NULL) {
        printf("Intersection Point: %d\n", intersectionPoint->data);
    } else {
        printf("No Intersection Point\n");
    }

    // Free allocated memory
    free(head1);
    free(head2);

    return 0;
}
