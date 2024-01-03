#include <stdio.h>
#include <stdlib.h>

struct doublenode {
    int data;
    struct doublenode* next;
    struct doublenode* prev; 
};

void printlistdoublylinked(struct doublenode** head) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct doublenode* itr = (*head);
    while (itr != NULL) {
        printf("%d ", itr->data);
        printf("\t");
        itr = itr->next;
    }
    printf("\n");
}

struct doublenode* createdoublenode(int data) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    if (temp == NULL) {
        printf("allocation failed\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void deletebegindoublylinked(struct doublenode** head) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct doublenode* temp = *head;
    *head = (*head)->next;
    if (*head) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteenddoublylinked(struct doublenode** head) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct doublenode* itr = (*head);
    while (itr->next != NULL) {
        itr = itr->next;
    }
    if (itr->prev) {
        itr->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(itr);
}

void deleteatkdoublylinked(struct doublenode** head, int k) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct doublenode* itr = (*head);
    while (itr != NULL && itr->data != k) {
        itr = itr->next;
    }
    if (!itr) {
        printf("Element %d not found\n", k);
        return;
    }
    if (itr->prev) {
        itr->prev->next = itr->next;
    } else {
        *head = itr->next;
    }
    if (itr->next) {
        itr->next->prev = itr->prev;
    }
    free(itr);
}

int main() {
    struct doublenode* head = createdoublenode(0);

    struct doublenode* itr = head;
    for (int i = 1; i < 11; i++) {
        struct doublenode* temp = createdoublenode(i);
        temp->prev = itr; 
        itr->next = temp;
        itr = itr->next;
    }

    printlistdoublylinked(&head);
    deletebegindoublylinked(&head);
    printlistdoublylinked(&head);

    deleteenddoublylinked(&head);
    printlistdoublylinked(&head);

    deleteatkdoublylinked(&head, 6);
    printlistdoublylinked(&head);

    return 0;
}