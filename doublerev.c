#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev; 
};

struct node* createnode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("allocation failed\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void reverse(struct node** head){
    // struct node* next = NULL;
    // struct node* prev = NULL;
    struct node* temp = NULL;
    struct node* h = NULL;
    struct node* current = *head;
    
    while(current){
        
        temp = current -> next;
        current -> next = current -> prev;
        current -> prev = temp;
        if(temp == NULL){
            *head = current;
        }
        current = temp;
    }
    

    
    
    
}


void printlist(struct node** head) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct node* itr = (*head);
    while (itr != NULL) {
        printf("%d ", itr->data);
        printf("\t");
        itr = itr->next;
    }
    printf("\n");
}


int main() {
    struct node* head = createnode(0);

    struct node* itr = head;
    for (int i = 1; i < 11; i++) {
        struct node* temp = createnode(i);
        temp->prev = itr; 
        itr->next = temp;
        itr = itr->next;
    }
    printlist(&head);
    reverse(&head);
    printlist(&head);
    
}