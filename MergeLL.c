#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
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

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node* current = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            if (mergedList == NULL) {
                mergedList = createNode(list1->data);
                current = mergedList;
            } else {
                current->next = createNode(list1->data);
                current = current->next;
            }
            list1 = list1->next;
        } else {
            if (mergedList == NULL) {
                mergedList = createNode(list2->data);
                current = mergedList;
            } else {
                current->next = createNode(list2->data);
                current = current->next;
            }
            list2 = list2->next;
        }
    }

    // If there are remaining nodes in list1 or list2
    while (list1 != NULL) {
        current->next = createNode(list1->data);
        current = current->next;
        list1 = list1->next;
    }

    while (list2 != NULL) {
        current->next = createNode(list2->data);
        current = current->next;
        list2 = list2->next;
    }

    return mergedList;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into the first linked list
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);

    // Insert elements into the second linked list
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);

    printf("First Linked List:\n");
    printList(list1);

    printf("\nSecond Linked List:\n");
    printList(list2);

    // Merge the two sorted linked lists
    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("\nMerged Linked List:\n");
    printList(mergedList);

    // Free allocated memory
    freeList(list1);
    freeList(list2);
    freeList(mergedList);

    return 0;
}
