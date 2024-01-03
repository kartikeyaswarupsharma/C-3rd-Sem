#include<stdio.h>
#include<stdlib.h>


struct doublenode {
    int data;
    struct doublenode* next;
    struct doublenode* prev;
};


void insertatbegindoublylinked(struct doublenode** head, int val) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    temp->data = val;
    temp->prev = NULL;
    if (!(*head)) {
        temp->next = NULL; 
    } else {
        temp->next = *head;
        (*head)->prev = temp;
    }
    *head = temp;
}

void printlistdoublylinked(struct doublenode** head){
    if(!(*head)){
        printf("List is empty\n");
        return;
    }
    struct doublenode* itr = (*head);
    while(itr!= NULL ){
        

        printf("%d ",itr->data );
        printf("\t");
        itr = itr->next;
        
    }
};




void insertatenddoublylinked(struct doublenode** head, int val) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    temp->data = val;
    temp->next = NULL;
    if (!(*head)) {
        temp->prev = NULL; 
        *head = temp;
        return;
    }
    struct doublenode* itr = *head;
    while (itr->next) {
        itr = itr->next;
    }
    itr->next = temp;
    temp->prev = itr;
}


void insertafterdoublylinked(struct doublenode** head, int k, int val) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }
    struct doublenode* itr = *head;
    while (itr->data != k && itr->next) {
        itr = itr->next;
    }
    temp->next = itr->next;
    temp->prev = itr;
    if (itr->next) {
        itr->next->prev = temp;
    }
    itr->next = temp;
}







int main(){
    struct doublenode* head = NULL;

    insertatbegindoublylinked(&head,6);
    insertatbegindoublylinked(&head,7);
    insertatbegindoublylinked(&head,8);
    insertatbegindoublylinked(&head,9);
    insertatenddoublylinked(&head,5);
    insertafterdoublylinked(&head,6,5.5);

    printlistdoublylinked(&head);
}
    