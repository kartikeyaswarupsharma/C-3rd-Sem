#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node* dltbtw(struct Node * head,int index){
    struct Node* p = head;
    struct Node *q = p->next;
    for (int i = 0; i < index; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);

    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL;

    Traversal(head);
    printf("Index deleted \n");
    head = dltbtw(head,1);

    Traversal(head);

    return 0;
}