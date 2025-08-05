#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void createSampleList(struct Node **start)
{
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    *start = n1;
}

void deleteAtPosition(struct Node **head, int position)
{
    struct Node *temp, *nodeToDelete;
    if (*head == NULL || position < 0)
    {
        printf("Invalid position or empty list.\n");
        return;
    }
    temp = *head;
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position.\n");
        return;
    }
    nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *start = NULL;

    createSampleList(&start);
    printf("Original List: ");
    display(start);

    deleteAtPosition(&start, 1);
    printf("List after deletion: ");
    display(start);

    return 0;
}