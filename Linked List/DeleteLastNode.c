#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;

void deleteLastNode()
{
    struct Node *ptr, *preptr;

    if (start == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    ptr = start;
    if (ptr->next == NULL)
    {
        free(ptr);
        start = NULL;
        return;
    }

    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
}

void insertEnd(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (start == NULL)
    {
        start = newNode;
        return;
    }

    struct Node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display()
{
    struct Node *temp = start;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("List:\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    display();
    deleteLastNode();
    display();
    return 0;
}