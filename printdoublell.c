#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createnode(int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("memory allocation failed");
        exit(1);    
    }

    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    return newnode;
}

void insertend(struct Node** head, int data)
{
    struct Node* newnode = createnode(data);

    if(*head == NULL)
    {
        *head = newnode;
    }else{
        struct Node* current = *head;
        while(current->next != NULL)
        {
            current=current->next;
        }
        current->next=newnode;
        newnode->prev=current;
    }
}
void printlist(struct Node* head){                               
    struct Node* current = head;
    int count = 0;

    while(current != NULL)
    {
        printf("Data : %d\n",current->data);
        count++;
        current=current->next;
    }
    printf("count : %d\n",count);
}

int main()
{
    struct Node* head = NULL;

    insertend(&head,2);
    insertend(&head,22);
    insertend(&head,12);
    insertend(&head,3);
    insertend(&head,5);

    printlist(head);

    return 0;
}
