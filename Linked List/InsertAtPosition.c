#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtPosition(struct Node **head, int data, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    int i;

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    temp = *head;
    for (i = 1; (temp != NULL) && (i < position - 1); i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    insertAtPosition(&head, 10, 1);
    insertAtPosition(&head, 30, 2);
    insertAtPosition(&head, 20, 2);
    insertAtPosition(&head, 40, 4);
    insertAtPosition(&head, 5, 1);

    printList(head);
    return 0;
}